#include "s3math.h"

SVector3::SVector3( ){ 
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}
SVector3::SVector3( float x, float y, float z ){
    x = x;
    y = y;
    z = z;
}

SVector3 SVector3::operator+ (SVector3 other){
    SVector3 temp;
    temp.x = x + other.x;
    temp.y = y + other.y;
    temp.z = z + other.z;
    return temp;
}

SVector3 SVector3::operator* (SVector3 other){
    SVector3 temp;
    
    return temp;
}

SVector3 SVector3::operator* (float scale){
    SVector3 temp;
    temp.x = x * scale;
    temp.y = y * scale;
    temp.z = z * scale;
    return temp;   
}


SVector3::~SVector3( ){ }