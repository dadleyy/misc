#ifndef _S3D_PLAYER_CONTROL_H
#define _S3D_PLAYER_CONTROL_H

#include "includes.h"
#include "component.h"

class GameObject;
extern bool keystates[256];

class PlayerControl : public Component {
    
public:
    void Init( GameObject* go );
    void Update( float dt );
};

#endif