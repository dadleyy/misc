#include "utils/utils.h"

void fn1 ( char pr[] ) {

    cout << "Inside fn1..." << endl;
    cout << "Sizeof pr: " << sizeof(pr) << endl;
    cout << "pr[0] = " << pr[0] << " | " << &pr << endl;
    
    pr[0] = 'F';
    
}

int main ( ) {
    
    cout << "Program #2 - Pointer stuff" << endl;
    
    char *overflow;
    
    overflow = (char*) calloc(20, sizeof(char) );
    
    srand( time(NULL) );
    
    cout << "Value of overflow: " << overflow << endl;
    
    for (int i = 0; i < 10e7; i++) {
        char rando  = (char) (rand() % 26) + 65; 
        overflow[i % 20] = rando;
        if ( false || i % 10000000 == 0 )
            cout << i << " .. pushing: " << rando 
                 << " | [" << i % 20 << "] = " << overflow[i % 20] <<  endl;
    }
    
    cout << "Value of overflow[0]: " << overflow[0] << endl;
    cout << "Value of overflow: [";
    for (int i = 0; i < 20; i++) {
        cout << *(overflow + i);
        if ( i != 19 )
            cout << ",";
    }
    cout << "]" << endl;
    
    fn1( overflow );
    
    cout << "Value of overflow: [";
    for (int i = 0; i < 20; i++) {
        cout << *(overflow + i);
        if ( i != 19 )
            cout << ",";
    }
    cout << "]" << endl;
        
    free(overflow);
    
    return 0;
}