#include "raylib.h"
#include "scenemanager.hpp"

void SceneManager::SwitchScene(int SceneID) {
	this->sceneType = SceneID;
}

void SceneManager::Render() {
	switch (this->sceneType) {
		case 0:
			ClearBackground(DARKBLUE);
			break;
		case 1:
			this->gameScene.Render();
			break;
		
		default:
			ClearBackground(DARKBLUE);
			break;
	}
}