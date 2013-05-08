/* Author: Danny Hadley
 * Date: Spring 2013
*/
#ifndef _JPM_COMPILER_H
#define _JPM_COMPILER_H

#include "includes.h"
#include "jpm.h"
#include <map>
#include <regex.h>

class JPMCompiler {

public:
    static int Compile( JPM* out );
    static int CharCount( FILE* file );
    static void Prepare( );
    
private:  
    static std::map<char*,char*> imports;
    // parsing expressions
    static regex_t r_line;
    
};

#endif
