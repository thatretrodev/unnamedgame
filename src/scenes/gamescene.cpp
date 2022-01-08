#include "raylib.h"
#include "gamescene.hpp"

void GameScene::Init() {

}

void GameScene::Render() {
	ClearBackground(DARKGRAY);
	
	char* text = "Hello, World!";
	int textWidth = MeasureText(text, 20);

	DrawText(text, (GetScreenWidth() / 2) - (textWidth / 2), GetScreenHeight() / 2, 20, WHITE);
}