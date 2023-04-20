#include <iostream>

using namespace std;

int count_hex_a(int n);

int main()
{
    int n;

    n = -5;
    cout << "n = " << n << ", count_hex_a = " << count_hex_a(n) << endl;
    n = 9;
    cout << "n = " << n << ", count_hex_a = " << count_hex_a(n) << endl;
    n = 10;
    cout << "n = " << n << ", count_hex_a = " << count_hex_a(n) << endl;
    n = 0;
    cout << "n = " << n << ", count_hex_a = " << count_hex_a(n) << endl;
    n = 8612;
    cout << "n = " << n << ", count_hex_a = " << count_hex_a(n) << endl;
    n = 2730;
    cout << "n = " << n << ", count_hex_a = " << count_hex_a(n) << endl;

    return 0;
}

int count_hex_a(int n){

    if(n < 0){
        return -1;
    }

    int count = 0;
    while(n != 0){
        int hexa = n % 16;
        if(hexa == 10){
            count++;
        }
        n /= 16;
    }
    return count;
    
}