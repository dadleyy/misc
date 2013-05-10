#include "s3math.h"
#include <iostream>

SVector3::SVector3( ) { 
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

SVector3::SVector3( float x, float y, float z ){
    x = x;
    y = y;
    z = z;
}

    
SVector3::~SVector3( ){ }