/**
 * Problema 0250: El desgaste de los bombines
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readIntNeg();

int dias[1000000];

int main() {
    int casos, suma, suma1, suma2, min, dia_min;

    casos = readIntNeg();

    while (casos > 0) {
        suma1 = 0;
        suma2 = 0;
        min = 2000000000;
        dia_min = casos + 1;

        for (int i = 0; i < casos; i++)
            dias[i] = readIntNeg();

        for (int i = 0; i < casos; i++)
            suma2 += dias[i];

        for (int i = 0; i < casos; i++) {
            suma = suma1 - suma2;
            if (suma < 0) suma = -suma;

            if (suma < min) {
                min = suma;
                dia_min = i;
            }

            suma1 += dias[i];
            suma2 -= dias[i];
        }
        printf("%i\n", dia_min);

        casos = readIntNeg();
    }

    return 0;
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