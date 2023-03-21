#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

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
}