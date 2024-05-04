#include <raylib-cpp.hpp>
#include <raylib.h>
#include"game_main.hpp"
#include<iostream>
//#include"enemy.hpp"



class Base_class
{
public:
};
class COIN
{
public:
    COIN();
    ~COIN();
    Texture2D Coin_Texture[50];
    Image Coin_image;
    Rectangle Coin_Rect[50];
    unsigned int nextFrameDataOffset;
    int animFrames;
    int currentAnimFrame;
    int frameDelay;
    int frameCounter;
    Vector2 coins_positions[50];
    void Draw();
    void Update();
    static int coin_counter;
};

int COIN::coin_counter = 0;
COIN::COIN()
{
    Coin_image = LoadImageAnim("coin.gif", &animFrames);
    for(int i=0;i<50;i++)
             Coin_Texture[i] = LoadTextureFromImage(Coin_image);

    coins_positions[0].x = 150;
    coins_positions[0].y = 880;

    coins_positions[1].x = 250;
    coins_positions[1].y = 790;

    coins_positions[2].x = 100;
    coins_positions[2].y = 100;

    coins_positions[3].x = 100;
    coins_positions[3].y = 800;

    coins_positions[4].x = 200;
    coins_positions[4].y = 900;
    nextFrameDataOffset = 0;
    currentAnimFrame = 0;
    frameDelay = 50;
    frameCounter = 0;
    for (int i = 0; i < 50; ++i)
    {
        Coin_Rect[i]={coins_positions[i].x,coins_positions[i].y,(float)Coin_image.width,(float)Coin_image.height };
    }

}

COIN::~COIN()
{
   
}

void COIN::Draw()
{
  for(int i=0;i<4;i++)
    DrawTextureV(Coin_Texture[i], coins_positions[i], GOLD);

}

void COIN::Update()
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
        for(int i=0;i<50;i++)
        UpdateTexture(Coin_Texture[i], ((unsigned char*)Coin_image.data) + nextFrameDataOffset);

        frameCounter = 0;
    }
}

int main() {
    const int screenWidth = GetScreenHeight();
    const int screenHeight = GetScreenWidth();
    
    /* const float playerSpeed = 0.5f;
     unsigned frameIndex = 0;
     unsigned numFrames = 6;
     unsigned frameDelay = 100;
     unsigned frameDelayCounter = 0;
     bool playerMoving = false;*/
    raylib::Window window(screenWidth, screenHeight, "WINDOW");

    // ENEMY_TYPE1 B1;
    
    // B1.Draw();
     // Player properties
     //Texture2D picture = LoadTexture("scarfy.png");
     //Rectangle playerRect(200.0f, 200.0f, float(picture.width / 6), float(picture.height));
     //Rectangle playerCollisionRect = { playerRect.x, playerRect.y, playerRect.width, playerRect.height };
     //Color playerColor = BLUE;

     //// Stationary object properties
     //Texture2D picture2 = LoadTexture("crate.png");
     //Rectangle obstacleRect(100.0f, 100.0f, float(picture2.width), float(picture2.height));

    COIN Coin_obj;

    GAME Game_obj;
    bool endprogram = false;
   
    
    while (!window.ShouldClose())
    {
        
        Game_obj.HandleInput();
       

        ClearBackground(BLACK);
        BeginDrawing();
    
        //   BeginMode2D(camera);
        Game_obj.Update();
        Game_obj.CheckForCollisions(Coin_obj.Coin_Rect);
        //if (CheckCollisionRecs(Game_obj.Player_obj.playerCollisionRect, Coin_obj.Coin_Rect[Coin_obj.currentAnimFrame]))
        //{
        //    for (int i = 0; i < 3; i++)
        //    {
        //       // if ((Game_obj.Player_obj.playerCollisionRect.x >= Coin_obj.coins_positions[i].x && Game_obj.Player_obj.playerCollisionRect.x <= Coin_obj.coins_positions[i].x+Coin_obj.Coin_Texture[i].width))
        //        if((Game_obj.Player_obj.playerCollisionRect.x>=Coin_obj.Coin_Rect[i].x )||( Game_obj.Player_obj.playerCollisionRect.y >= Coin_obj.Coin_Rect[i].y) &&
        //            (Game_obj.Player_obj.playerCollisionRect.x < Coin_obj.Coin_Rect[i].x +Coin_obj.Coin_Texture->width) || (Game_obj.Player_obj.playerCollisionRect.y < Coin_obj.Coin_Rect[i].y + Coin_obj.Coin_Rect->height))
        //        {
        //           std:: cout << "am i called\n";
        //            UnloadTexture(Coin_obj.Coin_Texture[i]);
        //            Coin_obj.Coin_Rect[i].x = 0;
        //            Coin_obj.Coin_Rect[i].y = 0;
        //            break;
        //           

        //        }
        //    }
        //    ++Coin_obj.coin_counter;
        //}
        if (CheckCollisionRecs(Game_obj.Player_obj.playerCollisionRect, Coin_obj.Coin_Rect[Coin_obj.currentAnimFrame]))
        {
            for (int i = 0; i < 50; i++)
            {
                if (CheckCollisionRecs(Game_obj.Player_obj.playerCollisionRect, Coin_obj.Coin_Rect[i]))
                {
                    // Collision detected with coin
                    std::cout << "Coin collected!\n";

                    // Unload texture and reset coin position
                    UnloadTexture(Coin_obj.Coin_Texture[i]);
                    
                    Coin_obj.Coin_Texture[i].height = 0;
                    Coin_obj.Coin_Texture[i].width = 0;
                  

                    // Increment coin counter
                    ++Coin_obj.coin_counter;
                    break;
                }
            }
        }
        Coin_obj.Update();
        // Player movements control Complete code
        
      /*
       Vector2 previousPosition;
        previousPosition.x = playerRect.x;
        previousPosition.y = playerRect.y;
      if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_UP) || IsKeyDown(KEY_DOWN)) {
            playerMoving = true;

            if (IsKeyDown(KEY_RIGHT)) {
                playerRect.x += playerSpeed;
                if (playerRect.width < 0)
                {
                    playerRect.width = -playerRect.width;
                }
            }
            if (IsKeyDown(KEY_LEFT)) {
                playerRect.x -= playerSpeed;
                if (playerRect.width > 0)
                {
                    playerRect.width = -playerRect.width;
                }
            }
            if (IsKeyDown(KEY_UP)) {
                playerRect.y -= playerSpeed;
            }
            if (IsKeyDown(key_down)) {
                playerRect.y += playerSpeed;
            }
        }
        else {
            playerMoving = false;
        }*/

        // Update player collision rectangle
      /*  playerCollisionRect.x = playerRect.x;
        playerCollisionRect.y = playerRect.y;*/

        // Check for player collision with stationary object
//bool collision = CheckCollisionRecs(playerCollisionRect, obstacleRect);



        endprogram = Game_obj.Draw();
        if (endprogram == true)
            break;
        Coin_obj.Draw();
        // Draw player
       // DrawTextureRec(picture, { float(frameIndex * playerRect.width), 0, float(playerRect.width), float(picture.height) },
           // { float(playerRect.x), float(playerRect.y) }, WHITE);

        // Draw obstacle texture
//DrawTexture(picture2, int(obstacleRect.x), int(obstacleRect.y), WHITE);

        // Show collision status

      /*  if (collision) {
            playerRect.x = previousPosition.x;
            playerRect.y = previousPosition.y;
        }
        else {
            DrawText("No Collision", 10, 10, 20, BLACK);
       } */

      
       // Update animation frame
     /*  ++frameDelayCounter;
       if (frameDelayCounter >= frameDelay) {
           frameDelayCounter = 0;
           if (playerMoving) {
               ++frameIndex;
               frameIndex %= numFrames;
           }
       }*/
       
        EndDrawing();

    }

    // Unload textures

    window.Close();


    return 0;
}