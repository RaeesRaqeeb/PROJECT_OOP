#include "game_main.hpp"
#include"enemy.hpp"


GAME::GAME()
{
   // Ptr_coin = new SMALL_COIN;
	IsPlayerMoving = false;
	InitGame();
}

GAME::~GAME()
{
    
}

bool GAME::Draw()
{
      
        Player_obj.Draw(IsPlayerMoving);
       
     
      
        return playing;
}


void GAME::Update()
{
    if (playing)
    {//Enemy movement updates
       
       // Enemy_obj1.Update();
    //Player updates
        Player_obj.Update();
        
     //   Enemy_obj1.Enemy_movement();
       
    }
    
}

void GAME::HandleInput()
{

	if (lives != 0)
	{
         
		Player_obj.Player_Movement();
	}

}

void GAME::CheckForCollisions()
{
  
    for (int i = 0; i < 10; i++)
    {
        if (Player_obj.Player_collision_with_platform1s())
        {
            Player_obj.playerRect.y = Player_obj.previousPosition.y;
            Player_obj.playerRect.x = Player_obj.previousPosition.x;
            Player_obj.IsplayerOnGround = true;
         
            Player_obj.jumpSpeed = 0.0f;
            // Reset jump speed if collided
            Player_obj.jump_count_index_in_air = 0;
        }

    }


    ++frameDelayCounter;

    if (frameDelayCounter >= frameDelay)
    {
        frameDelayCounter = 0;
        ++enemy_frame_index;
        enemy_frame_index %= enemy_frames;

        if (IsPlayerMoving)
        {
            ++frameIndex;
            frameIndex %= numFrames;

        }
    }

}

void GAME::Reset()
{
    Player_obj.reset();

}

void GAME::InitGame()
{
	IsPlayerMoving = true;
}
