#ifndef GRAFO_H
#define GRAFO_H
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <math.h>
#include <queue>
#include <list>
#include <iostream>

using namespace std;

class Grafo
{
    public:
        int **ciudades;
        int num_vertices;
        bool **matriz_ady;
        int **tabla_pesos;
        Grafo();
        Grafo(int n_aristas);
        void generar_grafo();
        void imprimir_vertices();
        void imprimir_tabla_pesos();
        void imprimir_tabla_ady();
        string generar_cromosoma(int j);
        string mutar(string g , int j);
        int calc_dist(string g);
        void ordenar_dist(int *t , int *b);
        void mejor_caminoAG();
        virtual ~Grafo();

    protected:

    private:
};

#endif // GRAFO_H
