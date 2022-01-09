#include <stdio.h>
#include "raylib.h"
#include "rlImGui.h"
#include "imgui.h"
#include "scenemanager.hpp"

int main() {
	bool gameRunning = true;

	SceneManager sceneManager(&gameRunning);

	InitWindow(1280, 720, "Unnamed Game");

	sceneManager.SwitchScene(1);

	SetWindowState(FLAG_WINDOW_RESIZABLE);
	SetWindowMinSize(800, 600);

	rlImGuiSetup(true);

	while (gameRunning) {
		gameRunning = !WindowShouldClose();

		BeginDrawing();

		sceneManager.Render();

		EndDrawing();
	}

	rlImGuiShutdown();
	sceneManager.Unload();
	CloseWindow();

	return 0;
}