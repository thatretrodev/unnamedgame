#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "renderer.hpp"

SDL_Window* window;
SDL_GLContext GLContext;

void Renderer::Init(char* title, int windowWidth, int windowHeight) {
	// TODO: Only initialize what's necessary
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("ERROR: Unable to initialize SDL2: %s\n", SDL_GetError());
	}

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	
	// TODO: Figure out what this does
	GLContext = SDL_GL_CreateContext(window);
}

void Renderer::PreRender(bool* isRunning) {
	SDL_Event event;
	
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				*isRunning = false;
				break;
			
				// TODO: Add code to handle an SDL_KEYDOWN event
			
			default:
					break;
		}
	}
}

void Renderer::PostRender() {
	SDL_GL_SwapWindow(window);
}