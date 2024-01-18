
#include "rys.h"

void wypisz(plansza **array, mrowisko *mrowka, arg *arglist, int iteracja) {
        int m=arglist->m;
	int n=arglist->n;
	int ilecyfr=0;
	int kopia=iteracja;
	while(kopia>0)
	{
		ilecyfr++;
		kopia/=10;
	}
	if(arglist->czyf == 0)
		FILE *file=stdout;
        else
	{
		char *file_out=malloc((ilecyfr+strlen(arglist->filename)+14)*sizeof(char));
                sprintf(file_out, "%s_%diteracji.txt", arglist->filename, arglist->i);
		FILE *file=fopen(file_out, "w");
	}
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

void wczytaj(plansza **array, mrowisko *mrowka, arg *arglist)
{
	if(load==1){
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
					n=(strlen(buf))/2-1;
				}
			}
	       		counter++;
		}
		**board = malloc(m * sizeof(plansza *));
                for (int i = 0; i < m; i++)
                        board[i] = malloc(n * sizeof(plansza);
		rewind(fload);
		counter=0;
                while(fgetws(buf,1000,fload)!=NULL)//w koncu wypelniamy tablice
		{
			if(counter%2!=0)
                               	for(int i=0;i<strlen(buf),i++)
					if((i-1)%2==0)
						if(buf[i]==" ") //biale
							board[(counter-1)/2][(i-1)/2]=0;
						else if(buf[i]=="█") //czarne
							board[(counter-1)/2][(i-1)/2]=1;
						else //mrowka
						{
							mrowka->x=(counter-1)/2;
							mrowka->y=(i-1)/2;
							switch(buf[i])
							{
								case "◀":
									mrowka->kierunek=0;
									board[(counter-1)/2][(i-1)/2]=1;
                                                        		break;
								case "▲":
									mrowka->kierunek=1;
									board[(counter-1)/2][(i-1)/2]=1;
									break;
								case "▶":
									mrowka->kierunek=2;
									board[(counter-1)/2][(i-1)/2]=1;
                                                        		break;
								case "▼":
									mrowka->kierunek=3;
									board[(counter-1)/2][(i-1)/2]=1;
                                                        		break;
								case "◁":
									mrowka->kierunek=0;
									board[(counter-1)/2][(i-1)/2]=0;
                                                        		break;
								case "△":
									mrowka->kierunek=1;
									board[(counter-1)/2][(i-1)/2]=0;
									break;
								case "▷":
									mrowka->kierunek=2;
									board[(counter-1)/2][(i-1)/2]=0;
									break;
                                                        	case "▽":
									mrowka->kierunek=3;
									board[(counter-1)/2][(i-1)/2]=0;
									break;
								default:
									printf("cos nie dziala we wczytywaniu \n");
							}
						}
                        counter++;
                }
	}
}
