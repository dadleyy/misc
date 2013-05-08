#ifndef _S3D_APP_H
#define _S3D_APP_H

#define MIN_TIME_DIFF 0.01f

#include "includes.h"
#include "state-manager.h";
#include "game-state.h";

class App {
    
public:    
    App( int argc, char* argv[ ] );
    ~App( );
    int Run( );
    
    void Update( float dt );
    void Resize( );
    
    void set_window_height( int height );
    void set_window_width( int height );
    
    long double c_time;
    long double l_time;
    
private:
    int window_height;
    int window_width;
    StateManager statemanager;
};

#endif