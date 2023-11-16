#include <stdio.h>
#include "sudoku.h"

int main() {
    Sudoku sudoku;
    readSudoku("sudoku.txt", &sudoku);

    printf("Input Sudoku:\n");
    printSudoku(&sudoku);

    if (solveSudoku(&sudoku)) {
        printf("\nSudoku Solved:\n");
        printSudoku(&sudoku);
        writeSudoku("output.txt", &sudoku);
    } else {
        printf("\nNo solution found!\n");
    }

    return 0;
}
