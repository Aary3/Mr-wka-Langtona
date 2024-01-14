#include <stdio.h>
#include "siatka.h"
#include "poz.h"
#include "plansza.h"
#include "getarg.h"

int main(int argc, char **argv) {
	arg arglist=malloc(sizeof(arg));
	getarg(argc, argv, arglist);
	if(arglist.load==0)
		plansza board[arglist.m][arglist.n];
	return 0;
}
