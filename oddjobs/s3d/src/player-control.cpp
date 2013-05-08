#include "player-control.h"
#include "game-object.h"


void PlayerControl::Init( GameObject* go ){
    
}

void PlayerControl::Update( float dt ){

    if( keystates[100] )
        std::cout << "moving right" << std::endl;
    if( keystates[97] )
        std::cout << "moving left" << std::endl;
    if( keystates[119] )
        std::cout << "moving forward" << std::endl;
    if( keystates[115] )
        std::cout << "moving backward" << std::endl;

}