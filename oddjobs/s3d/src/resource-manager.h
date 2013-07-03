#ifndef _S3_RESOURCE_MANAGER_H
#define _S3_RESOURCE_MANAGER_H

#include "includes.h"
#include <map>

struct ShaderHandle {
    
};

class ResourceManager {

public:
    ResourceManager( );
    ~ResourceManager( );
    void LoadShader( char* filename );
    
    std::map<char*,ShaderHandle*> shaders;
    
};

#endif