#include <iostream>

using std::cout;
using std::endl;

int last_index_of(const char* s, char c);

int main()
{
    int index;

    cout << "index = last_index_of(\"adamant\", 'a');\n";
    index = last_index_of("adamant", 'a');
    cout << "Returned index: " << index << endl;
    if (index == 4)
        cout << "PASSED\n";
    else
        cout << "FAILED - index should be 4\n";
    
    cout << endl;

    cout << "index = last_index_of(\"adamant\", 'm');\n";
    index = last_index_of("adamant", 'm');
    cout << "Returned index: " << index << endl;
    if (index == 3)
        cout << "PASSED\n";
    else
        cout << "FAILED - index should be 3\n";
    
    cout << endl;

    cout << "index = last_index_of(\"accouterment\", 't');\n";
    index = last_index_of("accouterment", 't');
    cout << "Returned index: " << index << endl;
    if (index == 11)
        cout << "PASSED\n";
    else
        cout << "FAILED - index should be 11\n";
    
    cout << endl;

    cout << "index = last_index_of(\"inhabitant\", 'x');\n";
    index = last_index_of("inhabitant", 'x');
    cout << "Returned index: " << index << endl;
    if (index == -1)
        cout << "PASSED\n";
    else
        cout << "FAILED - index should be -1\n";

    return 0;
}
int last_index_of(const char* s, char c){

    //count character of word
    int i = 0;
    //condition if the s[i] do not encounter the NULL character
    while(s[i] != '\0'){
        i++;
    }

    for(int j = i; j >= 0; j--){
        if(s[j] == c){
            return j;
        }

        //when loop almost end make sure that if every charater in word do not match with c return -1
        if(j == 0 && s[j] != c){
            return -1;
        }
    }

    return 0;
}