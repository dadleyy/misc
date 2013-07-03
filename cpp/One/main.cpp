#include "utils/utils.h"

// test
int main ( ) {
    
    cout << "Program #1 - Memory tests" << endl;
    
    char *ptr     = (char*) malloc(20+1);
    char name[20] = "Daniel James Hadley";
    
    ptr = (char*)"Daniel James Hadley\0";
    
    cout << "-- char* variable " << endl;
    cout << "Value: " << ptr << endl
         << "Size: " << sizeof( ptr ) << endl
         << "Strlen: " << strlen( ptr ) << endl
         << "Charsize: " << sizeof( char ) << endl;
    
    cout << "-- char[] variable " << endl;
    cout << "Value: " << name << endl
         << "Size: " << sizeof( name ) << endl
         << "Strlen: " << strlen( name ) << endl
         << "Charsize: " << sizeof( char ) << endl;
    

    int start = clock(),
        end, diff, stringsize = 20;
    
    char* stuff = (char*) malloc(stringsize);
    
    for(int i = 0; i < 10e7; i++) {
        stuff = (char*) malloc(stringsize);
        
        for(int j = 0; j < stringsize; j++){
            stuff[j] = (char)(rand() % 26) + 65;
        }
        stuff[stringsize-1] = '\0';
        
        if ( i % 10000000 == 0 ) {
            cout << i << " .. " << stuff << endl;
        }
        
        free( stuff );
        stuff = NULL;
    }
    
    end  = clock();
    diff = end - start;
    
    cout << "Start: " << start << endl
         << "End: " << end << endl
         << "Diff: " << diff << endl
         << "Time: " << ( (float)diff ) / CLOCKS_PER_SEC << endl; 
    
    return 0;
}
