#ifndef GRAFO_PONDERADO_HPP_
#define GRAFO_PONDERADO_HPP_

#include "grafo.hpp"

// Arista ponderada.

template <typename V, typename P = double>
class AristaPonderada: public Arista<V> {
public:
  using Peso = P;
  AristaPonderada(V u, V v, Peso p = Peso()): Arista<V>(u, v), p{p} {}
  Peso peso() const { return p; }
  Peso& peso() { return p; }
private:
  Peso p;
};

template <typename V, typename P = double>
bool operator < (AristaPonderada<V, P> a, AristaPonderada<V, P> b)
{
    if(a.peso() < b.peso())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Grafo ponderado.

template <typename V, typename P = double>
class GrafoPonderado: public Grafo<V, AristaPonderada<V, P>> {
public:
  using Peso = P;
  GrafoPonderado(size_t n = 0): Grafo<V, AristaPonderada<V, P>>(n) {}
};

#endif
