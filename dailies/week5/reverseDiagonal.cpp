#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::swap;


static void print_array(int array[][4])
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout << array[row][col] << ' ';
        }

        cout << endl;
    }
}

void reverse_diagonal(int[][4]);

int main()
{
    int array1[4][4] = {{21, 26, 31, 36},
                        {41, 46, 51, 56},
                        {61, 66, 71, 76},
                        {81, 86, 91, 96}};

    int array2[4][4] = {{35, 12, 27, 84},
                        {62, 19, 81, 32},
                        {74, 53, 29, 41},
                        {23, 60, 37, 15}};

    cout << "Before:\n\n";
    print_array(array1);

    reverse_diagonal(array1);

    cout << "\nAfter:\n\n";
    print_array(array1);

    cout << endl;

    cout << "Before:\n\n";
    print_array(array2);

    reverse_diagonal(array2);

    cout << "\nAfter:\n\n";
    print_array(array2);

    return 0;
}

void reverse_diagonal(int array[][4]){
    int count = 0;
    int i = 0;
    int j = 4;

    
    while(i < j){
        swap(array[i][i], array[j - 1][j - 1]);

        swap(array[i][j - 1], array[j - 1][i]);
        i++;
        j--;
    }
}
