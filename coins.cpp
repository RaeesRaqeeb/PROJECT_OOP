#include "Header_files/coins.hpp"


COIN::COIN()
{
    //Every coin status wheather it is collected or not
    for (int i = 0; i < 49; ++i)
    {
        coinCollected[i] = false;
    }
    
    //Loading coin Image
    Coin_image = LoadImageAnim("Pictures/coin.gif", &animFrames);

    //Loading image to texture for display
    for (int i = 0; i < 50; i++)
        Coin_Texture[i] = LoadTextureFromImage(Coin_image);

    //Initializing the position of coins
    coins_positions[0].x = 150;
    coins_positions[0].y = 880;

    coins_positions[1].x = 300;
    coins_positions[1].y = 800;

    coins_positions[2].x = 400;
    coins_positions[2].y = 890;

    coins_positions[3].x = 550;
    coins_positions[3].y = 800;

    //coins on the enemy plates
    coins_positions[4].x = 640;
    coins_positions[4].y = 890;

    coins_positions[5].x = 550;
    coins_positions[5].y = 920;

    //Coins after first enemy plate

    coins_positions[6].x = 600;
    coins_positions[6].y = 800;

    coins_positions[7].x = 900;
    coins_positions[7].y = 800;

    coins_positions[8].x = 1040;
    coins_positions[8].y = 800;

    coins_positions[9].x = 1000;
    coins_positions[9].y = 750;

    coins_positions[10].x = 1050;
    coins_positions[10].y = 650;

    coins_positions[11].x = 900;
    coins_positions[11].y = 500;

    coins_positions[12].x = 700;
    coins_positions[12].y = 500;

    coins_positions[13].x = 500;
    coins_positions[13].y = 600;

    coins_positions[14].x = 700;
    coins_positions[14].y = 700;

    coins_positions[15].x = 650;
    coins_positions[15].y = 650;

    coins_positions[16].x = 450;
    coins_positions[16].y = 580;

    coins_positions[17].x = 350;
    coins_positions[17].y = 580;

    coins_positions[18].x = 250;
    coins_positions[18].y = 580;

    coins_positions[19].x = 150;
    coins_positions[19].y = 580;

    coins_positions[20].x = 50;
    coins_positions[20].y = 400;

    coins_positions[21].x = 70;
    coins_positions[21].y = 300;

    coins_positions[22].x = 90;
    coins_positions[22].y = 200;

    coins_positions[23].x = 150;
    coins_positions[23].y = 100;

    coins_positions[24].x = 250;
    coins_positions[24].y = 120;

    coins_positions[25].x = 350;
    coins_positions[25].y = 120;

    coins_positions[26].x = 450;
    coins_positions[26].y = 180;

    coins_positions[27].x = 570;
    coins_positions[27].y = 300;

    coins_positions[28].x = 670;
    coins_positions[28].y = 250;

    coins_positions[29].x = 770;
    coins_positions[29].y = 150;

    coins_positions[30].x = 850;
    coins_positions[30].y = 220;

    coins_positions[31].x = 950;
    coins_positions[31].y = 120;

    coins_positions[32].x = 1050;
    coins_positions[32].y = 120;

    coins_positions[33].x = 1250;
    coins_positions[33].y = 220;

    coins_positions[34].x = 1450;
    coins_positions[34].y = 320;

    coins_positions[35].x = 1650;
    coins_positions[35].y = 350;

    coins_positions[36].x = 1750;
    coins_positions[36].y = 550;

    coins_positions[37].x = 1850;
    coins_positions[37].y = 550;

    coins_positions[38].x = 1950;
    coins_positions[38].y = 550;

    coins_positions[39].x = 1550;
    coins_positions[39].y = 550;

    coins_positions[40].x = 1650;
    coins_positions[40].y = 550;

    coins_positions[41].x = 1300;
    coins_positions[41].y = 480;

    coins_positions[42].x = 1400;
    coins_positions[42].y = 480;

    coins_positions[43].x = 1650;
    coins_positions[43].y = 880;

    coins_positions[44].x = 1750;
    coins_positions[44].y = 880;

    coins_positions[45].x = 1850;
    coins_positions[45].y = 880;

    coins_positions[46].x = 1550;
    coins_positions[46].y = 880;

    nextFrameDataOffset = 0;
    currentAnimFrame = 0;
    frameDelay = 50;
    frameCounter = 0;

    //Making rectangle for each coin
    for (int i = 0; i < 49; i++)
    {
        Coin_Rect[i] = { coins_positions[i].x,coins_positions[i].y,(float)Coin_image.width,(float)Coin_image.height };
    }

}

COIN::~COIN()
{
    //Unloading each taxture and image of coin to free the memory space
    for (int i = 0; i < 49; i++)
    {
        UnloadTexture(Coin_Texture[i]);

    }
    UnloadImage(Coin_image);

}

//Drawing coins
void COIN::Draw()
{
    //Coin will draw only if it is not collected
    for (int i = 0; i < 49; ++i)
    {
        // Draw only if the coin has not been collected
        if (!coinCollected[i]) {
            DrawTextureV(Coin_Texture[i], coins_positions[i], GOLD);
        }
    }

}

//Use to update the frames of coins to look like rotating coin
void COIN::Update()
{
    frameCounter++;
    if (frameCounter >= frameDelay)
    {
        // Move to next frame
        //If final frame is reached we return to first frame
        currentAnimFrame++;
        if (currentAnimFrame >= animFrames) currentAnimFrame = 0;


        nextFrameDataOffset = Coin_image.width * Coin_image.height * 4 * currentAnimFrame;



        for (int i = 0; i < 49; i++)
        {
            if (!coinCollected[i])
                UpdateTexture(Coin_Texture[i], ((unsigned char*)Coin_image.data) + nextFrameDataOffset);
        }
        frameCounter = 0;
    }

}




