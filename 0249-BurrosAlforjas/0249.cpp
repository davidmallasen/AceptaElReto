/**
 * Problema 0249: El burro y las alforjas
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int pesos[20000];

int main() {
    int casos = readInt();
    int burros, n_sacos, count;

    for (int c = 0; c < casos; c++) {
        burros = readInt();
        n_sacos = readInt();
        count = 0;

        for (int i = 0; i < 20000; i++)
            pesos[i] = 0;

        for (int i = 0; i < n_sacos; i++)
            pesos[readInt() - 1]++;

        for (int i = 0; i < 20000 && count < burros; i++) {
            if (pesos[i] > 0) {
                while (pesos[i] > 1 && count < burros) {
                    count++;
                    pesos[i] -= 2;
                }
            }
        }

        printf("%i\n", count);
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