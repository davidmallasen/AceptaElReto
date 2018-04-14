/**
 * Problema 0216: Goteras
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int main() {
    int casos, h, m, s;

    casos = readInt();

    for (int c = 0; c < casos; c++) {
        s = readInt();

        h = s / 3600;
        s %= 3600;

        m = s / 60;
        s %= 60;

        printf("%0*i:", 2, h);
        printf("%0*i:", 2, m);
        printf("%0*i\n", 2, s);
    }

    return 0;
}

int readInt() {
    int num = 0;
    char ch = gc();

    while (ch < '0') ch = gc();

    while (ch >= '0') {
        num = 10 * num + ch - 48;
        ch = gc();
    }

    return num;
}