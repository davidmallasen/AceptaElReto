/**
 * Problema 0179: Molinos de viento
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline int read_int();

int molinos[1000001];

int main() {
    int n_molinos, min, max, energia;

    molinos[0] = 0;

    n_molinos = read_int() + 1;

    while (n_molinos != 1) {
        energia = read_int();
        molinos[1] = energia;

        for (int i = 2; i < n_molinos; i++) {
            energia = read_int();
            molinos[i] =
                    molinos[i - 1] + energia;  //En cada casilla guardamos la suma de todas las energias anteriores.
        }

        n_molinos = read_int(); //n_casos

        for (int i = 0; i < n_molinos; i++) {
            min = read_int();
            max = read_int();

            printf("%i\n", molinos[max] - molinos[min - 1]);
        }

        n_molinos = read_int();
        n_molinos++;
    }

    return 0;
}


inline int read_int() {
    char ch = gc();
    int num = 0;

    while (ch < '0') ch = gc();

    while (ch >= '0' && ch <= '9') {
        num = 10 * num + ch - 48;
        ch = gc();
    }

    return num;
}