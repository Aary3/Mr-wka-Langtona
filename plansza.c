#include <stdlib.h>
#include <stdio.h>

int mrowka_operacja(mrowisko mrowka, plansza **array){
	switch(array[mrowka.x][mrowka.y].state) {
		case 0:
			mrowka.kierunek+=1;
			mrowka.kierunek%=4;//aby nie wyszlo za zakres kierunkow;
			array[mrowka.x][mrowka.y].state=1;
			break;
		case 1:
			mrowka.kierunek+=3;//symuluje +=4 ; -=1(+4 gwarantuje ze nie zejdziemy na liczbe ujemna i daje reszte 0 przy mod4 wiec nie ma znaczenia a -1 to kierunek w lewo)
			mrowka.kierunek%=4;
			array[mrowka.x][mrowka.y].state=0;
			break;
	}
	switch(mrowka.kierunek) {
		case 0:
			mrowka.x-=1;
			break;
		case 1:
			mrowka.y+=1;
			break;
		case 2:
			mrowka.x+=1;
			break;
		case 3:
			mrowka.y-=1;
			break;

	}

}

