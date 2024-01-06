#include "poz.h"

poz_t poz_init(poz_t poz) {
	poz->kierunek = malloc(sizeof*(poz->kierunek));
	return poz;
}
