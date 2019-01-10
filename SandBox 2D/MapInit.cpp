#include "stdafx.h"
#include "Game.h"

//Map
void Game::InitMap() {

	//srand(20000);

	struct Tree {
		int x;
		int y;
	};

	vector<Tree> Trees;

	float *fSurface = new float[Width];
	float *fNoiseSeed = new float[Width];

	int j = 0;

	// Populate with noise
	for (int i = 0; i < Width; i++)
		fNoiseSeed[i] = (float)rand() / (float)RAND_MAX;

	fNoiseSeed[0] = 0.5f;

	PerlinNoise(Width, fNoiseSeed, scale, 2.0f, fSurface);

	for (int x = 0; x < Width; x++) {
		j++;
		for (int y = 0; y < Height + 3; y++) {

			//map[y][x].solid = true;

			//Stone
			if (y >= fSurface[x] * Height + 4)
				map[y][x].Texture = 3;

			//Ore
			else if (y >= fSurface[x] * Height + 4 && (float)rand() / (float)RAND_MAX < 0.5f)
				map[y][x].Texture = 11;

			//Dirt
			else if (y >= fSurface[x] * Height + 1)
				map[y][x].Texture = 2;

			//Grass
			else if (y >= fSurface[x] * Height)
				map[y][x].Texture = 1;

			//Tree Pushback above surfave
			else if (y >= fSurface[x] * Height - 1 && (float)rand() / (float)RAND_MAX < 0.05f && j >= 3) {
				j = 0;
				Trees.push_back({ x, y });
			}

			//Sky
			else {
				map[y][x].Texture = 0;
				map[y][x].solid = false;
			}
		}
	}
	if (!Trees.empty())		
		for (auto &a : Trees) {
			if (rand() < 15000) {
				map[a.y - 0][a.x - 0].Texture = 4; map[a.y - 0][a.x - 0].solid = false;// map[a.y - 0][a.x - 0].Lit = false;
				map[a.y - 1][a.x - 0].Texture = 4; map[a.y - 1][a.x - 0].solid = false;// map[a.y - 1][a.x - 0].Lit = false;
				map[a.y - 2][a.x - 0].Texture = 4; map[a.y - 2][a.x - 0].solid = false;// map[a.y - 2][a.x - 0].Lit = false;
				map[a.y - 3][a.x - 0].Texture = 4; map[a.y - 3][a.x - 0].solid = false;// map[a.y - 3][a.x - 0].Lit = false;
				map[a.y - 4][a.x - 0].Texture = 13; map[a.y - 4][a.x - 0].solid = false;// map[a.y - 4][a.x - 0].Lit = false;
				map[a.y - 5][a.x - 0].Texture = 13; map[a.y - 5][a.x - 0].solid = false;// map[a.y - 5][a.x - 0].Lit = false;
				map[a.y - 4][a.x - 1].Texture = 13; map[a.y - 4][a.x - 1].solid = false;// map[a.y - 4][a.x - 1].Lit = false;
				map[a.y - 5][a.x - 1].Texture = 13; map[a.y - 5][a.x - 1].solid = false;// map[a.y - 5][a.x - 1].Lit = false;
				map[a.y - 4][a.x + 1].Texture = 13; map[a.y - 4][a.x + 1].solid = false;// map[a.y - 4][a.x + 1].Lit = false;
				map[a.y - 5][a.x + 1].Texture = 13; map[a.y - 5][a.x + 1].solid = false;// map[a.y - 5][a.x + 1].Lit = false;
				map[a.y - 4][a.x - 2].Texture = 13; map[a.y - 4][a.x - 2].solid = false;// map[a.y - 4][a.x - 2].Lit = false;
				map[a.y - 3][a.x - 2].Texture = 13; map[a.y - 3][a.x - 2].solid = false;// map[a.y - 3][a.x - 2].Lit = false;
				map[a.y - 4][a.x + 2].Texture = 13; map[a.y - 4][a.x + 2].solid = false;// map[a.y - 4][a.x + 2].Lit = false;
				map[a.y - 3][a.x + 2].Texture = 13; map[a.y - 3][a.x + 2].solid = false;// map[a.y - 3][a.x + 2].Lit = false;
				map[a.y - 3][a.x - 1].Texture = 13; map[a.y - 3][a.x - 1].solid = false;// map[a.y - 3][a.x - 1].Lit = false;
				map[a.y - 3][a.x + 1].Texture = 13; map[a.y - 3][a.x + 1].solid = false;// map[a.y - 3][a.x + 1].Lit = false;
			}
			else {
				map[a.y - 0][a.x - 0].Texture = 4; map[a.y - 0][a.x - 0].solid = false;
				map[a.y - 1][a.x - 2].Texture = 9; map[a.y - 1][a.x - 2].solid = false;
				map[a.y - 1][a.x - 1].Texture = 9; map[a.y - 1][a.x - 1].solid = false;
				map[a.y - 1][a.x - 0].Texture = 9; map[a.y - 1][a.x - 0].solid = false;
				map[a.y - 1][a.x + 1].Texture = 9; map[a.y - 1][a.x + 1].solid = false;
				map[a.y - 1][a.x + 2].Texture = 9; map[a.y - 1][a.x + 2].solid = false;
				map[a.y - 2][a.x - 1].Texture = 9; map[a.y - 2][a.x - 1].solid = false;
				map[a.y - 2][a.x - 0].Texture = 9; map[a.y - 2][a.x - 0].solid = false;
				map[a.y - 2][a.x + 1].Texture = 9; map[a.y - 2][a.x + 1].solid = false;
				map[a.y - 3][a.x - 1].Texture = 9; map[a.y - 3][a.x - 1].solid = false;
				map[a.y - 3][a.x - 0].Texture = 9; map[a.y - 3][a.x - 0].solid = false;
				map[a.y - 3][a.x + 1].Texture = 9; map[a.y - 3][a.x + 1].solid = false;
				map[a.y - 4][a.x - 0].Texture = 9; map[a.y - 4][a.x - 0].solid = false;
			}
		}
				
	delete[] fSurface;
	delete[] fNoiseSeed;
}
void Game::PerlinNoise(int nCount, float *fSeed, int nOctaves, float fBias, float *fOutput)
{
	// Used 1D Perlin Noise
	for (int x = 0; x < nCount; x++) {

		float fNoise = 0.0f;
		float fScaleAcc = 0.0f;
		float fScale = 1.0f;

		for (int o = 0; o < nOctaves; o++) {

			int nPitch = nCount >> o;
			int nSample1 = (x / nPitch) * nPitch;
			int nSample2 = (nSample1 + nPitch) % nCount;
			float fBlend = (float)(x - nSample1) / (float)nPitch;
			float fSample = (1.0f - fBlend) * fSeed[nSample1] + fBlend * fSeed[nSample2];
			fScaleAcc += fScale;
			fNoise += fSample * fScale;
			fScale = fScale / fBias;
		}

		// Scale to seed range
		fOutput[x] = fNoise / fScaleAcc;
	}
}