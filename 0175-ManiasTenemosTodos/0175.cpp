/**
 * Problema 0175: Manias tenemos todos
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

int main() {
    int casos, semanas;
    char ch;

    casos = readInt();

    for (int c = 0; c < casos; c++) {
        int dia_menor = 0;
        int frecuencias [7] = {0, 0, 0, 0, 0, 0, 0};

        semanas = readInt();

        int menor = semanas;

        for (int s = 0; s < semanas; s++) {
            for (int d = 0; d < 7; d++) {
                ch = gc();

                while (ch == '\n') ch = gc();

                if (ch == '*') frecuencias[d]++;
            }
        }

        for (int i = 0; i < 7; i++) {
            if (frecuencias[i] < menor) {
                menor = frecuencias[i];
                dia_menor = i;
            }
        }

        if (dia_menor == 0) printf("L ");
        else if (dia_menor == 1) printf("M ");
        else if (dia_menor == 2) printf("X ");
        else if (dia_menor == 3) printf("J ");
        else if (dia_menor == 4) printf("V ");
        else if (dia_menor == 5) printf("S ");
        else if (dia_menor == 6) printf("D ");

        printf("%i\n", frecuencias[dia_menor] + 1);
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