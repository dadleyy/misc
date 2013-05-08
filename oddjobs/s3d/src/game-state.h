#ifndef _S3D_GAME_STATE
#define _S3D_GAME_STATE

#include "includes.h"
#include "state.h"
#include <sstream>

class Player;

class GameState : public State {

public:
    GameState( );
    ~GameState( );
    
    void Update( float dt );
    void Draw( );
    
private:
    float alpha;
    Player* player;
};

#endif