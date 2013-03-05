/* ***************************************** *
 * App.cpp                                   *
 * Author: Danny Hadley <danny@dadleyy.com>  *
 * Date: Spring 2013                         *
 * License:                                  *
 * Copyright 2013 under the MIT liscense     *
 * ***************************************** */
#include "App.h"

App::App() {
    cout << "-[ Creating an Application object ]-" << endl;
    
    r_top = r_left = -0.5f;
    r_bottom = r_right = 0.5f;
    
    for( int i = 0; i < 255; i++ ) {
        a_keys[i] = false;
    }
    
}
App::~App() { }

void App::update() {
    
    if( a_keys[119] ) {
        r_top += 0.001f;
        r_bottom += 0.001f;
    }
    if( a_keys[115] ) {
        r_top -= 0.001f;
        r_bottom -= 0.001f;
    }
    if( a_keys[97] ) {
        r_left -= 0.001f;
        r_right -= 0.001f;
    }
    if( a_keys[100] ) {
        r_left += 0.001f;
        r_right += 0.001f;
    }
    
    
    render( );
}


void App::render() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        

    glBegin( GL_QUADS );
    glColor3f( 1.f, 0.f, 0.f ); glVertex2f( r_left,  r_top );
    glColor3f( 1.f, 1.f, 0.f ); glVertex2f( r_right, r_top );
    glColor3f( 0.f, 1.f, 0.f ); glVertex2f( r_right, r_bottom );
    glColor3f( 0.f, 0.f, 1.f ); glVertex2f( r_left,  r_bottom );
    glEnd();
    
    glutSwapBuffers( );

}


void App::resize( int width, int height ) {
    cout << "[Resizing to: (" << width << "," << height << ") ]" << endl;
    if ( height == 0 ) { height = 1; }
    a_screenWidth  = width;
    a_screenHeight = height;

    glViewport( 0.f, 0.f, a_screenWidth, a_screenHeight );
    glMatrixMode( GL_PROJECTION );
    
}


void App::keyManager( unsigned char key, bool isup ) {
    if( (int)key == 27 && !isup ) { exit(1); }
    
    if( a_keys[key] != isup && (int)key < 255 ) {
        a_keys[key] = isup;
        cout << "[Handling keyboard input: " << key << " | " << (int)key << " up: " << isup << "]" << endl;
    }
}