#ifndef GRAFO_PONDERADO_HPP_
#define GRAFO_PONDERADO_HPP_

#include "grafo.hpp"

#include <iostream>

using namespace std;

// Arista ponderada.
template <typename V, typename P = double >
class AristaPonderada: public Arista<V> {
public:
  using Peso = P;
  AristaPonderada(V u, V v, Peso p = Peso()): Arista<V>(u, v), p{p} {}
  Peso peso() const { return p; }
  Peso& peso() { return p; }
private:
  Peso p;
};

//IMPORTANTE: PARA LA PREORDENACIÓN NECESITAMOS EL < PARA PODER PREORDENAR DE MENOR A MAYOR USANDO EL std::less<Arista> EN EL MÉTODO sort()
template <typename V, typename P = double >
bool operator <(const AristaPonderada<V, P>& a, const AristaPonderada<V, P>& b) 
{
    return a.peso() < b.peso();
}

//IMPORTANTE: PARA LA PREORDENACIÓN NECESITAMOS EL > PARA PODER PREORDENAR DE MENOR A MAYOR USANDO EL std::greater<Arista> EN LA priority_queue
template <typename V, typename P = double >
bool operator >(const AristaPonderada<V, P>& a, const AristaPonderada<V, P>& b) 
{
    return a.peso() > b.peso();
}


// Grafo ponderado.

template <typename V, typename P = double >
class GrafoPonderado: public Grafo<V, AristaPonderada<V, P>> {
public:
  using Peso = P;
  GrafoPonderado(size_t n = 0): Grafo<V, AristaPonderada<V, P>>(n) {}
};

template <typename V, typename P>
istream& operator >>(istream& fe, AristaPonderada<V, P>& a)
{
  return fe >> a.primero() >> a.segundo() >> a.peso();
}

template <typename V, typename P>
ostream& operator <<(ostream& fs, const AristaPonderada<V, P>& a)
{
  return fs << a.primero() << ' ' << a.segundo() << ' ' << a.peso();
}

template <typename V, typename A>
istream& operator >>(istream& fe, Grafo<V, A>& g)
{
  size_t n = 0;
  fe >> n;
  g = Grafo<V, A>(n);
  V u{}, v{};
  A a(u, v);
  while (fe >> a)
  g.insertarArista(a);
  return fe;
}

template <typename V, typename A>
ostream& operator <<(ostream& fs, const Grafo<V, A>& g)
{
  fs << g.nVertices() << '\n';
  auto& a = g.aristas();
  copy(begin(a), end(a), ostream_iterator<A>(fs, "\n"));
  return fs << flush;
}


#endif
