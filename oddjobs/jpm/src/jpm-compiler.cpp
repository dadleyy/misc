#include "jpm-compiler.h"
#include <sstream>

void JPMCompiler::Prepare( ) {
    int hr;
    hr = regcomp( &JPMCompiler::r_line, "/(.*)\n/", 0 );    
}

int JPMCompiler::Compile( JPM* out ) {

    std::string ifile_n = out->get_infile( );
    std::string ofile_n = out->get_outfile( );
    
    FILE* ifile_h;
    FILE* ofile_h;
    char* obuffer = 0;
    char* ibuffer = 0;
    
    // try opening up the input file
    ifile_h = fopen( ifile_n.c_str( ), "r" );
    if( ifile_h == NULL )
        return JPM::Print("could not open input file");
    else 
        rewind( ifile_h );
    
    int icount = JPMCompiler::CharCount( ifile_h );
    // allocate the appropriate memory
    ibuffer = (char*) calloc( icount, sizeof(char) );
    // save the file into the buffer
    fread( ibuffer, sizeof(char)*icount, icount, ifile_h );
    
    JPM::Print( ibuffer );
            
    // garbage collection
    fclose( ifile_h );
    if( ibuffer != 0 )
        free( ibuffer );
    if( obuffer != 0 )
        free( obuffer );
    return 1;
}

int JPMCompiler::CharCount( FILE* file ) {
    char c; 
    int a = 0;
    rewind( file );
    
    do { 
        c = fgetc( file );
        if( c == '\n' )
            std::cout << "FOUND NEW LINE CHARACTER" << std::endl;
        a++;
    } while (c != EOF);
    
    rewind( file );
    return a;
}