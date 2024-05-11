#include <raylib.h>
#include<string>
#include<iostream>
#include<fstream>
#include<string>
#include"Header_files/coins.hpp"
#include"Header_files/Enemys.hpp"
#include"Header_files/player.hpp"




//Following functions are used for Score storing and loading from the file
std::string Formating_score(int Score, int width)
{
   std::string Num_text = std::to_string(Score);
    int leading_zeros = (int)width - (int)Num_text.length();

    //in this we are concatenating the string also used string class constructor to repeatly add the 0 to string 
    return Num_text =std:: string(leading_zeros, '0') + Num_text;
}
int High_score_load_from_File()
{
    int loaded_high_score = 0;
  std:: ifstream file("High_score.txt");

    if (file.is_open())
    {
        file >> loaded_high_score;
        file.close();
    }
    else
    {
        std::cout << "Error in loading from the file" << std::endl;
    }

    return loaded_high_score;
}
void HighScore_Save_to_File(int highScore)
{
   std:: ofstream file("High_score.txt");

    if (file.is_open())
    {
        file << highScore;
        file.close();
    }
    else
    {
        std::cout << "Faild to save score" << std::endl;
    }
}
int Score = 0;
int High_score = High_score_load_from_File();
void Check_for_high_score()
{
    if (Score > High_score)
    {
        High_score = Score;
        HighScore_Save_to_File(High_score);
    }
}



int main()
{
 
    const int screenWidth = GetScreenHeight();
    const int screenHeight = GetScreenWidth();
    InitWindow(screenWidth, screenHeight, "WINDOW");
   
   // Load button sound
    Texture2D button = LoadTexture("Pictures/button.png"); // Load button texture

    InitAudioDevice();
    Sound* Ptr[3];
    Music* ptr_music[2];

 //Pointers are used to store some data in heap also
    Ptr[0] = new Sound(LoadSound(("Sounds/coins_collection.wav")));
    Ptr[1] = new Sound(LoadSound("Sounds/kill_by_enemy.mp3"));
    Ptr[2]=new Sound (LoadSound("Sounds/Player_hit.mp3"));
    ptr_music[0] = new Music(LoadMusicStream("Sounds/Game_music.mp3"));
    ptr_music[1] = new Music(LoadMusicStream("Sounds/Victory.mp3"));


    // Define frame rectangle for drawing
    float frameHeight = (float)button.height;
    Rectangle Button_rectangle = { (float)GetScreenWidth() / 2 - 100,(float) GetScreenHeight() / 2 - 100, (float)button.width/2 + 50, frameHeight/2 +50 };

   //Ending Rectangle
    Rectangle Winning_rectangle = { 1700,900 ,100,100 };

    int btnState = 0;               
    bool btnAction = false;       
 
    Vector2 mousePoint = { 0.0f, 0.0f };

    //Objects of Class 
    COIN Coin_obj;
    PLAYER Player_obj;
  //  GAME Game_obj;
    SKILTON_ENEMY Skilton_1;
    BAT_ENEMY Bat_1;

    bool endprogram = false;
    bool Win = false;
    bool paused = false;
    mousePoint = GetMousePosition();
    bool Start = false;
    SetSoundVolume(*Ptr[1], 2.0f);
    SetMusicVolume(*ptr_music[0], 0.5f);
    SetMusicVolume(*ptr_music[1], 2.0f);


    //Game Loop
    while (!WindowShouldClose())
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
  

       
        //If Pressed P then Game Paused
        if (IsKeyPressed(KEY_P))
            paused = !paused;

        //In starting if the button is click then Game Will start
        if (btnAction)
        {
            if (!Win)
            {
                if (!paused)
                {
                    UpdateMusicStream(*ptr_music[0]);
                    PlayMusicStream(*ptr_music[0]);

                    Player_obj.Player_Movement();


                    ClearBackground(BLACK);

                    Player_obj.Update();
                    Player_obj.Player_collision_with_platform1s();
                    Coin_obj.Update();


                    Bat_1.Update();

                    Bat_1.MoveMents();

                    Skilton_1.Update();

                    Skilton_1.MoveMents();
                }
            }
        }

        //Game Displaying and Drawing the Frames and Objects
        BeginDrawing();
        Player_obj.Draw();
        Coin_obj.Draw();
        Bat_1.Draw();
        Skilton_1.Draw();
        //Collision Detection Part
      
        //Collision Of Player with Coins
        for (int i = 0; i < 50; i++)
        {
            if (CheckCollisionRecs(Player_obj.playerCollisionRect, Coin_obj.Coin_Rect[i]))
            {
                // Collision detected with coin
                //In the following lines in the loop, we are removing the frames and also the rectangle so when player stay their after collecting coin then the loop shouldn't run 
                PlaySound(*Ptr[0]);
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

        //Collision of Player with Skilton and Bats
        for (int i = 0; i < 5; i++)
        {
            if (CheckCollisionRecs(Player_obj.playerCollisionRect, Skilton_1.Enemy_rectangle[i]))
            {

                // Get the difference in X and Y positions for collision direction
                
                float X = abs(Player_obj.playerCollisionRect.x - Skilton_1.Enemy_rectangle[i].x);
                float Y = Player_obj.playerCollisionRect.y - Skilton_1.Enemy_rectangle[i].y;

                // Check for collision from any direction
                if (X < Player_obj.playerCollisionRect.width / 2.0f &&
                    Y < Skilton_1.Enemy_rectangle[i].height / 2.0f)
                {
                    // Player collided on top or slightly within enemy
                    Score += 100;
                    PlaySound(*Ptr[2]);
                    Check_for_high_score();

                    Skilton_1.enemy_Not_died[i] = false;
                    Skilton_1.Reset();
                }





                else 
                {
                    PlaySound(*Ptr[1]);
                    Player_obj.Reset();
                }
                


            }

            //Checking Collision between Player and Bats
            if (CheckCollisionRecs(Player_obj.playerCollisionRect, Bat_1.Enemy_rectangle[i]))
            {
                float X_Bat = abs(Player_obj.playerCollisionRect.x - Bat_1.Enemy_rectangle[i].x);
                float Y_Bat = Player_obj.playerCollisionRect.y - Bat_1.Enemy_rectangle[i].y;

                // Check for collision from any direction except bottom

                if (X_Bat < Player_obj.playerCollisionRect.width / 2.0f &&
                    Y_Bat < Bat_1.Enemy_rectangle[i].height / 2.0f)
                {
                    PlaySound(*Ptr[2]);

              
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
                    //Enemy Died if player jump on it 
                    Bat_1.enemy_Not_died[i] = false;
                    Bat_1.Reset();
                    Check_for_high_score();
                }

                else 
                {
                    PlaySound(*Ptr[1]);
                
                    Player_obj.Reset();
                }
            }
        }

         
       

            //Scoring diplay
            DrawTextEx(GetFontDefault(), "SCORE: ", { 1200,1000 }, 34, 2, YELLOW);
            std::string Score_text = Formating_score(Score,5);
            DrawTextEx(GetFontDefault(), Score_text.c_str(), { 1340,1000 }, 34, 2, YELLOW);

            DrawTextEx(GetFontDefault(), "HIGH SCORE: ", { 1500,1000 }, 34, 2, YELLOW);
            std::string Hight_score_text =Formating_score(High_score, 5);
            DrawTextEx(GetFontDefault(), Hight_score_text.c_str(), { 1750,1000 }, 34, 2, YELLOW);

            if(paused)
               DrawText("PAUSED", GetScreenWidth() / 2, GetScreenHeight() / 2, 100, RED);

            if (!btnAction)
            {
                DrawRectangle(GetScreenWidth() / 2 - 200, GetScreenHeight() / 2 - 200, 500, 600,GOLD);
              DrawLineEx({ (float)GetScreenWidth() / 2 - 170, (float)GetScreenHeight() / 2 -200 }, { (float)GetScreenWidth() / 2 - 170, (float)GetScreenHeight() -100 }, 5.0f, BLACK);
              DrawLineEx({ (float)GetScreenWidth()- 700, (float)GetScreenHeight()  - 900 }, { (float)GetScreenWidth() -700, (float)GetScreenHeight() - 100 }, 5.0f, BLACK);

                DrawTexture(button, GetScreenWidth() / 2 - 100, GetScreenHeight() / 2 - 100, WHITE);
            }

        //Winning collision check 
            if (CheckCollisionRecs(Player_obj.playerCollisionRect, Winning_rectangle))
            {
                PauseMusicStream(*ptr_music[0]);
                PlayMusicStream(*ptr_music[1]);
                DrawText("VICTORY ! ", 400, 400, 250, YELLOW);
                Win = true;
            }
            EndDrawing();

        }
      
        // Unload textures
        CloseAudioDevice();
        CloseWindow();

        for (int i = 0; i < 3; i++)
            delete Ptr[i];

        return 0;
        


    }


