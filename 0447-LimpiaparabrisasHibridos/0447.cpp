/**
 * Problema 0447: Limpiaparabrisas de los hibridos
 *
 * Fase local Ada Byron 2018. Equipo MineFinder:
 * David Mallasen Quintana
 * Ivan Prada Cazalla
 * Alvaro Rodriguez Garcia
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int mcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return mcd(b, a % b);
    }
}

int main() {
    int l, r;
    int capac[4];

    l = readInt();
    while (l > 0) {
        r = readInt();
        for (int i = 0; i < r; i++) {
            capac[i] = readInt();
        }

        int gcd = 0;
        for (int i = 0; i < r; i++) {
            gcd = mcd(gcd, capac[i]);
        }

        if ((l % gcd == 0))
            printf("SI\n");
        else
            printf("NO\n");

        l = readInt();
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