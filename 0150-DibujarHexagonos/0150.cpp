/**
 * Problema 0150: A dibujar hexagonos
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked
#define pc putchar_unlocked

inline int readInt();

int main() {
    int lado;
    char ch;

    lado = readInt();
    ch = gc();

    while (lado > 0) {
        //Mitad superior y centro del hexagono
        for (int i = 0; i < lado; i++) {
            for (int j = lado - i - 1; j > 0; j--) { pc(' '); }
            for (int j = lado + 2 * i; j > 0; j--) { pc(ch); }
            pc('\n');
        }
        //Mitad inferior del hexagono
        for (int i = lado - 1; i > 0; i--) {
            for (int j = lado - i; j > 0; j--) { pc(' '); }
            for (int j = lado + 2 * (i - 1); j > 0; j--) { pc(ch); }
            pc('\n');
        }

        lado = readInt();
        ch = gc();
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