/**
 * Problema 0168: La pieza perdida
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

bool arr [10001];

int main() {
    int piezas, pos;

    piezas = readInt();

    while (piezas > 0) {
        for (int i = 1; i <= piezas; i++)
            arr[i] = false;

        for (int i = 1; i < piezas; i++) //Se lee piezas-1 piezas
            arr[readInt()] = true;

        pos = 1;
        while (arr[pos]) pos++;

        printf("%i\n", pos);

        piezas = readInt();
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