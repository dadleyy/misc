#ifndef _S3D_PLAYER_H
#define _S3D_PLAYER_H

#include "includes.h"
#include "game-object.h"

class Drawable;
class PlayerControl;
class Transformer;
class PhysicsComponent;

class Player : public GameObject {

public:
    Player( );
    ~Player( );
    
    void Draw( );
    
private:
    Drawable* drawable;
    PlayerControl* controller;
    Transformer* transform;
    PhysicsComponent* physics;
};

#endif
