CC=gcc
all: bin/unnamedgame

prepare:
	@if [ ! -d bin ]; then\
		mkdir bin;\
	fi

bin/unnamedgame: prepare
	$(CC) src/main.cpp -o bin/unnamedgame