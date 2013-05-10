#include "player-control.h"
#include "game-object.h"
#include "transform.h"


void PlayerControl::Init( GameObject* go ){
    ok = false;
    transform = go->GetComponent<Transformer>( &ok ); 
}

void PlayerControl::Update( float dt ){

    if( keystates[100] )
        transform->rotation.y += 0.21f;
    if( keystates[97] )
        transform->rotation.y -= 0.21f;
    if( keystates[119] )
        transform->rotation.x -= 0.21f;
    if( keystates[115] )
        transform->rotation.x += 0.21f;

}