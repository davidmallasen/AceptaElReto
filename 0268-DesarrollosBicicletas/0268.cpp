/**
 * Problema 0268: Desarrollos en las bicicletas
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

typedef struct {
    int plato;
    int corona;
    double relacion;
} tElem;

inline int readInt();

int main() {
    int n_platos, n_coronas, cont;
    int platos[20];
    int coronas[20];
    tElem elem;
    tElem elementos[400];

    n_platos = readInt();
    n_coronas = readInt();

    while (n_platos != 0 && n_coronas != 0) {
        for (int i = 0; i < n_platos; i++)
            platos[i] = readInt();

        for (int i = 0; i < n_coronas; i++)
            coronas[i] = readInt();

        cont = 0;
        for (int i = 0; i < n_platos; i++) {
            for (int j = 0; j < n_coronas; j++) {
                elem.plato = platos[i];
                elem.corona = coronas[j];
                elem.relacion = double(platos[i]) / double(coronas[j]);

                int k;
                for (k = cont; k > 0 && elementos[k - 1].relacion > elem.relacion; k--)
                    elementos[k] = elementos[k - 1];
                elementos[k] = elem;
                cont++;
            }
        }

        for (int i = 0; i < cont - 1; i++)
            printf("%d-%d ", elementos[i].plato, elementos[i].corona);

        printf("%d-%d\n", elementos[cont - 1].plato, elementos[cont - 1].corona);

        n_platos = readInt();
        n_coronas = readInt();
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