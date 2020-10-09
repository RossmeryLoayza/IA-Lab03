#include "Grafo.h"

Grafo::Grafo()
{
    num_vertices = 0;
    matriz_ady = NULL;
    tabla_pesos = NULL;
}

Grafo::Grafo(int n_vertices)
{
    ciudades = new int *[n_vertices];
    for(int i = 0 ; i < n_vertices ; i++)
        ciudades[i] = new int[2];
    int arreglo[n_vertices*2];
    int aux = 0;
    int limite_inferior = 0;
    int limite_superior = 100;

    srand(time(0));

    for(int i = 0; i < n_vertices*2 ; i++)
    {
        aux = (limite_inferior + rand() % (limite_superior));
        int aux2 = 0;
        while(aux2 < i)
        {
            if(aux != arreglo[aux2])
            {
                aux2++;
            }
            else
            {
                aux = (limite_inferior + rand() % (limite_superior));
                aux2 = 0;
            }
        }
        arreglo[i] = aux;
        //cout << arreglo[i] << " - ";
    }
    //cout << endl;
    int j = 0;
    for (int i = 0 ; i < n_vertices ; i++)
    {
        for(int c = 0 ; c < 2 ; c++)
        {
            ciudades[i][c] = arreglo[j];
            j = j+1;
        }
    }
    num_vertices = n_vertices;
    matriz_ady = new bool *[n_vertices];
    tabla_pesos = new int *[n_vertices];
    for (int i = 0 ; i < n_vertices ; i++)
    {
        matriz_ady[i] = new bool[n_vertices];
        tabla_pesos[i] = new int[n_vertices];
    }
}

void Grafo::generar_grafo()
{
    for (int i = 0 ; i < num_vertices ; i++)
    {
        for(int j = 0 ; j < num_vertices ; j++)
        {
            if (i == j)
            {
                tabla_pesos[i][j] = 0;
            }
            else
            {
                tabla_pesos[i][j] = sqrt(pow((ciudades[i][0]-ciudades[j][0]),2) + pow((ciudades[i][1]-ciudades[j][1]),2));
            }
            matriz_ady[i][j] = 0;
        }
    }
    for (int i = 0 ; i < num_vertices ; i++)
    {
        for (int c = 0 ; c <= num_vertices ; c++)
        {
            if(i == c)
                matriz_ady[i][c] = 0;
            else
                matriz_ady[i][c] = 1;
        }
    }
}

void Grafo::imprimir_vertices()
{
    for (int i = 0 ; i < num_vertices ; i++)
    {
        for(int j = 0 ; j < 2 ; j++)
        {
            cout << ciudades[i][j] << endl;
        }
        cout << endl << "---------------------------------" << endl;
    }
}

void Grafo::imprimir_tabla_pesos()
{
    cout << "TABLA DE PESOS: " << endl;
    for (int i = 0 ; i < num_vertices ; i++)
    {
        for(int j = 0 ; j < num_vertices ; j++)
        {
            cout << tabla_pesos[i][j] << "   ";
        }
        cout << endl;
    }
}

void Grafo::imprimir_tabla_ady()
{
    cout << "MATRIZ DE ADYACENCIA: " << endl;
    for (int i = 0 ; i < num_vertices ; i++)
    {
        for(int j = 0 ; j < num_vertices ; j++)
        {
            cout << matriz_ady[i][j] << "   ";
        }
        cout << endl;
    }
}

string Grafo::generar_cromosoma(int j)
{
    string res;
    res.push_back(j+'0');
    int aux;
    int a[num_vertices];
    for(int i = 0; i < num_vertices ; i++)
    {
        aux = (0 + rand() % (num_vertices));
        int aux2 = 0;
        while(aux2 < i)
        {
            if(aux != a[aux2])
            {
                aux2++;
            }
            else
            {
                aux = (0 + rand() % (num_vertices));
                aux2 = 0;
            }
        }
        a[i] = aux;
    }
    for(int i = 0 ; i < num_vertices ; i++)
    {
        if(a[i] != j)
            res.push_back(a[i]+'0');
    }
    res.push_back(j+'0');
    return res;
}

string Grafo::mutar(string g , int j)
{
    string res = g;
    int aux;
    int a[2];
    for(int i = 0; i < 2 ; i++)
    {
        aux = (1 + rand() % (num_vertices-1));
        int aux2 = 0;
        while(aux2 < i)
        {
            if(aux != a[aux2])
            {
                aux2++;
            }
            else
            {
                aux = (1 + rand() % (num_vertices-1));
                aux2 = 0;
            }
        }
        a[i] = aux;
    }
    //cout << a[0] << "      -       " << a[1] << endl;
    char temp = res[a[0]];
    res[a[0]] = res[a[1]];
    res[a[1]] = temp;
    return res;
}

int Grafo::calc_dist(string g)
{
    int res = 0;
    for (int i = 0; i < g.size() - 1; i++)
    {
        res = res + tabla_pesos[g[i] - '0'][g[i + 1] - '0'];
    }
    return res;
}

void Grafo::ordenar_dist(int *t , int *b)
{
    int a[num_vertices];
    for (int z = 0 ; z < num_vertices ; z++)
    {
        a[z] = t[z];
        b[z] = z;
    }
    /*
    cout << "Fila: " << endl;
    for(int z = 0 ; z < num_vertices ; z++)
    {
        cout << a[z] << "  ";
    }
    cout << endl;
    for(int z = 0 ; z < num_vertices ; z++)
    {
        cout << b[z] << "  ";
    }
    cout << endl;*/
    for (int x = 0 ; x < num_vertices ; x++)
    {
        for (int y = 0 ; y < num_vertices-x-1 ; y++)
        {
            if(a[y] < a[y+1])
            {
                int tmp = a[y+1];
                int tmp2 = b[y+1];
                a[y+1] = a[y];
                b[y+1] = b[y];
                a[y] = tmp;
                b[y] = tmp2;
            }
        }
    }
    /*
    cout << "Fila ordenada " << endl;
    for(int z = 0 ; z < num_vertices ; z++)
    {
        cout << a[z] << "  ";
    }
    cout << endl;
    for(int z = 0 ; z < num_vertices ; z++)
    {
        cout << b[z] << "  ";
    }
    cout << endl;*/
}

void Grafo::mejor_caminoAG()
{
    int cont = 1;
    int promedio = 0;
    string pob[num_vertices];
    int pob_val[num_vertices];
    int inicio;
    cout << "Ingrese punto de inicio: ";
    cin >> inicio;
    for(int i = 0 ; i < num_vertices ; i++)
    {
        pob[i] = generar_cromosoma(inicio);
        pob_val[i] = calc_dist(pob[i]);
    }
    cout << "GENERACION #" << cont << endl;
    for(int i = 0 ; i < num_vertices ; i++)
    {
        cout << "Camino: " << pob[i] << "  - Distancia: " << pob_val[i] << endl;
        promedio = promedio + pob_val[i];
    }
    cout << "Promedio de poblacion: " << promedio/num_vertices << endl;
    while(cont != 10)
    {
        int dist_ord[num_vertices];
        ordenar_dist(pob_val , dist_ord);
        promedio = 0;
        /*cout << "valores de dist_ord" << endl;
        for(int i = 0 ; i < num_vertices ; i++)
            cout << dist_ord[i] << "  ";
        cout << endl;*/
        for (int i = 0 ; i < 1 ; i++)
        {
            int f = 0;
            while (f == 0)
            {
                string tmp = mutar(pob[dist_ord[i]] , inicio);
                if(calc_dist(tmp) <= calc_dist(pob[dist_ord[i]]) || calc_dist(tmp) <= calc_dist(pob[dist_ord[num_vertices-1]]))
                {
                    pob[dist_ord[i]] = tmp;
                    pob_val[dist_ord[i]] = calc_dist(tmp);
                    f = 1;
                }
            }
            cout << i << endl;
        }
        cont = cont + 1;
        cout << "GENERACION #" << cont << endl;
        for(int i = 0 ; i < num_vertices ; i++)
        {
            cout << "Camino: " << pob[i] << "  - Distancia: " << pob_val[i] << endl;
            promedio = promedio + pob_val[i];
        }
        cout << "Promedio de poblacion: " << promedio/num_vertices << endl;
    }
}

Grafo::~Grafo()
{
    //dtor
}
