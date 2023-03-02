#include <iostream>
#include <array>

using namespace std;

int main(){

    int a[] = {1, 2, 3, 4, 45, 6, 7};
    int size = sizeof(a)/sizeof(*a);

    cout << size << endl;

    return 0;
}