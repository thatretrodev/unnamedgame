CC=gcc
CFLAGS=-lm -lstdc++ -Iraylib-4.0.0_linux_amd64/include -Lraylib-4.0.0_linux_amd64/lib -lraylib -Ideps/imgui -Ideps/rlImGui
all: bin/unnamedgame

prepare:
	@if [ ! -d bin ]; then\
		mkdir bin;\
	fi

bin/unnamedgame: prepare
	$(CC) deps/imgui/*.cpp deps/rlImGui/*.cpp src/*.cpp src/scenes/*.cpp src/gui/*.cpp $(CFLAGS) -o bin/unnamedgame

test:
	LD_LIBRARY_PATH=`pwd`/raylib-4.0.0_linux_amd64/lib:$LD_LIBRARY_PATH ./bin/unnamedgame