#include "operacja.h"

plansza **przejscie_mrowki(int it, mrowisko *mrowka, plansza **array) {
	for (int i = 0; i < it; i++)
		mrowka_operacja(mrowka, array);
	return array;
}
