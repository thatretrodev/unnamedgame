#include "rlImGui.h"
#include "imgui.h"
#include "debugmenu.hpp"

void DebugMenu::Render() {
	rlImGuiBegin();

	ImGui::Begin("Debug Menu");

	ImGui::Text("Hello, world %d", 123);

	ImGui::End();

	rlImGuiEnd();
}