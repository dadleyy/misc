/* Author: Danny Hadley
 * Date: Spring 2013
*/
#ifndef _JPM_CONNECTION_H
#define _JPM_CONNECTION_H

#include "../include/curl/curl.h"
#include "jpm.h"

class JPMConnection {
    
public:
    JPMConnection( );
    JPMConnection(string serverinfo);
    ~JPMConnection( );
    
    int Push( char* filename );
    
    void set_password( string _password );
    void set_username( string _username );
    void set_port( unsigned int _port );
    
private:
    string desturl;
    string username;
    string password;
    unsigned int port;
    CURL* handle;
    
};

#endif