#include "raylib.h"

class SettingsScene {
	public:
		Texture2D buttonTexture;
		Font buttonFont;
		bool debugMenuOpen;
		bool* gameRunning;

		void Init(bool* gameRunning);
		bool DrawButton(bool enabled, char* name, int ButtonID);
		int Render();
		void Unload();
};