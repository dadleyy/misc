#ifndef _S3_CAMERA_H
#define _S3_CAMERA_H

#include "includes.h"
#include "s3math.h"
#include "transform.h"

class Camera {
    
public:
    Camera( );
    ~Camera( );
    void Update( float dt );
    void SetWindow( int width, int height );
    void Follow( Transformer* transform );
};

#endif