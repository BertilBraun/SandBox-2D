#include "stdafx.h"
#include "Game.h"
#include <fstream>
#include <stdlib.h>
#include <string>

void Game::SaveMap() {

	remove("SaveMap.txt");

	ofstream fof;
	fof.open("SaveMap.txt");
	if (fof.fail()) { GameState = EXIT; return; }

	fof << Width << "\n" << Player.x << "\n" << Player.y << "\n" << Sun.x << "\n" << Sun.y << "\n";

	for (int x = 0; x < Width; x++)
		for (int y = 0; y < Height; y++) 
			fof << map[y][x].Texture << "\n" << map[y][x].solid << "\n" << map[y][x].Lit << "\n";
		
	fof.close();
}

void Game::Load() {

	ifstream fin;
	fin.open("SaveMap.txt");
	if (fin.fail()) { GameState = EXIT; return; }

	fin.seekg(0L, ios::beg);

	string MAP, px, py, sx, sy;

	getline(fin, MAP);
	getline(fin, px);
	getline(fin, py);
	getline(fin, sx);
	getline(fin, sy);

	Player.x = stof(px.c_str());//strtof((px).c_str(), 0);
	Player.y = stof(py.c_str());
	Sun.x = stof(sx.c_str());
	Sun.y = stof(sy.c_str());

	for (int x = 0; x < Width; x++)
		for(int y = 0; y < Height; y++) {
			string tex, s, l;
			
			getline(fin, tex);
			getline(fin, s);
			getline(fin, l);

			map[y][x].Texture = stoi(tex.c_str());
			map[y][x].solid = stoi(s.c_str());
			map[y][x].Lit = stoi(l.c_str());
		}
	fin.close();
}	