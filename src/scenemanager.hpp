#include <string>
#include <map>
#include "scenes/gamescene.hpp"

class SceneManager {
	int sceneType;
	GameScene gameScene;

	public:
		void SwitchScene(int SceneID);
		void Render();
};