#include <iostream>
#include <cstring>


using namespace std;

char* trim(char*, const char*);

int main()
{
    char result[80];

    if (strcmp(trim(result, " \t  \nboth ends   \n\t"), "both ends") == 0)
        cout << "PASSED\n";
    else
        cout << "FAILED\n" << "Your result: \"" << result
             << "\"\n" << "Correct result: \"both ends\"\n";
    
    if (strcmp(trim(result, "trailing  \t\n"), "trailing") == 0)
        cout << "PASSED\n";
    else
        cout << "FAILED\n" << "Your result: \"" << result
             << "\"\n" << "Correct result: \"trailing\"\n";

    if (strcmp(trim(result, "\t\n\t  leading"), "leading") == 0)
        cout << "PASSED\n";
    else
        cout << "FAILED\n" << "Your result: \"" << result
             << "\"\n" << "Correct result: \"leading\"\n";

    if (strcmp(trim(result, " \t  \n\n\t"), "") == 0)
        cout << "PASSED\n";
    else
        cout << "FAILED\n" << "Your result: \"" << result
             << "\"\n" << "Correct result: \"\"\n";

    if (strcmp(trim(result, ""), "") == 0)
        cout << "PASSED\n";
    else
        cout << "FAILED\n" << "Your result: \"" << result
             << "\"\n" << "Correct result: \"\"\n";

    return 0;
}

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

// char* trim(char* destination, const char* source){
//     while(isspace(*source)){
//         source++;
//     }

//     char* goal = destination;
    
//     while(!isspace(*source)){
//         *destination++ = *source++;
//     }
//     *destination = '\0';

//     return goal;
// }