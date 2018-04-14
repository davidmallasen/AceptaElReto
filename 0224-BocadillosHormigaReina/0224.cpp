/**
 * Problema 0224: Los bocadillos de la hormiga reina
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

int trozos[100000];

inline int readInt();

int main() {
    int casos, suma, pos;
    bool enc;

    casos = readInt();

    while (casos > 0) {
        for (int c = 0; c < casos; c++)
            trozos[c] = readInt();

        suma = 0;
        for (int c = 1; c < casos; c++)
            suma += trozos[c];

        enc = false;
        for (pos = 0; pos < casos - 1 && !enc; pos++) {
            if (trozos[pos] == suma) enc = true;
            else suma -= trozos[pos + 1];
        }

        if (enc) printf("SI %i\n", pos);
        else printf("NO\n");

        casos = readInt();
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