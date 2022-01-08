#include <stdio.h>
#include "raylib.h"
#include "rlImGui.h"
#include "imgui.h"
#include "scenemanager.hpp"

int main() {
	int sceneID = 1;
	SceneManager sceneManager;

	sceneManager.SwitchScene(sceneID);

	InitWindow(640, 480, "Unnamed Game");

	SetWindowState(FLAG_WINDOW_RESIZABLE);
	SetWindowMinSize(640, 480);

	rlImGuiSetup(true);

	while (!WindowShouldClose()) {
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
	CloseWindow();

	return 0;
}