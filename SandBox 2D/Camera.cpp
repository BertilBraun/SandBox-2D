#include "stdafx.h"
#include "Game.h"

void Game::UpdateCamera(float fElapsedTime) {

	Camera.x = Player.x - ScreenWidth() / 2 - 1;

	if (Camera.x > Width) Camera.x -= Width;
	if (Camera.x < 1) Camera.x += Width;
}