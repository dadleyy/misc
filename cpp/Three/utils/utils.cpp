#include "utils.h"

void utils::printArgs(int count, char *arguments[]){
    cout << "Arugment count: " << count << endl;

    /* the first arg is just the way it was called */
    if ( count > 1 ) {
        for (int i = 1; i < count; i++) {
            cout << "Arguments[" << i << "] - " << arguments[i] << endl;
        }
    }

    cout << endl;
} 