/**
 * Problema 0272: Tres dedos en cada mano
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int main() {
    int casos, base10, base6, pow;

    casos = readInt();
    for (int i = 0; i < casos; ++i) {

        base10 = readInt();
        base6 = 0;
        pow = 1;
        while (base10 > 0) {
            base6 = base6 + (base10 % 6) * pow;
            base10 /= 6;
            pow *= 10;
        }

        printf("%i\n", base6);
    }

    return 0;
}

inline int readInt() {
    int num = 0;
    char ch = gc();
    while (ch < '0') {
        ch = gc();
    }
    while (ch >= '0') {
        num = num * 10 + ch - 48;
        ch = gc();
    }
    return num;
}