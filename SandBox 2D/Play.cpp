#include "stdafx.h"
#include "Game.h"

void Game::Play(float fElapsedTime) {

	Time += 1 * fElapsedTime;

	InputPlayer(fElapsedTime);
	UpdatePos(fElapsedTime);
	UpdateSunPos(fElapsedTime);
	Interaction();
	DrawMap();
	if (m_keys[VK_ESCAPE].bPressed)
		GameState = MENU;

}