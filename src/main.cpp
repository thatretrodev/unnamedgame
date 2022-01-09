#include <stdio.h>
#include "raylib.h"
#include "rlImGui.h"
#include "imgui.h"
#include "scenemanager.hpp"

int main() {
	int sceneID = 2;
	SceneManager sceneManager;

	InitWindow(1280, 720, "Unnamed Game");

	sceneManager.SwitchScene(sceneID);

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
	sceneManager.Unload();
	CloseWindow();

	return 0;
}