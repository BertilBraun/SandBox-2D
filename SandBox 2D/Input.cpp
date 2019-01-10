#include "stdafx.h"
#include "Game.h"


//Input
void Game::InputPlayer(float fElapsedTime) {
	KBInput(fElapsedTime);
	MouseInput();
	SelectBlock();
}

void Game::KBInput(float fElapsedTime) {

	if (m_keys[L'N'].bPressed) 
		Solid = !Solid;
	
	if (m_keys[L'M'].bPressed) {
		Player.y = 2;
		scale = (scale + 1 > 8) ? 1 : scale + 1;
		InitMap();
		Place = 1;
	}

	if (m_keys[L'A'].bPressed)
		Player.vx = -0.5f;
	if (m_keys[L'D'].bPressed)
		Player.vx = 0.5f;

	if (m_keys[L'A'].bHeld)
		if (!Player.Stable)
			Player.vx -= 0.5f * fElapsedTime;
		else
			Player.vx -= 1.0f * fElapsedTime;

	if (m_keys[L'D'].bHeld)
		if (!Player.Stable)
			Player.vx += 0.5f * fElapsedTime;
		else
			Player.vx += 1.0f * fElapsedTime;

	if (m_keys[L'D'].bReleased || m_keys[L'A'].bReleased)
		resetVel = true;

	if (resetVel && Player.Stable) {
		Player.vx = 0;
		resetVel = false;
	}

	if (Player.Stable && m_keys[VK_SPACE].bPressed) {
		Player.vy = -12.0f;
		Player.Stable = false;
	}
}

void Game::SelectBlock() {

	if (m_keys[VK_RIGHT].bPressed && Place + 1 < 8)
		Place++;

	if (m_keys[VK_LEFT].bPressed && Place - 1 > 0 )
		Place--;

	if (m_keys[L'P'].bPressed)
		Place = 1;
}

void Game::MouseInput() {

	if (m_keys[L'B'].bPressed)
		x3 = !x3;

	int x = m_mousePosX + Camera.x;

	if (x > Width) x -= Width;
	if (x < 0) x += Width;

	if (10 > sqrt(((m_mousePosY - Player.y) * (m_mousePosY - Player.y)) + ((x - Player.x) * (x - Player.x)))) {
		if (m_mouse[0].bPressed || m_mouse[0].bHeld)
			//if (UpdateInv(m_mousePosY, x, false)) 
		
			if(x3)
				for (int p = -1; p < 2; p++) 
					for(int q = -1; q < 2; q++){
						map[m_mousePosY + q][x + p].Texture = Place;
						map[m_mousePosY + q][x + p].solid = Solid;
						InteractionAccured = true;
					}
			else {
				map[m_mousePosY][x].Texture = Place;
				map[m_mousePosY][x].solid = Solid;
				InteractionAccured = true;
			}
		

		if (m_mouse[1].bPressed || m_mouse[1].bHeld) 
			//UpdateInv(m_mousePosY, x, true);
			if (x3)
				for (int p = -1; p < 2; p++)
					for (int q = -1; q < 2; q++) {
						map[m_mousePosY + q][x + p].Texture = 0;
						map[m_mousePosY + q][x + p].solid = false;
						InteractionAccured = true;
					}
			else {
				map[m_mousePosY][x].Texture = 0;
				map[m_mousePosY][x].solid = false;
				InteractionAccured = true;
			}
		
	}
}
	


