#include <string>
#include <map>
#include "scenes/gamescene.hpp"
#include "scenes/mainmenuscene.hpp"
#include "scenes/settingsscene.hpp"

class SceneManager {
	bool* gameRunning;
	int sceneType;
	GameScene gameScene;
	MainMenuScene mainMenuScene;
	SettingsScene settingsScene;

	public:
		SceneManager(bool* gameRunning);
		void SwitchScene(int SceneID);
		void DrawUnknownSceneScreen();
		void Render();
		void Unload();
};