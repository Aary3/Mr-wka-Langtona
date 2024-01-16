#include "getarg.h"

void getarg(int argc, char **argv, arg argload)
{
	int opt;
	while((opt=getopt(argc, argv, ":m:n:i:f:d:l:r:"))!= -1)
	{
		switch(opt)
		{
			case 'm':
				argload.m=atoi(optarg);
				break;
			case 'n':
				argload.n=atoi(optarg);
				break;
			case 'i':
				argload.i=atoi(optarg);
				break;
			case 'f':
				argload.czyf=1;
				argload.filename=optarg;
				break;
			case 'd':
				argload.dir=optarg;
				break;
			case 'l':
				argload.load=1;
				argload.loadf=optarg;
				break;
			case 'r':
				argload.rand=1;
				argload.randval=atoi(optarg);
			case '?':
				printf("nieznany argument: %c\n", optopt);
				break;
			case ':':
				printf("argument %c wymaga wartosci\n", optopt);
		}
	}
}
