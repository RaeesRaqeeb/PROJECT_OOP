#include"Header_Files/Enemys.hpp"




//Constructor
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
    Enemy_position[0].x = 200;
    Enemy_position[0].y = 80;

    Enemy_position[1].x = 830;
    Enemy_position[1].y = 90;

    Enemy_position[2].x = GetScreenWidth() + 100.0f;
    Enemy_position[2].y = (float)GetScreenHeight() / 2 - 300.0f;

    Enemy_position[3].x = 0;
    Enemy_position[3].y = (float)GetScreenHeight() / 2;


    Enemy_position[4].x = (float)GetScreenWidth();
    Enemy_position[4].y = 830;





    //Drawing Rectangle for each texture 
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

    //Loading Images
    for (int i = 0; i < 5; i++)
    {
        if (enemy_Not_died[i])
        {
            Enemy_Image_right[i] = LoadImageAnim("Pictures/bat_left.gif", &animFrames);
            Enemy_Image_left[i] = LoadImageAnim("Pictures/bat_right.gif", &animFrames);
        }
    }


    //Loading Images to Texture function
    for (int i = 0; i < 5; i++)
    {
        if (enemy_Not_died[i])
        {
            Enemy_texture_left[i] = LoadTextureFromImage(Enemy_Image_left[i]);
            Enemy_texture_right[i] = LoadTextureFromImage(Enemy_Image_right[i]);
        }
    }

    //Current Texture loading
    for (int i = 0; i < 5; i++)
    {
        if (enemy_Not_died[i])
            Current_Enemy_texure[i] = Enemy_texture_left[i];

    }

    //Making rectangle for each enemy
    for (int i = 0; i < 5; i++)
    {
        if (enemy_Not_died[i])
            Enemy_rectangle[i] = { Enemy_position[i].x,Enemy_position[i].y,(float)Enemy_Image_right[i].width,(float)Enemy_Image_right[i].height };
    }
}

//Destructor
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

//Draw Function to draw the Enemies in the screen
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

//Update function to update different attributes of enemies like Frames, positions, textures
void BAT_ENEMY::Update()
{

  


    for (int i = 0; i < 5; i++)
    {
        // Update texture based on direction of movement
        if (IsLeft[i])
            UpdateTexture(Current_Enemy_texure[i], ((unsigned char*)Enemy_Image_left[i].data) + nextFrameDataOffset[i]);
        else if (IsRight[i])
            UpdateTexture(Current_Enemy_texure[i], ((unsigned char*)Enemy_Image_right[i].data) + nextFrameDataOffset[i]);

    }

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
}


//Automatic movement function for enemies
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

        if (Enemy_position[2].x <= GetScreenWidth() + 100.0f && IsRight[2])
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

        if (Enemy_position[3].x <= GetScreenWidth() && IsRight[3])
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

//When player hit the enemy from the top it will removed from screen
void BAT_ENEMY::Reset()
{
    for (int i = 0; i < 5; i++)
    {
        if (!enemy_Not_died[i])
        {
         
            Enemy_rectangle[i].x = 0;
            Enemy_rectangle[i].y = 0;


        }
    }


}


//Skilton ENemy

//Similar to Bat functions
SKILTON_ENEMY::SKILTON_ENEMY()
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
        Enemy_rectangle[i].width = (float)Enemy_texture_left[i].width - 50;
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
        Enemy_rectangle[i] = { Enemy_position[i].x,Enemy_position[i].y,(float)Enemy_Image_right[i].width,(float)Enemy_Image_right[i].height };
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
            Enemy_rectangle[i].x = 0;
            Enemy_rectangle[i].y = 0;


        }
    }


}
