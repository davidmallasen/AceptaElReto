/**
 * Problema 0176: Campo de minas
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

bool a_minas[1000][1000];

inline int readInt();

int main() {
    int alto, ancho, casillas, minas;
    char ch;

    ancho = readInt();
    alto = readInt();

    while (alto > 0 && ancho > 0) {
        casillas = 0;

        for (int i = 0; i < alto; i++) {
            for (int j = 0; j < ancho; j++) {
                ch = gc();
                if (ch == '*') a_minas[i][j] = true;
                else a_minas[i][j] = false;
            }
            ch = gc();
        }

        for (int i = 1; i < alto - 1; i++) {
            for (int j = 1; j < ancho - 1; j++) {
                if (!a_minas[i][j]) {
                    minas = 0;
                    if (a_minas[i + 1][j + 1]) minas++;
                    if (a_minas[i][j + 1]) minas++;
                    if (a_minas[i + 1][j]) minas++;
                    if (a_minas[i + 1][j - 1]) minas++;
                    if (a_minas[i - 1][j + 1]) minas++;
                    if (a_minas[i - 1][j - 1]) minas++;
                    if (a_minas[i - 1][j]) minas++;
                    if (a_minas[i][j - 1]) minas++;

                    if (minas >= 6) casillas++;
                }
            }
        }

        printf("%i\n", casillas);

        ancho = readInt();
        alto = readInt();
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