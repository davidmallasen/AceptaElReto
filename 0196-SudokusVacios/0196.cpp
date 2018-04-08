/**
 * Problema 0196: Sudokus vacios
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

inline bool readIntBarra();

int main() {
    bool tablero[9][9];
    int casos, cont;
    bool ok;

    casos = readInt();

    for (int c = 0; c < casos; c++) {
        cont = 0;

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                tablero[i][j] = readIntBarra();

        for (int i = 0; i < 9 && cont < 33; i++)
            for (int j = 0; j < 9; j++)
                if (tablero[i][j]) cont++;

        if (cont > 32) ok = false;
        else {
            ok = true;
            for (int i1 = 0, i2 = 8; (i1 < 5) && ok; i1++, i2--) {
                for (int j1 = 0, j2 = 8; (j1 < 9) && ok; j1++, j2--) {
                    if (tablero[i1][j1] && !tablero[i2][j2]) ok = false;
                    else if (!tablero[i1][j1] && tablero[i2][j2]) ok = false;
                }
            }
        }

        if (ok) printf("SI\n");
        else printf("NO\n");
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

bool readIntBarra() {
    char ch = gc();

    while (ch < '-') ch = gc();

    return ch != '-';
}