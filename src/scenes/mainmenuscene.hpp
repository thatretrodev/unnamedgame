class MainMenuScene {
	public:
		Texture2D buttonTexture;
		Font buttonFont;

		void Init();
		void DrawButton(bool enabled, char* name, int ButtonID);
		void Render();
		void Unload();
};