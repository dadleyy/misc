/* Author: Danny Hadley
 * Date: Spring 2013
*/
#include "jpm.h"
#include "jpm-compiler.h"
#include "jpm-connection.h"
#include "jpm-parser.h"

// //////////////////// //
// JPM CLASS FUNCTIONS  //
JPM::JPM( ) : outfile("out.js"), infile(""), usingserver(false), ready(false) { 
    
}
JPM::~JPM( ) { }

// jpm getters and setters
void JPM::set_outfile(std::string filen){ outfile = filen; CheckReady( ); }
void JPM::set_infile(std::string filen){ infile = filen; CheckReady( ); }
void JPM::set_server(std::string serveri){
    serverinfo = serveri;
    usingserver = true;
    CheckReady( );
}
std::string JPM::get_outfile( ){ return outfile; }
std::string JPM::get_infile( ){ return infile; }

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
int JPM::Run( std::string command ) {
    if( command == "compile" )
        return JPMCompiler::Compile( this );
    else if( command == "upload" )
        return 1;
    else
        return 1;
}

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
    std::string command = argv[1];
    if( command == "init" ){
        
    } else {
        JPMParser::FromPackage( &man );
    }
    
    JPMCompiler::Prepare( );
    return man.Run( command );
}

/* JPM::Print
 * writes out a message to the console
*/
int JPM::Print( std::string msg ){
    std::cout << msg << std::endl;
    return 0;
}

