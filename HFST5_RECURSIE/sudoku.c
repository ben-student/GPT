#include <stdio.h>
#include "sudoku.h"
// #define SIZE 9

int isSafe(Sudoku *sudoku, int row, int col, int num) {
    for (int i = 0; i < SIZE; i++) {
        if (sudoku->matrix[row][i] == num || sudoku->matrix[i][col] == num) {
            return 0; //regels van sudoku oplossen (kijken of er al een getal is in de rij of kolom??)
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3; //3x3 subraster

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku->matrix[i + startRow][j + startCol] == num) {
                return 0; //REgels van sudoku voor het subraster 
            }
        }
    }

    return 1; //veilig om getal te plaatsen
}

int findEmptyCell(Sudoku *sudoku, int *row, int *col) { 
    for (*row = 0; *row < SIZE; (*row)++) { //rijden afgaan
        for (*col = 0; *col < SIZE; (*col)++) { //kolommen afgaan
            if (sudoku->matrix[*row][*col] == 0) { 
                return 1; //lege cell gevonden *row en *col worden gebruikt om lege cel aan te duiden
            }
        }
    }
    return 0;
}

int solveSudoku(Sudoku *sudoku) {
    int row, col;
    static int rec = 0;
    if (!findEmptyCell(sudoku, &row, &col)) {
        return 1; //geen lege cellen ==  sudoku klaar
    }

    for (int num = 1; num <= SIZE; num++) {
        if (isSafe(sudoku, row, col, num)) { //checken of num in lege cel van findEmptycell geplaatst mag worden
            sudoku->matrix[row][col] = num; //plaatsen van num in lege cel

            if (solveSudoku(sudoku)) { //recursieve functie om de sudoku verder op te lossen
                rec++;
                printf("recursie niveau : %d\n", rec);
                return 1; //1 niveau dieper in recursie, cell is weer opgevuld geraakt.
            }

            sudoku->matrix[row][col] = 0; 
        }
    }

    return 0;
}

//sudoko file uitlezen uit output.txt

void readSudoku(const char *filename, Sudoku *sudoku) { 
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file");
        return;
    }
    //for loop 9 vervangen door #define SIZE 9
    for (int i = 0; i < SIZE; i++) { //rij itereren
        for (int j = 0; j < SIZE; j++) { //kolommen itereren
            char ch;
            fscanf(file, " %c", &ch); //scannen voor char in file (A karakters)
            if (ch == 'A') {
                sudoku->matrix[i][j] = 0; //Matrix opvullen met 0 waarden voor A chrs
            } else {
                sudoku->matrix[i][j] = ch - '0'; //char omzetten naar integer door ASCII conversie ('5' - '0' = 5)
            }
        }
    }

    fclose(file);
}

void printSudoku(const Sudoku *sudoku) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) { //itereren over rijen en kolommen
            if (sudoku->matrix[i][j] == 0) {  
                printf("A");//A printen voor null waarden
            } else {
                printf("%d", sudoku->matrix[i][j]); //anders gewoon waarden printen
            }

            if (j != SIZE - 1) { //na elke kolom buiten de laatste
                printf(" "); //Spatie tussenin de kolommen printen
            }
        }
        printf("\n");
    }
}

void writeSudoku(const char *filename, const Sudoku *sudoku) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (sudoku->matrix[i][j] == 0) {
                fprintf(file, "A");
            } else {
                fprintf(file, "%d", sudoku->matrix[i][j]);
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
}
