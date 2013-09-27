#include "mesh.h"

Mesh::Mesh( ){ 
    
    verts.push_back( SVector3( -1, -1, -1 ) );
    verts.push_back( SVector3(-1, -1,  1) );
    verts.push_back( SVector3(-1,  1,  1) );
    verts.push_back( SVector3(-1,  1, -1) );
    
    verts.push_back( SVector3( 1, -1, -1) );
    verts.push_back( SVector3( 1, -1,  1) );
    verts.push_back( SVector3( 1,  1,  1) );
    verts.push_back( SVector3( 1,  1, -1) );
    
    verts.push_back( SVector3(-1, -1, -1) );
    verts.push_back( SVector3(-1, -1,  1) );
    verts.push_back( SVector3( 1, -1,  1) );
    verts.push_back( SVector3( 1, -1, -1) );
    
    verts.push_back( SVector3(-1,  1, -1) );
    verts.push_back( SVector3(-1,  1,  1) );
    verts.push_back( SVector3( 1,  1,  1) );
    verts.push_back( SVector3( 1,  1, -1) );
    
    verts.push_back( SVector3(-1, -1, -1) );
    verts.push_back( SVector3(-1,  1, -1) );
    verts.push_back( SVector3( 1,  1, -1) );
    verts.push_back( SVector3( 1, -1, -1) );
    
    verts.push_back( SVector3(-1, -1,  1) );
    verts.push_back( SVector3(-1,  1,  1) );
    verts.push_back( SVector3( 1,  1,  1) );
    verts.push_back( SVector3( 1, -1,  1) );
}

Mesh::~Mesh( ){ }
