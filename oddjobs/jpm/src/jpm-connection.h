/* Author: Danny Hadley
 * Date: Spring 2013
*/
#ifndef _JPM_CONNECTION_H
#define _JPM_CONNECTION_H

#include "includes.h"
#include <curl/curl.h>

class JPMConnection {
    
public:
    JPMConnection( );
    JPMConnection(std::string serverinfo);
    ~JPMConnection( );
    
    int Push( char* filename );
    
    void set_password( std::string _password );
    void set_username( std::string _username );
    void set_port( unsigned int _port );
    
private:
    std::string desturl;
    std::string username;
    std::string password;
    unsigned int port;
    CURL* handle;
    
};

#endif