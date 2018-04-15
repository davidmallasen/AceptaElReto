/**
 * Problema 0267: Postes para un cercado
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int main() {
    int lado1, lado2, distmax, total;

    lado1 = readInt();
    lado2 = readInt();
    distmax = readInt();

    while (lado1 != 0 && lado2 != 0 && distmax != 0) {
        total = lado1 / distmax;
        total += lado2 / distmax;
        if (lado1 % distmax != 0) total++;
        if (lado2 % distmax != 0) total++;

        printf("%i\n", total * 2);

        lado1 = readInt();
        lado2 = readInt();
        distmax = readInt();
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