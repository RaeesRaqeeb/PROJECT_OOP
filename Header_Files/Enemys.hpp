#pragma once
#include<raylib.h>
#include"Header_files/player.hpp"
#include"Header_files/Base_class.hpp"


//Enemy class 
class Enemy : public Base_class
{
public:
    PLAYER player_obj;
    bool enemy_Not_died[10];
    Image* Point_enemy;
    Rectangle Enemy_rectangle[10];

   
    
protected:
    Texture2D Enemy_texture_left[10];
    Texture2D Enemy_texture_right[10];
    Texture2D Current_Enemy_texure[10];
    Vector2 Enemy_position[10];
    unsigned int nextFrameDataOffset[10];
    int animFrames;
    int currentAnimFrame;
    int frameDelay;
    int frameCounter;
    bool IsLeft[10];
    bool IsRight[10];
    Image Enemy_Image_left[10];
    Image Enemy_Image_right[10];
    Image current;
};

//Bat Enemy Class
class BAT_ENEMY : public Enemy
{
public:
    BAT_ENEMY();
    ~BAT_ENEMY();
    void Draw()override;
    void Update()override;
    void MoveMents()override;
    void Reset()override;
};


//Skilton Class inherit from Enemy class using its attributes 
class SKILTON_ENEMY : public Enemy
{
public:


    SKILTON_ENEMY();
    ~SKILTON_ENEMY();
    void Draw() override;
    void Update()override;
    void MoveMents()override;
    void Reset()override;
};
