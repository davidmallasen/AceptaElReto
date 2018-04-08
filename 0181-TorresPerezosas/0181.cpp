/**
 * Problema 0181: Las torres perezosas
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int main() {
    int dim;
    int tablero[16][16];
    char ch;

    for (int i = 1; i < 16; i++) {
        tablero[0][i] = 0;
        tablero[i][0] = 0;
    }

    dim = readInt();

    while (dim > 0) {
        for (int i = dim; i > 0; i--) {
            for (int j = 1; j <= dim; j++) {
                ch = gc();
                if (ch == '.') tablero[i][j] = 0;
                else tablero[i][j] = -1;
            }
            ch = gc();
        }

        tablero[1][1] = 1;
        for (int i = 1; i <= dim; i++) {
            for (int j = 1; j <= dim; j++) {
                if (tablero[i][j] != -1) {
                    if (tablero[i - 1][j] > 0) tablero[i][j] = tablero[i - 1][j];
                    if (tablero[i][j - 1] > 0) tablero[i][j] += tablero[i][j - 1];
                }
            }
        }

        printf("%i\n", tablero[dim][dim]);

        dim = readInt();
    }

    return 0;
}

int readInt() {
    char ch = gc();
    int num = 0;

    while (ch < '0') ch = gc();
    while (ch >= '0') {
        num = 10 * num + ch - 48;
        ch = gc();
    }

    return num;
}