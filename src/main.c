#include "plansza.h"
#include "getarg.h"
#include "operacja.h"
#include "rys.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main(int argc, char **argv)
{
	arg *arglist=malloc(sizeof *arglist);
	getarg(argc, argv, arglist);
	if(arglist->load==0 )//jesli nie wczytujemy zrob board
	{
		plansza **board = malloc(arglist->m * sizeof(plansza *));
		for (int i = 0; i < arglist->m; i++)
			board[i] = malloc(arglist->n * sizeof(plansza);	
		mrowisko *mrowka = malloc(sizeof *mrowka);
		if(arglist->czydir == 0) 
			mrowka->kierunek = 1;
		else
		{
			if (strcmp(arglist->dir, "up") == 0)			//zmiana kierunku z char na int
				mrowka->kierunek = 1;
			else if (strcmp(arglist->dir, "right") == 0)
				mrowka->kierunek = 2;
			else if(strcmp(arglist->dir, "down") == 0)
				mrowka->kierunek = 3;
			else if(strcmp(arglist->dir, "left") == 0)
				mrowka->kierunek = 0;
		}
		mrowka->x = arglist->n / 2;
		mrowka->y = arglist->m / 2; //pozycja startowa na srodku ~
	} else //tu napisac wczytanie
	{
		plansza **board;
		mrowisko *mrowka=malloc(sizeof(mrowisko));
		wczytywanie(board, mrowka, arglist);
	}

	board = przejscie_mrowki(arglist->i, mrowka, board);

	//zwalnianie pamięci
	for (int i = 0; i < arglist->m; i++)
		free(board[i]);
	free(board);
	free(arglist);
	free(file_out);
	free(mrowka);
	return 0;
}
