/**
 * Problema 0161: Calculo de la mediana
 * David Mallasén Quintana
 */

#include <cstdio>
#include <queue>

void anyadeMediana(
        std::priority_queue<int, std::vector<int>, std::less<int>> &menoresMediana,
        std::priority_queue<int, std::vector<int>, std::greater<int>> &mayoresMediana,
        int dato) {

    //Insertamos el dato donde le corresponda
    //menoresMediana tiene al menos un elemento, el que insertamos como
    // primer elemento
    if (dato > menoresMediana.top()) {
        mayoresMediana.push(dato);
    } else {
        menoresMediana.push(dato);
    }

    //Equilibramos las dos colas para que la diferencia de elementos entre
    // una y otra sea como mucho uno.
    int aux;
    if (menoresMediana.size() > mayoresMediana.size() + 1) {
        aux = menoresMediana.top();
        menoresMediana.pop();
        mayoresMediana.push(aux);
    } else if (mayoresMediana.size() > menoresMediana.size() + 1) {
        aux = mayoresMediana.top();
        mayoresMediana.pop();
        menoresMediana.push(aux);
    }
}

bool resuelveCaso() {
    int nDatos;
    scanf("%i", &nDatos);

    if (nDatos == 0)
        return false;

    int dato;
    std::priority_queue<int, std::vector<int>, std::greater<int>> mayoresMediana;
    std::priority_queue<int, std::vector<int>, std::less<int>> menoresMediana;

    scanf("%i", &dato);
    menoresMediana.push(dato);
    for (int i = 1; i < nDatos; ++i) {
        scanf("%i", &dato);
        anyadeMediana(menoresMediana, mayoresMediana, dato);
    }

    int mediana;

    //Devolvemos el doble de la mediana
    if (mayoresMediana.size() > menoresMediana.size())
        mediana = mayoresMediana.top() * 2;
    else if (menoresMediana.size() > mayoresMediana.size())
        mediana = menoresMediana.top() * 2;
    else
        mediana = menoresMediana.top() + mayoresMediana.top();

    printf("%i\n", mediana);

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}