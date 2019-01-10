#include "stdafx.h"
#include "Game.h"

bool Game::UpdateInv(int y, int x, bool hit) {
	
	if (hit) {
		bool sorted = false;

		sInv p { 1, map[y][x].Texture, 64 };

		if (map[y][x].Texture != 0) {
			for (auto &a : Inv)
				if (a.Texture == map[y][x].Texture)
					if (a.num < a.StackSize) {
						a.num++;
						sorted = true;
					}
					else if (a.num + 1 > a.StackSize) {
						Inv.push_back(p);
						sorted = true;
					}
			if (!sorted)
				Inv.push_back(p);
		}
					
	}
	else 
		if(!Inv.empty())
			for (auto &a : Inv) 
			if (a.Texture == Place) 
				if (a.num > 1) {
					a.num--;
					if (a.num == 0) {
						a = Inv.back();
						Inv.pop_back();
					}
					return true;
				}
}