#include <iostream>
#include "cronometro.hpp"

using namespace std;

int main()
{
  const long vueltas = 1000000000L;
  cout << "Medida del tiempo de control de un bucle de " << vueltas
       << " de vueltas: \a" << flush;
  cronometro c;
  c.activar();
  for (long i = 0; i < vueltas; ++i)
    ;
  c.parar();
  cout << c.tiempo() << " s\a" << endl;
}
