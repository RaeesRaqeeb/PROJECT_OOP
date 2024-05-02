#include<raylib.h>
#include<raylib-cpp.hpp>
//Player class 
class PLAYER {
public:
    PLAYER();
    ~PLAYER();
    Camera2D camera;
    //Memebr variables or attributes for player
    Texture2D picture;
    Rectangle playerRect;
    Rectangle playerCollisionRect;
    bool IsplayerOnGround;
    unsigned frameIndex;
    unsigned numFrames;
    unsigned frameDelay;
    unsigned frameDelayCounter;
    bool playerMoving;
    const float playerSpeed = 0.2f;
    float jumpSpeed;
    int jump_count_index_in_air;

    //Member variable for obstacles
    Texture2D picture2;
    Rectangle obstacleRect;


    //Enemy
    Texture2D enemy_picture;
    Rectangle enemy_rect;
    int enemy_frames;
    int direction;
    int enemy_frame_index;



    //World related variable
    float ground_level;
    Vector2 Title_position;

    // Public member functions
    void Player_Movement();
    void TakeDamage(int damageAmount);
    void IncreaseScore(int points);
    bool Draw(bool IsPlayerMoving);
    void TILES_DRAW();
    bool Player_collision_with_platform1s();
    void Update();
    void Enemy_movement();



    Vector2 previousPosition;
   
    //Tiles
    bool platformsDrawn;
    int numTiles;
    Rectangle Tiles_Number[100];
    Rectangle Fake_tiles[10];
    Rectangle Big_Tiles_num[10];
    Rectangle Enemy_tiles[5];
    float minTileDistance;
    float maxTileDistance;
    int totalWidth;
    float averageDistance;
    bool firstFrame = true;
    int once = 0;
    //Rectangle originalplatform1Position[10];
    
    //Functions Making for managing 
    Rectangle player_GetRect();



    int GetHealth() const { return player_health; }
    int GetScore() const { return score; }

private:
    // Private attributes
    int player_health;
    int score;
    int positionX;
    int positionY;

    // Private helper functions
    bool IsAlive() const { return player_health > 0; }
};
