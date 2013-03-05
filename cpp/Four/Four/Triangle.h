/* ***************************************** *
 * Triangle.h                                *
 * Class definition.                         *
 *                                           *
 * Author: Danny Hadley <danny@dadleyy.com>  *
 * Date: Spring 2013                         *
 * License:                                  *
 * Copyright 2013 under the MIT liscense     *
 * ***************************************** */
#ifndef __Four__Triangle__
#define __Four__Triangle__

#include "Utils.h"

class Triangle {
    
public:
    Triangle( );
    ~Triangle( );
    
    void render( );
    vertex t_verts[3];
    
};



#endif /* defined(__Four__Triangle__) */
