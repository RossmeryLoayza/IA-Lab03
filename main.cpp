#include <iostream>
#include "Grafo.h"

using namespace std;

int main()
{
    Grafo c(5);
    c.generar_grafo();
    c.mejor_caminoAG();
    /*c.imprimir_vertices();
    c.imprimir_tabla_ady();
    c.imprimir_tabla_pesos();
    string p = c.generar_cromosoma(2);
    cout << "Primer cromosoma: " << endl;
    cout << p << endl;
    cout << c.calc_dist(p) << endl;
    cout << "------------------------------" << endl;
    cout << "Cromosoma Mutado: " << endl;
    string m = c.mutar(p,2);
    cout << m << endl;
    cout << c.calc_dist(m) << endl;*/
    return 0;
}
