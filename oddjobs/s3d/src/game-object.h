#ifndef _S3D_GAME_OBJECT
#define _S3D_GAME_OBJECT

#include <vector>
#include "component.h"

class GameObject {

public: 
    ~GameObject( );
    
    template <class T>
    T* GetComponent( );
    
    void Init( );
    void Update( float dt );
    void Draw( );
    
protected:
    std::vector<Component*> components;
    
};

#endif
