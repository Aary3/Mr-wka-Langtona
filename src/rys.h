#ifndef RYS_H
#define RYS_H
#include "plansza.h"
#include <stdio.h>
#include <locale.h>
#include <wchar.h>

void wypisz ( plansza **array, mrowisko *mrowka, arg *arglist, int iteracja );

plansza **wczytaj (mrowisko *mrowka, arg *arglist);

#endif
