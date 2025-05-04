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
    int offset = 0;

    while (offset < COLONNE) {
        for (int i = offset; i < COLONNE; i++) {
            matrix[offset][i] = 1 + i - offset;
            matrix[i][offset] = 1 + i - offset;
        }
        offset++;
    }

    printMatrix(matrix, RIGHE, COLONNE);
    return 0;
}
