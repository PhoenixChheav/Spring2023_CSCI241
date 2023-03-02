#include <iostream>
using namespace std;
 void print_primes(int, int);

 int main(){

    cout << "\nPrimes from 2 up to 20 that do not end in '6' : \n\n";
    print_primes(20, 6);

    cout << "\nPrimes from 2 up to 20 that do not end in '7':\n\n";
    print_primes(20, 7);
    
    cout << "\nPrimes from 2 up to 40 that do not end in '9':\n\n";
    print_primes(40, 9);

    cout << "\nPrimes from 2 up to 200 that do not end in '3':\n\n";
    print_primes(200, 3);

    return 0;
 }

 void print_primes(int limit, int d){
    int f;
    for(int i = 2; i <= limit; i++){
        if(i == 0 || i == 0){
            continue;
        }

        f = 1;
        for(int j = 2; j <= i/2; j++){
            if(i % j == 0){
                f = 0;
                break;
            }
        }

        if(f == 1 && i % 10 != d){
            cout << " " << i;
        }
    }
    cout << endl;
 }