/**
 * Problema 0126: Divisores del factorial
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readIntNeg();

int main() {
    int p = readIntNeg();

    while (p >= 0) {
        if (p <= readIntNeg() || p == 1) printf("YES\n");
        else printf("NO\n");

        p = readIntNeg();
    }

    return 0;
}

int readIntNeg() {
    int num = 0;
    char ch = gc();

    while (ch < '0' && ch != '-') ch = gc();

    if (ch == '-') {
        num = -1;
    } else {
        while (ch >= '0') {
            num = 10 * num + ch - 48;
            ch = gc();
        }
    }

    return num;
}