/**
 * Problema 0245: Los dalton
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

inline long long int readInt();

int main() {
    long long int personas, p, anterior, altura;
    bool ok;
    char ch;

    personas = readInt();

    while (personas != 0) {
        p = 2;
        ok = true;

        altura = readInt();
        anterior = readInt();

        if (altura > anterior) {    //El segundo es menor que el primero
            while (p < personas && ok) {
                altura = readInt();
                if (altura >= anterior)
                    ok = false;
                else {
                    p++;
                    anterior = altura;
                }
            }
        } else if (altura < anterior) {
            while (p < personas && ok) {
                altura = readInt();
                if (altura <= anterior)
                    ok = false;
                else {
                    p++;
                    anterior = altura;
                }
            }
        } else
            ok = false;

        if (ok)
            printf("DALTON\n");
        else {
            if (p < personas - 1) {
                ch = gc();
                while (ch != '\n')
                    ch = gc();
            }

            printf("DESCONOCIDOS\n");
        }

        personas = readInt();
    }

    return 0;
}

inline long long int readInt() {
    char ch = gc();
    long long int num = 0;

    while (ch < '0')
        ch = gc();

    while (ch >= '0') {
        num = 10 * num + ch - 48;
        ch = gc();
    }

    return num;
}