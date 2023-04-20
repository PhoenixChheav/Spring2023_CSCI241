#include <iostream>

using namespace std;

void binary_increment(int a[], int len){
    //int sum = 0;
    for(int i = len - 1; i >= 0; i--){
        if(a[i] == 0){
            a[i]++;
            break;
        }else{
            a[i] = 0;
        }
    }
}
