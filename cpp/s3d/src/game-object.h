#ifndef _S3D_GAME_OBJECT
#define _S3D_GAME_OBJECT

#include "includes.h"
#include <vector>
#include "component.h"
class Transformer;

class GameObject {

public: 
    ~GameObject( );
    
    template <class T>
    T* GetComponent( bool* ok ){
        bool found = false;
        for( int i = 0; i < components.size( ); i++ ){
            Component* c = components.at( i );
            if( dynamic_cast<T*>( c ) != NULL ){
                T* result = dynamic_cast<T*>( c );
                (*ok) = true; 
                return result;
            }
        }
        return NULL;  
    };
     
    void Init( );
    void Update( float dt );
    void Draw( );
    
protected:
    std::vector<Component*> components;
    
};

#endif
