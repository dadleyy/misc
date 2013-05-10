#ifndef _S3D_DRAWABLE_H
#define _S3D_DRAWABLE_H

#include "component.h"
class GameObject;
class Transformer;

class Drawable : public Component {
    
public:
    void Init( GameObject* go );
    void Draw( );  
    
private:

    Transformer* transform;
    
};

#endif