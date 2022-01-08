#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "renderer.hpp"

SDL_Window* window;
SDL_GLContext GLContext;
int windowWidth;
int windowHeight;

void Renderer::Init(char* title, int _windowWidth, int _windowHeight) {
	windowWidth = _windowWidth;
	windowHeight = _windowHeight;

	// TODO: Only initialize what's necessary
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("ERROR: Unable to initialize SDL2: %s\n", SDL_GetError());
	}

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	
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

			case SDL_WINDOWEVENT:
				if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
					printf("Resizing to %dx%d\n", event.window.data1, event.window.data2);
					windowWidth = event.window.data1;
					windowHeight = event.window.data2;
				}
				break;
			
				// TODO: Add code to handle an SDL_KEYDOWN event
			
			default:
					break;
		}
	}
}

void Renderer::Render() {
	glViewport(0, 0, windowWidth, windowHeight);

	glClearColor(0.2f, 0.2f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(0.5f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(-0.5f, -0.5f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(-0.5f, 0.5f);

	glEnd();

	glFlush();
}

void Renderer::PostRender() {
	SDL_GL_SwapWindow(window);
}