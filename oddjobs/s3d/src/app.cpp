#include "app.h"

App* instance;
bool keystates[256];
Mouse mouse;

void G_Update( ){
    instance->c_time = time(0) * 1000.0f;
    long dt = instance->c_time - instance->l_time;
    if( dt < MIN_TIME_DIFF )
        dt = MIN_TIME_DIFF;
    instance->Update( (float)dt );
}

void G_Resize( int width, int height ){
    instance->set_window_height( height );
    instance->set_window_width( width );
    instance->Resize( );
}

void G_Keyman( unsigned char key, int x, int y ){
    keystates[ (int)key ] = true;
}

void G_Keyup( unsigned char key, int x, int y ){
    keystates[ (int)key ] = false;
}

void G_Mouseman( int button, int state, int x, int y ){
    mouse.down = state;
}

void G_Mousemove( int x, int y ){
    mouse.x = x;
    mouse.y = y;
}

// Constructor
App::App( int argc, char* argv[ ] ) : window_height(600), window_width(800), l_time(0), c_time(0) {
    // add the states
    statemanager.AddState( new MenuState( ) );
    statemanager.AddState( new GameState( ) );
    // set up all the glut functions
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH );
    glutInitWindowSize( window_width , window_height );
    glutInitWindowPosition( 100, 100 ); 
    glutCreateWindow( "S3D" );
    glClearColor( 0.33f, 0.33f, 0.33f, 1.0f );
    glEnable( GL_DEPTH_TEST );
    
    instance = this;
}

void App::set_window_height( int height ) { window_height = height; }
void App::set_window_width( int width ) { window_width = width; }

// App.Run
int App::Run( ){
    glutDisplayFunc( G_Update );
    glutReshapeFunc( G_Resize );
    glutKeyboardFunc( G_Keyman );
    glutKeyboardUpFunc( G_Keyup );
    glutMouseFunc( G_Mouseman );
    glutMotionFunc( G_Mousemove );
    glutPassiveMotionFunc( G_Mousemove );
    Resize( );
    //glutIdleFunc( G_Update );
    glutMainLoop( );
    return 1;    
}

void App::Update( float dt ){
    // update
    statemanager.Update( dt );
    statemanager.Draw( );
    glutSwapBuffers( );
    glutPostRedisplay( );
}

void App::Resize( ){
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    gluPerspective( 20, window_width / (float) window_height, 5, 15 );
    glViewport( 0, 0, window_width, window_height );
    glMatrixMode( GL_MODELVIEW );
    glutPostRedisplay( );
}

// destructor
App::~App( ){ }