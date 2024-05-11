#pragma once
#include<raylib.h>
#include<raylib-cpp.hpp>
#include"Header_files/Base_class.hpp"

//Player class 
class PLAYER
{
public:
    PLAYER();
    ~PLAYER();
 

    //Memebr variables or attributes for player
    
    Rectangle playerRect;
    Rectangle playerCollisionRect;
    //lives 
    Texture2D lives[3];
    Vector2 positions[3];


    //World related variable
  

    // Public member functions
    void Player_Movement();
    bool Draw();
    bool Player_collision_with_platform1s();
    void Reset() ;
    void Update() ;




    Vector2 previousPosition;
   
 
    bool firstFrame = true;
   
    Texture2D picture;
    int player_health;
    //Functions Making for managing 
    Rectangle player_GetRect();


    int GetHealth() const { return player_health; }


private:
    // Private attributes
    
    bool IsplayerOnGround;
    unsigned frameIndex;
    unsigned numFrames;
    unsigned frameDelay;
    unsigned frameDelayCounter;
    bool playerMoving;
    const float playerSpeed = 0.4f;
    float jumpSpeed;
    int jump_count_index_in_air;
    bool IsPlayer_moving;

    //Tiles
    float ground_level;
    Rectangle Tiles_Number[22];
    Rectangle Fake_tiles[10];
    Rectangle Big_Tiles_num[10];
    Rectangle Enemy_tiles[5];
    // Private helper functions
    bool IsAlive() const { return player_health > 0; }

    //sound
    Sound Player_walking[50];
    Sound Player_falling;

    int  running_sound;
};

