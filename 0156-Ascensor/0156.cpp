/**
 * Problema 0156: Ascensor
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int main() {
    int num1, num2, total;

    num1 = readInt();

    while (num1 >= 0) {
        num2 = readInt();

        total = 0;
        while (num2 >= 0) {
            if (num1 > num2)
                total += num1 - num2;
            else
                total += num2 - num1;

            num1 = num2;
            num2 = readInt();
        }

        printf("%i\n", total);

        num1 = readInt();
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