#include <stdio.h>
#include "settingsscene.hpp"
#include "../gui/debugmenu.hpp"

void SettingsScene::Init(bool* gameRunning) {
	this->buttonTexture = LoadTexture("assets/button.png");
	this->debugMenuOpen = false;
	this->gameRunning = gameRunning;
	//this->buttonFont = LoadFontEx("assets/roboto/Roboto-Bold.ttf", 32, 0, 250);
}

void SettingsScene::Unload() {
	UnloadTexture(this->buttonTexture);
	//UnloadFont(this->buttonFont);
}

bool SettingsScene::DrawButton(bool enabled, char* name, int ButtonID) {
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
		return true;
	}

	return false;
}

int SettingsScene::Render() {
	if (IsKeyReleased(KEY_TAB)) {
		this->debugMenuOpen = !this->debugMenuOpen;
	}

	ClearBackground(LIGHTGRAY);

	bool backButtonPressed = this->DrawButton(true, "Back", 1);

	if (backButtonPressed) {
		return 1;
	}

	char* text = "Settings";
	int textWidth = MeasureText(text, 40);

	DrawText(text, (GetScreenWidth() / 2) - (textWidth / 2), (GetScreenHeight() / 2) - 100, 40, WHITE);
	
	if (this->debugMenuOpen) {
		DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), (Color){ 0, 0, 0, 128 });
		DebugMenu::Render();
	}
}