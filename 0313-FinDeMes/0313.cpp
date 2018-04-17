/**
 * Problema 0310: Fin de mes
 *
 * Fase local Ada Byron 2016. Equipo Compiler Error:
 * David Mallasén Quintana
 * Ivan Prada Cazalla
 * Alvaro Rodriguez Garcia
 */

#include <cstdio>

#define gc getchar_unlocked

int readIntNeg();

int main() {
    int casos = readIntNeg();
    int s, c;

    for (int cas = 0; cas < casos; cas++) {
        s = readIntNeg();
        c = readIntNeg();

        if (s + c >= 0)
            printf("SI\n");
        else
            printf("NO\n");
    }

    return 0;
}

int readIntNeg() {
    int num = 0, neg = 1;
    char ch = gc();

    while (ch < '0' && ch != '-')
        ch = gc();

    if (ch == '-') {
        neg = -1;
        ch = gc();
    }

    while (ch >= '0') {
        num = num * 10 + ch - 48;
        ch = gc();
    }

    return num * neg;
}
