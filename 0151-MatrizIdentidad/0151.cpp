/**
 * Problema 0151: Es matriz identidad
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readIntNeg();

typedef int aMatriz[50][50];
aMatriz matriz;

int main() {
    int fila;
    bool id;

    fila = readIntNeg();

    while (fila > 0) {
        for (int i = 0; i < fila; i++)
            for (int j = 0; j < fila; j++)
                matriz[i][j] = readIntNeg();


        id = true;
        for (int i = 0; i < fila && id; i++) {
            for (int j = 0; j < fila && id; j++) {
                if (i == j) {
                    if (matriz[i][j] != 1) {
                        id = false;
                    }
                } else if (matriz[i][j] != 0) {
                    id = false;
                }
            }
        }

        if (id) printf("SI\n");
        else printf("NO\n");

        fila = readIntNeg();
    }

    return 0;
}

int readIntNeg() {
    char ch = gc();
    int num = 0;
    bool neg = false;

    while (ch < '0' && ch != '-') ch = gc();

    if (ch == '-') {
        neg = true;
        ch = gc();
    }

    while (ch >= '0') {
        num = 10 * num + ch - 48;
        ch = gc();
    }

    if (neg) num = -num;

    return num;
}