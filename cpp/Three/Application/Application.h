#ifndef APPLICATION_H
#define APPLICATION_H

#include "../utils/utils.h"

class Application {
    
    public:
        /**/
        Application( );  // Constructor
        ~Application( ); // Destructor
        
        /**/
        void init( int argc, char *argv[] );
        int run( );
        void update( );
        void keyManager( unsigned char key, int mX, int mY );
        
        int version;
        
    private: 
        
        int   windowWidth;
        int   windowHeight;
        char  *windowName;
        
};

#endif