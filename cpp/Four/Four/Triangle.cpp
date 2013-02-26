/* ***************************************** *
 * Triangle.cpp                              *
 * Author: Danny Hadley <danny@dadleyy.com>  *
 * Date: Spring 2013                         *
 * License:                                  *
 * Copyright 2013 under the MIT liscense     *
 * ***************************************** */
#include "Triangle.h"
Triangle::Triangle( ) {
    vertex v1, v2, v3;
    
    
    v1 = { -0.5f, -0.5f, 0.0f };
    v2 = { 0.5f, 0.0f, 0.0f };
    v3 = { 0.0f, 0.5f, 0.0f };
    
    t_verts[0] = v1;
    t_verts[1] = v2;
    t_verts[2] = v3;
    
}
Triangle::~Triangle( ) {
    
}


void Triangle::render( ) {
    glBegin( GL_TRIANGLES );
    
    for( int i = 0; i < 3; i++ ) {
        glVertex3f( t_verts[i].x, t_verts[i].y, t_verts[i].z );
    }
    
    glEnd();
}
