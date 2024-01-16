#include "plansza.h"
#include "getarg.h"
#include "operacja.h"
#include "rys.h"
#include <stdlib.h>

int main(int argc, char **argv) {
	arg *arglist=malloc(sizeof *arglist);
	getarg(argc, argv, arglist);
	if(arglist->load==0)
		;
	plansza **board = malloc(arglist->m * sizeof(plansza *));
	for (int i = 0; i < arglist->m; i++)
			board[i] = malloc(arglist->n * sizeof(plansza));
	char *file_out = malloc(50*sizeof *file_out);
	if(arglist->filename == NULL)
		sprintf(file_out, "plansza_%diteracji.txt", arglist->i);
	else
		sprintf(file_out, "%s_%diteracji.txt", arglist->filename, arglist->i);
	FILE *f = fopen(file_out, "w");
	
	mrowisko *mrowka = malloc(sizeof *mrowka);
	mrowka->kierunek = arglist->dir;
	mrowka->x = arglist->n / 2;
	mrowka->y = arglist->m / 2;
	board = przejscie_mrowki(arglist->i, mrowka, board);

	wypisz(f, board, arglist->m, arglist->n);

	//zwalnianie pamięci
	free(arglist);
	for (int i = 0; i < arglist->m; i++)
		free(board[i]);
	free(board);
	free(file_out);
	free(mrowka);
	return 0;
}
