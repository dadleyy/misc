#include "Utils/utils.h"
#include "Application/Application.h"

void keyboard ( unsigned char key, int mousePositionX, int mousePositionY ) {
    cout << key << endl;
}

int main (int argc, char* argv[]) {
    
    cout << "Program Three: Messing around with OpenGL" << endl;
    utils::printArgs(argc, argv);
    
    Application app;
    
    app.init( argc, argv );

    
    
    return app.run( );
}
