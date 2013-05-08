#ifndef _S3D_TRANSFORM_H
#define _S3D_TRANSFORM_H

#include "includes.h"
#include "component.h"

class GameObject;
extern bool keystates[256];

class Transformer : public Component {
    
public:
    void Init( GameObject* go );
    void Update( float dt );
};

#endif