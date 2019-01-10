#include "stdafx.h"
#include "Game.h"

void Game::UpdateLight() {

	for (int x = (int)Camera.x; x < ScreenWidth() + (int)Camera.x; x++) {
		
		if (x > Width)
			x -= Width;
		if (x < 0)
			x += Width;

		int topY = Height, lastY = topY;	

		for (int y = Height; y >= 0; y--) {
			if (map[y][x].Texture != 0) {
				topY = y;
				map[lastY][x].Lit = false;
			}
			lastY = topY;
		}


	}

	/*
	//for (int x = 0; x < Width; x++)
		for (float a = 0; a < 3.141 * 2; a += 3.141 * 0.01) {

			float StepSize = 0.1f;		  
			float DistanceToBlock = 0.0f;

			bool HitWall = false;		
			bool Boundary = false;		
			bool Next = false;

			float DX = sinf(a);
			float DY = cosf(a);

			while (!Next && DistanceToBlock < Sun.Energy) {

				DistanceToBlock += StepSize;
				int nTestX = (int)(Sun.x + DX * DistanceToBlock);
				int nTestY = (int)(Sun.y + DY * DistanceToBlock);

				// Test if ray is out of bounds
				if (nTestX < 0 || nTestX >= Width || nTestY < 0 || nTestY >= Height) 
					continue;

				else {
					if (map[nTestX][nTestY].Texture != 0)
						HitWall = true;

					if (HitWall && map[nTestX][nTestY].Texture != 0)
						map[nTestX][nTestY].Lit = false;
				}
				
			}
		}

		/*
		float m = y - 5 / x - (Player.x - (ScreenWidth() / 2 + 1));
		float step = 0.1f, d = 0;

		bool hit = false;

		while (!hit || d < sqrt(((y - 5) * (y - 5)) + ((x - (Player.x - (ScreenWidth() / 2 + 1))) * (x - (Player.x / (ScreenWidth() / 2 + 1)))))) {
			if (map[m*step + y][((m*step + y) - y) / step].solid) {
				map[y][x].lit = false;
				continue;
			}
			d += step;
		}
		*/
}

void Game::UpdateSunPos(float fElapsedTime) {

	Sun.x = (Time < 30) ? ((Time / 30) * ScreenWidth()) : (((Time - 30) / 20) * ScreenWidth());

}