/**
 * Problema 0207: Sombras en el camping
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

//Terreno real + 1 casilla alrededor
//0 = nada; 1 = arbol; 2 = sombra
int parcelas [52][52];

int main() {
    int c, f, a, c2, f2, cont;

    c = readInt();
    f = readInt();
    a = readInt();

    while (c > 0) {
        for (int i = 1; i <= f; i++) //Reset terreno real
            for (int j = 1; j <= c; j++)
                parcelas[i][j] = 0;

        cont = 0;
        if (a > 0) {
            for (int i = 0; i < a; i++) {
                c2 = readInt();
                f2 = readInt();     //c2 y f2 (1...n) coincide con el terreno "real" en el array
                parcelas[f2][c2] = 1;

                if (parcelas[f2 + 1][c2] != 1) parcelas[f2 + 1][c2] = 2;
                if (parcelas[f2][c2 + 1] != 1) parcelas[f2][c2 + 1] = 2;
                if (parcelas[f2 - 1][c2] != 1) parcelas[f2 - 1][c2] = 2;
                if (parcelas[f2][c2 - 1] != 1) parcelas[f2][c2 - 1] = 2;
                if (parcelas[f2 + 1][c2 + 1] != 1) parcelas[f2 + 1][c2 + 1] = 2;
                if (parcelas[f2 - 1][c2 - 1] != 1) parcelas[f2 - 1][c2 - 1] = 2;
                if (parcelas[f2 + 1][c2 - 1] != 1) parcelas[f2 + 1][c2 - 1] = 2;
                if (parcelas[f2 - 1][c2 + 1] != 1) parcelas[f2 - 1][c2 + 1] = 2;
            }

            for (int i = 1; i <= f; i++)
                for (int j = 1; j <= c; j++)
                    if (parcelas[i][j] == 2) cont++;
        }

        printf("%i\n", cont);

        c = readInt();
        f = readInt();
        a = readInt();
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