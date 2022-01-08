#include <stdio.h>
#include "raylib.h"
#include "scenemanager.hpp"

int main() {
	SceneManager sceneManager;
	
	sceneManager.SwitchScene(1);

	InitWindow(640, 480, "Unnamed Game");

	SetWindowState(FLAG_WINDOW_RESIZABLE);
	SetWindowMinSize(640, 480);

	while (!WindowShouldClose()) {
		BeginDrawing();

		sceneManager.Render();

		EndDrawing();
	}

	CloseWindow();

	return 0;
}