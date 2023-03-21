#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setfill;
using std::setw;

void rotate_matrix(int[][8], int[][8]);

static void print_matrices(int original[][8], int rotated[][8], int width)
{
    cout << setfill('0');

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            cout << setw(width) << original[row][col] << ' ';
        }

        cout << setfill(' ') << setw(5) << ' ';

        cout << setfill('0');

        for (int col = 0; col < 8; col++)
        {
            cout << setw(width) << rotated[row][col] << ' ';
        }

        cout << endl;
    }
}

int main()
{
    int matrix1[8][8] = {{ 0,  1,  2,  3,  4,  5,  6,  7},
                         {10, 11, 12, 13, 14, 15, 16, 17},
                         {20, 21, 22, 23, 24, 25, 26, 27},
                         {30, 31, 32, 33, 34, 35, 36, 37},
                         {40, 41, 42, 43, 44, 45, 46, 47},
                         {50, 51, 52, 53, 54, 55, 56, 57},
                         {60, 61, 62, 63, 64, 65, 66, 67},
                         {70, 71, 72, 73, 74, 75, 76, 77}};

    int matrix2[8][8] = {{0, 0, 0, 0, 0, 1, 0, 0},
                         {0, 1, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 1, 0},
                         {1, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 1, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 1},
                         {0, 0, 0, 0, 1, 0, 0, 0},
                         {0, 0, 1, 0, 0, 0, 0, 0}};

    int matrix3[8][8] = {{0, 0, 0, 1, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 1, 0},
                         {0, 0, 1, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 1},
                         {0, 1, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 1, 0, 0, 0},
                         {1, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 0}};

    int rotated[8][8];

    rotate_matrix(rotated, matrix1);

    cout << "        ORIGINAL                     ROTATED\n";
    print_matrices(matrix1, rotated, 2);

    cout << endl;

    rotate_matrix(rotated, matrix2);
    
    cout << "   ORIGINAL              ROTATED\n";
    print_matrices(matrix2, rotated, 1);

    cout << endl;

    rotate_matrix(rotated, matrix3);
    
    cout << "   ORIGINAL              ROTATED\n";
    print_matrices(matrix3, rotated, 1);

    return 0;
}

/**
 * void rotate_matrix(int des[][8], int source[][8]){
    int des_col=8;
    for(int i = 0; i< 8; i++){
        int j = 0;
        des_col--;
        for(int k = 8; k>0; k--){
            des[j][des_col]=source[i][j];
            j++;
        }
    }
}
*/
void rotate_matrix(int destination[][8], int source[][8]){
    int size = 8;

    for(int row = 0; row < 8; row++){
        int col = 0;
        size--;
        for(int i = 8; i > 0; i--){
            destination[col][size] = source[row][col];
            col++;
        }
    }

    // int temp;
    // int n = 8;
    // //transfer all array from source to destination
    // for(int row = 0; row < n; row++){
    //     for(int col = 0; col < n; col++){
    //         destination[row][col] = source[row][col];
    //     }
    // }
    
    // for(int i = 0; i < n; i++){
    //     for(int j = i; j < n; j++){
    //         //store current num in temp
    //         temp = destination[i][j];
    //         //move from left to top
    //         destination[i][j] = destination[j][n - 1 - i];
    //         //move from bottom to left
    //         destination[j][n - 1 - i] = destination[n - 1 - i][n - 1 - j];
    //         //move from right to bottom
    //         destination[n - 1 - i][n - 1 - j] = destination[n - 1 - j][n - 1 - i];
    //         //assign temp to right
    //         destination[n - 1 - j][n - 1 - i] = temp;

            
    //     }
    // cout << endl;
    // }

    // for(int i = 0; i < n; i++){
    //     for(int j = i; j < n; j++){
    //         destination[i][j] = source[i][j];
    //     }
    // }
}