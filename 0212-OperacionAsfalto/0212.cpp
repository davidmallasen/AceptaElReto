/**
 * Problema 0212: Operacion asfalto
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int main() {
    bool intersecciones [50];
    int n_calles, n_inter, aux, count;

    n_calles = readInt() * 2;

    while (n_calles > 0) {
        n_inter = readInt();

        for (int i = 0; i < n_inter; i++)
            intersecciones[i] = true;

        for (int i = 0; i < n_calles; i++) {
            aux = readInt() - 1;
            intersecciones[aux] = !intersecciones[aux];
        }

        count = 0;
        for (int i = 0; i < n_inter && count <= 2; i++)
            if (!intersecciones[i]) count++;

        if (count == 0 || count == 2) printf("SI\n");
        else printf("NO\n");

        n_calles = readInt() * 2;
    }

    return 0;
}

int readInt() {
    int num = 0;
    char ch = gc();

    if (ch < '0') ch = gc();

    while (ch >= '0') {
        num = 10 * num + ch - 48;
        ch = gc();
    }

    return num;
}