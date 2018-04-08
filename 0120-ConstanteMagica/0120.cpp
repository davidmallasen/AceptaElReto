/**
 * Problema 0120: Constante magica
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int main() {
    int n, k;

    n = readInt();

    while (n > 0) {
        k = readInt();

        printf("%i\n", ((k + ((n * n) + k)) / 2) * n);

        n = readInt();
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