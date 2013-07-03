#include "camera.h"

Camera::Camera( ){ }
void Camera::Update( float dt ){
    
}
void Camera::SetWindow( int width, int height ){
    
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    gluPerspective( 20, width / (float) height, 5, 15 );
    glViewport( 0, 0, width, height );
    glMatrixMode( GL_MODELVIEW );
    glutPostRedisplay( );
    
}

void Camera::Follow( Transformer* transform ){
    
}

Camera::~Camera( ){ }