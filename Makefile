all:
	gcc -pedantic -ggdb src/*.h src/*.c -o bin/mrowka

test_small: all
	bin/mrowka -m 10 -n 10 -i 10 -f test_small -d up
	bin/mrowka -m 10 -n 10 -i 50 -f test_small -d up

test_big: all
	bin/mrowka -m 50 -n 50 -i 100 -f test_big -d up
	bin/mrowka -m 50 -n 50 -i 200 -f test_big -d up
