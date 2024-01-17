all:
	gcc -pedantic -ggdb src/*.h src/*.c -o bin/mrowka

test: all
	bin/mrowka -m 10 -n 10 -i 10 -f test1 -d 0
	bin/mrowka -m 10 -n 10 -i 50 -f test1 -d 0
