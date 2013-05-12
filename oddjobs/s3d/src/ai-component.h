#ifndef _S3_AI_COMPONENT_H
#define _S3_AI_COMPONENT_H

#include "component.h"
class GameObject;
class Transform;

class AIComponent : public Component {
  
public:
    AIComponent( );
    ~AIComponent( );
    
    void Init( GameObject* go );
    void Update( float dt );
    
};

#endif