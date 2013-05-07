#include "jpm-connection.h"

JPMConnection::JPMConnection( ) : handle(0) { }
JPMConnection::JPMConnection( string serverinfo ) : handle(0) {  
    
}
JPMConnection::~JPMConnection( ) { }

// setters
void JPMConnection::set_port( unsigned int _port ) { port = _port; }
void JPMConnection::set_username( string _username ) { username = _username; }
void JPMConnection::set_password( string _password ) { password = _password; }

int JPMConnection::Push( char* filename ){
    
}

