#pragma once
#include"player.hpp"
#include<string>
#include<fstream>
#include<iostream>

using namespace std;

class GAME
{
public:
	GAME();
	~GAME();
	bool Draw();
	void Update();
	void HandleInput();
	bool IsPlayerMoving;
	int score;
	int highscore;
	int lives;
	bool playing;

	//Enemy
	Texture2D enemy_picture;
	Rectangle enemy_rect;
	int enemy_frames;
	int direction;
	int enemy_frame_index;



	//Coins
	//BASE_COIN* Ptr_coin;

	//Player
	unsigned frameIndex;
	unsigned numFrames;
	unsigned frameDelay;
	unsigned frameDelayCounter;
	PLAYER Player_obj;
	void CheckForCollisions();
	void Reset();
	string Formating_score(int, int);
	 void Check_high_score();

	

private:
	void InitGame();


};
