#include "game-state.h"
#include "player.h"

GameState::GameState( ) : alpha(0.0f){ 
    player = new Player( );
}

void GameState::Update( float dt ){ 
    
    /* Clear the buffer, clear the matrix */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    /* A step backward, then spin the cube */
    glTranslatef( 0, 0, -10 );
    glRotatef( 30, 1, 0, 0 );
    glRotatef( alpha, 0, 1, 0 );

    alpha += (10000 * dt);
    
    player->Update( dt );
}

void GameState::Draw( ){     
    player->Draw( );
}

GameState::~GameState( ){ 
    delete player;
}