/**
 * Problema 0284: La tienda de la esquina
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int main() {
    int casos, coste, dinero;
    casos = readInt();
    for (int i = 0; i < casos; ++i) {
        coste = readInt();
        dinero = readInt();
        int aux = coste - dinero;
        if (aux > 0) {
            printf("DEBE %i\n", aux);
        } else {
            aux = -aux;
            printf("%i ", aux / 200);
            aux %= 200;
            printf("%i ", aux / 100);
            aux %= 100;
            printf("%i ", aux / 50);
            aux %= 50;
            printf("%i ", aux / 20);
            aux %= 20;
            printf("%i ", aux / 10);
            aux %= 10;
            printf("%i ", aux / 5);
            aux %= 5;
            printf("%i ", aux / 2);
            aux %= 2;
            printf("%i\n", aux);
        }
    }

    return 0;
}

inline int readInt() {
    int num = 0;
    char ch = gc();
    while (ch < '0') {
        ch = gc();
    }
    while (ch >= '0') {
        num = num * 10 + ch - 48;
        ch = gc();
    }
    return num;
}
