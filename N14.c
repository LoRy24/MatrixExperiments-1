#include <stdio.h>

#define RIGHE 10
#define COLONNE 10

void printMatrix(const int (*matrix)[COLONNE], const int row, const int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void buildCorner(int (*matrix)[COLONNE], const int v, const int offset) {
    // Riga sopra
    for (int i = offset; i < COLONNE - offset; i++) {
        matrix[offset][i] = v;
    }

    // Riga sotto
    for (int i = offset; i < COLONNE - offset; i++) {
        matrix[RIGHE - 1 - offset][i] = v;
    }

    // Margine destro
    for (int i = offset; i < COLONNE - offset; i++) {
        matrix[i][COLONNE - 1 - offset] = v;
    }

    // Margine sinistro
    for (int i = offset; i < COLONNE - offset; i++) {
        matrix[i][offset] = v;
    }
}

void buildAzteca(int (*matrix)[COLONNE], const int v, const int offset) {
    if (offset == COLONNE / 2) {
        return;
    }

    buildCorner(matrix, v, offset);
    buildAzteca(matrix, v + 1, offset + 1);
}

void buildSpirale(int (*matrix)[COLONNE], const int v, const int x, const int y) {
    // Margini
    const int leftMargin = x - 1 < 0 ? -1 : matrix[y][x - 1];
    const int rightMargin = x + 1 == COLONNE ? -1 : matrix[y][x + 1];
    const int topMargin = y - 1 < 0 ? -1 : matrix[y - 1][x];
    const int bottomMargin = y + 1 == COLONNE ? -1 : matrix[y + 1][x];

    // Se tutti i margini sono diversi da 0, ritorna
    if (leftMargin != 0 && rightMargin != 0 && topMargin != 0 && bottomMargin != 0) {
        matrix[y][x] = v;
        return;
    }

    // Angolo sinistra sopra pieno
    if (leftMargin != 0 && topMargin != 0) {
        // Vai a destra
        if (rightMargin == 0) {
            matrix[y][x] = v;
            buildSpirale(matrix, v + 1, x + 1, y);
        }
        else { // Va sotto
            matrix[y][x] = v;
            buildSpirale(matrix, v + 1, x, y + 1);
        }
    }

    // Angolo destra sopra
    if (rightMargin != 0 && topMargin != 0) {
        // Vai sotto
        if (bottomMargin == 0) {
            matrix[y][x] = v;
            buildSpirale(matrix, v + 1, x, y + 1);
        }
        else { // Va a sinistra
            matrix[y][x] = v;
            buildSpirale(matrix, v + 1, x - 1, y);
        }
    }

    // Angolo destra sotto
    if (rightMargin != 0 && bottomMargin != 0) {
        if (leftMargin == 0) { // Va a sinistra
            matrix[y][x] = v;
            buildSpirale(matrix, v + 1, x - 1, y);
        }
        else { // Va sopra
            matrix[y][x] = v;
            buildSpirale(matrix, v + 1, x, y - 1);
        }
    }

    // Angolo sinistra sotto
    if (leftMargin != 0 && bottomMargin != 0) {
        if (topMargin == 0) { // Va sopra
            matrix[y][x] = v;
            buildSpirale(matrix, v + 1, x, y - 1);
        }
        else { // Destra
            matrix[y][x] = v;
            buildSpirale(matrix, v + 1, x + 1, y);
        }
    }
}

void buildDoppiGradini(int (*matrix)[COLONNE], const int v, const int offset) {
    if (offset == COLONNE / 2 - 1) {
        buildCorner(matrix, v, offset);
        return;
    }

    buildCorner(matrix, v, offset);
    buildCorner(matrix, v, offset + 1);
    buildDoppiGradini(matrix, v + 1, offset + 2);
}

int main(void) {
    // Matrici
    int azteca[RIGHE][COLONNE] = {0};
    int spirale[RIGHE][COLONNE] = {0};
    int doppiGradini[RIGHE][COLONNE] = {0};

    // Azteca
    buildAzteca(azteca, 1, 0);
    printMatrix(azteca, RIGHE, COLONNE);
    printf("\n");

    // Spirale
    buildSpirale(spirale, 1, 0, 0);
    printMatrix(spirale, RIGHE, COLONNE);
    printf("\n");

    // Doppi gradini
    buildDoppiGradini(doppiGradini, 1, 0);
    printMatrix(doppiGradini, RIGHE, COLONNE);
    printf("\n");

    return 0;
}
