//***************************************************************************
//
//  merge_sort.cpp
//  CSCI 241 Assignment 3
//
//  Sam Normoyle (Z-ID: Z1980761)
//  Leang Y Chheav(Z-ID: Z1966108)
//**************************************************************************

#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>

using namespace std;
using std:: end;

int build_array(int []);
void merge_sort(int [], int , int);
void merge(int [], int, int, int);
void print_array(int [], int);

int main(){
    int numbers[1000];
    int n;

    n = build_array(numbers);
    merge_sort(numbers, 0, n-1);
    print_array(numbers, n);


    return 0;
}

/**
 * Reads a list of integers into an array from standard input.
 *
 * @param array The array into which the integers are read.
 *
 * @return The number of integers read (size of the list).
 */
int build_array(int array[]){
    int n = 0;
    while(cin >> array[n]){
        n++;
    }
    return n;
}

/**
 * This function will merge the 2sublists together into one
 * 
 * @param array : the list of array
 * 
 * @param start : first element of the list
 * 
 * @param end : last element of the list
*/
void merge_sort(int array[], int start, int end){
    int mid;
    if(start < end){
        mid = (start + end) / 2;
        
        merge_sort(array, start, mid);
        merge_sort(array, mid + 1, end);

        merge(array, start, mid, end);
    }
}


/**
 * This function will sort a list of arrays in ascending order by spliting array into 2 sublists first
 * 
 * then start searching and sort
 * 
 * @param array is the list of array
 * 
 * @param start first element of first sublist
 * 
 * @param mid last element of first sublist
 * 
 * @param end last element of second sublist
 * 
 * @note this function use merge sort algorithm
*/
void merge(int array[], int start, int mid, int end){
    //temporary vector of size (end - start +1)
    vector<int> temp(end - start + 1);

    int i = start;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= end){
        if(array[i] < array[j]){
            temp[k] = array[i];
            i++;
        }else{
            temp[k] = array[j];
            j++;
        }
        k++;
    }

    while(i <= mid){
        temp[k] = array[i];
        i++;
        k++;
    }

    while(j <= end){
        temp[k] = array[j];
        j++;
        k++;
    }
    

    //copy from vector temp to array
    int count = 0;
    for(i = start; i<= end; i++){
        array[i] = temp[i - start];
        count++;
    }

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
        cout<< setw(10) << right << array[i];
        count ++;

        if(count % 8 == 0){
            cout << endl;
        }
    }

    if(count % 8 != 0){
        cout << endl;
    }
}
