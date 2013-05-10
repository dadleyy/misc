#ifndef _S3_MENU_ITEM_H
#define _S3_MENU_ITEM_H

#include "includes.h"
#include "game-object.h"
extern Mouse mouse;
class Drawable;
class Transformer;

class MenuItem : public GameObject {
    
public:
    MenuItem( );
    ~MenuItem( );
    
    void Update( float dt );
    void Draw( );
    
private: 
    Transformer* transform;
    Drawable* drawable;
    
};


#endif