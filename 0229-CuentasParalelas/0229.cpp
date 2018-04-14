/**
 * Problema 0229: Cuentas paralelas
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

int movimientos[100000];

inline int readInt();

int main() {
    int num_mov, count, suma1, suma2;

    num_mov = readInt();

    while (num_mov > 0) {
        count = 0;
        suma1 = 0;
        suma2 = 0;

        for (int i = 0; i < num_mov; i++)
            movimientos[i] = readInt();

        for (int i = 0; i < num_mov; i++)
            suma2 += movimientos[i];

        if (suma2 == 0) count++;
        for (int i = 0; i < num_mov; i++) {
            suma1 += movimientos[i];
            suma2 -= movimientos[i];
            if (suma1 == suma2) count++;
        }

        printf("%i\n", count);

        num_mov = readInt();
    }

    return 0;
}

int readInt() {
    char ch = gc();
    int num = 0, neg = 1;

    while (ch < '0' && ch != '-') ch = gc();

    if (ch == '-') {
        neg = -1;
        ch = gc();
    }

    while (ch >= '0') {
        num = 10 * num + ch - 48;
        ch = gc();
    }

    return num * neg;
}