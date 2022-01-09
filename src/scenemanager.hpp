#include <string>
#include <map>
#include "scenes/gamescene.hpp"
#include "scenes/mainmenuscene.hpp"

class SceneManager {
	int sceneType;
	GameScene gameScene;
	MainMenuScene mainMenuScene;

	public:
		void SwitchScene(int SceneID);
		void Render();
		void Unload();
};