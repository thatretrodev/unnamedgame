#include "raylib.h"
#include "scenemanager.hpp"

SceneManager::SceneManager(bool* gameRunning) {
	this->gameRunning = gameRunning;
}

void SceneManager::SwitchScene(int SceneID) {
	this->sceneType = SceneID;

	switch (this->sceneType) {
		case 1:
			this->gameScene.Init();
			break;
		case 2:
			this->mainMenuScene.Init(this->gameRunning);
			break;
		
		default:
			break;
	}
}

void SceneManager::DrawUnknownSceneScreen() {
	ClearBackground(DARKBLUE);
	char* text = "Somehow, you have reached a scene that does not exist.\nWas it even worth your time?";
	int textWidth = MeasureText(text, 20);

	DrawText(text, (GetScreenWidth() / 2) - (textWidth / 2), GetScreenHeight() / 2, 20, WHITE);
}

void SceneManager::Render() {
	switch (this->sceneType) {
		case 0:
			this->DrawUnknownSceneScreen();
			break;
		case 1:
			this->gameScene.Render();
			break;
		case 2:
			this->mainMenuScene.Render();
			break;
		
		default:
			this->DrawUnknownSceneScreen();
			break;
	}
}

void SceneManager::Unload() {
	this->mainMenuScene.Unload();
}