#include "plansza.h"

int mrowka_operacja(mrowisko *mrowka, plansza **array, arg *arglist){
	switch(array[mrowka->y][mrowka->x].state) 
	{
		case 0:
			mrowka->kierunek+=1;
			mrowka->kierunek%=4;//aby nie wyszlo za zakres kierunkow;
			array[mrowka->y][mrowka->x].state=1;
			break;
		case 1:
			mrowka->kierunek+=3;//symuluje +=4 ; -=1(+4 gwarantuje ze nie zejdziemy na liczbe ujemna i daje reszte 0 przy mod4 wiec nie ma znaczenia a -1 to kierunek w lewo)
			mrowka->kierunek%=4;
			array[mrowka->y][mrowka->x].state=0;
			break;
	}
	switch(mrowka->kierunek)
       	{
		case 0:
			mrowka->y-=1;
			if(mrowka->x<0)
				mrowka->x=arglist->m-1;
			break;
		case 1:
			mrowka->x-=1;
			if(mrowka->y==arglist->n)
				mrowka->y=0;
			break;
		case 2:
			mrowka->y+=1;
			if(mrowka->x==arglist->m)
				mrowka->x=0;
			break;
		case 3:
			mrowka->x+=1;
			if(mrowka->y<0)
				mrowka->y=arglist->n-1;
			break;
	}
}
