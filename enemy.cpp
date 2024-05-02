#include "enemy.hpp"

//#include "enemy.hpp"
//#include"player.hpp"
//ENEMY::ENEMY()
//{
//    // Constructor implementation if needed
//
//}
//
//ENEMY::~ENEMY()
//{
//    // Destructor implementation if needed
//}
//
//ENEMY_TYPE1::ENEMY_TYPE1()
//{
//    frameIndex = 0;
//    numFrames = 4;
//    frameDelay = 150;
//    frameDelayCounter = 0;
//    enemy_picture = LoadTexture("enemy1.png");
//    enemy_rect = { 250 * 3.0f,50 * 3.0f,(float)enemy_picture.width / numFrames,(float)enemy_picture.height };
//
//}
//
//ENEMY_TYPE1::~ENEMY_TYPE1()
//{
//
//}
//
//void ENEMY_TYPE1::Draw()
//{
//    DrawTextureRec(enemy_picture, enemy_rect, { (float)frameIndex*enemy_picture.width/numFrames,(float)enemy_picture.height},BLACK);
//}
//
//void ENEMY_TYPE1::Update()
//{
//    ++frameDelayCounter;
//    
//    if (frameDelayCounter >= frameDelay)
//    {
//        frameDelayCounter = 0;
//        frameIndex++;
//        frameIndex %= numFrames;
//    }
//
//}
//
////void ENEMY_TYPE1::Enemy_movement(const vector<Rectangle> platform1)
////{
////    while ((enemy_rect.x <= (platform1.x + platform1.width)))
////    {
////
////    }
////
////}
//
//
//
//

void ENEMY_Type1::Enemy_movement()
{
    
        if (enemy_rect.x <= GetScreenWidth() - enemy_rect.width)
        {
            enemy_rect.x += 0.1f;
            if (enemy_rect.width > 0)
            {
                enemy_rect.width = -enemy_rect.width;
            }
        }
        else if (enemy_rect.x >= 0)
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

ENEMY::ENEMY()
{

}
