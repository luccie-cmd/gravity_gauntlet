all:
	gcc -o build/main ./src/*.c -Iinclude -O3 -ggdb -Llib -lm -lSDL2