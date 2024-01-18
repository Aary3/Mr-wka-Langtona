#include "getarg.h"

void getarg(int argc, char **argv, arg *argload)
{
	int opt;
	//domyślne wartości; jak getopt przeczyta jakąś to ją nadpisze
	argload->m = 10;
	argload->n = 10;
	argload->i = 10;
	argload->czyf=0;
	argload->czydir=0;
	argload->load = 0;
	argload->rand = 0;
	argload->filename_len = 0;

	while((opt=getopt(argc, argv, ":m:n:i:f:d:l:r:"))!= -1)
	{
		switch(opt)
		{
			case 'm':
				argload->m=atoi(optarg);
				break;
			case 'n':
				argload->n=atoi(optarg);
				break;
			case 'i':
				argload->i=atoi(optarg);
				break;
			case 'f':
				argload->czyf=1;
				argload->filename=malloc(strlen(optarg)*sizeof(char));
				argload->filename=optarg;
				argload->filename_len=strlen(argload->filename);
				break;
			case 'd':
				argload->czydir=1;
				argload->dir=malloc(strlen(optarg)*sizeof(char));
				argload->dir=optarg;
				break;
			case 'l':
				argload->load=1;
				argload->loadf=malloc(strlen(optarg)*sizeof(char));
				argload->loadf=optarg;
				break;
			case 'r':
				argload->rand=1;
				argload->randval=atof(optarg);
				break;
			case '?':
				printf("nieznany argument: %c\n", optopt);
				break;
			case ':':
				printf("argument %c wymaga wartosci\n", optopt);
		}
	}
}
