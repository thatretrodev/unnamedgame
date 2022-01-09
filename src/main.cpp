#include <stdio.h>
#include "raylib.h"
#include "rlImGui.h"
#include "imgui.h"
#include "scenemanager.hpp"

int main() {
	bool gameRunning = true;
	int sceneID = 1;

	SceneManager sceneManager(&gameRunning);

	InitWindow(1280, 720, "Unnamed Game");

	sceneManager.SwitchScene(sceneID);

	SetWindowState(FLAG_WINDOW_RESIZABLE);
	SetWindowMinSize(800, 600);

	rlImGuiSetup(true);

	while (gameRunning) {
		gameRunning = !WindowShouldClose();

		if (IsKeyReleased(KEY_LEFT)) {
			sceneID--;
			sceneManager.SwitchScene(sceneID);
		}
		else if (IsKeyReleased(KEY_RIGHT)) {
			sceneID++;
			sceneManager.SwitchScene(sceneID);
		}

		BeginDrawing();

		sceneManager.Render();

		EndDrawing();
	}

	rlImGuiShutdown();
	sceneManager.Unload();
	CloseWindow();

	return 0;
}