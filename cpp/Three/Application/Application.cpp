#include "Application.h"

Application::Application() {
    cout << "[Application: Creating]" << endl;
    
    windowWidth  = 800;
    windowHeight = 600;
    windowName   = (char*)"Program Three";
    
}

Application *cApp;
void cUpdate( ) { cApp->update(); }
void cKeyman( unsigned char key, int x, int y ){ cApp->keyManager( key, x, y ); }
void Application::init( int argc, char *argv[] ) {    
    cout << "[Application: Initializing..]" << endl;
    
    cApp = this;

    // initialize and run program
    glutInit( &argc, argv );                                    // GLUT initialization
	glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH ); // Display Mode
	glutInitWindowSize( windowWidth, windowHeight );			// set window size
	glutCreateWindow( windowName );						        // create Window
	glutDisplayFunc( cUpdate );                                 // register Display Function
	glutIdleFunc( cUpdate );						            // register Idle Function
    glutKeyboardFunc( cKeyman );					            // register Keyboard Handler
}

int Application::run(void) {
    glutMainLoop( );	
    return 1;
} 

void Application::keyManager( unsigned char key, int mX, int mY ) {
    char a[2] = { (char)key, '\0' };
    string value = ( key == 27 ) ? (string)"escape" : (string)a;
    cout << "[Key press: " << value << "]" << endl;
    if( value == "escape" ){ exit(1); }
}

void Application::update( ) {   
    // cout << "[Application: Updating]" << endl;
}


Application::~Application() { 
    cout << "[Application: Deleting]" << endl;
}
