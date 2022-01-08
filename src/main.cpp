#include <stdio.h>
#include <GL/gl.h>
#include "renderer.hpp"

int main() {
	int windowWidth = 640;
	int windowHeight = 480;
	bool isRunning = true;

	// Initialize the Renderer

	Renderer::Init("Unnamed Game!", windowWidth, windowHeight);

	// Game loop

	while (isRunning) {

		Renderer::PreRender(&isRunning);

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

		Renderer::PostRender();
	}

	printf("Game stopping!\n");

	return 0;
}