#include "drawable.h"
#include "game-object.h"
#include "transform.h"

Drawable::Drawable( ) : drawmode(GL_QUADS){ 
    
}
Drawable::~Drawable( ){ }

void Drawable::Init( GameObject* go ){
    ok = false;
    transform = go->GetComponent<Transformer>( &ok );  
}

void Drawable::Draw( ){
    
    glLoadIdentity( );
    
    glTranslatef( transform->position.x, transform->position.y, transform->position.z );
    glRotatef( transform->rotation.x, 1, 0, 0 );
    glRotatef( transform->rotation.y, 0, 1, 0 );
    glRotatef( transform->rotation.z, 0, 1, 0 );
    
    // quads
    glBegin( drawmode );
    
    for( int i = 0; i < mesh.verts.size( ); i++ ){
        SVector3 v = mesh.verts.at( i );
        glColor3f( 1, 0.5, 0); 
        glVertex3f( v.x * transform->scale.x, v.y * transform->scale.y, v.z * transform->scale.z);
    }
    
    // finished passing vers
    glEnd( );
    // render the glu data
    glFlush( );
}
