#ifndef PLANSZA_H
#define PLANSZA_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "getarg.h"

typedef struct komorka{ //idea: zadeklarowac pointer[x][y] o wymiarach planszy
	bool state; 	// i trzymac stan.
} plansza;

typedef struct mrow{
	int kierunek; //0< 1^ 2> 3v
	int x;
	int y;
} mrowisko;

int mrowka_operacja(mrowisko *mrowka, plansza **array, arg *arglist);

#endif
