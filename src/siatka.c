#include "siatka.h"

int **siatka_init(int **siatka, int m, int n) {			//siatka jako tablica
	siatka = malloc(m*sizeof(int*));
	for (int i = 0; i < m; i++) {
		siatka[i] = malloc(n*sizeof(int));
		for(int j = 0; j < n; j++)
			siatka[i][j] = 0;		//0 - biale pole; 1 - czarne pole
	}
	return siatka;
}
