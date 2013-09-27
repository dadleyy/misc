#include "menu-state.h"
#include "state-manager.h"

MenuState::MenuState( ){ }
MenuState::~MenuState( ){ }

void MenuState::Update( float dt ){
    if( mouse.down )
        stateman->PopState( );   
}

void MenuState::Draw( ) {
    
}