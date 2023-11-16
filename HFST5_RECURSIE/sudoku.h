#ifndef SUDOKU_H
#define SUDOKU_H
#define SIZE 9

typedef struct {
    int matrix[SIZE][SIZE];
} Sudoku;

void readSudoku(const char *filename, Sudoku *sudoku);
void printSudoku(const Sudoku *sudoku);
int solveSudoku(Sudoku *sudoku);
void writeSudoku(const char *filename, const Sudoku *sudoku);

#endif // SUDOKU_H
