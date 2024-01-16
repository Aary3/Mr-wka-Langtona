#ifndef GETARG_H
#define GETARG_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct argumennty {
	int m;
	int n;
	int i;
	bool czyf;
	char *filename;
	char dir;
	bool load;
	bool rand;
	char *loadf;
	int randval;
} arg;

void getarg(int argc, char **argv);

#endif
