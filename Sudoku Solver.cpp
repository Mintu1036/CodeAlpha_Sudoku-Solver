#include <iostream>
using namespace std;

const int N = 9; // Sudoku is 9x9

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Check if placing 'num' at grid[row][col] is valid
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Row check
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return false;

    // Column check
    for (int x = 0; x < N; x++)
        if (grid[x][col] == num)
            return false;

    // 3x3 box check
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[startRow + i][startCol + j] == num)
                return false;

    return true;
}

// Backtracking function to solve Sudoku
bool solveSudoku(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == 0) { // Empty cell
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(grid, row, col, num)) {
                        grid[row][col] = num; // Place number

                        if (solveSudoku(grid))
                            return true; // Solved!

                        grid[row][col] = 0; // Undo & try next
                    }
                }
                return false; // No valid number found
            }
        }
    }
    return true; // No empty cells left
}

int main() {
    // Example Sudoku puzzle (0 means empty cell)
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    cout << "Original Sudoku Puzzle:\n";
    printGrid(grid);

    if (solveSudoku(grid)) {
        cout << "\nSolved Sudoku:\n";
        printGrid(grid);
    } else {
        cout << "\nNo solution exists!";
    }

    return 0;
}
