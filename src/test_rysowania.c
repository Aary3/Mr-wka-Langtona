#include <stdio.h>
#include "rys.h"

int main() {
	plansza **array = malloc(9*sizeof*array);
	array[0] = malloc(4*sizeof*array);
	array[0][0].state = 1;
	array[0][1].state = 0;
	array[0][2].state = 1;
	array[0][3].state = 0;
	array[1] = malloc(4*sizeof*array);
	array[1][0].state = 0;
	array[1][1].state = 0;
	array[1][2].state = 0;
	array[1][3].state = 1;
	array[2] = malloc(4*sizeof*array);
	array[2][0].state = 1;
	array[2][1].state = 1;
	array[2][2].state = 1;
	array[2][3].state = 0;
	FILE *file = stdout;
	wypisz(file, array, 3, 4);
	return 0;
}
