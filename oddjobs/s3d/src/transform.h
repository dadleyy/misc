#ifndef _S3D_TRANSFORM_H
#define _S3D_TRANSFORM_H

#include "includes.h"
#include "component.h"
#include "s3math.h"

class GameObject;
extern bool keystates[256];

class Transformer : public Component {
    
public:
    Transformer( SVector3 initialposition, SVector3 initialrotation );
    void Init( GameObject* go );
    void Update( float dt );
    
    SVector3 position;
    SVector3 rotation;
    
private:

};

#endif