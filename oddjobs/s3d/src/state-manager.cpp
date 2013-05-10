#include "state-manager.h"

StateManager::StateManager( ){ }

void StateManager::AddState( State* state ){
    states.push( state ); 
    state->stateman = this;
}
void StateManager::PopState( ) {
    states.pop( );
}

void StateManager::Update( float dt ){ 
    states.front( )->Update( dt ); 
}

void StateManager::Draw( ){
    // clear out the buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    states.front( )->Draw( );     
}

StateManager::~StateManager( ) { 
    while( !states.empty() ){
        State* s = states.front( );
    	states.pop();
    	delete s;
    }
}