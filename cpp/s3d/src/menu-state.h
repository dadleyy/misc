#ifndef _S3_MENU_STATE_H
#define _S3_MENU_STATE_H

#include "includes.h"
#include "state.h"
#include <vector>
extern Mouse mouse;
class MenuItem;

class MenuState : public State{

public:
    MenuState( );
    ~MenuState( );

    void Update( float dt );
    void Draw( );
    
private:
    std::vector<MenuItem*> menuitems;

};

#endif