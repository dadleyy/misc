/* Author: Danny Hadley
 * Date: Spring 2013
*/
#ifndef _JPM_CONNECTION_H
#define _JPM_CONNECTION_H

#include "../include/curl/curl.h"

class JPMConnection {
    
public:
    JPMConnection( );
    ~JPMConnection( );
private:
    CURL *curl;
};

#endif