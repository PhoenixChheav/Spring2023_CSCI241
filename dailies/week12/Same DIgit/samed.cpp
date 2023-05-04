#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

/**
 * This approach converts the integers to strings, 
 * sorts the digits in each string, and then compares the sorted strings. 
 * If the sorted strings are equal, then the integers have the same digits. 
 * Note that this approach has a time complexity of O(n log n) due to the sorting step, 
 * where n is the length of the strings. However, it does not require an unordered_map, 
 * which may be useful in situations where the use of a hash table is not desirable.
 */

bool same_digits(int a, int b){
    //convert integer to string
    string str_a = to_string(a);
    string str_b = to_string(b);

    //check if strings have the same length
    if(str_a.length() != str_b.length()){
        return false;
    }

    sort(str_a.begin(), str_a.end());
    sort(str_b.begin(), str_b.end());
    return str_a == str_b;
}

int main()
{
    if (same_digits(2020, 2200))
        cout << "Correct: 2020 and 2200 have the same digits\n";
    else
        cout << "Incorrect: 2020 and 2200 have the same digits\n";

    if (same_digits(312, 123))
        cout << "Correct: 312 and 123 have the same digits\n";
    else
        cout << "Incorrect: 312 and 123 have the same digits\n";

    if (same_digits(980, 9801))
        cout << "Incorrect: 980 and 9801 do not have the same digits\n";
    else
        cout << "Correct: 980 and 9801 do not have the same digits\n";

    if (same_digits(312, 124))
        cout << "Incorrect: 312 and 124 do not have the same digits\n";
    else
        cout << "Correct: 312 and 124 do not have the same digits\n";
    
    return 0;
}