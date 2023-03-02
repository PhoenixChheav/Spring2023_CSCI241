#include <iostream>
#include <iomanip>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using namespace std;
static int build_array(int[]);
static void print_array(int[], int);
void heap_sort(int[], int);
void heapify(int [], int);
void sift_down(int[], int, int);

int main()
{
    int array[1000];
    int n;
 
    n = build_array(array);

    cout << n << " elements unsorted\n\n";

    print_array(array, n);
    
    cout << endl << n << " elements in ascending order\n\n";
    
    heap_sort(array, n);
    print_array(array, n);

    return 0;
}

int build_array(int array[])
{
    int n = 0;

    while (cin >> array[n])
        n++;

    return n;
}

void print_array(int array[], int n)
{
    int i;
    
    for (i = 0; i < n; i++)
    {
        cout << setw(8) << array[i];
        if ((i+1) % 8 == 0)
            cout << endl;
    }

    if (i % 8 != 0)
        cout << endl;
}

void heap_sort(int array[], int n){
    int end = 0;
    
    heapify(array, n);
    //the heap size is reduced by 1
    end = n - 1;
    while (end > 0)
    {
        swap(array[end], array[0]);

        end = end - 1;
        //the swap ruined the heap property, so restore it
        sift_down(array, 0, end);
    }
    
    

}

void heapify(int array[], int n){
    int start;

    start = (n - 2) / 2;

    while(start >= 0){
        //sift down the value at the subscript 'start' to the proper place
        //such that all values below the starts subscript are in max heap order

        sift_down(array, start, n - 1);

        //go to next parent
        start = start - 1;
    }

}

void sift_down(int array[], int start, int end){
    int root;
    int largest;
    int child;

    root = start;

    while((2 * root + 1) <= end){
        child = 2 * root + 1; //left child root
        largest = root; //Assume that root is largest

        if(array[largest] < array[child]){
            largest = child;
        }

        if((child + 1) <= end && array[largest] < array[child+1]){
            largest = child + 1;
        }

        if(largest == root){
            return;
        }else{
            swap(array[root], array[largest]);
            root = largest;
        }
    }
}