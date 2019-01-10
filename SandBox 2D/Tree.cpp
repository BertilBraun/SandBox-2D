#include "stdafx.h"
#include "Game.h"

void Game::UpdateTree() {

	for(int x = 0; x < Width; x++)
		for (int y = 0; y < Height; y++) 
			if (map[y][x].Texture == 9 ||map[y][x].Texture == 13) {
				bool LeaveStabel = false;
				for (int i = -2; i <= 2; i++)
					for (int j = -4; j <= 4; j++)
						if (map[y + j][x + i].Texture == 8 || map[y + j][x + i].Texture == 4)
							LeaveStabel = true;
				if (!LeaveStabel)
					map[y][x].Texture = 0;
			}
}


