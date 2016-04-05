#include <iostream>

using namespace std;
 
#define N 9

int answer[N][N];

// Checks whether it will be legal to assign num to the given row,col
bool isSafe(int grid[N][N], int row, int col, int num);

void printGrid(int grid[N][N]);

bool FindUnassignedLocation(int grid[N][N]);

void copyGrid(int orig[N][N], int copy[N][N] );

/* Takes a partially filled-in grid and attempts to assign values to
  all unassigned locations in such a way to meet the requirements
  for Sudoku solution (non-duplication across rows, columns, and boxes) */
bool SolveSudoku(int grid[N][N], int row, int col, int &counter){
    int tempRow, tempCol, tempAns;
    
    if ( !FindUnassignedLocation(grid) ) {
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
                //printGrid(grid);

                if( col == 8 ) {
                    tempCol = 0;
                    tempRow = row + 1;
                } else {
                    tempCol = col + 1;
                    tempRow = row;
                }
     
                if (SolveSudoku(grid,tempRow, tempCol, counter)) {
                    copyGrid(grid,answer);
                    counter++;
                }

                //Undoing the addition
                grid[row][col] = 0;

            }
        }
    } else {

        tempAns = grid[row][col];
        grid[row][col] = 0;
        if ( isSafe(grid, row, col, tempAns) ) {
            if (col == 8) {
                tempCol = 0;
                tempRow = row + 1;
            } else {
                tempCol = col + 1;
                tempRow = row;
            }
            grid[row][col] = tempAns;
            if (SolveSudoku(grid, tempRow, tempCol, counter)) {
                counter++;
            }
        } else {
            grid[row][col] = tempAns;
        }
    }

    return false;
}

bool FindUnassignedLocation(int grid[N][N])
{
    for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}

/* Returns a boolean which indicates whether any assigned entry
   in the specified row matches the given number. */
bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if ( (grid[row][col] == num) )
            return true;
    return false;
}
 
/* Returns a boolean which indicates whether any assigned entry
   in the specified column matches the given number. */
bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if ( (grid[row][col] == num) )
            return true;
    return false;
}
 
/* Returns a boolean which indicates whether any assigned entry
   within the specified 3x3 box matches the given number. */
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int tempRow = 0; tempRow < 3; tempRow++)
        for (int tempCol = 0; tempCol < 3; tempCol++)
            if ( (grid[tempRow+boxStartRow][tempCol+boxStartCol] == num) )
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

void copyGrid(int orig[N][N], int copy[N][N]){
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++) {
            copy[row][col] = orig[row][col];
        }
    }
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

            if ( counter == 1) {
                printGrid(answer);
            } else if ( counter > 1) {
                cout << "Non-unique\n\n";
            } else {
                cout << "Find another job\n\n";
            }


        }
    }
                   
 
    return 0;
}
