#ifndef GRAFO_HPP_
#define GRAFO_HPP_

#include <list>

#include <iostream>

// Arista.

template <typename V>
class Arista {
public:
  using Vertice = V;
  Arista(Vertice u, Vertice v): u{u}, v{v} {} 
  Vertice primero() const { return u; }
  Vertice segundo() const { return v; }
  Vertice& primero() { return u; }
  Vertice& segundo() { return v; }
private:
  Vertice u, v;
};

// Grafo.

template <typename V, typename A = Arista<V>>
class Grafo {
public:
  using Vertice = V;
  using Arista = A;
  using Aristas = std::list<Arista>;
  Grafo(size_t n = 0): n{n} {}
  size_t nVertices() const { return n; }
  const Aristas& aristas() const { return a; }
  void insertarArista(const Arista& u) { a.push_back(u); }
private:
  size_t n;
  Aristas a;
};


#endif
