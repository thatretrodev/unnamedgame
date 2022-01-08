#include "raylib.h"
#include "rlImGui.h"
#include "imgui.h"
#include "gamescene.hpp"

void GameScene::Init() {

}

void GameScene::Render() {
	ClearBackground(DARKGRAY);

	rlImGuiBegin();

	ImGui::Begin("Debug Menu");

	ImGui::Text("Hello, world %d", 123);

	ImGui::End();

	rlImGuiEnd();
	
	char* text = "Hello, World!";
	int textWidth = MeasureText(text, 20);

	DrawText(text, (GetScreenWidth() / 2) - (textWidth / 2), GetScreenHeight() / 2, 20, WHITE);
}