/**
 * Problema 0165: Numero hyperpar
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int main() {
    int num;
    bool ok;

    num = readInt();

    while (num >= 0) {
        ok = true;

        while (num > 0 && ok) {
            if (num % 2 == 1) ok = false;
            else num /= 10;
        }

        if (ok) printf("SI\n");
        else printf("NO\n");

        num = readInt();
    }

    return 0;
}

int readInt() {
    char ch = gc();
    int num = 0;

    if (ch == '-') return -1;

    while (ch >= '0') {
        num = 10 * num + ch - 48;
        ch = gc();
    }

    return num;
}