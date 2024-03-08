all:
# mkdir build
	gcc -o build/main ./src/*.c -Iinclude -O0 -ggdb -Llib -lm -lSDL2 -lSDL2main