/**
 * Problema 0314: Temperaturas extremas
 *
 * Fase local Ada Byron 2016. Equipo Compiler Error:
 * David Mallasén Quintana
 * Ivan Prada Cazalla
 * Alvaro Rodriguez Garcia
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

inline int readIntNeg();

int main() {

    int num_c_prueba, tem_reg;
    int a[10000];
    num_c_prueba = readInt();

    for (int i = 0; i < num_c_prueba; i++) {
        tem_reg = readInt();
        for (int j = 0; j < tem_reg; j++) {
            a[j] = readIntNeg();
        }
        int valles = 0, picos = 0;
        for (int w = 0; w < tem_reg - 2; w++) {
            if ((a[w] < a[w + 1]) && (a[w + 1] > a[w + 2])) {
                picos++;
            } else if ((a[w] > a[w + 1]) && (a[w + 1] < a[w + 2])) {
                valles++;
            }
        }
        printf("%i %i\n", picos, valles);
    }

    return 0;
}

int readInt() {
    int num = 0;
    char ch = gc();

    while (ch < '0') ch = gc();

    while (ch >= '0') {
        num = 10 * num + ch - 48;
        ch = gc();
    }

    return num;
}

int readIntNeg() {
    int num = 0, neg = 1;
    char ch = gc();

    while (ch < '0' && ch != '-') ch = gc();
    if (ch == '-') {
        neg = -1;
        ch = gc();
    }
    while (ch >= '0') {
        num = 10 * num + ch - 48;
        ch = gc();
    }

    return num * neg;
}