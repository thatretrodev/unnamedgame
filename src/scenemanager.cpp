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

void SceneManager::Render() {
	switch (this->sceneType) {
		case 0:
			ClearBackground(DARKBLUE);
			break;
		case 1:
			this->gameScene.Render();
			break;
		case 2:
			this->mainMenuScene.Render();
			break;
		
		default:
			ClearBackground(DARKBLUE);
			break;
	}
}

void SceneManager::Unload() {
	this->mainMenuScene.Unload();
}