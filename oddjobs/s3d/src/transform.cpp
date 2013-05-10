#include "transform.h"
#include "game-object.h"
#include <iostream>

Transformer::Transformer( SVector3 initialposition, SVector3 initialrotation, SVector3 initialscale ){
    position = initialposition;
    rotation = initialrotation;
    scale = initialscale;
}

void Transformer::Update( float dt ){
    
}

void Transformer::Init( GameObject* go ){
}