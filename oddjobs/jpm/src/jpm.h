/* Author: Danny Hadley
 * Date: Spring 2013
*/
#ifndef _JPM_H
#define _JPM_H

#define JPM_ERR "need help?\n  type --help for more options\n  thank you or using jpm\n\n"
#define JPM_WELCOME "\nwelcome to jpm\n"
#define JPM_HELP "\nlist of available flags:\n  -o : the output file\n\n"

#include <iostream>
using namespace std;

class JPM {

public:
    static int execute(int argc, char* argv[ ]); 
private:
    static int print(string message);

public:
    JPM( );
    ~JPM( );
    
    void set_outfile(string filen);
    void set_infile(string filen);
    
private:
    string outfile;
    string infile;
    

};

#endif