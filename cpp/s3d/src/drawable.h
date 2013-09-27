#ifndef _S3D_DRAWABLE_H
#define _S3D_DRAWABLE_H

#include "includes.h"
#include "component.h"
#include "mesh.h"
class GameObject;
class Transformer;

class Drawable : public Component {
    
public:
    Drawable( );
    ~Drawable( );
    void Init( GameObject* go );
    void Draw( );
    
private:
    GLenum drawmode;
    Transformer* transform;
    Mesh mesh;
    
};

#endif