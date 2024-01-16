#include "poz.h"
#include "plansza.h"
#include "getarg.h"

int main(int argc, char **argv) {
	arg arglist=malloc(sizeof(arg));
	getarg(argc, argv, arglist);
	if(arglist.load==0)
		plansza board[arglist.m][arglist.n];
	char *file_out = malloc(50*sizeof *file_out);
	if(arglist.filename == NULL)
		sprintf(file_out, "plansza_%diteracji", arglist.i);
	else
		sprintf(file_out, "%s_%diteracji", arglist.filename, arglist.i);
	FILE *f = fopen(file_out, "w");
	
	return 0;
}
