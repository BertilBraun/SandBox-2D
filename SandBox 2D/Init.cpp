#include "stdafx.h"
#include "Game.h"

void Game::Init() {

	GameState = PLAY;

	//InitPlayer
	Player.x = Width / 2;
	Player.y = 5;

	//InitCamera
	Camera.x = Player.x;
	Camera.y = Player.y;

	//Init Sun
	Sun.x = 20.0f;
	Sun.y = 5.0f;
	Sun.Energy = 200.0f;

	scale = 2;

	InitMap();
	//UpdateLight();
	DrawMap();

	Place = 1;
}
