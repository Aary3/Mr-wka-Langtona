#include "ruch.h"

char *obrot_prawo(poz_t poz) {
	if (strcmp(poz->kierunek,"up")==0) {
		poz->kierunek = "right";
		return poz->kierunek;
	}
	if (strcmp(poz->kierunek."right")==0) {
		poz->kierunek = "down";
		return poz->kierunek;
	}
	if(strcpm(poz->kierunek,"down")==0) {
		poz->kierunek = "left";
		return poz->kierunek;
	}
	if (strcmp(poz->kierunek, "left")==0) {
		poz->kierunek = "up";
		return poz->kierunek;
}

char *obrot_lewo(poz_t poz) {
        if (strcmp(poz->kierunek,"up")==0) {
                poz->kierunek = "left";
                return poz->kierunek;
        }
        if (strcmp(poz->kierunek."right")==0) {
                poz->kierunek = "up";
                return poz->kierunek;
        }
        if(strcpm(poz->kierunek,"down")==0) {
                poz->kierunek = "right";
                return poz->kierunek;
        }
        if (strcmp(poz->kierunek, "left")==0) {
                poz->kierunek = "down";
                return poz->kierunek;
}


poz_t zmiana(poz_t poz) {
	if (poz->kolor == 0) {
		poz->kolor = 1;
		poz->kierunek = obrot_prawo(poz);
	}
	else {
		poz->kolor = 0;
		poz->kierunek = obort_lewo(poz);
	}
	poz = ruch(poz);
	return poz;
}

poz_t ruch(poz_t poz) {
	if(strcmp(poz->kierunek, "up")==0)
		poz->y+=1;
	if(strcmp(poz->kierunek, "right")==0)
		poz->x+=1;
	if(strcmp(poz->kierunek,"down")==0)
		poz->y-=1;
	if(strcmp(poz->kierunek,"left")==0)
		poz->s-=1;
	return poz;
}
