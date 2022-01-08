CC=gcc
CFLAGS=`sdl2-config --libs --cflags` -lGL -Iinclude
RENDERER=sdl2_gl
all: bin/unnamedgame

prepare:
	@if [ ! -d bin ]; then\
		mkdir bin;\
	fi

bin/unnamedgame: prepare
	$(CC) $(RENDERER)/renderer.cpp src/main.cpp $(CFLAGS) -o bin/unnamedgame