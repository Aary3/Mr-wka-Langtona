#include <stdio.h>
#include "siatka.h"
#include "poz.h"

int main(int argc, char **argv) {
	int m = argc>1?atoi(argv[1]):10;
	int n = argc>2?atoi(argv[2]):10;
	int i = argc>3?atoi(argv[3]):5;

	int **siatka;
	siatka = siatka_init(siatka, m, n);

	return 0;
}
