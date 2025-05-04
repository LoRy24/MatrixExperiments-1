#include <stdio.h>

#define RIGHE 8
#define COLONNE 8

void printMatrix(const int (*matrix)[COLONNE], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int matrix[RIGHE][COLONNE];

    // Riempimento
    for (int i = 0; i < RIGHE; i++) {
        for (int j = 0; j < COLONNE; j++) {
            matrix[i][j] = j + i + 1;
        }
    }

    printMatrix(matrix, RIGHE, COLONNE);

    return 0;
}
