/**
 * Problema 0315: Jugando al buscaminas
 *
 * Fase local Ada Byron 2016. Equipo Compiler Error:
 * David Mallasén Quintana
 * Ivan Prada Cazalla
 * Alvaro Rodriguez Garcia
 */

#include <iostream>
#include <cstdio>

#define gc getchar_unlocked

using namespace std;

struct pos {
    int i;
    int j;
};

typedef bool mat[51][51];
typedef char sol[51][51];
typedef pos arr[3000];

bool show(mat superficie, sol soluciones, pos casilla, int tami, int tamj);

int contar(mat superficie, pos casilla, int tami, int tamj);

int main() {
    int tami, tamj, num_casos;
    mat superficie;
    sol soluciones;
    arr posiciones;
    char ch;

    cin >> tami >> tamj;
    while (!cin.eof()) {

        ch = gc();
        for (int i = 0; i < tami; i++) {
            for (int j = 0; j < tamj; j++) {
                ch = gc();
                if (ch == '*')
                    superficie[i][j] = true;
                else
                    superficie[i][j] = false;
            }
            ch = gc();
        }

        cin >> num_casos;
        for (int c = 0; c < num_casos; c++) {
            cin >> posiciones[c].i >> posiciones[c].j;
            posiciones[c].i--;
            posiciones[c].j--;
        }

        for (int i = 0; i < tami; i++) {
            for (int j = 0; j < tamj; j++) {
                soluciones[i][j] = 'X';
            }
        }

        bool eano = false;
        for (int i = 0; i < num_casos && !eano; i++) {
            eano = show(superficie, soluciones, posiciones[i], tami, tamj);
        }

        if (eano) {
            printf("GAME OVER\n");
        } else {
            for (int i = 0; i < tami; i++) {
                for (int j = 0; j < tamj; j++) {
                    putchar(soluciones[i][j]);
                }
                printf("\n");
            }
        }

        cin >> tami >> tamj;
    }

    return 0;
}

bool show(mat superficie, sol soluciones, pos casilla, int tami, int tamj) {
    if (soluciones[casilla.i][casilla.j] == 'X') {
        int bombas = contar(superficie, casilla, tami, tamj);
        if (superficie[casilla.i][casilla.j]) {
            return true;
        } else if (bombas == 0) {
            soluciones[casilla.i][casilla.j] = '-';
            int xmin = max(casilla.i - 1, 0), xmax = min(casilla.i + 1,
                                                         tami - 1);
            int ymin = max(casilla.j - 1, 0), ymax = min(casilla.j + 1,
                                                         tamj - 1);
            for (int x = xmin; x <= xmax; x++) {
                for (int y = ymin; y <= ymax; y++) {
                    pos aux;
                    aux.i = x;
                    aux.j = y;
                    if (show(superficie, soluciones, aux, tami, tamj)) {
                        return true;
                    }
                }
            }
        } else {
            soluciones[casilla.i][casilla.j] = bombas + '0';
        }
    }
    return false;
}

//cuantas bombas tiene alrededor
int contar(mat superficie, pos casilla, int tami, int tamj) {
    int suma = 0;
    int xmin = max(casilla.i - 1, 0), xmax = min(casilla.i + 1, tami - 1);
    int ymin = max(casilla.j - 1, 0), ymax = min(casilla.j + 1, tamj - 1);
    for (int x = xmin; x <= xmax; x++) {
        for (int y = ymin; y <= ymax; y++) {
            if (superficie[x][y] && (x != casilla.i || y != casilla.j)) {
                suma++;
            }
        }
    }
    return suma;
}