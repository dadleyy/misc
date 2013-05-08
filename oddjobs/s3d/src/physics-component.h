#ifndef _S3D_PHYSICS_H
#define _S3D_PHYSICS_H

#include "includes.h"
#include "component.h"

class GameObject;

class PhysicsComponent : public Component {
    
public:
    void Init( GameObject* go );
    void Update( float dt );
    
};

#endif