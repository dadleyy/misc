#include "game-state.h"
#include "player.h"

GameState::GameState( ) : alpha(0.0f){
 
    player = new Player( );
    player->Init( );
    
}

void GameState::Update( float dt ){ 
    /* Clear the buffer, clear the matrix */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    
    player->Update( dt );
}

void GameState::Draw( ){     
    player->Draw( );
}

GameState::~GameState( ){ 
    delete player;
}