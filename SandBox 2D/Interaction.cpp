#include "stdafx.h"
#include "Game.h"

void Game::Interaction() {
	
	if (InteractionAccured) {
		InteractionAccured = false;
		UpdateTree();
		//UpdateLight();
	}
}