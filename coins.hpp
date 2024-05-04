#pragma once
#include <raylib-cpp.hpp>




class SMALL_COIN 
{
public:
	SMALL_COIN();
	~SMALL_COIN();
	Texture2D Coin_Texture;
	Image Coin_image;
	Rectangle Coin_Rect[10];
	unsigned int nextFrameDataOffset;
	int animFrames;
	int currentAnimFrame;
	int frameDelay;
	int frameCounter;


	void Draw()  ;
	void Update() ;
	void Movement() ;
	

};
