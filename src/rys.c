
#include "rys.h"

void wypisz(plansza **array, mrowisko *mrowka, arg *arglist, int iteracja) {
        int m=arglist->m;
	int n=arglist->n;
	int ilecyfr=0;
	int kopia=iteracja;
	FILE *file;
	while(kopia>0)
	{
		ilecyfr++;
		kopia/=10;
	}
	char *file_out = NULL;
	if(arglist->czyf == 0)
		file=stdout;
        else
	{
		file_out=malloc((ilecyfr+arglist->filename_len+14)*sizeof(char));
                sprintf(file_out, "%s_%diteracji.txt", arglist->filename, arglist->i);
		if (iteracja == -1)
			file=fopen(file_out, "w");
		else
			file=fopen(file_out, "a+");
	}
	int x = 0;
	int y = 0;
	if (file == stdout)
		fprintf(file, "Iteracja nr. %d:\n", iteracja+1);
	for (int i = 1; i <= 2*m+1; i++) {		//wiersze
		y = (i-1)/2;
		for (int j = 1; j <= 2*n+1; j++) {		//kolumny
			x = (j-1)/2;
			if (i == 1 && j == 1)			//najpierw warunki dla rogów
				fprintf(file, "┌");
			else if (i == 1 && j == 2*n+1)
				fprintf (file, "┐");
			else if (i == 2*m+1 && j == 1)
				fprintf(file, "└");
			else if (i == 2*m+1 && j == 2*n+1)
				fprintf(file, "┘");
			else if ( i % 2 == 1)			//jak jesteśmy w nieparzystym wierszu
					if (j % 2 == 1 && i != 1 && i != 2*m+1)
						fprintf(file,"│");
					else
						fprintf(file, "─");			//jak jesteśmy w parzystym wierszu
			else if (j % 2 == 1)			//jak jesteśmy w nieparzystej kolumnie
				fprintf(file, "│");
			else if (array[x][y].state == 1)
			{
				if(mrowka->y==x && mrowka->x==y)
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
			if(mrowka->y==x && mrowka->x==y)
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

	free(file_out);
}

plansza **wczytaj(mrowisko *mrowka, arg *arglist)
{
	if(arglist->load==1){
		FILE *fload;
		wchar_t buf[1000];
		int counter=0; //liczy linijki pliku
		int m=0;
		int n=0; //liczy wiersze pliku
		setlocale(LC_CTYPE, "it_IT.UTF-8");
		if((fload=fopen(arglist->filename,"r"))==NULL)
			printf("\n blad w otwarciu pliku \n");
		while(fgetws(buf,1000,fload)!=NULL)
		{//faktyczne wczytywanie (to powinno czytac linijke albo 1000 znakow(co pierwsze)// na start znajdujemy m i n
			if(counter%2!=0)
			{
				m++;
				if(counter==1)
				{
					n=(wcslen(buf))/2-1;
				}
			}
	       		counter++;
		}
		plansza **board = malloc(m * sizeof(plansza *));
                for (int i = 0; i < m; i++)
                        board[i] = malloc(n * sizeof(plansza));
		rewind(fload);
		counter=0;
                while(fgetws(buf,1000,fload)!=NULL)
		{					//w koncu wypelniamy tablice
			if(counter%2!=0)
                               	for(int i=0;i<wcslen(buf);i++)
					if((i-1)%2==0)
						if(buf[i]==L' ') //biale
							board[(counter-1)/2][(i-1)/2].state=0;
						else if(buf[i]==L'█') //czarne
							board[(counter-1)/2][(i-1)/2].state=1;
						else //mrowka
						{
							mrowka->x=(counter-1)/2;
							mrowka->y=(i-1)/2;
							
							switch(buf[i])
							{
								case L'◀':
									mrowka->kierunek=0;
									board[(counter-1)/2][(i-1)/2].state=1;
									break;
								case L'▲':
									mrowka->kierunek=1;
									board[(counter-1)/2][(i-1)/2].state=1;
									break;
								case L'▶':
									mrowka->kierunek=2;
									board[(counter-1)/2][(i-1)/2].state=1;
                                                        		break;
								case L'▼':
									mrowka->kierunek=3;
									board[(counter-1)/2][(i-1)/2].state=1;
                                                        		break;
								case L'◁':
									mrowka->kierunek=0;
									board[(counter-1)/2][(i-1)/2].state=0;
                                                        		break;
								case L'△':
									mrowka->kierunek=1;
									board[(counter-1)/2][(i-1)/2].state=0;
									break;
								case L'▷':
									mrowka->kierunek=2;
									board[(counter-1)/2][(i-1)/2].state=0;
									break;
								case L'▽':
									mrowka->kierunek=3;
									board[(counter-1)/2][(i-1)/2].state=0;
									break;
								default:
									printf("cos nie dziala we wczytywaniu \n");
							}
						}
                        counter++;
                }
		arglist->m = m;
		arglist->n = n;
		return board;
	}
	return NULL;
}
