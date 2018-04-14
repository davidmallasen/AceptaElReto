/**
 * Problema 0238: Repartiendo el botin
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked


typedef struct {
    int billetes[1000];
    int num;
    int total;
} tParticipante;

tParticipante participantes[10];

inline int readInt();

int main() {
    int billetes, personas;

    billetes = readInt();
    personas = readInt();

    while (billetes > 0) { //==> personas > 0

        for (int i = 0; i < personas; i++) {
            participantes[i].num = 0;
            participantes[i].total = 0;
        }

        int p;
        for (p = 0, billetes; billetes > 0; billetes--, p++) {
            if (p == personas) p = 0;
            participantes[p].billetes[participantes[p].num] = readInt();
            participantes[p].total += participantes[p].billetes[participantes[p].num];
            participantes[p].num++;
        }

        for (int i = 0; i < personas; i++) {
            printf("%i:", participantes[i].total);

            for (int j = 0; j < participantes[i].num; j++) {
                printf(" %i", participantes[i].billetes[j]);
            }

            printf("\n");
        }
        printf("---\n");

        billetes = readInt();
        personas = readInt();
    }

    return 0;
}


int readInt() {
    char ch = gc();
    int num = 0;

    while (ch < '0' || ch > '9') ch = gc();

    while (ch >= '0' && ch <= '9') {
        num = 10 * num + ch - 48;
        ch = gc();
    }

    return num;
}