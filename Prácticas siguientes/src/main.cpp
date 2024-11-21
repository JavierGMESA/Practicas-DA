#include <iostream>
#include <map>

#include "cronometro.hpp"

#include "fajo.hpp"
#include "particion.hpp"
#include "grafo-ponderado.hpp"
#include "kruskal.hpp"

#include "mochilaDiscreta.hpp"
#include "carreteras.hpp"

#include "tabla64.hpp"
#include "matriz.hpp"
#include "potenciaMatriz.hpp"

void P1ej1();
void P1ej2();
void P1ej3();
void P1ej4();
void P1ej5();

void P2ej1();
void P2ej2();

void P3ej1();
ostream& operator <<(ostream& fs, matriz& a);
// Función delta de Kronecker.
inline double delta(size_t i, size_t j)
{
  return i == j;
}
void P3ej2();

int main() {
    //P1ej1();
    //P1ej2();
    //P1ej3();
    //P1ej4();
    //P1ej5();

    //P2ej1();
    //P2ej2();
    //P3ej1();
    P3ej2();

    std::cout << std::endl << std::endl << "System pause" << std::endl;
}

void P1ej1()
{
    std::ifstream datos("caja.dat");
    fajos caja;
    datos >> caja;
    std::cout << caja << std::endl;

    fajos resultado = reintegrar(caja, 120);
    std::cout << resultado << std::endl;
}

void P1ej2()
{
    Particion P(8);
    P.unir(0, 1);
    P.unir(P.buscar(0), 2);
    std::cout << P.buscar(2) << " " << P.buscar(0) << std::endl;
}

void P1ej3()
{
    using namespace std;
    GrafoPonderado<int> G;
    ifstream datos("grafo.dat"); //IMPORTANTE: LECTURA DE FICHERO
    datos >> G;
    cout << G << endl;

    cout << Kruskal1(G) << endl;
}

void P1ej4()
{
    GrafoPonderado<int> g;
    std::ifstream datos("grafo.dat"); //IMPORTANTE: LECTURA DE FICHERO
    datos >> g;
    std::cout << g << std::endl;

    GrafoPonderado g1 = Kruskal2(g);
    std::cout << g1 << std::endl;
}

void P1ej5()
{
    cronometro crono;
    GrafoPonderado<int> g;
    std::ifstream datos("grafo.dat"); //IMPORTANTE: LECTURA DE FICHERO
    datos >> g;

    crono.activar();
    GrafoPonderado g1 = Kruskal1(g);
    crono.parar();
    std::cout << "El tipo en la preordenacion ha sido " << crono.tiempo() << std::endl;

    crono.activar();
    GrafoPonderado g2 = Kruskal2(g);
    crono.parar();
    std::cout << "El tipo con los montículos ha sido " << crono.tiempo() << std::endl;
}

void P2ej1()
{
    Objetos o;
    std::ifstream datos("objetos.dat");
    datos >> o;
    std::cout << o << std::endl;

    Objetos solucion = mochila(o, 50);
    std::cout << solucion << std::endl;
}

void P2ej2()
{
    cronometro crono;

    ifstream dgt("dgt.dat");

    map<string, size_t> codigo; // Código asociado a una ciudad.
    map<size_t, string> ciudad; // Ciudad asociada a un código.
    string origen, destino; // Ciudades de origen y destino.
    double distancia; // Distancia entre ambas.
    size_t n = 0; // Número de ciudades.

    std::cout << "Empieza la primera pasada" << std::endl;  //La distancia se desecha
    while(dgt >> origen >> destino >> distancia)            //IMPORTANTE: LEER DE UN FICHERO HASTA SU FINAL
    {
        auto res = codigo.insert(std::make_pair(origen, n));
        if(res.second)  //Se ha insertado?
        {
            ciudad.insert(std::make_pair(n, origen));
            ++n;
        }
        res = codigo.insert(std::make_pair(destino, n));
        if(res.second)
        {
            ciudad.insert(std::make_pair(n, destino));
            ++n;
        }
    }
    std::cout << ciudad << std::endl;

    // 2ª pasada: obtiene la matriz de pesos.
    MatrizPesos p(n);
    // ... inicializa la matriz de pesos con pesos «infinitos».
    dgt.close();
    dgt.clear();
    std::cout << "Empieza la segunda pasada" << std::endl;
    dgt.open("dgt.dat");
    while(dgt >> origen >> destino >> distancia)
    {
        p[codigo[origen]][codigo[destino]] = p[codigo[destino]][codigo[origen]] = distancia;
    }

    crono.activar();
    MatrizCaminos c = Floyd(p); // Calcula los caminos mínimos.
    crono.parar();
    std::cout << "El tiempo de ejecución de Floyd es " << crono.tiempo() << std::endl;

    // Respuesta a las consultas.
    // Solicitud de origen y el destino.
    std::cout << "Por favor, introduzca un origen y destino" << std::endl << std::endl;
    std::cout << "Origen:  ";
    std::cin >> origen;
    std::cout << "Destino: ";
    std::cin >> destino;
    std::cout << std::endl << std::endl;

    auto o = codigo.find(origen);       //IMPORTANTE: COMPROBAR QUE UN ELEMENTO EXISTE EN UN MAP
    auto d = codigo.find(destino);
    if(o == codigo.end()) //Se comprueba que ambas ciudades existan
    {
        std::cout << "El origen introducido no existe en las rutas" << std::endl;
    }
    else if(d == codigo.end())
    {
        std::cout << "El destino introducido no existe en las rutas" << std::endl;
    }
    else
    {
        std::size_t co = codigo[origen];
        std::size_t cd = codigo[destino];
        if(p[co][cd] == MatrizPesos::INFINITO) //Se comprueba que exista una ruta
        {
            std::cout << "No existe ruta entre las ciudades introducidas" << std::endl;
        }
        else
        {
            Camino l = CaminoMinimo(c, co, cd); //Se obtiene el camino mínimo codificado.
            //Se muestra la longitud de la ruta y las ciudades que la integran.
            std::cout << "La ruta más corta (" << p[co][cd] << "km) es:" << std::endl << std::endl << origen << " ";
            for (auto e: l)
            {
                std::cout << ciudad[e] << " ";
            }
            std::cout << destino << std::endl;
        }
    }
    dgt.close();
}

void P3ej1()
{
    fila_tabla* tabla = tabla64(64);
    for(int i = 0; i < 64; ++i)
    {
        std::cout << tabla[i] << std::endl;
    }
}

void P3ej2()
{
    matriz a(3, 3);	  // Matriz nula de 3×3.
    matriz b(3, 3, 2.0);    // Matriz de 3×3 con todos sus elementos a 2. 
    matriz c(3, 3, delta);  // Matriz identidad de 3×3.
    a = c;
    cout << "A =\n" << a << endl;
    b += -a;
    cout << "B =\n" << b << endl;
    c *= c += c;
    cout << "C =\n" << c << endl;
    matriz d(a + b * c);
    cout << "A + B * C =\n" << d << endl;
    matriz e(100, 100, delta);
    cronometro crono;
    crono.activar();
    for(int i = 1; i <= 64; ++i)
    {
        matriz f = potencia_iterativa(e, i);
    }
    crono.parar();
    std::cout << "El tiempo en el iterativo es " << crono.tiempo() << std::endl;
    crono.activar();
    for(int i = 1; i <= 64; ++i)
    {
        matriz f = potencia_rapida(e, i);
    }
    crono.parar();
    std::cout << "El tiempo en el de potencia rapida es " << crono.tiempo() << std::endl;
}

ostream& operator <<(ostream& fs, matriz& a)
{
  for (size_t i = 0; i < a.filas(); ++i) {
    for (size_t j = 0; j < a.columnas(); ++j)
      fs << a[i][j] << ' ';
    fs << '\n';
  }
  return fs;
}