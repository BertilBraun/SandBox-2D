#include "stdafx.h"
#include "Game.h"


//Physik
void Game::UpdatePos(float fElapsedTime) {

	for (int i = 0; i < 10; i++) {

		if (Player.vx > 2.5f)
			Player.vx = 2.5f;
		if (Player.vx < -2.5f)
			Player.vx = -2.5f;
		if (Player.vy > 20)
			Player.vy = 20;

		//Apply "Gravity"
		if (!Player.Stable)
			if (Player.vy < 0)
				Player.vy += 11.0f * fElapsedTime;
			else
				Player.vy += 3.0f * fElapsedTime;

		CheckCollision(fElapsedTime);

		//Update Player Pos
		Player.x += Player.vx * fElapsedTime;
		Player.y += Player.vy * fElapsedTime;

		//Player Warp 
		if (Player.x > Width)
			Player.x -= Width;
		if (Player.x < 1)
			Player.x += Width;

		UpdateCamera(fElapsedTime);
	}
}

void Game::CheckCollision(float fElapsedTime) {

	int TestX = Player.x + Player.vx * fElapsedTime;
	int TestY = Player.y + Player.vy * fElapsedTime;

	if (TestX > Width) TestX -= Width;
	if (TestX < 0) TestX += Width;
	if (TestY < 0) Player.vy = 0;
	if (TestY > Height) Player.y = Height;

	if (Player.vy < 0 && map[TestY - 1][TestX].solid)
		Player.vy = 0;

	else if (!Player.Stable && map[TestY + 1][TestX].solid) {
		Player.y = TestY;
		Player.vy = 0;
		Player.Stable = true;
	}

	if (Player.Stable && !map[TestY + 1][TestX].solid)
		Player.Stable = false;

	if (map[TestY][TestX].solid) {
		if (!map[TestY - 1][TestX].solid && Player.vx != 0)
			Player.y--;
		else
			Player.vx = 0;
		//Player.x = TestX;
	}
}
