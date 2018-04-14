/**
 * Problema 0223: Aprendiendo a multiplicar
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

typedef int v[10000];

int main() {
    int casos, longitud, min, max, min_mejor, max_mejor, long_mejor;
    v arr;

    casos = readInt();
    for (int c = 0; c < casos; c++) {
        longitud = readInt();

        for (int l = 0; l < longitud; l++) {
            arr[l] = readInt();
        }

        min = 0;
        min_mejor = 0;
        max_mejor = 0;
        long_mejor = 0;
        for (max = 0; max < longitud; max++) {
            if (arr[max] == 0) {
                if (max - min > long_mejor) {
                    min_mejor = min;
                    max_mejor = max - 1;
                    long_mejor = max_mejor - min_mejor + 1;
                }
                min = max + 1;
            }
        }
        if (max - min > long_mejor) {
            min_mejor = min;
            max_mejor = max - 1;
            long_mejor = max_mejor - min_mejor + 1;
        }

        if (long_mejor > 0) {
            printf("%i -> [%i,%i]\n", long_mejor, min_mejor, max_mejor);
        } else {
            printf("SIGUE BUSCANDO\n");
        }
    }

    return 0;
}

inline int readInt() {
    int num = 0;
    char ch = gc();

    while (ch < '0') {
        ch = gc();
    }
    while (ch >= '0') {
        num = num * 10 + ch - 48;
        ch = gc();
    }

    return num;
}