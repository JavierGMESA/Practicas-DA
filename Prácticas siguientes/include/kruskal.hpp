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


template <typename Arista>
std::list<Arista> ordenarAristas(const std::list<Arista>& aristas) 
{
    std::vector<Arista> vectorAristas(aristas.begin(), aristas.end());

    std::cout << "Va a usar el sort" << std::endl;

    std::sort(vectorAristas.begin(), vectorAristas.end()); //método sort para ordenar de menor a mayor gracias al operador <

    return std::list<Arista>(vectorAristas.begin(), vectorAristas.end());
}


template <typename G> //Suponemos que el tipo G es un grafo ponderado
G Kruskal1(const G& g)
{
    using std::list;
    using Arista = typename G::Arista;  //IMPORTANTE: OTRA FORMA DE USAR EL typedef
    using Vertice = typename G::Vertice;
    size_t n = g.nVertices();           // Número de vértices del grafo original.

    std::cout << "Crea el grafo solución" << std::endl;

    G s(n);         //Grafo solución.
    Particion p(n); //Construye la partición inicial.

    std::cout << "Va a crear la lista de aristas" << std::endl;

    std::list<Arista> l(g.aristas()); //SE CORROMPE EN ESTE PUNTO

    std::cout << "Termina de crear la lista" << std::endl;

    int n_uniones = 0;
    unsigned v1, v2;

    std::cout << "Va a preordenar" << std::endl;
    
    auto lo = ordenarAristas(l); //Lista de candidatos preordenados.

    std::cout << "Empieza el bucle" << std::endl;

    while(n_uniones < n - 1)
    {
        Arista a = lo.front();
        lo.pop_front();
        v1 = p.buscar(a.primero());
        v2 = p.buscar(a.segundo());
        if(v1 != v2)
        {
            p.unir(v1, v2);
            s.insertarArista(a);
            ++n_uniones;
            std::cout << "union " << n_uniones << std::endl;
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

    std::cout << "Crea el grafo solución" << std::endl;

    G s(n); // Grafo solución.
    Particion p(n); // Construye la partición inicial.

    std::cout << "Va a crear la lista de aristas" << std::endl;

    //list<Arista> c(g.aristas()); // Lista de candidatos.
    const auto& c = g.aristas();


    std::cout << "Termina de crear la lista" << std::endl;
    int n_uniones = 0;
    unsigned v1, v2;

    std::cout << "Va a crear el montículo" << std::endl;
    
    std::priority_queue<Arista> l(c.begin(), c.end()); //Cola de prioridad preordenada

    std::cout << "Empieza el bucle" << std::endl;
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
            std::cout << "union " << n_uniones << std::endl;
        }
    }

    return s;
}


#endif