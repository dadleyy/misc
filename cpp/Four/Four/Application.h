/* ***************************************** *
 * Application.h                             *
 * Sets up a namespace that will take care   *
 * of the communication between openGL and   *
 * the App class instance                    *
 *                                           *
 * Author: Danny Hadley <danny@dadleyy.com>  *
 * Date: Spring 2013                         *
 * License:                                  *
 * Copyright 2013 under the MIT liscense     *
 * ***************************************** */
#ifndef __Four__Application__
#define __Four__Application__

#include "Utils.h"
#include "App.h"

namespace Application {
    
    int init( int argc, char *argv[] );
    void update( );
    void keyDown( unsigned char key, int x, int y );
    void keyUp( unsigned char key, int x, int y );
    void resize( int width, int height );
  
    static App *app;
};

#endif
