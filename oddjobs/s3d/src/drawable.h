#ifndef _S3D_DRAWABLE_H
#define _S3D_DRAWABLE_H

#include "includes.h"
#include "component.h"

class Drawable : public Component {
    
public:
    Drawable( );
    ~Drawable( );
    
    void Update( float dt );
    void Draw( );  
    
};

#endif