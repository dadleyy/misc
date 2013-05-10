#include "transform.h"
#include "game-object.h"
#include <iostream>

Transformer::Transformer( SVector3 initialposition, SVector3 initialrotation ){
    position = initialposition;
    rotation = initialrotation;
}

void Transformer::Update( float dt ){
    
}

void Transformer::Init( GameObject* go ){
}