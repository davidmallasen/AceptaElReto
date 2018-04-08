/**
 * Problema 0119: Escudos del ejercito romano
 * David Mallasén Quintana
 */

#include <cstdio>
#include <cmath>

#define gc getchar_unlocked

inline int readInt();

int main() {
    int soldados, escudos, raiz;

    soldados = readInt();

    while (soldados > 0) {
        escudos = 0;
        while (soldados > 0) {
            raiz = sqrt(soldados);
            soldados -= raiz * raiz;
            escudos += raiz * raiz + 4 * raiz;
        }

        printf("%i\n", escudos);
        soldados = readInt();
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