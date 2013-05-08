#include "game-object.h"

template <class T>
T* GameObject::GetComponent( ){
    for(int i = 0; i < components.size( ); i++){
        void* result = dynamic_cast<T*>( *components.at(i) );
            if( result != NULL )
                 return result;
    }
    return NULL;
}

void GameObject::Init( ){
    for( int i = 0; i < components.size( ); i++ ){
        components.at(i)->Init( this );
    }
}

void GameObject::Draw( ){ }

void GameObject::Update( float dt ){
    for( int i = 0; i < components.size( ); i++ ){
        components.at(i)->Update( dt );
    }
}

GameObject::~GameObject( ){ 
    for( int i = 0; i < components.size( ); i++ ){
        delete components.at( i );
    } 
}