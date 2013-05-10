#ifndef _S3D_COMPONENT_H
#define _S3D_COMPONENT_H

class GameObject;

class Component {

public:
    virtual void Init(GameObject* go);
    virtual void Update( float dt );
    void Draw( );

protected:
    bool ok;

};

#endif
