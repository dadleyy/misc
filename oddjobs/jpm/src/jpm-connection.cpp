#include "jpm-connection.h"

JPMConnection::JPMConnection( ) : handle(0) { }
JPMConnection::JPMConnection( std::string serverinfo ) : handle(0) {  
    
}
JPMConnection::~JPMConnection( ) { }

// setters
void JPMConnection::set_port( unsigned int _port ) { port = _port; }
void JPMConnection::set_username( std::string _username ) { username = _username; }
void JPMConnection::set_password( std::string _password ) { password = _password; }

int JPMConnection::Push( char* filename ){
    
}

