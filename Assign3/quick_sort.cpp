//***************************************************************************
//
//  quick_sort.cpp
//  CSCI 241 Assignment 3
//
//  Sam Normoyle (Z-ID: Z1980761)
//  Leang Y Chheav(Z-ID: Z1966108)
//**************************************************************************

#include <iostream>
#include <utility>
#include <iomanip>

using namespace std;

int build_array(int []);
void quick_sort(int [], int, int);
int partition(int [], int, int);
void print_array(int [], int);


int main(){
    int numbers[1000];
    int n;

    n = build_array(numbers);
    quick_sort(numbers, 0,n-1);
    print_array(numbers, n);
    return 0;
}

/**
 * Read a list of integers into an array from standard input
 * 
 * @param array the array which integer are read
 * 
 * @return the number of integers read
*/
int build_array(int array[]){
    int n = 0;
    while(cin >> array[n]){
        n++;
    }
    return n;
}

/**
 * This function is used to sort all elements in array
 * 
 * @param array: the list of integers to sorts
 * 
 * @param start: the first element in array list
 * 
 * @param end: the final element in array list
 * 
 * @note Uses Quick Sort Algorithm
*/
void quick_sort(int array[], int start, int end){
    int pivot_point = 0;
    if(start <end){
        pivot_point = partition(array, start, end);
        quick_sort(array, start, pivot_point - 1);
        quick_sort(array, pivot_point + 1, end);
    }
}

/**
 * This function divides large array into two sub-array the low element and high elements
 * 
 * @param array list of sortable item
 * 
 * @param start first element of list
 * 
 * @param end last element of list
*/
int partition(int array[], int start, int end){
    int mid = (start + end)/2;
    swap(array[start], array[mid]);

    int pivot_index = start;
    int pivot_value = array[start];

    int scan = start + 1;
    while(scan <= end){
        if(array[scan] < pivot_value){
            pivot_index = pivot_index + 1;
            swap(array[pivot_index], array[scan]);
        }
        scan = scan + 1;
    }

    swap(array[start], array[pivot_index]);

    return pivot_index;
}

/**
 * Prints a list of integers.
 *
 * @param array The list of integers to print.
 * 
 * @param n The size of the list.
 */
void print_array(int array[], int n){
    int count = 0;

    for(int i = 0; i < n; i++){
        cout << setw(10) << right << array[i];
        count++;

        if(count % 8 == 0){
            cout << endl;
        }
    }
    if(count % 8 != 0){
        cout << endl;
    }
}
