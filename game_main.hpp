#pragma once
#include"player.hpp"
#include"enemy.hpp"

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
	unsigned frameIndex;
	unsigned numFrames;
	unsigned frameDelay;
	unsigned frameDelayCounter;
	PLAYER Player_obj;


private:
	
	ENEMY_Type1 Enemy_obj1;
	void MoveEnemy();
	void CheckForCollisions();
	void InitGame();
	void CheckForHighscore();
	void GameOver();
	void Reset();
	void checkForHighscore();
	void saveHighscoreToFile(int highscore);
	int loadHighscoreFromFile();
};