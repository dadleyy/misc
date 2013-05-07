/* Author: Danny Hadley
 * Date: Spring 2013
*/
#ifndef _JPM_H
#define _JPM_H

#include "defs.h"
#include "includes.h"
#include "jpm-connection.h"
#include "jpm-parser.h"

class JPM {

public:
    static int Execute(int argc, char* argv[ ]); 
    static int Print(string message);
    
public:
    JPM( );
    ~JPM( );
    
    int Run( string command );
    
    void set_outfile(string filen);
    void set_infile(string filen);
    void set_server(string serveri);
    bool ready;
    
private:
    void CheckReady( );
    
    int Compile( );
    int Upload( );
    
    string outfile;
    string infile;
    
    string serverinfo;
    bool usingserver;
};

#endif