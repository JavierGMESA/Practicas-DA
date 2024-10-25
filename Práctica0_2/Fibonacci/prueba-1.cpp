#include <iostream>
#include "natural.hpp"
#include "cronometro.hpp"

natural f(natural n);

// Genera la tabla de tiempos frente a n.

int main()
{
  cronometro c;
  for (natural n = 0; n <= 50; ++n) {
    c.activar();
    f(n);
    c.parar();
    std::cout << n << '\t' << c.tiempo() << std::endl;
  }
}
