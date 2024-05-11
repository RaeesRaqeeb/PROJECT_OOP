#include "Header_files/player.hpp"
#include<time.h>
#include<iostream>

//Player class Constructor
PLAYER::PLAYER()
{
    //SOunds
    Player_walking[0] = LoadSound("Sounds/player_walking.mp3");
    Player_falling = LoadSound("Sounds/player_fall_down.mp3");
   

    running_sound = 0;
    for (int i = 0; i < 50; i++)
    {
        Player_walking[i] = LoadSoundAlias(Player_walking[0]);
    }
    //lives
    for(int i=0;i<3;i++)
      lives[i] = LoadTexture("Pictures/lives.png");
    
    //Setting the position of player lives on the screen
    positions[0].x = 1030.0f;
    positions[0].y = GetScreenHeight()-100.0f;
    positions[1].x = 1080.0f;
    positions[1].y = GetScreenHeight() - 100.0f;
    positions[2].x = 1130.0f;
    positions[2].y = GetScreenHeight() - 100.0f;


   
    //Player Attributes
    IsPlayer_moving = false;
    player_health = 3;
    jump_count_index_in_air = 0;
    jumpSpeed = 10.0f;
    IsplayerOnGround = true;
    frameIndex = 0;
    numFrames = 6;
    frameDelay = 50;
    frameDelayCounter = 0;
    playerMoving = false;
    picture = LoadTexture("Pictures/scarfy.png");
    playerRect = { 0, 950, float(picture.width / 6), float(picture.height) };
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
    Tiles_Number[20] = { 1300,700,320.0f,20.0f };
    
    //LAST tiles
    Tiles_Number[21] = { 1600,900,520.0f,20.0f };


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
    Enemy_tiles[3] = { 1600,600,220.0f,20.0f };

    //world related 
    ground_level = GetScreenHeight() - playerRect.height;

   
}

    PLAYER::~PLAYER()
    {
        UnloadTexture(picture);
        UnloadSound(Player_falling);
            for(int i=0;i<51;i++)
        UnloadSound(Player_walking[i]);
       }

    //Function for Player Movement control
    void PLAYER::Player_Movement()
    {
        //when Collide with screen player should stop
        previousPosition.x = playerRect.x;
        previousPosition.y = playerRect.y;

        //If any of the two button is pressed the it means player is moving
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_DOWN))
        {
            playerMoving = true;
            IsplayerOnGround = false;
            
            if (IsKeyDown(KEY_RIGHT))
            {
                //To insure player don't go out of screen
                if (playerRect.x < GetScreenWidth() - 85)
                    playerRect.x += playerSpeed;

                //Foot sound
                if(IsKeyPressed(KEY_RIGHT))
                    PlaySound(Player_walking[running_sound]);
                running_sound++;
                if (running_sound >= 50)
                    running_sound = 0;

                //For changing the direction of player frames
                if (playerRect.width < 0)
                {
                    playerRect.width = -playerRect.width;
                }

                //For Jump when pressed space
                if (IsKeyReleased(KEY_SPACE))
                {
                    if (jump_count_index_in_air != 2)
                    {
                        if (playerRect.y >= 0)
                        {
                            // Set the initial jump velocity
                            jumpSpeed = 1.0f; 
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
            //Same as the Right movement
            if (IsKeyDown(KEY_LEFT))
            {
                if (playerRect.x >= 20)
                    playerRect.x -= playerSpeed;
                //Sound system
                if (IsKeyPressed(KEY_LEFT))
                    PlaySound(Player_walking[running_sound]);
                running_sound++;
                if (running_sound >= 50)
                    running_sound = 0;
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
        else
        {
            playerMoving = false;
        }
      
        if (IsKeyPressed(KEY_SPACE) && IsplayerOnGround) {

            if (playerRect.y >= 0)
            {
                jumpSpeed = 1.0f;
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
        
                //If player fall on the ground the player died and start again
                Reset();
                PlaySound(Player_falling);


            }
        }

        // Update player collision rectangle
        playerCollisionRect.x = playerRect.x;
        playerCollisionRect.y = playerRect.y;


    }

    bool PLAYER::Draw()
    {
        //Live icon
        if (player_health != 0)
        {
            for(int i=0;i<player_health; i++)
            DrawTextureV(lives[i],positions[i], WHITE);

        }
       

 
  

        //Sections Divider left middle 1
        //BIg Tiles 0 to 5
        for (int i = 0; i < 6; i++)
        {
            DrawRectangleRec(Big_Tiles_num[i], GRAY);
        }
        
        //Tiles Detail
        //Starting tiles from 0 to 4
        //Top left most tiles 9 to 11
        // Middle chaning path from tile 5
        //Middle tiles 12 to 15
        //Right most tiles 16 to 21 
        for (int i = 0; i < 22; i++)
        {
            DrawRectangleRec(Tiles_Number[i], GREEN);
        }

        //Tile where enemy is walking
        for(int i=0;i<4;i++)
        DrawRectangleRec(Enemy_tiles[i], RED);
 

        //fake tiles
        for(int i=0;i<4;i++)
        DrawRectangleRec(Fake_tiles[0], GREEN);
      
     
  
        
        //Draw player
        if (GetHealth())
            DrawTextureRec(picture, { float(frameIndex * playerRect.width), 0, float(playerRect.width), float(picture.height) },
                { float(playerRect.x), float(playerRect.y) }, WHITE);

        else
        {
            DrawText("GAME OVER", GetScreenWidth()/2 -500, GetScreenHeight()/2, 150, RED);
         
            return true;
        }
       
        return false;

    }
    

    bool PLAYER::Player_collision_with_platform1s()
    {

        //We can use loop here also check this letter
        for (int i = 0; i < 22; i++)
        {
            if (CheckCollisionRecs(playerCollisionRect, Tiles_Number[i]))
            {
                playerRect.y = previousPosition.y;
                playerRect.x = previousPosition.x;
                IsplayerOnGround = true;

                jumpSpeed = 0.0f;
                // Reset jump speed if collided
                jump_count_index_in_air = 0;
                return true;

            }
        }
        for (int i = 0; i < 6; i++)
        {
            if (CheckCollisionRecs(playerCollisionRect, Big_Tiles_num[i]))
            {
                playerRect.y = previousPosition.y;
                playerRect.x = previousPosition.x;
                IsplayerOnGround = true;

                jumpSpeed = 0.0f;
                // Reset jump speed if collided
                jump_count_index_in_air = 0;
                return true;
            }
        }

        for (int i = 0; i < 4; i++)

        {
            if (CheckCollisionRecs(playerCollisionRect, Enemy_tiles[i]))
            {
                playerRect.y = previousPosition.y;
                playerRect.x = previousPosition.x;
                IsplayerOnGround = true;

                jumpSpeed = 0.0f;
                // Reset jump speed if collided
                jump_count_index_in_air = 0;
                return true;
            }
        }

            return false;

        }
    
//This function reset the player to its initial position
void PLAYER::Reset()
{
   
    UnloadTexture(picture);
    if (IsAlive())
    {
        --player_health;
        picture = LoadTexture("Pictures/scarfy.png");
        DrawTextureRec(picture, playerRect, { 0.0f,900.0f }, BLACK);
        playerRect = { 0.0f, 850.0f, float(picture.width / 6) - 2, float(picture.height) };
        playerCollisionRect = { playerRect.x, playerRect.y, playerRect.width, playerRect.height };
    }
}

//Use to update player frames as it moves
void PLAYER::Update()
{
 
    ++frameDelayCounter;
    if (frameDelayCounter >= frameDelay)
        {
        frameDelayCounter = 0;
    
        if (playerMoving)
        {
            ++frameIndex;
            frameIndex %= numFrames;
           
        }
    }
   
   
}

//This function is used to get the player rectangle
Rectangle PLAYER::player_GetRect()
{
    return playerRect;
}
