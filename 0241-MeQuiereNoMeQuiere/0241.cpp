/**
 * Problema 0241: Me quiere, no me quiere
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int main() {
    int casos, num;

    casos = readInt();

    for (int c = 0; c < casos; c++) {
        num = readInt();

        if (num < 6) {
            if (num == 3) printf("0\n");
            else if (num == 4) printf("1\n");
            else printf("IMPOSIBLE\n");
        } else {
            printf("%i\n", num % 3);
        }
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