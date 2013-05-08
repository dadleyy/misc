#ifndef _S3D_MATH_H
#define _S3D_MATH_H

#include <cmath>

class SVector3 {

public:

    SVector3( );
    SVector3( float x, float y, float z );
    ~SVector3( );
    
    // operator overloads
    SVector3 operator+(SVector3);
    SVector3 operator*(SVector3);
    SVector3 operator*(float scale);
    
    float x;
    float y;
    float z;

};

#endif