/**
 * Problema 0265: Suma descendente
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt(int &digit);

int main() {
    int num, total, digit, diez;

    digit = 0;
    num = readInt(digit);

    while (num != 0) {
        total = num;

        diez = 10;
        for (digit; digit > 1; digit--) {
            total += num % diez;
            diez *= 10;
        }

        printf("%i\n", total);

        digit = 0;
        num = readInt(digit);
    }

    return 0;
}


int readInt(int &digit) {
    char ch = gc();
    int num = 0;

    while (ch < '0') ch = gc();
    while (ch >= '0') {
        num = 10 * num + ch - 48;
        digit++;
        ch = gc();
    }

    return num;
}