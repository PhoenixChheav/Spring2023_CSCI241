#include <iostream>

using std::cout;
using std::endl;

int cutting_rope(int a[], int n, int sum);

void print_array(int a[], int n)
{
    int i;

    for (i = 0; i < n; i ++)
        cout << a[i] << ' ';
}

int main()
{
    int a[100], n, sum;

    a[0] = 1; a[1] = 2; a[2] = 1; a[3] = 2; n = 4; sum = 2; // 1
    print_array(a, n);
    cout << " sum = " << sum << endl;
    cout << cutting_rope(a, n, sum) << endl << endl;

    a[0] = 1; a[1] = 2; a[2] = 1; a[3] = 2; n = 4; sum = 1; // -1
    print_array(a, n);
    cout << " sum = " << sum << endl;
    cout << cutting_rope(a, n, sum) << endl << endl;

    // sum = 1  --> 3
    // sum = 3  --> 2
    // sum = 6  --> 1
    // sum = 10 --> 0
    a[0] = 2; a[1] = 4; a[2] = 1; a[3] = 0; a[4] = 3; n = 5;
    for (sum = 1; sum <= 12; sum++)
    {
        print_array(a, n);
        cout << " sum = " << sum << endl;
        cout << cutting_rope(a, n, sum) << endl << endl;
    }

    return 0;
}

int cutting_rope(int a[], int n, int sum){
    int max;
    int cut = 0;
    int sum_left = 0; //the total length of all ropes that have been cut

    max = a[0];
    for(int i = 0; i < n; i++){//find the longest rope
        if(max < a[i]){
            max = a[i];
        }
    }

    for(int i = 0; i < max; i++){
        sum_left = 0;
        for(int j = 0; j < n; j++){
            cut = a[j] - i;

            if(cut >= 0){
                sum_left += cut;
            }
            
            
        }

        if(sum_left == sum){
        return i;
        }
        if(sum_left == 0){
            return -1;
        }
    }
    return -1
}