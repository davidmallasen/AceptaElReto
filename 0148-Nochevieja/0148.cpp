/**
 * Problema 0148: Nochevieja
 * David Mallasén Quintana
 */


#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int main() {
    int horas, minutos;

    horas = readInt();
    minutos = readInt();

    while (horas > 0 || minutos > 0) {
        printf("%i\n", (60 - minutos) + 60 * (23 - horas));

        horas = readInt();
        minutos = readInt();
    }
    return 0;
}


int readInt() {
    char ch = gc();
    int num = 0;

    while (ch < '0') ch = gc();

    while (ch >= '0' && ch <= '9') {
        num = 10 * num + ch - 48;
        ch = gc();
    }

    return num;
}