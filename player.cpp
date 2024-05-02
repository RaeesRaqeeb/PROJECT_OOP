#include "player.hpp"
#include<time.h>
#include<iostream>

PLAYER::PLAYER()
{
    //Camera
    
    //Player
    player_health = 3;
    jump_count_index_in_air = 0;
    jumpSpeed = 10.0f;
    IsplayerOnGround = true;
    frameIndex = 0;
    numFrames = 6;
    frameDelay = 80;
    frameDelayCounter = 0;
    playerMoving = false;
    picture = LoadTexture("scarfy.png");
    playerRect = { 0.0f, 0.0f, float(picture.width / 6), float(picture.height) };
    playerCollisionRect = { playerRect.x, playerRect.y, playerRect.width, playerRect.height };
    
    
    //Declaraing the Tiles positions

    //Bottom left starting tiles
    Tiles_Number[0] = { 10,1000,80,5 };
    Tiles_Number[1] = { 100,950,50,5 };
    Tiles_Number[2] = { 200,900,90,5 };
    Tiles_Number[3] = { 300,950,50,5 };
    Tiles_Number[4] = { 430,900,50,5 };
    //Changing Path from this tile
    Tiles_Number[5] = { 700,880,50,3 };

    //Path 1 
    Tiles_Number[7] = { 600,820,50,3 };
  
    //Path 2 
    Tiles_Number[6] = { 800,850,50,3 };
    Tiles_Number[8] = { 950,880,40,3 };

    //Small Left most tiles
    Tiles_Number[9] = { 70,200,20.0f,20.0f };
    Tiles_Number[10] = { 80,350,20.0f,20.0f };
    Tiles_Number[11] = { 100,450,20.0f,20.0f };

    //Middle tiles
    Tiles_Number[12] = { 500,350,40.0f,20.0f };
    Tiles_Number[13] = { 620,280,20.0f,20.0f };
    Tiles_Number[14] = { 700,300,20.0f,20.0f };
    Tiles_Number[15] = { 950,180,100.0f,10.0f };

    //Right most Tiles  
    Tiles_Number[16] = { 1200,300,50.0f,20.0f };
    Tiles_Number[17] = { 1400,200,50.0f,20.0f };
    Tiles_Number[18] = { 1500,400,20.0f,20.0f };
    Tiles_Number[19] = { 1400,350,20.0f,20.0f };
    


    //Fake Tiles
    Fake_tiles[0] = { 390,800,30,5 };
    Fake_tiles[1] = { 550,350,60.0f,20.0f };
    Fake_tiles[2] = { 1300,300,50.0f,20.0f };
    Fake_tiles[3] = { 1600,400,120.0f,20.0f };
 
    //Divider big tiles
    Big_Tiles_num[0] = { 0,(float)GetScreenHeight() / 2 + 100,(float)GetScreenWidth() / 3,100.0f };
    Big_Tiles_num[1] = { (float)GetScreenWidth()/ 3 +100,(float)GetScreenHeight() / 2,(float)GetScreenWidth() / 8,250.0f };
    Big_Tiles_num[2] = { (float)GetScreenWidth() / 3 + 450, 150 ,100.0f,700.0f };
    Big_Tiles_num[3] = { 200, 150 ,200.0f,400.0f };
    Big_Tiles_num[4] = { 550,0,200.0f,200.0f };
    Big_Tiles_num[5] = { 850,0,(float)GetScreenWidth() / 2,100.0f };

    //Enemy Tiles
    Enemy_tiles[0]= { 550,950,100,10 };
    Enemy_tiles[1] = { 800,250,150.0f,10.0f };
    Enemy_tiles[2] = { 1300,500,150.0f,20.0f };

    //world related 
    ground_level = GetScreenHeight() - playerRect.height;

    //Enemy
    enemy_picture = LoadTexture("enemy2.png");
    enemy_frames = 3;
    enemy_rect = { 0.0f, 100.0f,(float)enemy_picture.width / enemy_frames,(float)enemy_picture.height };

    enemy_frame_index = 0;
    direction = 1;
}
    PLAYER::~PLAYER()
    {
        UnloadTexture(picture);
        UnloadTexture(picture2);
        
    }

    void PLAYER::Player_Movement()
    {
        //when Collide with screen player should stop
        previousPosition.x = playerRect.x;
        previousPosition.y = playerRect.y;

        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_UP) || IsKeyDown(KEY_DOWN))
        {
            playerMoving = true;

            if (playerRect.x <= obstacleRect.x || playerRect.x >= (obstacleRect.x + obstacleRect.width))
            {
                IsplayerOnGround = false;
            }
            if (IsKeyDown(KEY_RIGHT))
            {
                if (playerRect.x < GetScreenWidth() - 85)
                    playerRect.x += playerSpeed;
                if (playerRect.width < 0)
                {
                    playerRect.width = -playerRect.width;
                }
                if (IsKeyReleased(KEY_SPACE))
                {
                    if (jump_count_index_in_air != 2)
                    {
                        if (playerRect.y >= 0)
                        {
                            jumpSpeed = 1.0f; // Set the initial jump velocity
                            IsplayerOnGround = false;
                        }
                        jump_count_index_in_air++;
                    }
                    else
                    {
                        IsplayerOnGround = true;

                    }
                }
            }
            if (IsKeyDown(KEY_LEFT))
            {
                if (playerRect.x >= 20)
                    playerRect.x -= playerSpeed;
                if (playerRect.width > 0)
                {
                    playerRect.width = -playerRect.width;
                }
                if (IsKeyReleased(KEY_SPACE))
                {
                    if (jump_count_index_in_air != 2)
                    {
                        if (playerRect.y >= 0)
                        {
                            jumpSpeed = 1.0f; // Set the initial jump velocity
                            IsplayerOnGround = false;
                        }
                        jump_count_index_in_air++;
                    }
                    else
                    {
                        IsplayerOnGround = true;

                    }
                }

            
            }

        }
        else {
            playerMoving = false;
        }

        if (IsKeyPressed(KEY_SPACE) && IsplayerOnGround) {

            if (playerRect.y >= 0)
            {
                jumpSpeed = 1.0f; // Set the initial jump velocity
                IsplayerOnGround = false;
            }
        }



        // Apply gravity
        if (!IsplayerOnGround)
        {
            // Update vertical position based on jump speed
            /*First it become jumpspeed is used to move the player upward then after the
            negative of jumpspeed will help the player to move downward apply the gravity effect*/
            playerRect.y -= jumpSpeed;
            // Decrease jump speed to simulate gravity
            jumpSpeed -= 0.01f;

            // Check if player has landed on the ground 
            if (playerRect.y >= ground_level || playerRect.y==700 || playerRect.y == 600 || playerRect.y == 400)
            {
                playerRect.y = ground_level;
                IsplayerOnGround = true;
                jump_count_index_in_air = 0;
                jumpSpeed = 1.0f; // Reset jump speed
                --player_health;
                //If player fall on the ground the player died and start again
                UnloadTexture(picture);
                if (player_health > 0)
                {
                    picture = LoadTexture("scarfy.png");
                    DrawTextureRec(picture, playerRect, { 0.0f,850.0f }, BLACK);
                    playerRect = { 0.0f, 850.0f, float(picture.width / 6) - 2, float(picture.height) };
                    playerCollisionRect = { playerRect.x, playerRect.y, playerRect.width, playerRect.height };
                }


            }
        }

        // Update player collision rectangle
        playerCollisionRect.x = playerRect.x;
        playerCollisionRect.y = playerRect.y;


    }

    bool PLAYER::Draw(bool IsPlayerMoving)
    {

        DrawTextureRec(enemy_picture, { float(enemy_frame_index * enemy_rect.width), 0, float(enemy_rect.width), float(enemy_picture.height) }, { enemy_rect.x,enemy_rect.y }, WHITE);
      //  DrawTextureV(enemy_picture, { 200.0f,200.0f }, BLACK);
        DrawTextureRec(picture2, { 580, 350,float(picture2.width),(float)picture2.height },{580.0f,350.0f}, WHITE);

        //Sections Divider left middle 1
        DrawRectangleRec(Big_Tiles_num[0], GRAY);

        //Big Tile 2
        DrawRectangleRec(Big_Tiles_num[1], GRAY);

        //Big Tile 3
        DrawRectangleRec(Big_Tiles_num[2], GRAY);

        //Big Tile 4
        DrawRectangleRec(Big_Tiles_num[3], GRAY);

        //Big Tile 5
        DrawRectangleRec(Big_Tiles_num[4], GRAY);

        //Big Tile 6
        DrawRectangleRec(Big_Tiles_num[5], GRAY);
        //Sections 
        //DrawRectangleRec({x,y,width,height},color);
        DrawRectangleRec(Tiles_Number[0], GREEN);
        DrawRectangleRec(Tiles_Number[1], GREEN);
        DrawRectangleRec(Tiles_Number[2], GREEN);
        DrawRectangleRec(Tiles_Number[3], GREEN);
        DrawRectangleRec(Tiles_Number[4], GREEN);

        //Left most tiles:
        DrawRectangleRec(Tiles_Number[9], GREEN);
        DrawRectangleRec(Tiles_Number[10], GREEN);
        DrawRectangleRec(Tiles_Number[11], GREEN);
        //Changing Path
        DrawRectangleRec(Tiles_Number[5], GREEN);

       // Path 2 Real one
        DrawRectangleRec(Tiles_Number[6], GREEN);
        DrawRectangleRec(Tiles_Number[8], GREEN);

        //Path 1 in this we have to jump using walls
        DrawRectangleRec(Tiles_Number[7], GREEN);
    
         //Middle tiles
        DrawRectangleRec(Tiles_Number[12], GREEN);
        DrawRectangleRec(Tiles_Number[13], GREEN);
        DrawRectangleRec(Tiles_Number[14], GREEN);
        DrawRectangleRec(Tiles_Number[15], GREEN);


        //Right most tiles
        DrawRectangleRec(Tiles_Number[16], GREEN);
        DrawRectangleRec(Tiles_Number[17], GREEN);
        DrawRectangleRec(Tiles_Number[18], GREEN);
        DrawRectangleRec(Tiles_Number[19], GREEN);
        

        //Tile where enemy is walking
        DrawRectangleRec(Enemy_tiles[0], RED);
        DrawRectangleRec(Enemy_tiles[1], RED);
        DrawRectangleRec(Enemy_tiles[2], RED);

        //fake tiles
        DrawRectangleRec(Fake_tiles[0], GREEN);
        DrawRectangleRec(Fake_tiles[1], GREEN);
        DrawRectangleRec(Fake_tiles[2], GREEN);
        DrawRectangleRec(Fake_tiles[3], GREEN);
     
      /*  DrawRectangleRec({ 880,300,50,5 }, GREEN);
        DrawRectangleRec({ 980,150,50,5 }, GREEN);
        DrawRectangleRec({ 0,5,800,5}, GREEN);*/
        
        
        //Draw player
        if (player_health > 0)
            DrawTextureRec(picture, { float(frameIndex * playerRect.width), 0, float(playerRect.width), float(picture.height) },
                { float(playerRect.x), float(playerRect.y) }, WHITE);

        else
        {
            DrawText("GAME OVER", 200, 200, 50, GREEN);
            return true;
        }
       
        return false;

    }
    

    void PLAYER::TILES_DRAW()
    {

    }
bool PLAYER::Player_collision_with_platform1s()
{
    return CheckCollisionRecs(playerCollisionRect, Tiles_Number[0]) ||
        CheckCollisionRecs(playerCollisionRect, Tiles_Number[1]) || CheckCollisionRecs(playerCollisionRect, Tiles_Number[2])
        || CheckCollisionRecs(playerCollisionRect, Tiles_Number[3]) || CheckCollisionRecs(playerCollisionRect, Tiles_Number[4])||
        CheckCollisionRecs(playerCollisionRect, Tiles_Number[5])||CheckCollisionRecs(playerCollisionRect,Tiles_Number[6])||CheckCollisionRecs(playerCollisionRect,Tiles_Number[7])
        || CheckCollisionRecs(playerCollisionRect, Tiles_Number[8])|| CheckCollisionRecs(playerCollisionRect, Tiles_Number[9])
        || CheckCollisionRecs(playerCollisionRect, Tiles_Number[10]) || CheckCollisionRecs(playerCollisionRect, Tiles_Number[11]) 
        || CheckCollisionRecs(playerCollisionRect, Tiles_Number[12]) || CheckCollisionRecs(playerCollisionRect, Tiles_Number[13])||
        CheckCollisionRecs(playerCollisionRect, Tiles_Number[14])|| CheckCollisionRecs(playerCollisionRect, Tiles_Number[15]) ||
        CheckCollisionRecs(playerCollisionRect, Tiles_Number[16])|| CheckCollisionRecs(playerCollisionRect, Tiles_Number[17]) || CheckCollisionRecs(playerCollisionRect, Tiles_Number[18])
       || CheckCollisionRecs(playerCollisionRect, Tiles_Number[19]) ||  CheckCollisionRecs(playerCollisionRect, Big_Tiles_num[0]) ||
        CheckCollisionRecs(playerCollisionRect, Big_Tiles_num[1])|| CheckCollisionRecs(playerCollisionRect, Big_Tiles_num[2])||
        CheckCollisionRecs(playerCollisionRect, Big_Tiles_num[3])|| CheckCollisionRecs(playerCollisionRect, Big_Tiles_num[4])|| CheckCollisionRecs(playerCollisionRect, Big_Tiles_num[5])
            || CheckCollisionRecs(playerCollisionRect, Enemy_tiles[0]) || CheckCollisionRecs(playerCollisionRect, Enemy_tiles[1]) || CheckCollisionRecs(playerCollisionRect, Enemy_tiles[2]);
  }
void PLAYER::Update()
{
 //Calculation for changing the frames
    ++frameDelayCounter;
    if (frameDelayCounter >= frameDelay)
        {
        frameDelayCounter = 0;
      //  ++enemy_frame_index;
          //  enemy_frame_index %= enemy_frames;
        if (playerMoving)
        {
            ++frameIndex;
            frameIndex %= numFrames;
           
        }
    }
   
   
}


void PLAYER::Enemy_movement()
{
    if (enemy_rect.x <= GetScreenWidth()-enemy_rect.width)
    {
        enemy_rect.x += 0.1f;
        if (enemy_rect.width > 0)
        {
            enemy_rect.width = -enemy_rect.width;
           }
    }
     else if(enemy_rect.x>=0)
    {
        if (enemy_rect.width < 0)
        {
            enemy_rect.width = -enemy_rect.width;
        }
        while (enemy_rect.x > 0.0f)
        {
            enemy_rect.x -= 1.0f;
        }
       
    }

}

Rectangle PLAYER::player_GetRect()
{
    return playerRect;
}


