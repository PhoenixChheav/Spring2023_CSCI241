#include <iostream>
#include <cstring>

char* trim(char* destination, const char* source){
    while(isspace(*source)){
        ++source;
    }
    
    int len = 0;
    len = strlen(source);
    while(len > 0 && isspace(source[len - 1])){
        --len;
    }

    memcpy(destination, source, len);
    destination[len] = '\0';

    return destination;
}