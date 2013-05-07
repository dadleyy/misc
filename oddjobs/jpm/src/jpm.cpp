/* Author: Danny Hadley
 * Date: Spring 2013
*/
#include "jpm.h"

JPM::JPM( ) : outfile("out.js"), infile(""), usingserver(false), ready(false) {
    
}

JPM::~JPM( ) {
    
}

// getters and setters
void JPM::set_outfile(string filen){ outfile = filen; CheckReady( ); }
void JPM::set_infile(string filen){ infile = filen; CheckReady( ); }
void JPM::set_server(string serveri){
    serverinfo = serveri;
    usingserver = true;
    CheckReady( );
}

/*
 *
*/
void JPM::CheckReady( ){
    if( outfile == "" || infile == "" )
        ready = false;
    else
        ready = true;
}

int JPM::run( ) {
    
    if( usingserver ){
        JPMConnection up(serverinfo);
    }
    
    JPM::print("");
    return 1;
}

/*
 *
*/
int JPM::execute( int argc, char* argv[ ] ){

    JPM::print( JPM_WELCOME );    
    
    // ready the jpm object
    JPM man;
    // make sure at least the input was passed in
    if( argc < 2 )
        return JPM::print( JPM_ERR_NOARG );
    
    //           
    if( !man.ready )
        return JPM::print( JPM_ERR_NOREADY );
        
    return man.run( );
}


/*
 *
*/
int JPM::print(string msg){
    cout << msg << endl;
    return 0;
}

