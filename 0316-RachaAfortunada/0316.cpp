/**
 * Problema 0316: Racha afortunada
 *
 * Fase local Ada Byron 2016. Equipo Compiler Error:
 * David Mallasén Quintana
 * Ivan Prada Cazalla
 * Alvaro Rodriguez Garcia
 */

#include <cstdio>

#define gc getchar_unlocked

typedef int arr[100000];

int readIntNeg();

int main() {
    arr v;
    int casos, dias;

    casos = readIntNeg();
    for (int c = 0; c < casos; ++c) {

        dias = readIntNeg();
        for (int i = 0; i < dias; ++i) {
            v[i] = readIntNeg();
        }

        int i = 0, suma = 0, sumaMax = 0, iniMejor = 0, finMejor = 0;
        for (int j = 0; j < dias; ++j) {

            suma += v[j];

            if (suma <= 0) {
                i = j + 1;
                suma = 0;
            } else if (suma > sumaMax) {
                sumaMax = suma;
                iniMejor = i;
                finMejor = j;
            } else if (suma == sumaMax) {
                if ((finMejor - iniMejor) > (j - i)) {
                    iniMejor = i;
                    finMejor = j;
                }
            }
        }

        printf("%i %i\n", iniMejor + 1, finMejor + 1);
    }
}

int readIntNeg() {
    int num = 0;
    char ch = gc();
    bool neg = false;

    while (ch < '0' && ch != '-') {
        ch = gc();
    }
    if (ch == '-') {
        neg = true;
        ch = gc();
    }
    while (ch >= '0') {
        num = num * 10 + ch - 48;
        ch = gc();
    }

    if (neg)
        num = -num;

    return num;
}