#ifndef KRUSKAL
#define KRUSKAL

#include "grafo-ponderado.hpp"
#include "particion.hpp"

#include <queue>
#include <list>
#include <vector>
#include <functional>

#include <list>
#include <vector>
#include <algorithm>


template <typename G> //Suponemos que el tipo G es un grafo ponderado
G Kruskal1(const G& g)
{
    using std::list;
    using Arista = typename G::Arista;  //IMPORTANTE: OTRA FORMA DE USAR EL typedef
    using Vertice = typename G::Vertice;
    size_t n = g.nVertices();           // Número de vértices del grafo original.
    G s(n);         //Grafo solución.
    Particion p(n); //Construye la partición inicial.
    list<Arista> c(g.aristas()); //lista de candidatos
    int n_uniones = 0;
    int v1, v2;
    c.sort(std::less<Arista>()); //Lista de candidatos preordenados. IMPORTANTE: USO DE SORT PARA PREORDENAR

    while(n_uniones < n - 1)
    {
        Arista a = *(c.begin());
        c.erase(c.begin());
        v1 = p.buscar(a.primero());
        v2 = p.buscar(a.segundo());
        if(v1 != v2)
        {
            p.unir(v1, v2);
            s.insertarArista(a);
            ++n_uniones;
        }
    }

    return s;
}


template <typename G> //Suponemos que el tipo G es un grafo ponderado
G Kruskal2(const G& g)
{
    using std::list;
    using Arista = typename G::Arista;  //IMPORTANTE: OTRA FORMA DE USAR EL typedef
    using Vertice = typename G::Vertice;
    size_t n = g.nVertices(); // Número de vértices del grafo original.

    G s(n); // Grafo solución.
    Particion p(n); // Construye la partición inicial.

    list<Arista> c(g.aristas()); // Lista de candidatos.
    int n_uniones = 0;
    unsigned v1, v2;
    
    std::priority_queue<Arista, std::vector<Arista>, std::greater<Arista>> l(c.begin(), c.end()); //Cola de prioridad preordenada
    while(n_uniones < n - 1)
    {
        Arista a = l.top();
        l.pop();
        v1 = p.buscar(a.primero());
        v2 = p.buscar(a.segundo());
        if(v1 != v2)
        {
            p.unir(v1, v2);
            s.insertarArista(a);
            ++n_uniones;
        }
    }

    return s;
}


#endif