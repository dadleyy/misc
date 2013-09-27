#ifndef _S3D_MATH_H
#define _S3D_MATH_H

#include <cmath>

class SVector3 {

public:

    SVector3( );
    SVector3( float _x, float _y, float _z );
    ~SVector3( );
    
    float x;
    float y;
    float z;

};

class SVector4 {

public: 
    SVector4( );
    SVector4( float _x, float _y, float _z, float _w );
    ~SVector4( );
    
    float x;
    float y;
    float z;
    float w;
    
};

#endif