#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/gl.h>

int main() {
	int windowWidth = 640;
	int windowHeight = 480;
	bool isRunning = true;

	// TODO: Only initialize what's necessary
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("ERROR: Unable to initialize SDL2: %s\n", SDL_GetError());
	}

	SDL_Window* window = SDL_CreateWindow("Unnamed Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	
	// TODO: Figure out what this does
	SDL_GLContext GLContext = SDL_GL_CreateContext(window);

	// Game loop

	while (isRunning) {

		// Handle SDL events

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

			// OpenGL rendering

			glViewport(0, 0, windowWidth, windowHeight);

			glClearColor(1.0f, 0.f, 1.0f, 0.f);
			glClear(GL_COLOR_BUFFER_BIT);

			glBegin(GL_TRIANGLES);

			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex2f(0.f, 0.f);

			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex2f(0.5f, 0.5f);

			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex2f(1.0f, 0.f);

			glEnd();

			glFlush();

			SDL_GL_SwapWindow(window);
		}
	}

	printf("Game stopping!\n");

	return 0;
}