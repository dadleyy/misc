#include "player.h"
#include "drawable.h"
#include "player-control.h"
#include "transform.h"
#include "physics-component.h"
#include "s3math.h"

Player::Player( ){ 
    std::cout << "making the player" << std::endl;
    
    drawable = new Drawable( );
    controller = new PlayerControl( );
    transform = new Transformer( SVector3(0,0,-10), SVector3(0,0,0), SVector3(1.0f,1.0f,1.0f) );
    physics = new PhysicsComponent( );
    
    components.push_back( drawable );
    components.push_back( controller );
    components.push_back( transform );
    components.push_back( physics );
}

void Player::Draw( ){
    drawable->Draw( );
}

Player::~Player( ){ 
    delete drawable;
    delete controller;
    delete transform;
}