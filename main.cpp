#include <raylib-cpp.hpp>
#include <raylib.h>
#include"game_main.hpp"
#include<iostream>
//#include"enemy.hpp"

int num = 0;

class Base_class
{
public:
   // virtual void Draw() = 0;
    //virtual void Update() = 0;

};
class COIN:virtual public Base_class
{

    //In this try to use the attributes from the base class in the end
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
    bool coinCollected[50];
    GAME Game_obj;


};

int COIN::coin_counter = 0;
COIN::COIN()
{
    
    for (int i = 0; i < 49; ++i)
    {
        coinCollected[i] = false;
    }
    Coin_image = LoadImageAnim("coin.gif", &animFrames);
    for(int i=0;i<50;i++)
             Coin_Texture[i] = LoadTextureFromImage(Coin_image);

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

    for (int i = 0; i < 49;i++)
    {
        Coin_Rect[i]={coins_positions[i].x,coins_positions[i].y,(float)Coin_image.width,(float)Coin_image.height };
    }

}

COIN::~COIN()
{
   
}

void COIN::Draw()
{
    for (int i = 0; i < 49; ++i) 
    {
        // Draw only if the coin has not been collected
        if (!coinCollected[i]) {
            DrawTextureV(Coin_Texture[i], coins_positions[i], GOLD);
        }
    }

}

void COIN::Update()
{
    frameCounter++;
    if (frameCounter >= frameDelay )
    {
        // Move to next frame
        //If final frame is reached we return to first frame
        currentAnimFrame++;
        if (currentAnimFrame >= animFrames) currentAnimFrame = 0;

       
        nextFrameDataOffset = Coin_image.width * Coin_image.height * 4 * currentAnimFrame;

     
     
        for (int i = 0; i < 49; i++) 
        {
            if(!coinCollected[i])
                UpdateTexture(Coin_Texture[i], ((unsigned char*)Coin_image.data) + nextFrameDataOffset);
        }
        frameCounter = 0;
    }

}


class Enemy :public Base_class
{
public:
     void Draw();
     void Update();
     void Collision();
     void MoveMent();
     PLAYER player_obj;
    
//protected:
    Image Enemy_Image_left;
    Image Enemy_Image_right;
    Image current;
    Image* Point_enemy;
    Rectangle Enemy_rectangle[10];
    Texture2D Enemy_texture_left[10];
    Texture2D Enemy_texture_right[10];
    Texture2D Current_Enemy_texure;
    Vector2 Enemy_position[10];
    unsigned int nextFrameDataOffset;
    int animFrames;
    int currentAnimFrame;
    int frameDelay;
    int frameCounter;
    bool IsLeft;
    bool IsRight;

};

class SKILTON_ENEMY :  public Enemy
{
public:
 
    SKILTON_ENEMY();
    ~SKILTON_ENEMY();
    void Draw();
    void Update();
    void Collision();
    void MoveMents();
};


SKILTON_ENEMY::SKILTON_ENEMY()
{
    IsLeft = true;
    IsRight = false;
    //Position of Skilton 
    Point_enemy = &Enemy_Image_right;
    Enemy_position[0].x = 580;
    Enemy_position[0].y = 545;

   //s int previous_position = 500;
   
    Enemy_rectangle[0].width = (float)Enemy_texture_left[0].width;
    Enemy_rectangle[0].height =(float) Enemy_texture_left[0].height;

    animFrames = 0;
    currentAnimFrame = 0;
    frameDelay = 100;
    frameCounter = 0;
    Enemy_Image_right = LoadImageAnim("skilton_right.gif",&animFrames);
    Enemy_Image_left = LoadImageAnim("skilton_left.gif",&animFrames);

    for (int i = 0; i < 10; i++)
    {
        Enemy_texture_left[i] = LoadTexture("skilton_left.gif");
        Enemy_texture_right[i] = LoadTexture("skilton_right.gif");

    }
    Current_Enemy_texure = Enemy_texture_left[0];
    for (int i = 0; i < 10; i++)

        Enemy_rectangle[i] = { Enemy_position[i].x,Enemy_position[i].y,(float)Enemy_Image_right.width,(float)Enemy_Image_right.height };

}

SKILTON_ENEMY::~SKILTON_ENEMY()
{
}

void SKILTON_ENEMY::Draw()
{
    for(int i=0;i<10;i++)
        DrawTextureV(Current_Enemy_texure, Enemy_position[i], WHITE);
   
}


void SKILTON_ENEMY::Update()
{
    frameCounter++;
    if (frameCounter >= frameDelay)
    {
        // Move to next frame
        //If final frame is reached we return to first frame
        currentAnimFrame++;
        if (currentAnimFrame >= animFrames) currentAnimFrame = 0;

        nextFrameDataOffset = Enemy_Image_right.width * Enemy_Image_right.height * 4 * currentAnimFrame;

        // Update texture based on direction of movement
        if (IsLeft)
            UpdateTexture(Current_Enemy_texure, ((unsigned char*)Enemy_Image_left.data) + nextFrameDataOffset);
        else if (IsRight)
            UpdateTexture(Current_Enemy_texure, ((unsigned char*)Enemy_Image_right.data) + nextFrameDataOffset);

        frameCounter = 0;
    }
   
  
    
   // Collision();
}

void SKILTON_ENEMY::Collision()
{
   
}


void SKILTON_ENEMY::MoveMents()
{

    
    if (Enemy_position[0].x != 10 && IsLeft )
    {
        Enemy_position[0].x -= 0.1f;
        
            Current_Enemy_texure = Enemy_texture_left[0];
       
    }

    if (Enemy_position[0].x <= 580 && IsRight)
    {
      
        Enemy_position[0].x += 0.1f;
        Current_Enemy_texure = Enemy_texture_right[0];
    }

    if (Enemy_position[0].x >= 580)
    {
        IsLeft = true;
        IsRight = false;
    }
    if (Enemy_position[0].x <= 10)
    {
        IsRight = true;
        IsLeft = false;
    }

    Enemy_rectangle[0].x = Enemy_position[0].x;
    Enemy_rectangle[0].y = Enemy_position[0].y;
}


//For Dragon 

class DRAGON_ENEMY : public Enemy
{
public:
    DRAGON_ENEMY();
    ~DRAGON_ENEMY();
    void Draw();
    void Update();
    void Collision();
    void MoveMent();
};

DRAGON_ENEMY::DRAGON_ENEMY()
{
    //Position of Dragons 

    Enemy_position[0].x = 500;
    Enemy_position[0].y = 500;

    animFrames = 0;
    currentAnimFrame = 0;
    frameDelay = 100;
    frameCounter = 0;
    Enemy_Image_right = LoadImageAnim("dragon.gif", &animFrames);


    for (int i = 0; i < 10; i++)
      //  Enemy_texture[i] = LoadTextureFromImage(Enemy_Image_right);

    for (int i = 0; i < 10; i++)
        Enemy_rectangle[i] = { Enemy_position[i].x,Enemy_position[i].y,(float)Enemy_Image_right.width,(float)Enemy_Image_right.height };

}

DRAGON_ENEMY::~DRAGON_ENEMY()
{
}

void DRAGON_ENEMY::Draw()
{
    for (int i = 0; i < 10; i++)
    {
      //  DrawTextureV(Enemy_texture[i], Enemy_position[i], WHITE);
    }

}

void DRAGON_ENEMY::Update()
{
    frameCounter++;
    if (frameCounter >= frameDelay)
    {
        // Move to next frame
        //If final frame is reached we return to first frame
        currentAnimFrame++;
        if (currentAnimFrame >= animFrames) currentAnimFrame = 0;


        nextFrameDataOffset = Enemy_Image_right.width * Enemy_Image_right.height * 4 * currentAnimFrame;



        for (int i = 0; i < 10; i++)
        {

         //   UpdateTexture(Enemy_texture[i], ((unsigned char*)Enemy_Image_right.data) + nextFrameDataOffset);
        }
        frameCounter = 0;
    }
}


int main() {
    const int screenWidth = GetScreenHeight();
    const int screenHeight = GetScreenWidth();
    
 
    raylib::Window window(screenWidth, screenHeight, "WINDOW");

 

    COIN Coin_obj;

    GAME Game_obj;

    SKILTON_ENEMY Skilton_1;
    bool endprogram = false;
   
    
    while (!window.ShouldClose())
    {
        
        Game_obj.HandleInput();


        ClearBackground(BLACK);
        BeginDrawing();
    
 
        Game_obj.Update();
        Game_obj.CheckForCollisions(Coin_obj.Coin_Rect);
        Coin_obj.Update();
        Skilton_1.Update();
        Skilton_1.Draw();
        Skilton_1.MoveMents();
   
       
            for (int i = 0; i < 49; i++)
            {
                if (CheckCollisionRecs(Game_obj.Player_obj.playerCollisionRect, Coin_obj.Coin_Rect[i])) 
                {
                    // Collision detected with coin
                    std::cout <<++num<< " :Coin collected!\n";

                   //In the following lines in the loop, we are removing the frames and also the rectangle so when player stay their after collecting coin then the loop shouldn't run 
                    Coin_obj.Coin_Texture[i].height = 0;
                    Coin_obj.Coin_Texture[i].width = 0;
                    Coin_obj.Coin_Rect[i].height = 0;
                    Coin_obj.Coin_Rect[i].width = 0;
                    Coin_obj.Coin_Rect[i].y =0;
                    Coin_obj.Coin_Rect[i].x = 0;
                    break;
            
                   
                }
            }
            if (CheckCollisionRecs(Game_obj.Player_obj.playerCollisionRect, Skilton_1.Enemy_rectangle[0]))
            {
                Game_obj.Player_obj.playerRect.y = Game_obj.Player_obj.previousPosition.y;
                Game_obj.Player_obj.playerRect.x = Game_obj.Player_obj.previousPosition.x;
            }
      
        
        endprogram = Game_obj.Draw();
        if (endprogram == true)
            break;
        Coin_obj.Draw();
       
        EndDrawing();

    }

    // Unload textures

    window.Close();

    for (int i = 0; i < 50; i++)
    {
        UnloadTexture(Coin_obj.Coin_Texture[i]);
    }


    return 0;
}


