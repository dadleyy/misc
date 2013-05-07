#include "jpm-connection.h"

JPMConnection::JPMConnection( ) { }
JPMConnection::JPMConnection( string serverinfo ) { }
JPMConnection::~JPMConnection( ) { }

// setters
void JPMConnection::set_port( unsigned int _port ) { port = _port; }
void JPMConnection::set_username( string _username ) { username = _username; }
void JPMConnection::set_password( string _password ) { password = _password; }

int JPMConnection::Push( char* filename ){
    
}

