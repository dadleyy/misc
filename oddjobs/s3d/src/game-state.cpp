#include "game-state.h"
#include "player.h"

GameState::GameState( ) {
 
    player = new Player( );
    player->Init( );
    
}

void GameState::Update( float dt ){   
    player->Update( dt );
}

void GameState::Draw( ){     
    player->Draw( );
}

GameState::~GameState( ){ 
    delete player;
}