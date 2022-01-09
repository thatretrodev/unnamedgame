#include <string>
#include <map>
#include "scenes/gamescene.hpp"
#include "scenes/mainmenuscene.hpp"

class SceneManager {
	bool* gameRunning;
	int sceneType;
	GameScene gameScene;
	MainMenuScene mainMenuScene;

	public:
		SceneManager(bool* gameRunning);
		void SwitchScene(int SceneID);
		void DrawUnknownSceneScreen();
		void Render();
		void Unload();
};