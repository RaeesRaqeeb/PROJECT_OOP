#include <raylib-cpp.hpp>
#include <raylib.h>
#include"game_main.hpp"

//#include"enemy.hpp"

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
    //COins creations
    int animFrames = 0;
    
    Image Coin_image= LoadImageAnim("coin.gif",&animFrames);
    Coin_image.height = 20;
    Coin_image.width = 20;
    Texture2D Coin_image_Texture = LoadTextureFromImage(Coin_image);
    unsigned int nextFrameDataOffset = 0;  // Current byte offset to next frame in image.data

    int currentAnimFrame = 0;       // Current animation frame to load and draw
    int frameDelay = 50;             // Frame delay to switch between animation frames
    int frameCounter = 0;

    // B1.Draw();
     // Player properties
     //Texture2D picture = LoadTexture("scarfy.png");
     //Rectangle playerRect(200.0f, 200.0f, float(picture.width / 6), float(picture.height));
     //Rectangle playerCollisionRect = { playerRect.x, playerRect.y, playerRect.width, playerRect.height };
     //Color playerColor = BLUE;

     //// Stationary object properties
     //Texture2D picture2 = LoadTexture("crate.png");
     //Rectangle obstacleRect(100.0f, 100.0f, float(picture2.width), float(picture2.height));

    GAME Game_obj;
    bool endprogram = false;
   

    while (!window.ShouldClose())
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
            UpdateTexture(Coin_image_Texture, ((unsigned char*)Coin_image.data) + nextFrameDataOffset);

            frameCounter = 0;
        }

        
        Game_obj.HandleInput();


        ClearBackground(BLACK);
        BeginDrawing();
        DrawTexture(Coin_image_Texture, 80, 940, WHITE);
        //   BeginMode2D(camera);
        Game_obj.Update();
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

     //   DrawTextureV(Coin_image, { 400.0f,400.0f }, BLACK);

        endprogram = Game_obj.Draw();
        if (endprogram == true)
            break;

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