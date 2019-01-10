#include "stdafx.h"
#include "Game.h"


bool Game::OnUserCreate() {

	Init();
	return true;
}

bool Game::OnUserUpdate(float fElapsedTime) {

	switch (GameState) {

	case MENU:
		Menu();		
		return true;

	case PLAY:
		Play(fElapsedTime);
		return true;

	case EXIT:
		SaveMap();
		return false;

	}
}

