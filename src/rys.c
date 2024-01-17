
#include "rys.h"

void wypisz(FILE *file, plansza **array, mrowisko *mrowka, int m, int n) {
	int x = 0;
	int y = 0;
	for (int i = 1; i <= 2*m+1; i++) {		//wiersze
		x = (i-1)/2;
		for (int j = 1; j <= 2*n+1; j++) {		//kolumny
			y = (j-1)/2;
			if (i == 1 && j == 1)			//najpierw warunki dla rogów
				fprintf(file, "┌");
			else if (i == 1 && j == 2*n+1)
				fprintf (file, "┐");
			else if (i == 2*m+2 && j == 1)
				fprintf(file, "└");
			else if (i == 2*m+2 && j == 2*n+2)
				fprintf(file, "┘");
			else if ( i % 2 == 1)			//jak jesteśmy w nieparzystym wierszu
					fprintf(file, "─");			//jak jesteśmy w parzystym wierszu
			else if (j % 2 == 1)			//jak jesteśmy w nieparzystej kolumnie
				fprintf(file, "│");
			else if (array[x][y].state == 1)
			{
				if(mrowka->x==x && mrowka->y==y)
					switch(mrowka->kierunek){
						case 0:
							fprintf(file, "◀");
							break;
						case 1:
							fprintf(file, "▲");
							break;
						case 2:
							fprintf(file, "▶");
							break;
						case 3:
							fprintf(file, "▼");
					}
				else	
					fprintf(file, "█");
			}
			else
			{
			if(mrowka->x==x && mrowka->y==y)
                                        switch(mrowka->kierunek){
                                                case 0:
                                                        fprintf(file, "◁");
                                                        break;
                                                case 1:
                                                        fprintf(file, "△");
                                                        break;
                                                case 2:
                                                        fprintf(file, "▷");
                                                        break;  
                                                case 3:
                                                        fprintf(file, "▽");
                                        }
                                else    
                                        fprintf(file, " ");
			}
		}
	fprintf(file, "\n");	
}
}
