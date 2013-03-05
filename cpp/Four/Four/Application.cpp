/* ***************************************** *
 * Application.cpp                           *
 * Author: Danny Hadley <danny@dadleyy.com>  *
 * Date: Spring 2013                         *
 * License:                                  *
 * Copyright 2013 under the MIT liscense     *
 * ***************************************** */
#include "Application.h"
int Application::init( int argc, char *argv[] ) {

    glutInit( &argc, argv );
    
    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH );
    glutInitWindowSize( 800, 600 );
    glutInitWindowPosition( 100, 100 );
    
    glutCreateWindow( "Program Four" );
    
    /* attatch the event callbacks */
    glutIdleFunc( update );
    glutDisplayFunc( update );
    glutKeyboardFunc( keyDown );
    glutKeyboardUpFunc( keyUp );
    glutReshapeFunc( resize );
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    
    app = new App( );

    glutMainLoop( );
    
    free( app );
    
    return 0;
}
void Application::update() { app->update(); }
void Application::resize( int width, int height ) { app->resize( width, height ); }
void Application::keyDown( unsigned char key, int x, int y ) { app->keyManager( key , true ); }
void Application::keyUp( unsigned char key, int x, int y ) { app->keyManager( key, false ); }

