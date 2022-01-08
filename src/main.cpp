#include <stdio.h>
#include "model.hpp"
#include "renderer.hpp"

int main() {
	int windowWidth = 640;
	int windowHeight = 480;
	bool isRunning = true;

	Model model("assets/test.obj");

	// Initialize the Renderer

	Renderer::Init("Unnamed Game", windowWidth, windowHeight);

	// Game loop

	while (isRunning) {

		Renderer::PreRender(&isRunning);

		Renderer::RenderModel(model, 0.2);

		Renderer::PostRender();
	}

	printf("Game stopping!\n");

	return 0;
}