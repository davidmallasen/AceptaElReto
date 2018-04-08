/**
 * Problema 0149: San Fermines
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int main() {
    int n, vel, mayor;

    scanf("%d", &n);

    while (!feof(stdin)) {
        mayor = 0;

        for (int i = 0; i < n; i++) {
            vel = readInt();
            if (vel > mayor) mayor = vel;
        }
        printf("%i\n", mayor);

        scanf("%d", &n);
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