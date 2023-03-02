#include <iostream>

using std::cout;
using std::endl;

void even_odd(int a[], int b[], int len);

static void print_arrays(int a[], int b[], int len)
{
    int i;

    cout << "a[] = {";
    for (i = 0; i < len-1; i ++)
        cout << a[i] << ", ";
    cout << a[len-1] << "}, b[] = {";
    
    for (i = 0; i < len-1; i ++)
        cout << b[i] << ", ";
    cout << b[len-1] << "}" << endl;
}

int main()
{
    int a1[] = {1, 2}, b1[2];
    even_odd(a1, b1, 2);
    print_arrays(a1, b1, 2);

    int a2[] = {1, 2, 3, 4}, b2[4];
    even_odd(a2, b2, 4);
    print_arrays(a2, b2, 4);

    int a3[] = {1, 2, 4, 6}, b3[4];
    even_odd(a3, b3, 4);
    print_arrays(a3, b3, 4);

    int a4[] = {1}, b4[1];
    even_odd(a4, b4, 1);
    print_arrays(a4, b4, 1);

    return 0;
}

void even_odd(int a[], int b[], int len){
    
    int temp_even[50];
    int temp_odd[50];
    int j = 0;
    int k = 0;
    int count_even= 0;
    int count_odd = 0;
    

    if(len <= 1){
        b[0] = a[0];
        return;
    }

    for(int i = 0; i < len; i++){
        if(a[i] % 2 == 0){
            temp_even[j] = a[i];
            count_even++;
            j++;
        }
        else{
            temp_odd[k] = a[i];
            k++;
            count_odd++;
        }
    }
    
    j=0;
    k=0;
    for(int i = 0; i < len; i++){

        if(j < count_even){
            b[i] = temp_even[j];
            j++;
        }
        
        if(k < count_odd){
            i++;
            b[i] = temp_odd[k];
            k++;
        }
    }
        
}

// void even_odd(int a[], int b[], int len){
    
//     int temp_even[50];
//     int temp_odd[50];

//     int count_even = 0; //count even number in array
//     int count_odd = 0; //count odd number in array
//     int j = 0;
//     int k = 0;

//     for(int i = 0; i < len; i++){
//         if(a[i] % 2 == 0){
//             count_even++;
//             temp_even[i] = a[i];
//             b[i] = temp_even[i];
//             temp_even[j] = temp_even[i];
//             j++;
//         }else{
//             count_odd++;
//             temp_odd[i] = a[i];
//             b[i] = temp_odd[i];
//             temp_odd[k] = temp_odd[i]; //put in the new array
//             k++;
//         }
//     }

//     j = 0;
//     k = 0;
//     for(int i = 0; i < len; i++){
        
        
//         b[0] = temp_even[0];
        
//         if (i % 2 == 0 && count_even > count_odd)
//         {
//             b[j] = temp_even[j];
//             j++;
//         }
        
//         if(i % 2 == 1 && count_even <= count_odd){
//             b[k] = temp_odd[k];
//             k++;
            
//         }

//         if(len <= 1){
//             b[i] = a[i];
//         }

       
        
//     }

    
    
        
// }

// void even_odd(int a[], int b[], int len){
//     int odd_p = 0; //count even number in array
//     int even_p = 0; //count odd number in array
//     int position = 0; // position

//     bool even_turn = true;

//     while(position < len){
//         while (even_p < len && a[even_p] % 2 != 0)
//         {
//             even_p++;
//         }

//         while(odd_p < len && a[even_p] % 2 == 0){
//             odd_p++;
//         }

//         if(even_p >= len){
//             b[position++] = a[odd_p++];
//         }else if(odd_p >= len){
//             b[position++] = a[even_p++];
//         }else{
//             if(even_turn){
//                 b[position++] = a[even_p++];
//                 even_turn = false;
//             }else{
//                 b[position++] = a[odd_p++];
//                 even_turn = true;
//             }
//         }
        
//     }

// }