#pragma once
#include "olcConsoleGameEngine.h"

class Game : public olcConsoleGameEngine {
public:

	enum State { MENU, PLAY, EXIT } GameState;

	struct Object {
		float x;
		float y;
		float vx = 0.0f;
		float vy = 0.0f;
		bool Stable = false;
	}Player, Camera;

	struct Light {
		float x;
		float y;
		float Energy;
	} Sun;

	struct Block {
		bool Lit = true;
		bool solid;
		unsigned short Texture;
	};

	struct sInv {
		unsigned short num;
		unsigned short Texture;
		unsigned short StackSize;
	};

	static const int Width = 160;
	static const int Height = 60;

	Block map[Height][Width];
	vector<sInv> Inv;

	bool resetVel = false;
	bool InteractionAccured = true;
	bool Solid = true;
	bool x3 = false;

	unsigned short Place;
	unsigned short scale;
	float Time = 0;

	//Init
	Game() { m_sAppName = L"SandBox 2D"; }

	//GameLoop
	virtual bool OnUserCreate();
	virtual bool OnUserUpdate(float fElapsedTime);

	void Menu();
	void Play(float fElapsedTime);

	//Init Player & Map 
	void Init();

	//Physik
	void UpdatePos(float fElapsedTime);
	void CheckCollision(float fElapsedTime);

	//Input
	void InputPlayer(float fElapsedTime);
	void KBInput(float fElapsedTime);
	void MouseInput();
	void SelectBlock();

	//Map
	void InitMap();
	void PerlinNoise(int nCount, float *fSeed, int nOctaves, float fBias, float *fOutput);
	void DrawMap();
	void DrawBlock(int x, int y);
	void SelectToDraw(unsigned short &ToDraw, int x, int y);

	//Camera
	void UpdateCamera(float fElapsedTime);
	
	//Sun
	void UpdateLight();
	void UpdateSunPos(float fElapsedTime);

	//Tree
	void UpdateTree();

	//Interaction
	void Interaction();

	//Inventory
	bool UpdateInv(int y, int x, bool hit);

	//Save
	void SaveMap();
	void Load();

};

