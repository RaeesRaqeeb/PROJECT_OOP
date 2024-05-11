//#include "Header_files/game_main.hpp"
//#include<fstream>
//
//GAME::GAME()
//{
//
//	IsPlayerMoving = false;
// 
//}
//
//GAME::~GAME()
//{
//    
//}
//
//void GAME::Draw()
//{
//      
//        Player_obj.Draw();
//       
//     
//      
//       
//}
//
//
//void GAME::Update()
//{
//
//        Player_obj.Update();
//  
//    
//}
//
//void GAME::HandleInput()
//{
//
//
//		Player_obj.Player_Movement();
//	
//
//}
//
//void GAME::CheckForCollisions()
//{
//  
//    for (int i = 0; i < 10; i++)
//    {
//        if (Player_obj.Player_collision_with_platform1s())
//        {
//            Player_obj.playerRect.y = Player_obj.previousPosition.y;
//            Player_obj.playerRect.x = Player_obj.previousPosition.x;
//            Player_obj.IsplayerOnGround = true;
//         
//            Player_obj.jumpSpeed = 0.0f;
//            // Reset jump speed if collided
//            Player_obj.jump_count_index_in_air = 0;
//        }
//
//    }
//
//    /*
//    ++frameDelayCounter;
//
//    if (frameDelayCounter >= frameDelay)
//    {
//        frameDelayCounter = 0;
//        ++enemy_frame_index;
//        enemy_frame_index %= enemy_frames;
//
//        if (IsPlayerMoving)
//        {
//            ++frameIndex;
//            frameIndex %= numFrames;
//
//        }
//    }
//    */
//}
//
//void GAME::Reset()
//{
//
//    Player_obj.Reset();
//
//}
//
