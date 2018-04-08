/**
 * Problema 0155: Perimetro de un rectangulo
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int main() {
    int num1, num2;

    num1 = readInt();
    num2 = readInt();

    while (num1 > -1) {
        printf("%i\n", ((num1 * 2) + (num2 * 2)));

        num1 = readInt();
        num2 = readInt();
    }

    return 0;
}

int readInt() {
    char ch = gc();
    int num = 0;

    while (ch < '0' && ch != '-') ch = gc();

    if (ch == '-') return -1;

    while (ch >= '0') {
        num = 10 * num + ch - 48;
        ch = gc();
    }

    return num;
}