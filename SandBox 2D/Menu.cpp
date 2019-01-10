#include "stdafx.h"
#include "Game.h"

void Game::Menu() {

	//Draw Menu
	Fill(12, 9, ScreenWidth() - 12, ScreenHeight() - 9, PIXEL_SOLID, FG_BLACK);
	Fill(13, 10, ScreenWidth() - 13, ScreenHeight() - 10, PIXEL_SOLID, FG_DARK_GREY);

	DrawString(ScreenWidth() / 2 - 4, 15, L"NEW GAME", FG_CYAN);
	DrawString(ScreenWidth() / 2 - 5, 18, L"LOAD  SAVE", FG_CYAN);
	DrawString(ScreenWidth() / 2 - 2, 25, L"EXIT", FG_CYAN);

	//Input
	if ((int)m_mousePosX >= ScreenWidth() / 2 - 4 && (int)m_mousePosX <= ScreenWidth() / 2 + 3 && (int)m_mousePosY == 15 && m_mouse[0].bPressed) {
		Init();
		Sleep(100);
	}
	if ((int)m_mousePosX >= ScreenWidth() / 2 - 5 && (int)m_mousePosX <= ScreenWidth() / 2 + 5 && (int)m_mousePosY == 18 && m_mouse[0].bPressed) {
		Load();
		Sleep(100);
	}
	if ((int)m_mousePosX >= ScreenWidth() / 2 - 2 && (int)m_mousePosX <= ScreenWidth() / 2 + 2 && (int)m_mousePosY == 25 && m_mouse[0].bPressed)
		GameState = EXIT;

	//Return to Game
	if (m_keys[VK_ESCAPE].bPressed)
		GameState = PLAY;

}