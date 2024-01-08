#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct komorka{ //idea: zadeklarowac pointer[x][y] o wymiarach planszy
	bool state; 	// i trzymac stan.
} plansza;

typedef struct mrow{
	int kierunek; //0< 1^ 2> 3v
	int x;
	int y;
} mrowisko;

int mrowka_operacja(mrowisko mrowka, plansza **array);


