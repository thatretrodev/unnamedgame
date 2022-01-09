#include "raylib.h"
#include "rlImGui.h"
#include "imgui.h"
#include "gamescene.hpp"

void GameScene::Init() {
	this->camera = { 0 };
	this->camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
	this->camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
	this->camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
	this->camera.fovy = 45.0f;
	this->camera.projection = CAMERA_PERSPECTIVE;
}

void GameScene::Render() {
	ClearBackground(WHITE);
	
	BeginMode3D(this->camera);

	DrawCube(this->cubePosition, 2.0f, 2.0f, 2.0f, RED);
	DrawCubeWires(this->cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

	DrawGrid(10, 1.0f);

	EndMode3D();
}