CC=gcc
CFLAGS=`sdl2-config --libs --cflags`
all: bin/unnamedgame

prepare:
	@if [ ! -d bin ]; then\
		mkdir bin;\
	fi

bin/unnamedgame: prepare
	$(CC) src/main.cpp $(CFLAGS) -o bin/unnamedgame