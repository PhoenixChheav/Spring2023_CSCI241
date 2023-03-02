#include <iostream>
#include <iomanip>

using namespace std;

int sum_odd_elements(int a[], int n);

static void print_array(int a[], int n)
{
    int i;

    cout << "a[] = {";
    for (i = 0; i < n-1; i++)
        cout << a[i] << ", ";
    cout << a[n-1] << "}\n";
}

int main()
{
    int a1[] = {1};
    print_array(a1, 1);
    cout << "sum of odd elements = "
         << sum_odd_elements(a1, 1) << endl << endl;

    int a2[] = {8, 12, 3, 19, 34, 29, 6, 15};
    print_array(a2, 7);
    cout << "sum of odd elements = "
         << sum_odd_elements(a2, 7) << endl << endl;

    int a3[] = {50, 49, 87, 94, 5, 38, 80, 85,
                78, 17, 54, 49, 79, 40, 42};
    print_array(a3, 15);
    cout << "sum of odd elements = "
         << sum_odd_elements(a3, 15) << endl;

    return 0;
}

int sum_odd_elements(int a[], int n){
    
    int sum;

    
        sum = 0;
        /**
         * if n = 1 array has only one element, there are no odd numbered elements in array
         * function will return 0
        */
        if(n == 1){
            sum = 0;
        }else{
            /**
             * if n > 1, sum the odd numbered element
            */
        for(int i = 0; i < n; i ++){
            if(i % 2 == 1){
                sum += a[i];
            }
            //cout << sum << " " <<endl;
        }
    }

    return sum;
}


