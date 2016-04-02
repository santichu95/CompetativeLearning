// A Backtracking program  in C++ to solve Sudoku problem
#include <stdio.h>
#include <iostream>

using namespace std;
 
// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0
 
// N is used for size of Sudoku grid. Size will be NxN
#define N 9

// Checks whether it will be legal to assign num to the given row,col
bool isSafe(int grid[N][N], int row, int col, int num);
 
/* Takes a partially filled-in grid and attempts to assign values to
  all unassigned locations in such a way to meet the requirements
  for Sudoku solution (non-duplication across rows, columns, and boxes) */
bool SolveSudoku(int grid[N][N], int row, int col, int &counter){
    int tempRow, tempCol;
    
    if ( row == 9 && col == 0) {
        return true;
    }


    if ( grid[row][col] == 0 ){
        for (int num = 1; num <= 9; num++)
        {
            // if looks promising
            if (isSafe(grid, row, col, num))
            {
                //Temp addition
                grid[row][col] = num;

                if( col == 8 ) {
                    tempCol = 0;
                    tempRow = row + 1;
                } else {
                    tempCol = col + 1;
                }
     
                if (SolveSudoku(grid,tempRow, tempCol, counter)) {
                    cout << "Trigger\n\n";
                    counter++;
                }

                //Undoing the addition
                grid[row][col] = UNASSIGNED;

            }
        }
    } else {
        if( col == 8 ) {
            tempCol = 0;
            tempRow = row + 1;
        } else {
            tempCol = col + 1;
        }
        SolveSudoku(grid,tempRow,tempCol, counter);
    }

    return false;


    /*
    int row, col;
 
    // If there is no unassigned location, we are done
    if (!FindUnassignedLocation(grid, row, col))
       return true; // success!
 
    // consider digits 1 to 9
    for (int num = 1; num <= 9; num++)
    {
        // if looks promising
        if (isSafe(grid, row, col, num))
        {
            // make tentative assignment
            grid[row][col] = num;
 
            // return, if success, yay!
            if (SolveSudoku(grid))
                return true;
 
            // failure, unmake & try again
            grid[row][col] = UNASSIGNED;
        }
    }
    return false; // this triggers backtracking
    */
}
 
 
/* Returns a boolean which indicates whether any assigned entry
   in the specified row matches the given number. */
bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
/* Returns a boolean which indicates whether any assigned entry
   in the specified column matches the given number. */
bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
/* Returns a boolean which indicates whether any assigned entry
   within the specified 3x3 box matches the given number. */
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}
 
/* Returns a boolean which indicates whether it will be legal to assign
   num to the given row,col location. */
bool isSafe(int grid[N][N], int row, int col, int num)
{
    /* Check if 'num' is not already placed in current row,
       current column and current 3x3 box */
    return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row%3 , col - col%3, num);
}
 
/* A utility function to print grid  */
void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
       for (int col = 0; col < N; col++) {
           cout << grid[row][col];
           if ( col != N - 1){
               cout << " ";
           }
       }
       cout << endl;
    }
    cout << endl;
}
 
/* Driver Program to test above functions */
int main()
{
    // 0 means unassigned cells
    int grid[9][9];
    int temp;
    int counter = 0;
    int i = 0;

    while ( cin >> temp ) {
        grid[i][0] = temp;
        for (int j = 1; j < 9; j++) {
            cin >> temp;
            grid[i][j] = temp;
        }
        i++;
        if ( i == 9) {
            i = 0;
            counter = 0;
            SolveSudoku(grid, 0, 0, counter);
            cout << counter << endl;
            if ( counter == 1) {
                printGrid(grid);
            } else if ( counter > 1) {
                cout << "Non-unique\n";
            } else {
                cout << "Find another job\n";
            }
            /*
            if (SolveSudoku(grid, 0, 0, counter) == true)
                  printGrid(grid);
            else if ( counter > 0 )
                cout << "Non-unique\n";
            else
                cout << "find another job\n";
                */
        }
    }
                   
 
    return 0;
}
