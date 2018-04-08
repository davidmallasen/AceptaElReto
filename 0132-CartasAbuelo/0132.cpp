/**
 * Problema 0132: Las cartas del abuelo
 * David Mallasén Quintana
 *
 * Idea: resuelveCaso lee y procesa la linea. El vector conjunto contiene en
 *  que conjunto esta cada posicion de la linea. Dos posiciones estan en el
 *  mismo conjunto si todos los caracteres entre ellos (incluidas ambas
 *  posiciones) son iguales.
 */

#include <cstdio>

#define gc getchar_unlocked

inline int readInt();

char frase [1000000];
int conjunto [1000000];

bool resuelveCaso() {
    int l = 0, iCjto = 0;

    frase[l] = gc();
    while(frase[l] != '\n') {
        ++l;
        frase[l] = gc();
    }

    conjunto[0] = iCjto;
    for(int i = 1; i < l; ++i) {
        if (frase[i-1] != frase[i]) {
            iCjto++;
        }
        conjunto[i] = iCjto;
    }

    int nIntervalos, j, k;

    nIntervalos = readInt();
    if (nIntervalos == 0) {
        return false;
    }

    for (int n = 0; n < nIntervalos; ++n) {
        j = readInt();
        k = readInt();

        if (conjunto[j] == conjunto[k]) {
            printf("SI\n");
        } else {
            printf("NO\n");
        }
    }

    printf("\n");

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}

int readInt() {
    char ch = gc();
    int num = 0;

    if (ch == '-') return -1;

    while (ch >= '0') {
        num = 10 * num + ch - 48;
        ch = gc();
    }

    return num;
}