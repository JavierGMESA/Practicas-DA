#ifndef KRUSKAL
#define KRUSKAL

#include "grafo-ponderado.hpp"
#include "particion.hpp"

#include <queue>
#include <list>
#include <vector>
#include <functional>


//template <typename G> //Suponemos que el tipo G es un grafo ponderado
//G Kruskal(const G& g)
//{
//    using std::list;
//    using Arista = typename G::Arista;
//    using Vertice = typename G::Vertice;
//    size_t n = g.nVertices(); // Número de vértices del grafo original.
//    G s(n); // Grafo solución.
//    Particion p(n); // Construye la partición inicial.
//    list<Arista> c(g.aristas()); // Lista de candidatos.
//    int n_uniones = 0;
//    Arista a;
    
//    std::priority_queue<Arista, list<Arista>, std::less<Arista>> c(c.begin(), c.end()); //Cola de prioridad preordenada
//    //c.top() para obtener la referencia al menor
//    //c.pop() para eliminar el frente
//    while(n_uniones < n - 1)
//    {
//        a = c.top();
//        c.pop_front();
        
//    }

//    return s;
//}


#endif