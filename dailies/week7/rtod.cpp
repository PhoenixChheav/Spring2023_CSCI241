#include <iostream>
#include <string>

using namespace std;

int roman_to_decimal(const string&);

int main()
{
    cout << "I:         " << roman_to_decimal("I") << endl;
    cout << "IV:        " << roman_to_decimal("IV") << endl;
    cout << "VIII:      " << roman_to_decimal("VIII") << endl;
    cout << "X:         " << roman_to_decimal("X") << endl;
    cout << "XXXIX:     " << roman_to_decimal("XXXIX") << endl;
    cout << "CDXC:      " << roman_to_decimal("CDXC") << endl;
    cout << "CCXLVI:    " << roman_to_decimal("CCXLVI") << endl;
    cout << "DCCLXXXIV: " << roman_to_decimal("DCCLXXXIV") << endl;
    cout << "MCMXVIII:  " << roman_to_decimal("MCMXVIII") << endl;
    cout << "MMMCMXCIX: " << roman_to_decimal("MMMCMXCIX") << endl;

    return 0;
}

int roman_to_decimal(const string& roman_value){
    
    int char_value[1000];
    int decimal;
    for(size_t i = 0; i < roman_value.length(); i++){
        if(roman_value[i] == 'I'){
            char_value[i] = 1;
        }
        if(roman_value[i] == 'V'){
            char_value[i] = 5;
        }
        if(roman_value[i] == 'X'){
            char_value[i] = 10;
        }
        if(roman_value[i] == 'L'){
            char_value[i] = 50;
        }
        if(roman_value[i] == 'C'){
            char_value[i] = 100;
        }
        if(roman_value[i] == 'D'){
            char_value[i] = 500;
        }
        if(roman_value[i] == 'M'){
            char_value[i] = 1000;
        }
    }
    for(size_t i = 0; i < roman_value.length(); i++){
            if(char_value[i] < char_value[i+1] && i+1 < roman_value.length()){
                decimal += char_value[i+1] - char_value[i];
                i++;
            }else{
                decimal += char_value[i];
            }
            
        }
    return decimal;
}