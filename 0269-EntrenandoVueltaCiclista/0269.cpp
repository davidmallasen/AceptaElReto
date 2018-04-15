/**
 * Problema 0269: Entrenando para la vuelta ciclista
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int main() {
    int casos, total, num, dist;

    casos = readInt();
    for (int i = 0; i < casos; i++) {
        total = 0;
        dist = 0;
        num = readInt();
        while (num != 0) {
            dist += num;
            total += dist;
            num = readInt();
        }

        printf("%i\n", total * 2);
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