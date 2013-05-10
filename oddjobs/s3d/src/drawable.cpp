#include "drawable.h"
#include "game-object.h"
#include "transform.h"

void Drawable::Init( GameObject* go ) {
    ok = false;
    transform = go->GetComponent<Transformer>( &ok );
    
}

void Drawable::Draw( ){

    // quads
    glBegin(GL_QUADS);
    // start making verts
    glColor3f(0, 0, 0); glVertex3f(-1, -1, -1);
    glColor3f(0, 0, 1); glVertex3f(-1, -1,  1);
    glColor3f(0, 1, 1); glVertex3f(-1,  1,  1);
    glColor3f(0, 1, 0); glVertex3f(-1,  1, -1);
    
    glColor3f(1, 0, 0); glVertex3f( 1, -1, -1);
    glColor3f(1, 0, 1); glVertex3f( 1, -1,  1);
    glColor3f(1, 1, 1); glVertex3f( 1,  1,  1);
    glColor3f(1, 1, 0); glVertex3f( 1,  1, -1);
    
    glColor3f(0, 0, 0); glVertex3f(-1, -1, -1);
    glColor3f(0, 0, 1); glVertex3f(-1, -1,  1);
    glColor3f(1, 0, 1); glVertex3f( 1, -1,  1);
    glColor3f(1, 0, 0); glVertex3f( 1, -1, -1);
    
    glColor3f(0, 1, 0); glVertex3f(-1,  1, -1);
    glColor3f(0, 1, 1); glVertex3f(-1,  1,  1);
    glColor3f(1, 1, 1); glVertex3f( 1,  1,  1);
    glColor3f(1, 1, 0); glVertex3f( 1,  1, -1);
    
    glColor3f(0, 0, 0); glVertex3f(-1, -1, -1);
    glColor3f(0, 1, 0); glVertex3f(-1,  1, -1);
    glColor3f(1, 1, 0); glVertex3f( 1,  1, -1);
    glColor3f(1, 0, 0); glVertex3f( 1, -1, -1);
    
    glColor3f(0, 0, 1); glVertex3f(-1, -1,  1);
    glColor3f(0, 1, 1); glVertex3f(-1,  1,  1);
    glColor3f(1, 1, 1); glVertex3f( 1,  1,  1);
    glColor3f(1, 0, 1); glVertex3f( 1, -1,  1);
    
    // finished passing vers
    glEnd( );
    // render the glu data
    glFlush( );
}
