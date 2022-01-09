#include <stdio.h>
#include "raylib.h"
#include "mainmenuscene.hpp"
#include "../gui/debugmenu.hpp"

void MainMenuScene::Init(bool* gameRunning) {
	this->buttonTexture = LoadTexture("assets/button.png");
	this->debugMenuOpen = false;
	this->gameRunning = gameRunning;
	//this->buttonFont = LoadFontEx("assets/roboto/Roboto-Bold.ttf", 32, 0, 250);
}

void MainMenuScene::Unload() {
	UnloadTexture(this->buttonTexture);
	//UnloadFont(this->buttonFont);
}

void MainMenuScene::DrawButton(bool enabled, char* name, int ButtonID) {
	int textWidth = MeasureText(name, 20);
	//Vector2 textSize = MeasureTextEx(this->buttonFont, name, 30, 2);

	float buttonWidth = (GetScreenWidth() / 2) - (this->buttonTexture.width / 2);
	float buttonHeight = (GetScreenHeight() / 2) + (50 * ButtonID);

	Rectangle buttonAABB = {
		(GetScreenWidth() / 2) - (this->buttonTexture.width / 2),
		buttonHeight,
		this->buttonTexture.width,
		this->buttonTexture.height
	};

	//DrawRectangleRec(buttonAABB, BLUE);

	if (CheckCollisionPointRec(GetMousePosition(), buttonAABB) && !this->debugMenuOpen) {
		if (IsMouseButtonDown(0)) {
			DrawTexture(this->buttonTexture, (GetScreenWidth() / 2) - (this->buttonTexture.width / 2), (GetScreenHeight() / 2) + (50 * ButtonID), GRAY);
		}
		else {
			DrawTexture(this->buttonTexture, (GetScreenWidth() / 2) - (this->buttonTexture.width / 2), (GetScreenHeight() / 2) + (50 * ButtonID), LIGHTGRAY);
		}
	}
	else {
		DrawTexture(this->buttonTexture, (GetScreenWidth() / 2) - (this->buttonTexture.width / 2), (GetScreenHeight() / 2) + (50 * ButtonID), WHITE);
	}

	//DrawTextEx(this->buttonFont, name, (Vector2){ (GetScreenWidth() / 2) - (textSize.x / 2), (GetScreenHeight() / 2) + ((50 * ButtonID) + 5) }, 30.0f, 2, BLACK);
	DrawText(name, (GetScreenWidth() / 2) - (textWidth / 2), (GetScreenHeight() / 2) + (50 * ButtonID) + 10, 20, BLACK);

	if (CheckCollisionPointRec(GetMousePosition(), buttonAABB) && IsMouseButtonReleased(0) && !this->debugMenuOpen) {
		/*printf("IsMouseButtonDown(0): %s\n", IsMouseButtonDown(0) ? "true" : "false");
		printf("IsMouseButtonReleased(0): %s\n", IsMouseButtonReleased(0) ? "true" : "false");*/

		switch (ButtonID) {
			case 1:
				printf("Play button pressed!\n");
				break;
			
			case 2:
				printf("Settings button pressed!\n");
				break;

			case 3:
				printf("Quit button pressed!\n");
				*this->gameRunning = false;
				break;
			
			default:
				break;
		}
	}
}

void MainMenuScene::Render() {
	if (IsKeyReleased(KEY_TAB)) {
		this->debugMenuOpen = !this->debugMenuOpen;
	}

	ClearBackground(LIGHTGRAY);

	this->DrawButton(true, "Play", 1);
	this->DrawButton(false, "Settings", 2);
	this->DrawButton(true, "Quit", 3);

	char* text = "Unnamed Game";
	int textWidth = MeasureText(text, 50);

	DrawText(text, (GetScreenWidth() / 2) - (textWidth / 2), (GetScreenHeight() / 2) - 50, 50, WHITE);
	
	if (this->debugMenuOpen) {
		DebugMenu::Render();
	}
}