/**
 * Problema 0247: Saliendo de la crisis
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int main() {
    int dias[100];
    int casos;
    bool ok;

    casos = readInt();

    while (casos > 0) {
        ok = true;
        if (casos > 1) {
            for (int i = 0; i < casos; i++)
                dias[i] = readInt();

            for (int i = 0; i + 1 < casos && ok; i++)
                if (dias[i] >= dias[i + 1]) ok = false;
        }

        if (ok) printf("SI\n");
        else printf("NO\n");

        casos = readInt();
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