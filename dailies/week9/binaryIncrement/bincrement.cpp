#include <iostream>

using namespace std;

void binary_increment(int a[], int len){
    //int sum = 0;
    //if it encounter 0 add 1 and break the loop
    for(int i = len - 1; i >= 0; i--){
        if(a[i] == 0){
            cout << "Before increment" << endl;
            cout << "a[" << i << "]: " << a[i] << endl;
            a[i]++;
            cout << "After increment" << endl;
            cout << "a[" << i << "]: " << a[i] << endl;
            break;
        }else{ // if it is not 0 change it to 0
            a[i] = 0;
        }
    }
}

static void print_array(int a[], int len)
{
    int i;

    for (i = 0; i < len; i ++)
        cout << a[i] << ' ';
    cout << endl;
}

int main()
{
    int a[100], len;

    a[0] = 1; a[1] = 0; len = 2;
    cout << "Input:  ";
    print_array(a, len);
    binary_increment(a, len);
    cout << "Output: ";
    print_array(a, len);
    cout << endl;
    
    a[0] = 0; a[1] = 0; a[2] = 0; len = 3;
    cout << "Input:  ";
    print_array(a, len);
    binary_increment(a, len);
    cout << "Output: ";
    print_array(a, len);
    cout << endl;

    a[0] = 1; a[1] = 0; a[2] = 1; a[3] = 0; a[4] = 1; len = 5;
    cout << "Input:  ";
    print_array(a, len);
    binary_increment(a, len);
    cout << "Output: ";
    print_array(a, len);
    cout << endl;

    a[0] = 1; a[1] = 0; a[2] = 1; a[4] = 1; len = 4;
    cout << "Input:  ";
    print_array(a, len);
    binary_increment(a, len);
    cout << "Output: ";
    print_array(a, len);
    cout << endl;

    return 0;
}
