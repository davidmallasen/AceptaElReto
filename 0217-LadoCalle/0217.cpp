/**
 * Problema 0217: Que lado de la calle
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int main() {
    int num = readInt();

    while (num > 0) {
        if (num % 2 == 0) printf("DERECHA\n");
        else printf("IZQUIERDA\n");

        num = readInt();
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