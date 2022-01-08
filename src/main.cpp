#include <stdio.h>
#include <SDL2/SDL.h>

int main() {
	int windowWidth = 640;
	int windowHeight = 480;
	bool isRunning = true;

	// TODO: Only initialize what's necessary
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("ERROR: Unable to initialize SDL2: %s\n", SDL_GetError());
	}

	SDL_Window* window = SDL_CreateWindow("Unnamed Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE);

	// Game loop

	while (isRunning) {
		SDL_Event event;

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_QUIT:
					isRunning = false;
					break;
				
				// TODO: Add code to handle an SDL_KEYDOWN event

				default:
					break;
			}
		}
	}

	printf("Game stopping!\n");

	return 0;
}