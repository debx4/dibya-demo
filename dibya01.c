 #include <stdio.h>
    #include <stdbool.h>
    
    #define SIZE 9
    
    // Function to print the Sudoku grid
    void printGrid(int grid[SIZE][SIZE]) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%2d ", grid[i][j]);
            }
            printf("\n");
        }
    }
    
    // Function to check if a number can be placed in the given position
    bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
        // Check if the number is not present in the current row and column
        for (int x = 0; x < SIZE; x++) {
            if (grid[row][x] == num || grid[x][col] == num) {
                return false;
            }
        }
    
        // Check if the number is not present in the current 3x3 subgrid
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i + startRow][j + startCol] == num) {
                    return false;
                }
            }
        }
    
        // The number can be placed in the given position
        return true;
    }
    
    // Function to solve the Sudoku puzzle using backtracking
    bool solveSudoku(int grid[SIZE][SIZE]) {
        int row, col;
    
        // Find an unassigned position
        bool isEmpty = false;
        for (row = 0; row < SIZE; row++) {
            for (col = 0; col < SIZE; col++) {
                if (grid[row][col] == 0) {
                    isEmpty = true;
                    break;
                }
            }
            if (isEmpty) {
                break;
            }
        }
    
        // If there is no unassigned position, the puzzle is solved
        if (!isEmpty) {
            return true;
        }
    
        // Try placing numbers 1 to 9 in the current position
        for (int num = 1; num <= 9; num++) {
            if (isSafe(grid, row, col, num)) {
                // Place the number in the current position
                grid[row][col] = num;
    
                // Recur to solve the rest of the puzzle
                if (solveSudoku(grid)) {
                    return true; // If a solution is found, return true
                }
    
                // If placing the number leads to an invalid solution, backtrack
                grid[row][col] = 0;
            }
        }
    
        // If no number can be placed in the current position, backtrack
        return false;
    }
    
    int main() {
        int grid[SIZE][SIZE];
    
        // Input the Sudoku grid (0 represents unassigned cells)
        printf("Enter the Sudoku grid (use 0 for unassigned cells):\n");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                scanf("%d", &grid[i][j]);
            }
        }
    
        // Solve the Sudoku puzzle
        if (solveSudoku(grid)) {
            printf("\nSolution:\n");
            printGrid(grid);
        } else {
            printf("\nNo solution exists.\n");
        }
    
        return 0;
    }
    