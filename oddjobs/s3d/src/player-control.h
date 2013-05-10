#ifndef _S3D_PLAYER_CONTROL_H
#define _S3D_PLAYER_CONTROL_H

#include "component.h"
class GameObject;
class Transformer;

extern bool keystates[256];

class PlayerControl : public Component {
    
public:
    void Init( GameObject* go );
    void Update( float dt );

private:
    Transformer* transform;    

};

#endif