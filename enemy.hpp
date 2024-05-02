#pragma once
#include<raylib-cpp.hpp>

//
class ENEMY
{
public:
    ENEMY();
//    virtual ~ENEMY(); 
    virtual void Draw() = 0;
    virtual void Update() = 0; 
    virtual void Enemy_movement() = 0; 
    Rectangle Enemy_GetRect();

    //Attributes
    Texture2D enemy_picture;
    Rectangle enemy_rect;
    int enemy_frames;
    int direction;
    int enemy_frame_index;

private:
    
    Texture2D Enemy_Image;
    Vector2 Enemy_image_position;



//    unsigned frameIndex;
//    unsigned numFrames;
//    unsigned frameDelay;
//    unsigned frameDelayCounter;
//
//protected:
//    float velocity;
//    Vector2 enemy_position;
//    int health;
//    Texture2D enemy_picture;
//    Rectangle enemy_rect;
//};
//
//
//class ENEMY_TYPE1 : public ENEMY
//{
//public:
//	ENEMY_TYPE1();
//	~ENEMY_TYPE1();
//
//    void Draw() override;
//    void Update() override;
//    void Enemy_movement(const Rectangle& platform1);
//
//
};

class ENEMY_Type1 :public ENEMY
{
public:
    void Draw() override {
        // Implement Draw() for ENEMY_Type1
    }

    void Update() override {
        // Implement Update() for ENEMY_Type1
    }

    void Enemy_movement() override;


};