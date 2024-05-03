#pragma once
#include <raylib-cpp.hpp>


class BASE_COIN
{
public:
	Texture2D Coin_Texture;
	Image Coin_image;
	unsigned int nextFrameDataOffset;
	int currentAnimFrame;
	int frameDelay;      
	int frameCounter;
	virtual void Draw() = 0;


};

