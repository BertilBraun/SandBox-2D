#include "stdafx.h"
#include "Game.h"


void Game::DrawMap() {

	for (int x = 0; x < ScreenWidth(); x++)
		for (int y = 0; y < ScreenHeight(); y++)
			DrawBlock(x, y);

	//Draw Sun
	if(Time < 30)
		Draw((int)Sun.x, (int)Sun.y, PIXEL_SOLID, FG_YELLOW);
	else
		Draw((int)Sun.x, (int)Sun.y, PIXEL_THREEQUARTERS, FG_WHITE);
	//Draw Player
	Draw(ScreenWidth() / 2 + 1, (int)Player.y, PIXEL_SOLID, FG_RED);

	switch (Place) {
	case 1:
		Draw(2, 2, PIXEL_SOLID, FG_GREEN); break;
	case 2:
		Draw(2, 2, PIXEL_HALF, FG_GREY); break;
	case 3:
		Draw(2, 2, PIXEL_SOLID, FG_DARK_GREY); break;
	case 4:
		Draw(2, 2, PIXEL_THREEQUARTERS, FG_WHITE); break;
	case 5:
		Draw(2, 2, PIXEL_SOLID, FG_YELLOW); break;
	case 6:
		Draw(2, 2, PIXEL_SOLID, FG_RED); break;
	case 7:
		Draw(2, 2, PIXEL_SOLID, FG_MAGENTA); break;
	case 8:
		Draw(2, 2, PIXEL_SOLID, FG_DARK_BLUE); break;
	default:
		Draw(2, 2, PIXEL_SOLID, FG_CYAN);
	}
	if (Solid)
		Draw(4, 2, PIXEL_SOLID, FG_RED);
	else
		Draw(4, 2, PIXEL_SOLID, FG_WHITE);

	if (x3)
		Draw(2, 4, PIXEL_SOLID, FG_RED);
	else
		Draw(2, 4, PIXEL_SOLID, FG_WHITE);
}

void Game::DrawBlock(int x, int y) {

	unsigned short ToDraw;
	SelectToDraw(ToDraw, x, y);

	switch (ToDraw) {
	case 0://sky
		Draw(x, y, PIXEL_SOLID, FG_BLUE); break;
	case 1://grass
		Draw(x, y, PIXEL_SOLID, FG_GREEN); break;
	case 2://dirt
		Draw(x, y, PIXEL_HALF, FG_GREY); break;
	case 3://stone
		Draw(x, y, PIXEL_SOLID, FG_DARK_GREY); break;
	case 4://Wood
		Draw(x, y, PIXEL_THREEQUARTERS, FG_WHITE); break;
	case 5:
		Draw(x, y, PIXEL_SOLID, FG_YELLOW); break;
	case 6:
		Draw(x, y, PIXEL_SOLID, FG_RED); break;
	case 7:
		Draw(x, y, PIXEL_SOLID, FG_MAGENTA); break;
	case 8://dSky
		Draw(x, y, PIXEL_SOLID, FG_DARK_BLUE); break;
	case 9://dgrass
		Draw(x, y, PIXEL_THREEQUARTERS, FG_DARK_GREEN); break;
	case 10://ddirt
		Draw(x, y, PIXEL_HALF, FG_DARK_GREY); break;
	case 11://dstone
		Draw(x, y, PIXEL_HALF, FG_BLACK); break;
	case 12://dWood
		Draw(x, y, PIXEL_HALF, FG_WHITE); break;
	case 13://Leave
		Draw(x, y, PIXEL_QUARTER, BG_GREEN); break;
	default://noTexture
		Draw(x, y, PIXEL_SOLID, FG_CYAN); break;
	}
}

void Game::SelectToDraw(unsigned short &ToDraw, int x, int y) {

	int xDraw = x + Camera.x;

	if (xDraw > Width) xDraw -= Width;
	if (xDraw < 1) xDraw += Width;

	if (map[y][xDraw].Texture < 5) {
		if (Time > 30)
			ToDraw = map[y][xDraw].Texture + 8;
		else if (!map[y][xDraw].Lit) {
			ToDraw = map[y][xDraw].Texture + 8;
		}
		else if (map[y][xDraw].Lit)
			ToDraw = map[y][xDraw].Texture;
	}
	else
		ToDraw = map[y][xDraw].Texture;

	if (Time > 50)
		Time = 0;

}