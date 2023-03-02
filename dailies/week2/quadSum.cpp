#include <iostream>

using namespace std;

bool quad_sum_is_n(int[], int, int);
void print_array(int[], int);

int main()
{
    int A1[] = {1, 2, 3, 4}, n1 = 10;
    print_array(A1, 4);
    cout << "quadsum n = " << n1 
	     << (quad_sum_is_n(A1, 4, n1) ? " found" : " not found") << endl;

    int A2[] = {1}, n2 = 1;
    print_array(A2, 1);
    cout << "quadsum n = " << n2 
	<< (quad_sum_is_n(A2, 1, n2) ? " found" : " not found") << endl;

    int A3[] = {-1, 0, -2, 5, 1, 6, 0}, n3=0;
    print_array(A3, 7);
    cout << "quadsum n = " << n3 
	     << (quad_sum_is_n(A3, 7, n3) ? " found" : " not found") << endl;
    
    int n4 = 14;
    print_array(A3, 7);
    cout << "quadsum n = " << n4 
	     << (quad_sum_is_n(A3, 7, n4) ? " found" : " not found") << endl;
    
    int n5 = 15;
    print_array(A3, 7);
    cout << "quadsum n = " << n5 
        << (quad_sum_is_n(A3, 7, n5) ? " found" : " not found") << endl;
    
    int n6 = 7;
    print_array(A3, 7);
    cout << "quadsum n = " << n6 
	     << (quad_sum_is_n(A3, 7, n6) ? " found" : " not found") << endl;

    return 0;
}

void print_array(int a[], int len)
{
    int i;

    cout << "a[] = {";
    for (i = 0; i < len-1; i++)
        cout << a[i] << ", ";
    cout << a[len-1] << "}" << endl;
}

bool quad_sum_is_n(int a[], int len, int n){
    int sum = 0;
    bool result = false;
    int count = 0;

    if(len >= 4){
        for(int i = 0; i < len; i++){
            //sum += a[i];
            for(int j = i+1; j < len; j++){
                //sum += a[j];
                for(int k = j+1; k < len; k++){
                    //sum += a[k];
                    for(int l = k+1; l < len; l++){
                        sum = a[i] + a[j] + a[k] + a[l];

                        cout << "a[i]: " << a[i] << endl;
                        cout << "a[j]: " << a[j] << endl;
                        cout << "a[k]: " << a[k] << endl;
                        cout << "a[l]: " << a[l] << endl;
                        cout << "sum = " << sum << endl;
                        if(sum == n){
                            result = true;
                        }
                    }
                    cout << "end L" << endl;
                }
                cout << "end K" << endl;
            }
            cout << "end J" << endl;
        }

    }else{
        result = false;
    }
   
    return result;
}