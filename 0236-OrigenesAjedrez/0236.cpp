/**
 * Problema 0236: Los origenes del ajedrez
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int main() {
    int granos, mult, casillas;
    unsigned long long int total, t;

    granos = readInt();
    mult = readInt();
    casillas = readInt();

    while (granos != 0 || mult != 0 || casillas != 0) {
        if (granos != 0 && mult != 0 && casillas != 0) {
            if (mult == 1) printf("%i\n", granos * casillas);
            else if (casillas == 1) printf("%i\n", granos);
            else {
                total = granos;
                for (int i = 1; i < casillas; i++) {
                    t = 1;

                    for (int j = 0; j < i; j++)
                        t *= mult;

                    total += granos * t;
                }

                printf("%llu\n", total);
            }
        } else if (granos == 0 || casillas == 0)
            printf("%i\n", 0);
        else
            printf("%i\n", granos);

        granos = readInt();
        mult = readInt();
        casillas = readInt();
    }

    return 0;
}


int readInt() {
    char ch = gc();
    int num = 0;

    while (ch < '0') ch = gc();

    while (ch >= '0' && ch <= '9') {
        num = 10 * num + ch - 48;
        ch = gc();
    }
    return num;
}