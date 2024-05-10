#include <raylib-cpp.hpp>
#include <raylib.h>
#include"Header_files/game_main.hpp"
#include<iostream>
#include<string>
#include<raygui.h>
//#include"enemy.hpp"





using namespace std;

static string Formating_score(int Score, int width)
{
    string Num_text = to_string(Score);
    int leading_zeros = (int)width - (int)Num_text.length();

    //in this we are concatenating the string also used string class constructor to repeatly add the 0 to string 
    return Num_text = string(leading_zeros, '0') + Num_text;
}
static int High_score_load_from_File()
{
    int loaded_high_score = 0;
    ifstream file("High_score.txt");

    if (file.is_open())
    {
        file >> loaded_high_score;
        file.close();
    }
    else
    {
        cout << "Error in loading from the file" << endl;
    }

    return loaded_high_score;
}
static void HighScore_Save_to_File(int highScore)
{
    ofstream file("High_score.txt");

    if (file.is_open())
    {
        file << highScore;
        file.close();
    }
    else
    {
        cout << "Faild to save score" << endl;
    }
}
static int Score = 0;
static int High_score = High_score_load_from_File();
static void Check_for_high_score()
{
    if (Score > High_score)
    {
        High_score = Score;
        HighScore_Save_to_File(High_score);
    }
}

int num = 0;



class Base_class
{
public:
   // virtual void Draw() = 0;
    //virtual void Update() = 0;

};
class COIN: public Base_class
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
    Coin_image = LoadImageAnim("Pictures/coin.gif", &animFrames);
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
    for (int i = 0; i < 49; i++)
    {
        UnloadTexture(Coin_Texture[i]);
     
    }
    UnloadImage(Coin_image);
   
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



//Enemy class
class Enemy :public Base_class
{
public:
     void Draw();
     void Update();
     void Collision();
     void MoveMent();
     bool reset();
     PLAYER player_obj;
    
//protected:
    Image Enemy_Image_left[10];
    Image Enemy_Image_right[10];
    Image current;
    Image* Point_enemy;
    Rectangle Enemy_rectangle[10];
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
    bool enemy_Not_died[10];
 

};
class BAT_ENEMY : public Enemy
{
public:
    BAT_ENEMY();
    ~BAT_ENEMY();
    void Draw();
    void Update();
    void MoveMents();
    void Reset();
};


//Bat Enemy Class
BAT_ENEMY::BAT_ENEMY()
{
    for (int i = 0; i < 5; i++)
        enemy_Not_died[i] = true;
    for (int i = 0; i < 5; i++)
    {
        IsLeft[i] = true;
        IsRight[i] = false;
    }
    //Position of Skilton 
   // Point_enemy = &Enemy_Image_right
    Enemy_position[0].x = 200;
    Enemy_position[0].y = 80;

    Enemy_position[1].x = 830;
    Enemy_position[1].y = 90;

    Enemy_position[2].x = GetScreenWidth()+100.0f;
    Enemy_position[2].y =(float) GetScreenHeight()/2 -300.0f;
    
    Enemy_position[3].x = 0;
    Enemy_position[3].y =(float) GetScreenHeight() / 2;


    Enemy_position[4].x = (float)GetScreenWidth();
    Enemy_position[4].y = 830 ;
      /*
      

     

      Enemy_position[4].x = 1800;
      Enemy_position[4].y = 530;*/


    for (int i = 0; i < 5; i++)
    {
        if (enemy_Not_died[i])
        {
            Enemy_texture_left[i] = LoadTextureFromImage(Enemy_Image_left[i]);
            Enemy_texture_right[i] = LoadTextureFromImage(Enemy_Image_right[i]);
        }
    }


    //s int previous_position = 500;

    for (int i = 0; i < 5; i++)
    {
        if (enemy_Not_died[i])
        {
            Enemy_rectangle[i].width = (float)Enemy_texture_left[i].width;
            Enemy_rectangle[i].height = (float)Enemy_texture_left[i].height;
        }
    }

    animFrames = 0;
    currentAnimFrame = 0;
    frameDelay = 70;
    frameCounter = 0;


    for (int i = 0; i < 5; i++)
    {
        if (enemy_Not_died[i])
        {
            Enemy_Image_right[i] = LoadImageAnim("Pictures/bat_left.gif", &animFrames);
            Enemy_Image_left[i] = LoadImageAnim("Pictures/bat_right.gif", &animFrames);
        }
    }


    for (int i = 0; i < 5; i++)
    {
        if (enemy_Not_died[i])
        {
            Enemy_texture_left[i] = LoadTextureFromImage(Enemy_Image_left[i]);
            Enemy_texture_right[i] = LoadTextureFromImage(Enemy_Image_right[i]);
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (enemy_Not_died[i])
            Current_Enemy_texure[i] = Enemy_texture_left[i];

    }


    for (int i = 0; i < 5; i++)
    {
        if (enemy_Not_died[i])
            Enemy_rectangle[i] = { Enemy_position[i].x,Enemy_position[i].y,(float)Enemy_Image_right[i].width,(float)Enemy_Image_right[i].height };
    }
}

BAT_ENEMY::~BAT_ENEMY()
{
    for (int i = 0; i < 5; i++)
    {
        UnloadImage(Enemy_Image_left[i]);
        UnloadImage(Enemy_Image_right[i]);
        UnloadTexture(Enemy_texture_left[i]);
        UnloadTexture(Enemy_texture_right[i]);
        UnloadTexture(Current_Enemy_texure[i]);
    }

}

void BAT_ENEMY::Draw()
{
    for (int i = 0; i < 5; i++)
    {
        if (enemy_Not_died[i])
        {
            DrawTextureV(Current_Enemy_texure[i], Enemy_position[i], WHITE);
        }
    }
}

void BAT_ENEMY::Update()
{

    frameCounter++;
    if (frameCounter >= frameDelay)
    {
        // Move to next frame
        //If final frame is reached we return to first frame
        currentAnimFrame++;
        if (currentAnimFrame >= animFrames) currentAnimFrame = 0;
        for (int i = 0; i < 5; i++)
        {
            nextFrameDataOffset[i] = Enemy_Image_right[i].width * Enemy_Image_right[i].height * 4 * currentAnimFrame;

        }

        frameCounter = 0;
    }

    
    for (int i = 0; i < 5; i++)
    {
        // Update texture based on direction of movement
        if (IsLeft[i])
            UpdateTexture(Current_Enemy_texure[i], ((unsigned char*)Enemy_Image_left[i].data) + nextFrameDataOffset[i]);
        else if (IsRight[i])
            UpdateTexture(Current_Enemy_texure[i], ((unsigned char*)Enemy_Image_right[i].data) + nextFrameDataOffset[i]);

    }
}

void BAT_ENEMY::MoveMents()
{

   
    if (enemy_Not_died[0])
    {
        if (Enemy_position[0].x != 30 && IsLeft[0])
        {
            Enemy_position[0].x -= 0.1f;

            Current_Enemy_texure[0] = Enemy_texture_left[0];

        }

        if (Enemy_position[0].x <= 300 && IsRight[0])
        {

            Enemy_position[0].x += 0.1f;
            Current_Enemy_texure[0] = Enemy_texture_right[0];
        }

        if (Enemy_position[0].x >= 300)
        {
            IsLeft[0] = true;
            IsRight[0] = false;
        }
        if (Enemy_position[0].x <= 30)
        {
            IsRight[0] = true;
            IsLeft[0] = false;
        }

        Enemy_rectangle[0].x = Enemy_position[0].x;
        Enemy_rectangle[0].y = Enemy_position[0].y;

    }
    if (enemy_Not_died[1])
    {
        if (Enemy_position[1].x > 750 && IsLeft[1])
        {
            Enemy_position[1].x -= 0.3f;

            Current_Enemy_texure[1] = Enemy_texture_left[1];

        }

        if (Enemy_position[1].x < 980 && IsRight[1])
        {

            Enemy_position[1].x += 0.3f;
            Current_Enemy_texure[1] = Enemy_texture_right[1];
        }

        if (Enemy_position[1].x >= 980)
        {
            IsLeft[1] = true;
            IsRight[1] = false;
        }
        if (Enemy_position[1].x <= 750)
        {
            IsRight[1] = true;
            IsLeft[1] = false;
        }

        Enemy_rectangle[1].x = Enemy_position[1].x;
        Enemy_rectangle[1].y = Enemy_position[1].y;

    }
    
    if (enemy_Not_died[2])
    {
        if (Enemy_position[2].x != 0 && IsLeft[2])
        {
            Enemy_position[2].x -= 1.5f;

            Current_Enemy_texure[2] = Enemy_texture_left[2];

        }

        if (Enemy_position[2].x <= GetScreenWidth()+100.0f && IsRight[2])
        {

            Enemy_position[2].x += 1.5f;
            Current_Enemy_texure[2] = Enemy_texture_right[2];
        }

        if (Enemy_position[2].x >= GetScreenWidth() + 100.0f)
        {
            IsLeft[2] = true;
            IsRight[2] = false;
        }
        if (Enemy_position[2].x <= 0)
        {
            IsRight[2] = true;
            IsLeft[2] = false;
        }

        Enemy_rectangle[2].x = Enemy_position[2].x;
        Enemy_rectangle[2].y = Enemy_position[2].y;
    }
  
    if (enemy_Not_died[3])
    {
        if (Enemy_position[3].x >= 0 && IsLeft[3])
        {
            Enemy_position[3].x -= 1.0f;

            Current_Enemy_texure[3] = Enemy_texture_left[3];

        }

        if (Enemy_position[3].x <=GetScreenWidth() && IsRight[3])
        {

            Enemy_position[3].x += 1.0f;
            Current_Enemy_texure[3] = Enemy_texture_right[3];
        }

        if (Enemy_position[3].x >= GetScreenWidth())
        {
            IsLeft[3] = true;
            IsRight[3] = false;
        }
        if (Enemy_position[3].x <= 0)
        {
            IsRight[3] = true;
            IsLeft[3] = false;
        }

        Enemy_rectangle[3].x = Enemy_position[3].x;
        Enemy_rectangle[3].y = Enemy_position[3].y;

    }

    if (enemy_Not_died[4])
    {
        if (Enemy_position[4].x >= 0 && IsLeft[4])
        {
            Enemy_position[4].x -= 0.6f;

            Current_Enemy_texure[4] = Enemy_texture_left[4];

        }

        if (Enemy_position[4].x <= GetScreenWidth() && IsRight[4])
        {

            Enemy_position[4].x += 0.6f;
            Current_Enemy_texure[4] = Enemy_texture_right[4];
        }

        if (Enemy_position[4].x >= GetScreenWidth())
        {
            IsLeft[4] = true;
            IsRight[4] = false;
        }
        if (Enemy_position[4].x <= 0)
        {
            IsRight[4] = true;
            IsLeft[4] = false;
        }

        Enemy_rectangle[4].x = Enemy_position[4].x;
        Enemy_rectangle[4].y = Enemy_position[4].y;

    }



}

void BAT_ENEMY::Reset()
{
    for (int i = 0; i < 5; i++)
    {
        if (!enemy_Not_died[i])
        {
            UnloadTexture(Enemy_texture_left[i]);
            UnloadTexture(Enemy_texture_right[i]);
            Enemy_rectangle[i].x = 0;
            Enemy_rectangle[i].y = 0;


        }
    }


}



//Skilton Class Code
class SKILTON_ENEMY :  public Enemy
{
public:


    SKILTON_ENEMY();
    ~SKILTON_ENEMY();
    void Draw();
    void Update();
    void Collision();
    void MoveMents();
    void Reset();
};

SKILTON_ENEMY::SKILTON_ENEMY()
{
    for(int i=0;i<5;i++)
             enemy_Not_died[i] = true;
    for (int i = 0; i < 5; i++)
    {
        IsLeft[i] = true;
        IsRight[i] = false;
    }
    //Position of Skilton 
   // Point_enemy = &Enemy_Image_right
    Enemy_position[0].x = 610;
    Enemy_position[0].y = 880;

    Enemy_position[1].x = 580;
    Enemy_position[1].y = 570;

    Enemy_position[2].x = 830;
    Enemy_position[2].y = 180;

    Enemy_position[3].x = 1360;
    Enemy_position[3].y = 430;

    Enemy_position[4].x = 1800;
    Enemy_position[4].y = 530;


    for (int i = 0; i < 5; i++)
    {
        Enemy_texture_left[i] = LoadTextureFromImage(Enemy_Image_left[i]);
        Enemy_texture_right[i] = LoadTextureFromImage(Enemy_Image_right[i]);

    }


   //s int previous_position = 500;
   
    for (int i = 0; i < 5; i++)
    {
        Enemy_rectangle[i].width = (float)Enemy_texture_left[i].width-50;
        Enemy_rectangle[i].height = (float)Enemy_texture_left[i].height;
    }

    animFrames = 0;
    currentAnimFrame = 0;
    frameDelay = 70;
    frameCounter = 0;
   

        for (int i = 0; i < 5; i++)
        {
            Enemy_Image_right[i] = LoadImageAnim("Pictures/skilton_right.gif", &animFrames);
            Enemy_Image_left[i] = LoadImageAnim("Pictures/skilton_left.gif", &animFrames);
        }
    

    for (int i = 0; i < 5; i++)
    {
        Enemy_texture_left[i] = LoadTextureFromImage(Enemy_Image_left[i]);
        Enemy_texture_right[i] = LoadTextureFromImage(Enemy_Image_right[i]);

    }

    for (int i = 0; i < 5; i++)
    {
        Current_Enemy_texure[i] = Enemy_texture_left[i];

    }


    for (int i = 0; i < 5; i++)
    {
        Enemy_rectangle[i] = { Enemy_position[i].x,Enemy_position[i].y,(float)Enemy_Image_right[i].width,(float)Enemy_Image_right[i].height};
    }
}

SKILTON_ENEMY::~SKILTON_ENEMY()
{
    for (int i = 0; i < 5; i++)
    {
        UnloadTexture(Enemy_texture_left[i]);
        UnloadTexture(Enemy_texture_right[i]);
        UnloadImage(Enemy_Image_left[i]);
        UnloadImage(Enemy_Image_right[i]);


    }

}

void SKILTON_ENEMY::Draw()
{
    for (int i = 0; i < 5; i++)
    {
        if (enemy_Not_died[i])
        {
          
                DrawTextureV(Current_Enemy_texure[i], Enemy_position[i], WHITE);
        }
    }
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
      /*  nextFrameDataOffset[0] = Enemy_Image_right[0].width * Enemy_Image_right[0].height * 4 * currentAnimFrame;
        nextFrameDataOffset[1] = Enemy_Image_right[1].width * Enemy_Image_right[1].height * 4 * currentAnimFrame;
        nextFrameDataOffset[2] = Enemy_Image_right[2].width * Enemy_Image_right[2].height * 4 * currentAnimFrame;*/
        for (int i = 0; i < 5; i++)
        {
            nextFrameDataOffset[i] = Enemy_Image_right[i].width * Enemy_Image_right[i].height * 4 * currentAnimFrame;

        }

        frameCounter = 0;
    }

    //F
    for (int i = 0; i < 5; i++)
    {
                // Update texture based on direction of movement
             if (IsLeft[i])
                  UpdateTexture(Current_Enemy_texure[i], ((unsigned char*)Enemy_Image_left[i].data) + nextFrameDataOffset[i]);
             else if (IsRight[i])
                    UpdateTexture(Current_Enemy_texure[i], ((unsigned char*)Enemy_Image_right[i].data) + nextFrameDataOffset[i]);
  
    }
}
    
void SKILTON_ENEMY::MoveMents()
{

    if (enemy_Not_died[4])
    {
        if (Enemy_position[4].x >= 1550 && IsLeft[4])
        {
            Enemy_position[4].x -= 0.1f;

            Current_Enemy_texure[4] = Enemy_texture_left[4];

        }

        if (Enemy_position[4].x <= 1810 && IsRight[4])
        {

            Enemy_position[4].x += 0.1f;
            Current_Enemy_texure[4] = Enemy_texture_right[4];
        }

        if (Enemy_position[4].x >= 1810)
        {
            IsLeft[4] = true;
            IsRight[4] = false;
        }
        if (Enemy_position[4].x <= 1550)
        {
            IsRight[4] = true;
            IsLeft[4] = false;
        }

        Enemy_rectangle[4].x = Enemy_position[4].x;
        Enemy_rectangle[4].y = Enemy_position[4].y;

    }
        if (enemy_Not_died[0])
        {
            if (Enemy_position[0].x != 490 && IsLeft[0])
            {
                Enemy_position[0].x -= 0.1f;

                Current_Enemy_texure[0] = Enemy_texture_left[0];

            }

            if (Enemy_position[0].x <= 610 && IsRight[0])
            {

                Enemy_position[0].x += 0.1f;
                Current_Enemy_texure[0] = Enemy_texture_right[0];
            }

            if (Enemy_position[0].x >= 610)
            {
                IsLeft[0] = true;
                IsRight[0] = false;
            }
            if (Enemy_position[0].x <= 500)
            {
                IsRight[0] = true;
                IsLeft[0] = false;
            }

            Enemy_rectangle[0].x = Enemy_position[0].x;
            Enemy_rectangle[0].y = Enemy_position[0].y;

        }
        if (enemy_Not_died[1])
        {
            if (Enemy_position[1].x != 10 && IsLeft[1])
            {
                Enemy_position[1].x -= 0.1f;

                Current_Enemy_texure[1] = Enemy_texture_left[1];

            }

            if (Enemy_position[1].x <= 580 && IsRight[1])
            {

                Enemy_position[1].x += 0.1f;
                Current_Enemy_texure[1] = Enemy_texture_right[1];
            }

            if (Enemy_position[1].x >= 580)
            {
                IsLeft[1] = true;
                IsRight[1] = false;
            }
            if (Enemy_position[1].x <= 10)
            {
                IsRight[1] = true;
                IsLeft[1] = false;
            }

            Enemy_rectangle[1].x = Enemy_position[1].x;
            Enemy_rectangle[1].y = Enemy_position[1].y;
        }
        if (enemy_Not_died[2])
        {
            if (Enemy_position[2].x > 750 && IsLeft[2])
            {
                Enemy_position[2].x -= 0.1f;

                Current_Enemy_texure[2] = Enemy_texture_left[2];

            }

            if (Enemy_position[2].x < 880 && IsRight[2])
            {

                Enemy_position[2].x += 0.1f;
                Current_Enemy_texure[2] = Enemy_texture_right[2];
            }

            if (Enemy_position[2].x >= 880)
            {
                IsLeft[2] = true;
                IsRight[2] = false;
            }
            if (Enemy_position[2].x <= 750)
            {
                IsRight[2] = true;
                IsLeft[2] = false;
            }

            Enemy_rectangle[2].x = Enemy_position[2].x;
            Enemy_rectangle[2].y = Enemy_position[2].y;
           
        }
        if (enemy_Not_died[3])
        {
            if (Enemy_position[3].x >= 1260 && IsLeft[3])
            {
                Enemy_position[3].x -= 0.1f;

                Current_Enemy_texure[3] = Enemy_texture_left[3];

            }

            if (Enemy_position[3].x <= 1390 && IsRight[3])
            {

                Enemy_position[3].x += 0.1f;
                Current_Enemy_texure[3] = Enemy_texture_right[3];
            }

            if (Enemy_position[3].x >= 1390)
            {
                IsLeft[3] = true;
                IsRight[3] = false;
            }
            if (Enemy_position[3].x <= 1260)
            {
                IsRight[3] = true;
                IsLeft[3] = false;
            }

            Enemy_rectangle[3].x = Enemy_position[3].x;
            Enemy_rectangle[3].y = Enemy_position[3].y;
           
        }
       




}

void SKILTON_ENEMY::Reset()
{
    for (int i = 0; i < 5; i++)
    {
        if (!enemy_Not_died[i])
        {
            UnloadTexture(Enemy_texture_left[i]);
            UnloadTexture(Enemy_texture_right[i]);
            Enemy_rectangle[i].x = (float)GetScreenWidth() + 500;
            Enemy_rectangle[i].y = (float)GetScreenHeight() + 500;
        

        }
    }


}


//Skilton Class code END






int main()
{
 
    const int screenWidth = GetScreenHeight();
    const int screenHeight = GetScreenWidth();
    raylib::Window window(screenWidth, screenHeight, "WINDOW");
   
   // Load button sound
    Texture2D button = LoadTexture("Pictures/button.png"); // Load button texture

    InitAudioDevice();
    Sound Coins_collected = LoadSound("Sounds/coins_collection.wav");
    Sound Kill_by_enemy = LoadSound("Sounds/kill_by_enemy.mp3");
    Sound sound_list = LoadSound("Sounds/player_walking.wav");
    Sound Player_hit = LoadSound("Sounds/Player_hit.mp3");
    Sound Game_over = LoadSound("Sounds/Game_over.mp3");
    Music Game_music = LoadMusicStream("Sounds/Game_music.mp3");

    // Define frame rectangle for drawing
    float frameHeight = (float)button.height;
    Rectangle Button_rectangle = { (float)GetScreenWidth() / 2 - 100,(float) GetScreenHeight() / 2 - 100, (float)button.width/2, frameHeight/2 };

   //Ending Rectangle
    Rectangle Winning_rectangle = { 1700,900 ,100,100 };

    int btnState = 0;               
    bool btnAction = false;       
 
    Vector2 mousePoint = { 0.0f, 0.0f };

    COIN Coin_obj;
    GAME Game_obj;

    SKILTON_ENEMY Skilton_1;
    BAT_ENEMY Bat_1;
    bool endprogram = false;
    bool Win = false;
    bool paused = false;
    mousePoint = GetMousePosition();
    bool Start = false;
    SetSoundVolume(Kill_by_enemy, 2.0f);
    SetMusicVolume(Game_music, 0.5f);
    while (!window.ShouldClose())
    {
       
        mousePoint = GetMousePosition();

        // Check button state
        if (!btnAction)
        {
            if (CheckCollisionPointRec(mousePoint, Button_rectangle))
            {

                if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                    btnAction = true;
                    UnloadTexture(button);
                    Button_rectangle.x = 0;
                    Button_rectangle.y = 0;
                }
            }

        }
  

        // Calculate button frame rectangle to draw depending on button state

        if (IsKeyPressed(KEY_P))
            paused = !paused;

        if (btnAction)
        {
            if (!Win)
            {
                if (!paused)
                {
                    UpdateMusicStream(Game_music);
                    PlayMusicStream(Game_music);

                    Game_obj.HandleInput();


                    ClearBackground(BLACK);

                    Game_obj.Update();
                    Game_obj.CheckForCollisions();
                    Coin_obj.Update();


                    Bat_1.Update();

                    Bat_1.MoveMents();

                    Skilton_1.Update();

                    Skilton_1.MoveMents();
                }
            }
        }
        BeginDrawing();
      
        Coin_obj.Draw();
        Bat_1.Draw();
        Skilton_1.Draw();
        //Collision Detection Part
      
        //Collision Of Player with Coins
        for (int i = 0; i < 50; i++)
        {
            if (CheckCollisionRecs(Game_obj.Player_obj.playerCollisionRect, Coin_obj.Coin_Rect[i]))
            {
                // Collision detected with coin
                //In the following lines in the loop, we are removing the frames and also the rectangle so when player stay their after collecting coin then the loop shouldn't run 
                PlaySound(Coins_collected);
                Score += 50;
                Check_for_high_score();
                Coin_obj.Coin_Texture[i].height = 0;
                Coin_obj.Coin_Texture[i].width = 0;
                Coin_obj.Coin_Rect[i].height = 0;
                Coin_obj.Coin_Rect[i].width = 0;
                Coin_obj.Coin_Rect[i].y = 0;
                Coin_obj.Coin_Rect[i].x = 0;
                break;


            }
        }

        //Collision of Player with Skilton
        for (int i = 0; i < 5; i++)
        {
            if (CheckCollisionRecs(Game_obj.Player_obj.playerCollisionRect, Skilton_1.Enemy_rectangle[i]))
            {

                // Get the difference in X and Y positions for collision direction
                
                float deltaX = abs(Game_obj.Player_obj.playerCollisionRect.x - Skilton_1.Enemy_rectangle[i].x);
                float deltaY = Game_obj.Player_obj.playerCollisionRect.y - Skilton_1.Enemy_rectangle[i].y;

                // Check for collision from any direction except bottom

                if (deltaX < Game_obj.Player_obj.playerCollisionRect.width / 2.0f &&
                    deltaY < Skilton_1.Enemy_rectangle[i].height / 2.0f) {
                    // Player collided on top or slightly within enemy
                    Score += 100;
                    PlaySound(Player_hit);
                    Check_for_high_score();

                    Skilton_1.enemy_Not_died[i] = false;
                    Skilton_1.Reset();
                }

                else {
                    PlaySound(Kill_by_enemy);
                    // Check for standard left/right collisions (optional)
                    Game_obj.Reset();
                }
                //d }


            }
            if (CheckCollisionRecs(Game_obj.Player_obj.playerCollisionRect, Bat_1.Enemy_rectangle[i]))
            {
                float deltaX = abs(Game_obj.Player_obj.playerCollisionRect.x - Bat_1.Enemy_rectangle[i].x);
                float deltaY = Game_obj.Player_obj.playerCollisionRect.y - Bat_1.Enemy_rectangle[i].y;

                // Check for collision from any direction except bottom

                if (deltaX < Game_obj.Player_obj.playerCollisionRect.width / 2.0f &&
                    deltaY < Bat_1.Enemy_rectangle[i].height / 2.0f) {
                    PlaySound(Player_hit);

                    // Player collided on top or slightly within enemy
                    if (i == 0 || i == 1)
                    {
                        Score += 200;

                    }
                    if (i==2)
                    {
                        Score += 2000;

                    }
                    if (i == 3)
                    {
                        Score += 1000;
                    }
                    if (i == 4)
                    {
                        Score += 500;
                    }
                    Bat_1.enemy_Not_died[i] = false;
                    Bat_1.Reset();
                    Check_for_high_score();
                }

                else {
                    PlaySound(Kill_by_enemy);
                
                    Game_obj.Reset();
                }
            }
        }

            endprogram = Game_obj.Draw();
            if (endprogram)
            {
                PlaySound(Game_over);

           }

            //Scoring diplay
            DrawTextEx(GetFontDefault(), "SCORE: ", { 1200,1000 }, 34, 2, YELLOW);
            string Score_text = Formating_score(Score,5);
            DrawTextEx(GetFontDefault(), Score_text.c_str(), { 1340,1000 }, 34, 2, YELLOW);

            DrawTextEx(GetFontDefault(), "HIGH SCORE: ", { 1500,1000 }, 34, 2, YELLOW);
            string Hight_score_text =Formating_score(High_score, 5);
            DrawTextEx(GetFontDefault(), Hight_score_text.c_str(), { 1750,1000 }, 34, 2, YELLOW);

            if(paused)
               DrawText("PAUSED", GetScreenWidth() / 2, GetScreenHeight() / 2, 100, RED);

            if (!btnAction)
            {
                DrawRectangle(GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 200, 500, 600,GOLD);
              //  DrawLine(GetScreenWidth() / 2 - 170, GetScreenHeight() / 2 - 200, GetScreenWidth() / 2 - 170, GetScreenHeight() / 2, BLACK);
              DrawLineEx({ (float)GetScreenWidth() / 2 - 170, (float)GetScreenHeight() / 2 -200 }, { (float)GetScreenWidth() / 2 - 170, (float)GetScreenHeight() -100 }, 5.0f, BLACK);
              DrawLineEx({ (float)GetScreenWidth()- 700, (float)GetScreenHeight()  - 900 }, { (float)GetScreenWidth() -700, (float)GetScreenHeight() - 100 }, 5.0f, BLACK);

                DrawTexture(button, GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 - 100, WHITE);
            }

        //Winning collision check 
            if (CheckCollisionRecs(Game_obj.Player_obj.playerCollisionRect, Winning_rectangle))
            {
                DrawText("VICTORY ! ", 400, 400, 250, YELLOW);
                Win = true;
            }
            EndDrawing();

        }
      
        // Unload textures
        CloseAudioDevice();
        window.Close();

  

        return 0;
        


    }


