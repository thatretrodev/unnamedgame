class MainMenuScene {
	public:
		Texture2D buttonTexture;
		Font buttonFont;
		bool debugMenuOpen;
		bool* gameRunning;

		void Init(bool* gameRunning);
		void DrawButton(bool enabled, char* name, int ButtonID);
		void Render();
		void Unload();
};