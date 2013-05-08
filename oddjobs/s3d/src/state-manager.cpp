#include "state-manager.h"

StateManager::StateManager( ){ }

void StateManager::AddState( State* state ){
    states.push( state ); 
}

void StateManager::Update( float dt ){ 
    states.front( )->Update( dt ); 
}

void StateManager::Draw( ){
    states.front( )->Draw( );     
}

StateManager::~StateManager( ) { 
    while( !states.empty() ){
        State* s = states.front( );
    	states.pop();
    	delete s;
    }
}