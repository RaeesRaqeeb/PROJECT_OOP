#pragma once
#include <raylib-cpp.hpp>
#include"Header_files/Base_class.hpp"
#include"Header_files/game_main.hpp"

class COIN
{
private:
    unsigned int nextFrameDataOffset;
    int animFrames;
    int currentAnimFrame;
    int frameDelay;
    int frameCounter;
    Image Coin_image;

    Vector2 coins_positions[50];
    static int coin_counter;
    bool coinCollected[50];

public:
    COIN();
    ~COIN();

    //Following are the attributes of coin
    Texture2D Coin_Texture[50];

    Rectangle Coin_Rect[50];

    //TO draw the coin
    void Draw();

    //TO update the frame of coin
    void Update();
};
