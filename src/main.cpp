#include <stdio.h>
#include "raylib.h"

int main() {
	InitWindow(640, 480, "Unnamed Game");

	SetWindowState(FLAG_WINDOW_RESIZABLE);
	SetWindowMinSize(640, 480);

	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(DARKGRAY);

		char* text = "Hello, World!";
		int textWidth = MeasureText(text, 20);

		DrawText(text, (GetScreenWidth() / 2) - (textWidth / 2), GetScreenHeight() / 2, 20, LIGHTGRAY);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}