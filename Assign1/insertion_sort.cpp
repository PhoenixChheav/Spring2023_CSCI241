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
 * @note Uses the insertion sort algorithm.
 */
void sort_array(int array[], int n)
{
  int i;
  int j;
  int temp;

  i = 1;
  while(i < n){
    temp = array[i];
    j = i;

    while(j > 0 && array[j - 1] > temp){
      array[j] = array[j-1];
      j = j - 1;
    }

    array[j] = temp;
    i = i +1;
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
    int count = 1;

    for (i = 0; i < n; i++){
        cout <<setw(10) << right << array[i];

        if(count % 8 == 0){
          cout << endl;
        }
        count++;

        
    }
    if(count % 8 != 0){
        cout << endl;
    }
}