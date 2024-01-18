#include "operacja.h"
#include "rys.h"
#include "plansza.h"

plansza **przejscie_mrowki(int it, mrowisko *mrowka, plansza **array, arg *arglist ) {
	wypisz(array, mrowka, arglist, 0);
	for (int i = 0; i < it; i++){
		mrowka_operacja(mrowka, array, arglist);
		wypisz(array, mrowka, arglist, i);}
	return array;
}
