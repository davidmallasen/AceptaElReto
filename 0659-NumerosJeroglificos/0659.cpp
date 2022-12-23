/**
 * Problema 0659: Números Jeroglíficos
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked
#define pc putchar_unlocked

inline bool resuelveCaso() {
    char ch = gc();

    while (ch < '0') ch = gc();

    if (ch == '0') {
        gc();
        return false;
    }

    char num_digitos = 0;
    char digitos[7];

    while (ch >= '0') {
        digitos[num_digitos] = ch - 48;
        num_digitos++;
        ch = gc();
    }

    char digito_actual = 0;
    char num_digitos_1 = num_digitos - 1;

    while (digito_actual < num_digitos) {
        for (char i = 0; i < digitos[digito_actual]; ++i) {
            switch (num_digitos_1 - digito_actual)  {
                case 0:
                    pc('T');
                    break;
                case 1:
                    pc('G');
                    break;
                case 2:
                    pc('C');
                    break;
                case 3:
                    pc('F');
                    break;
                case 4:
                    pc('D');
                    break;
                case 5:
                    pc('R');
                    break;
                case 6:
                    pc('H');
                    break;
            }
        }
        digito_actual++;
    }

    pc('\n');

    return true;
}

int main() {
    while (resuelveCaso()) {}
    return 0;
}

