#pragma once
#include"player.hpp"

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

	

private:
	
	void MoveEnemy();

	void InitGame();
	void CheckForHighscore();
	void GameOver();
	
	void checkForHighscore();
	void saveHighscoreToFile(int highscore);
	int loadHighscoreFromFile();
};
