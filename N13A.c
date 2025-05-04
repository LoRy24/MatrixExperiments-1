#include <math.h>
#include <stdio.h>

#define RIGHE 8
#define COLONNE 8

void printMatrix(const int (*matrix)[COLONNE], const int row, const int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void fillMatrix(int (*matrix)[COLONNE], const bool way, int row, const int val) {
    if (way) { // Destra
        for (int i = 0; i < COLONNE; ++i) {
            matrix[row][i] = val + i;
        }
    }
    else { // Sinistra
        for (int i = COLONNE - 1; i >= 0; --i) {
            matrix[row][i] = val + abs(i - COLONNE + 1);
        }
    }

    if (row == RIGHE - 1) {
        return;
    }

    fillMatrix(matrix, !way, row + 1, val + COLONNE);
}

int main(void) {
    int matrix[RIGHE][COLONNE];

    // Riempimento
    fillMatrix(matrix, 1, 0, 1);

    // Scrittura
    printMatrix(matrix, RIGHE, COLONNE);

    return 0;
}
