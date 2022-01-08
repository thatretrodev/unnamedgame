#include <stdio.h>
#include <GL/gl.h>
#include "renderer.hpp"

int main() {
	int windowWidth = 640;
	int windowHeight = 480;
	bool isRunning = true;

	// Initialize the Renderer

	Renderer::Init("Unnamed Game", windowWidth, windowHeight);

	// Game loop

	while (isRunning) {

		Renderer::PreRender(&isRunning);

		Renderer::Render();

		Renderer::PostRender();
	}

	printf("Game stopping!\n");

	return 0;
}