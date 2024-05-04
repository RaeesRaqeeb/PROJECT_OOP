#include "coins.hpp"



SMALL_COIN::SMALL_COIN()
{
	Coin_image = LoadImageAnim("coin.gif", &animFrames);
	Coin_Texture = LoadTextureFromImage(Coin_image);
	Coin_Rect[0] = {100, 940 ,(float)Coin_image.width,(float)Coin_image.height};
	unsigned int nextFrameDataOffset = 0;  
	int currentAnimFrame = 0;       
	int frameDelay = 50;             
	int frameCounter = 0;
}
SMALL_COIN::~SMALL_COIN()
{
	UnloadImage(Coin_image);
	UnloadTexture(Coin_Texture);
}
void SMALL_COIN::Draw()
{
	ImageDrawRectangleRec(&Coin_image, Coin_Rect[0], BLACK);
	DrawTexture(Coin_Texture, 300, 400, BLACK);
}
void SMALL_COIN::Update()
{
	frameCounter++;
	if (frameCounter >= frameDelay)
	{
		// Move to next frame
		// NOTE: If final frame is reached we return to first frame
		currentAnimFrame++;
		if (currentAnimFrame >= animFrames) currentAnimFrame = 0;

		// Get memory offset position for next frame data in image.data
		nextFrameDataOffset = Coin_image.width * Coin_image.height * 4 * currentAnimFrame;

		// Update GPU texture data with next frame image data
		// WARNING: Data size (frame size) and pixel format must match already created texture
		UpdateTexture(Coin_Texture, ((unsigned char*)Coin_image.data) + nextFrameDataOffset);

		frameCounter = 0;
	}

}

void SMALL_COIN::Movement()
{

}
