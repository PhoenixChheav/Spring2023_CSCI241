#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

string decimal_to_roman(int decimal_value){
    const string roman[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    string result = "";
    const int value[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

    for(int i = 0; i < 13; i++){
        while(decimal_value >= value[i]){
            result += roman[i];
            decimal_value -= value[i];
        }
    }

    return result;
}

int main()
{
    cout << "1:    " << decimal_to_roman(1) << endl;
    cout << "14:   " << decimal_to_roman(14) << endl;
    cout << "26:   " << decimal_to_roman(26) << endl;
    cout << "39:   " << decimal_to_roman(39) << endl;
    cout << "247:  " << decimal_to_roman(247) << endl;
    cout << "789:  " << decimal_to_roman(789) << endl;
    cout << "160:  " << decimal_to_roman(160) << endl;
    cout << "227:  " << decimal_to_roman(227) << endl;
    cout << "1099: " << decimal_to_roman(1099) << endl;
    cout << "1918: " << decimal_to_roman(1918) << endl;
    cout << "1954: " << decimal_to_roman(1954) << endl;
    cout << "3999: " << decimal_to_roman(3999) << endl;

    return 0;
}

// string decimal_to_roman(int decimal_value){

//     const string roman[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
//     string result = "";
//     const int value[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

//     for(int i = 0; i < 13; i++){
//         while(decimal_value >= value[i]){
//             result += roman[i];
//             decimal_value -= value[i];
//         }
//     }

//     return result;
    // for(size_t i = 0; i < roman_value.length(); i++){
    //     if(decimal/1 == 1){
    //         roman_value[i] == 'I';
    //     }
    //     if(decimal/5 == 1){
    //         roman_value[i] == 'V';
    //     }
    //     if(decimal/10 == 1){
    //         roman_value[i] == 'X';
    //     }
    //     if(decimal/50 == 1){
    //         roman_value[i] == 'L';
    //     }
    //     if(value == 100){
    //         roman_value[i] == 'C';
    //     }
    //     if(value == 500){
    //         roman_value[i] == 'D';
    //     }
    //     if(value == 1000){
    //         roman_value[i] == 'M';
    //     }
    // }
    // //check condition
    // for(size_t i = 0; i < roman_value.length(); i++){
    //         if(char_value[i] < char_value[i+1] && i+1 < roman_value.length()){
    //             decimal += char_value[i+1] - char_value[i];
    //             i++;
    //         }else{
    //             decimal += char_value[i];
    //         }
            
    //     }
//}