#include "przeszkody.h"

plansza **przeszkody(plansza **array,arg *arglist) {
	srand(time(NULL));
	double random = 0;
	for (int i = 0; i < arglist->m; i++)
	       for(int j = 0; j < arglist->n; j++) {
		       random = (double)rand()/RAND_MAX;
		       if (random <= (arglist->randval/100))
			       array[i][j].state=1;
		       else
			       array[i][j].state=0;
	       }
	return array;
}
