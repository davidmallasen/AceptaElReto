/**
 * Problema 0230: Desordenes temporales
 * David Mallasén Quintana
 */

#include <cstdio>

#define gc getchar_unlocked

typedef int v[100000];


inline int readInt();

long long int mezclaOrdenada(v arr, int ini, int fin);

long long int numInversiones(v arr, int ini, int fin);

int main() {
    int n;
    v arr;

    n = readInt();

    while (n > 0) {

        for (int i = 0; i < n; i++)
            arr[i] = readInt();

        printf("%lli\n", numInversiones(arr, 0, n - 1));

        n = readInt();
    }

    return 0;
}

int readInt() {
    int num = 0;
    char ch = gc();

    while (ch < '0')
        ch = gc();

    while (ch >= '0') {
        num = 10 * num + ch - 48;
        ch = gc();
    }

    return num;
}

long long int numInversiones(v arr, int ini, int fin) {
    int longitud = fin - ini + 1;
    if (longitud < 2) {
        return 0;
    } else if (longitud == 2) {
        if (arr[ini] > arr[fin]) {
            int aux = arr[fin];
            arr[fin] = arr[ini];
            arr[ini] = aux;
            return 1;
        } else
            return 0;
    } else {
        int medio = (ini + fin) / 2;
        long long int resultado = 0;
        resultado += numInversiones(arr, ini, medio);
        resultado += numInversiones(arr, medio + 1, fin);
        resultado += mezclaOrdenada(arr, ini, fin);

        return resultado;
    }
}

long long int mezclaOrdenada(v arr, int ini, int fin) {
    v aux;
    int medio = (fin + ini) / 2;
    long long int inversiones = 0;

    //Copia el array
    for (int i = ini; i <= fin; i++) {
        aux[i] = arr[i];
    }

    //Mezcla ordenadamente devolviendo el numero de inversiones
    int ind1 = ini, ind2 = medio + 1, ind_arr = ini;
    while (ind1 < medio + 1 && ind2 <= fin) {
        if (aux[ind1] <= aux[ind2]) {
            arr[ind_arr] = aux[ind1];
            ind1++;
        } else {
            arr[ind_arr] = aux[ind2];
            ind2++;
            //numero de numeros que faltan por añadir de la primera parte del array (numero de elementos invertidos)
            inversiones += medio + 1 - ind1;
        }
        ind_arr++;
    }
    while (ind1 < medio + 1) {
        arr[ind_arr] = aux[ind1];
        ind1++;
        ind_arr++;
    }
    while (ind2 <= fin) {
        arr[ind_arr] = aux[ind2];
        ind2++;
        ind_arr++;
    }

    return inversiones;
}