/**
 * Problema 0310: Altura de un arbol general
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

int readInt();

void alturaArbol(int &alturaMax, int k);

int main() {
    int casos, alturaMax;

    casos = readInt();
    for (int c = 0; c < casos; c++) {
        alturaMax = 0;
        alturaArbol(alturaMax, 1);
        printf("%i\n", alturaMax);
    }

    return 0;
}

void alturaArbol(int &alturaMax, int k) {
    int num;
    num = readInt();
    if (num == 0) {
        if (alturaMax < k)
            alturaMax = k;
    } else {
        for (int i = 0; i < num; i++) {
            alturaArbol(alturaMax, k + 1);
        }
    }
}

int readInt() {
    int num = 0;
    char ch = gc();

    while (ch < '0')
        ch = gc();
    while (ch >= '0') {
        num = num * 10 + ch - 48;
        ch = gc();
    }

    return num;
}