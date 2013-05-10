#include "s3math.h"
#include <iostream>

SVector3::SVector3( ) : x(0.0f), y(0.0f), z(0.0f) { }
SVector3::SVector3( float _x, float _y, float _z ){
    x = _x;
    y = _y;
    z = _z;
}

SVector4::SVector4( ) : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { }
SVector4::SVector4( float _x, float _y, float _z, float _w ){
    x = _x;
    y = _y;
    z = _z;
    w = _w;
}

SVector4::~SVector4( ){ }
SVector3::~SVector3( ){ }