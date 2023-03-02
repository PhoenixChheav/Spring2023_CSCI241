#include <iostream>

using namespace std;

int main(){
    int a[10] = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9};

    for(int i = 0; i < 10; i++){
        if(a[i] % 2 == 0){
            cout << "even" << a[i];
        }else{
            cout << "odd: " << a[i];
        }
    }

    return 0;
}