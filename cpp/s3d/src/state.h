#ifndef _S3D_STATE
#define _S3D_STATE

#include "includes.h"
class StateManager;

class State {

public:
    virtual void Update( float dt ) = 0;
    virtual void Draw( ) = 0;
    StateManager* stateman;
    
};

#endif