all:
	gcc -pedantic -ggdb src/*.h src/*.c -o bin/mrowka

test: all

