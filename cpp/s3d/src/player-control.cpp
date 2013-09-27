#include "player-control.h"
#include "game-object.h"
#include "transform.h"
#include "camera.h"
extern Camera camera;

void PlayerControl::Init( GameObject* go ){
    ok = false;
    transform = go->GetComponent<Transformer>( &ok ); 
}

void PlayerControl::Update( float dt ){

    if( keystates[100] )
        transform->rotation.x += 0.11f;
    if( keystates[97] )
        transform->rotation.x -= 0.11f;
    if( keystates[119] )
        transform->position.z -= 0.11f;
    if( keystates[115] )
        transform->position.z += 0.11f;

    camera.Follow( transform );
}