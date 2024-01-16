#include <stdio.h>
#include "siatka.h"
#include "ruch.h"

int main(int argc, char **argv) {
	int m = argc>1?atoi(argv[1]):10;
	int n = argc>2?atoi(argv[2]):10;
	int it = argc>3?atoi(argv[3]):5;
	char *kierunek = argc>4?argv[4]:"up";

	int **siatka;
	poz_t pozycja;
	siatka = siatka_init(siatka, m, n);
	if (siatka == NULL) {
		fprintf(stderr, "%s: Nie udało się zaalokować pamięci na siatkę!\n", argv[0]);
		return 1;
	}
	pozycja = poz_init(pozycja);
	if (pozycja == NULL) {
		fprintf(stderr, "%s: Nie udało się zaalokować pamięci na pozycję!\n", argv[0]);
	}
	siatka = przejscia(pozycja, siatka, 3, 3, it, kierunek);

	return 0;
}
