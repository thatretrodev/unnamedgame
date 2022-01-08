#include "model.hpp"

namespace Renderer {
	void Init(char* title, int windowWidth, int windowHeight);
	void PreRender(bool* isRunning);
	void RenderModel(Model model, float size);
	void PostRender();
	//void Unload();
}