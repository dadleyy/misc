/* ***************************************** *
 * App.h                                     *
 * Class definition.                         *
 *                                           *
 * Author: Danny Hadley <danny@dadleyy.com>  *
 * Date: Spring 2013                         *
 * License:                                  *
 * Copyright 2013 under the MIT liscense     *
 * ***************************************** */
#ifndef __Four__App__
#define __Four__App__

#include "Utils.h"
#include "Triangle.h"

class App {

public:
    
    App( );
    ~App( );

    void update( );
    void keyManager( unsigned char key, bool isup );
    
private:
    
    void render( );
    
    bool a_ready = false;
    bool a_keys[255];
    
    Triangle a_tri;

};

#endif