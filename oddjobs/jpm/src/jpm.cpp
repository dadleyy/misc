/* Author: Danny Hadley
 * Date: Spring 2013
*/
#include "jpm.h"

JPM::JPM( ) : outfile(""), infile("") {
    
}

JPM::~JPM( ) {
    
}

void JPM::set_outfile(string filen){ outfile = filen; }
void JPM::set_infile(string filen){ infile = filen; }

/*
 *
*/
int JPM::execute( int argc, char* argv[ ] ){

    JPM::print( JPM_WELCOME );    
    
    // ready the jpm object
    JPM man;
    // make sure at least the input was passed in
    if( argc < 2 )
        return JPM::print( JPM_ERR );
    
    // grab the first argument
    string farg = argv[1];
    // if it is not a flag, set it as the infile
    if( farg[1] != '-' )
        man.set_infile( farg );
        
    
    for(int i = 1; i < argc; i++){
        if( (string)argv[i] == "-o" && i < argc - 1 ){
            man.set_outfile( (string)argv[i+1] );
        } else if( (string)argv[i] == "--help" ){
            return JPM::print( JPM_HELP );
        } else {   
            
        }
    }
    return 0;
}


/*
 *
*/
int JPM::print(string msg){
    cout << msg;
    return 0;
}