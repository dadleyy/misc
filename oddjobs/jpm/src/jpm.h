/* Author: Danny Hadley
 * Date: Spring 2013
*/
#ifndef _JPM_H
#define _JPM_H

#include "defs.h"
#include "includes.h"

class JPM {

public:
    static int Execute(int argc, char* argv[ ]); 
    static int Print( std::string message );
    
public:
    JPM( );
    ~JPM( );
    
    int Run( std::string command );
    
    void set_outfile( std::string filen );
    void set_infile( std::string filen );
    void set_server( std::string serveri );
    
    std::string get_outfile( );
    std::string get_infile( );
    
    bool ready;
    
private:
    void CheckReady( );
    
    std::string outfile;
    std::string infile;
    
    std::string serverinfo;
    bool usingserver;
};

#endif