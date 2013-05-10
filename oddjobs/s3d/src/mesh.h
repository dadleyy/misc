#ifndef _S3_MESH_H
#define _S3_MESH_H

#include <vector>
#include "s3math.h"

class Mesh {
    
public:
    Mesh( );
    ~Mesh( );
    
    std::vector<SVector3> verts;
};

#endif