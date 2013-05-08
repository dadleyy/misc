#include "jpm-parser.h"

/* JPMParser::FromPackage
 * attempts to read in the information from a package.json file
 * @param {JPM*} a pointer to a manager
*/
int JPMParser::FromPackage( JPM* outman ){

    FILE* package;
    rapidjson::Document pdoc;
    char* buffer;

    // open up the package.json file
    package = fopen("package.json","r");  
    if( package == NULL )
        return JPM::Print("could not open package.json file");
    
    // find out hom many characters are in this file
    int a = JPMCompiler::CharCount( package );
    // open up some space for it
    buffer = (char*) calloc( a, sizeof(char) );
    // save the file into the buffer
    fread( buffer, sizeof(char)*a, a, package);
    // wrap the package in the json wrapper
    pdoc.Parse<0>( buffer );
    
    if( !pdoc.IsObject() || !pdoc.HasMember("name") )
        return JPM::Print("your package.json file is not structured correctly");
    
    // print out the package name
    JPM::Print( "parsing package:" );
    JPM::Print( std::string("  ").append( pdoc["name"].GetString( ) ) );   
    
    if( pdoc.HasMember("root") )
        outman->set_infile( pdoc["root"].GetString( ) );
    if( pdoc.HasMember("target") )
        outman->set_outfile( pdoc["target"].GetString( ) );
    
    // close and fre
    fclose( package ); 
    free( buffer );
}