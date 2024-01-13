
#include "rys.h"

void wypisz(FILE *file, plansza **array, int m, int n) {
	int x = 0;
	int y = 0;
	for (int i = 1; i <= 2*m+1; i++) {		//wiersze
		x = (i-1)/2;
		for (int j = 1; j <= 2*n+1; j++) {		//kolumny
			y = (j-1)/2;
			if (i == 1 && j == 1)			//najpierw warunki dla rogów
				printf("┌");
			else if (i == 1 && j == 2*n+1)
				printf ("┐");
			else if (i == 2*m+2 && j == 1)
				printf("└");
			else if (i == 2*m+2 && j == 2*n+2)
				printf("┘");
			else if ( i % 2 == 1)			//jak jesteśmy w nieparzystym wierszu
				printf("─");			//jak jesteśmy w parzystym wierszu
			else if (j % 2 == 1)			//jak jesteśmy w nieparzystej kolumnie
				printf("│");
			else if (array[x][y].state == 1)
				printf("█");
			else
				printf(" ");

		}
	printf("\n");	
}
}
