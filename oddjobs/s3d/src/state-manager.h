#ifndef _S3D_STATE_MANAGER_H
#define _S3D_STATE_MANAGER_H

#include "includes.h"
#include <deque>
#include <list>
#include <queue>
#include "state.h"

class StateManager {

public:
    StateManager( );
    ~StateManager( );
    
    void Update( float dt );
    void Draw( );
    void AddState( State* state );
    
private:
    std::queue<State*> states; 

};

#endif