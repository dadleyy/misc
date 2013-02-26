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
}
App::~App() { }

void App::update() {
    render( );
}


void App::render() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    a_tri.render( );

    glutSwapBuffers();

}

void App::keyManager( unsigned char key, bool isup ) {
    if( (int)key == 27 && !isup ) { exit(1); }
    
    if( a_keys[key] != isup ) {
        a_keys[key] = isup;
        cout << "[Handling keyboard input: " << key << " up: " << isup << "]" << endl;
    }
}