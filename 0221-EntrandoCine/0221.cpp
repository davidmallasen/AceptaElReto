/**
 * Problema 0221: Entrando al cine
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int vecinos[10000];

int main() {
    int casos, n_vecinos, cont, i;

    casos = readInt();

    for (int c = 0; c < casos; c++) {
        cont = 0;
        n_vecinos = readInt();

        for (i = 0; i < n_vecinos; i++)
            vecinos[i] = readInt();

        for (i = 0; i < n_vecinos && vecinos[i] % 2 == 0; ++i)
            cont++;
        for (i; i < n_vecinos && vecinos[i] % 2 == 1; ++i);

        if (i == n_vecinos) printf("SI %i\n", cont);
        else printf("NO\n");
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