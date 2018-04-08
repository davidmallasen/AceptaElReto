/**
 * Problema 0152: Va de modas...
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

const int MAX = 25000;

inline int readIntNeg();

typedef struct {
    int num;
    int rep;
} tFrec;

int elem [MAX];
tFrec frec [MAX];

int main() {
    int num, cont, cont_frec, max, num_max;

    num = readIntNeg();

    while (num > 0) {
        for (int i = 0; i < num; i++)
            elem[i] = readIntNeg();

        cont = 0;
        for (int i = 0; i < num; i++)
            if (elem[i] == 0) cont++;

        if (cont > 0) {
            cont_frec = 1;
            frec[0].num = 0;
            frec[0].rep = cont;
        } else
            cont_frec = 0;

        for (int i = 0; i < num; i++) {
            if (elem[i] != 0) {
                cont = 1;
                for (int j = i + 1; j < num; j++) {
                    if (elem[j] == elem[i]) {
                        cont++;
                        elem[j] = 0;
                    }
                }
                frec[cont_frec].num = elem[i];
                frec[cont_frec].rep = cont;
                cont_frec++;
            }
        }

        max = 0;
        for (int i = 0; i < cont_frec; i++) {
            if (frec[i].rep > max) {
                max = frec[i].rep;
                num_max = frec[i].num;
            }
        }

        printf("%i\n", num_max);

        num = readIntNeg();
    }

    return 0;
}


int readIntNeg() {
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
    num *= neg;

    return num;
}