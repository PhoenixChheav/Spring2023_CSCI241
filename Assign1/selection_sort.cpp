/**
* CSCI 241 Assignment 1
*
* Author: Leang Y Chheav (Phoenix, z-ID: z1966108)
*
*Assignment 1
*
*************************************/

#include <iostream>
#include <utility>
#include <iomanip>

using namespace std;

int build_array(int[]);
void sort_array(int[], int);
void print_array(int[], int);

/**
 * Builds a list of integers from standard input and then sorts and prints
 * them.
 *
 * @return Returns 0 on successful completion.
 */

int main()
{
    int numbers[1000];
    int n;

    n = build_array(numbers);

    sort_array(numbers, n);

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
int build_array(int array[])
{
    int n = 0;

    while (cin >> array[n])
        n++;

    return n;
}

/**
 * Sorts a list of integers in ascending order.
 *
 * @param array The list of integers to sort.
 * @param n The size of the list.
 *
 * @note Uses the selection sort algorithm.
 */
void sort_array(int array[], int n)
{
    int i, j, min_index;
    // int temp;

    for (i = 0; i < n - 1; i++)
    {
        // Locate the smallest value in the unsorted part of the list.

        min_index = i;
        for (j = i + 1; j < n; j++)
            if (array[j] < array[min_index])
                min_index = j;

        // Swap smallest value with first unsorted value.

        swap(array[i], array[min_index]);

        /*
        temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
        */
    }
}

/**
 * Prints a list of integers.
 *
 * @param array The list of integers to print.
 * @param n The size of the list.
 * @param count is to count the times of loop
 */
void print_array(int array[], int n)
{
    int i;
    int count = 0;

    for (i = 0; i < n; i++){
        cout <<setw(10) << right << array[i];
        count++;

        if(count % 8 == 0){
          cout << endl;
        }
    }
    if(count % 8 != 0){
        cout << endl;
    }
}