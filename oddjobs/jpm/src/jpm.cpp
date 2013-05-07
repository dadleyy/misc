/* Author: Danny Hadley
 * Date: Spring 2013
*/
#include "jpm.h"

// //////////////////// //
// JPM CLASS FUNCTIONS  //
JPM::JPM( ) : outfile("out.js"), infile(""), usingserver(false), ready(false) { 
    
}
JPM::~JPM( ) { }

/* jpm getters and setters
*/
void JPM::set_outfile(string filen){ outfile = filen; CheckReady( ); }
void JPM::set_infile(string filen){ infile = filen; CheckReady( ); }
void JPM::set_server(string serveri){
    serverinfo = serveri;
    usingserver = true;
    CheckReady( );
}

/* jpm.CheckReady
 * checks to see if the manager has all the necessary info
*/
void JPM::CheckReady( ){
    if( outfile == "" || infile == "" )
        ready = false;
    else
        ready = true;
}

/* jpm.Run
 * accepts a string and runs it as a command
 * @param {string} command 
*/
int JPM::Run( string command ) {
    if( command == "compile" )
        return Compile( );
    else if( command == "upload" )
        return Upload( );
    else
        return 1;
}

int JPM::Compile( ) { }
int JPM::Upload( ) { }


// ///////////////////// //
// JPM STATIC FUNCTIONS  //

/* JPM::Execute
 * called from the main function
*/
int JPM::Execute( int argc, char* argv[ ] ){

    JPM::Print( JPM_WELCOME );    
    
    // ready the jpm object
    JPM man;
    // make sure at least the input was passed in
    if( argc < 2 )
        return JPM::Print( JPM_ERR_NOARG );
    
    // grab the first agument
    string command = argv[1];
    if( command == "init" )
        man = JPM( );
    else 
        JPMParser::FromPackage( &man );

    return man.Run( command );
}

/* JPM::Print
 * writes out a message to the console
*/
int JPM::Print(string msg){
    cout << msg << endl;
    return 0;
}

