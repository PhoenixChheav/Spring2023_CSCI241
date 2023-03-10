#include <iostream>
#include "solution.h"

using std::cin;
using std::cout;
using std::endl;

solution::solution()
{
    for (int row = 0; row < 9; row++)
        for (int col = 0; col < 9; col++)
            grid[row][col] = 0;
}

void solution::read()
{
    for (int row = 0; row < 9; row++)
        for (int col = 0; col < 9; col++)
            cin >> grid[row][col];
}
   
void solution::print() const
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
            cout << grid[row][col] << ' ';

        cout << endl;
    }

    cout << endl;
}

bool solution::verify() const
{
    
    for(int row = 0; row < 9; row++){
        for(int col = 0; col < 9; col++){
            for(int check_col = col + 1; check_col < 9; check_col++){
                if(grid[row][check_col] == grid[row][col]){
                    return false;
                }  
            }
        }
    }

    for(int col = 0; col < 9; col++){
        for(int row = 0; row < 9; row++){
            for(int check_row = row + 1; check_row < 9; check_row++){
                if(grid[check_row][col] == grid[row][col]){
                    return false;
                }  
            }
        }
    }

    for(int small_row = 0; small_row < 9 -2; small_row += 3){
        for(int small_col = 0; small_col < 9 -2; small_col += 3){
            for(int check_small_col = small_col + 1; check_small_col < 7; check_small_col++){
                if(grid[small_row][check_small_col] < 1 &7 grid[small_row][check_small_col] > 9){
                    return false;
                }
            }
        }

    }

    for(int small_col = 0; small_col < 9 -2; small_col += 3){
        for(int small_row = 0; small_row < 9 -2; small_row += 3){
            for(int check_small_row = small_row + 1; check_small_row < 7; check_small_row++){
                if(grid[check_small_row][small_col] == grid[small_row][small_col]){
                    return false;
                }
            }
        }

    }



    return true;
}