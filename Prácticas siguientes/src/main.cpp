#include <iostream>
#include <map>
#include <random>
#include <list>

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
#include "ordenacion.hpp"

#include "damas.hpp"

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
void P3ej4();
void P3ej5();
void P3ej6();
void P3ej7();

void P4ej1();
void P4ej2();

int main() {
    //P1ej1();
    //P1ej2();
    //P1ej3();
    //P1ej4();
    //P1ej5();

    //P2ej1();
    //P2ej2();
    
    //P3ej1();
    //P3ej2();
    //P3ej4();
    //P3ej5();
    //P3ej6();
    //P3ej7();

    //P4ej1();
    P4ej2();

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

void P3ej4()
{
    std::vector<int> v(20);
    for(int i = 0; i < 20; ++i)
    {
        v[i] = 20 - i;
    }

    for(auto i: v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    ordenacion_fusion(v.begin(), v.end(), 2);

    for(auto i: v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for(int i = 0; i < 20; ++i)
    {
        v[i] = 20 - i;
    }

    for(auto i: v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    ordenacion_rapida(v.begin(), v.end(), 2);

    for(auto i: v)
    {
        std::cout << i << " ";
    }
}

void P3ej5()
{
    for(int i = 0; i < 13; ++i)
    {
        std::vector<int> v(i);
        for(int j = 0; j < i; ++j)
        {
            v[j] = j + 1;
        }

        std::vector<int> w = v;

        while(std::next_permutation(v.begin(), v.end()))
        {
            std::vector<int> x1 = v;
            std::vector<int> x2 = v;
            ordenacion_fusion(x1.begin(), x1.end(), 4);
            for(auto l: x1)
            {
                std::cout << l << " ";
            }
            std::cout << std::endl;
            ordenacion_rapida(x2.begin(), x2.end(), 4);
            for(auto l: x2)
            {
                std::cout << l << " ";
            }
            std::cout << std::endl;
            if(x1 != w)
            {
                std::cout << "No se ha ordenado con fusión con tamaño " << i << std::endl;
            }
            if(x2 != w)
            {
                std::cout << "No se ha ordenado con rápida con tamaño " << i << std::endl;
            }
        }
        std::cout << "Fin con tamaño " << i << std::endl;
    }
}

void P3ej6()
{
    cronometro c;
    std::default_random_engine gnp;
    for(double i = 0; i <= 1000000; i += 20000)
    {
        std::vector<double> v(i);
        for(int j = 0; j < i; ++j)
        {
            v[j] = j + 1;
        }

        std::vector<double> w = v;

        c.activar();
        for(int iteraciones = 0; iteraciones < 10; ++iteraciones)
        {
            std::vector<double> x1 = v;
            std::shuffle(x1.begin(), x1.end(), gnp);
            std::vector<double> x2 = x1;
            ordenacion_fusion(x1.begin(), x1.end(), 4);
        }
        c.parar();
        std::cout << "El tiempo de ordenacion por fusion con tamaño " << i << " es " << (c.tiempo() / 20) << std::endl;
        c.activar();
        for(int iteraciones = 0; iteraciones < 10; ++iteraciones)
        {
            std::vector<double> x1 = v;
            std::shuffle(x1.begin(), x1.end(), gnp);
            std::vector<double> x2 = x1;
            ordenacion_rapida(x1.begin(), x1.end(), 4);
        }
        c.parar();
        std::cout << "El tiempo de ordenacion rápida con tamaño " << i << " es " << (c.tiempo() / 20) << std::endl;
        std::cout << "Fin con tamaño " << i << std::endl;
    }
}

void P3ej7()
{
    cronometro c;
    std::default_random_engine gnp;
    for(double i = 0; i <= 1000000; i += 20000)
    {
        std::vector<double> v(i);
        for(int j = 0; j < i; ++j)
        {
            v[j] = j + 1;
        }

        std::vector<double> w = v;

        c.activar();
        for(int iteraciones = 0; iteraciones < 10; ++iteraciones)
        {
            std::vector<double> x1 = v;
            std::shuffle(x1.begin(), x1.end(), gnp);
            std::vector<double> x2 = x1;
            ordenacion_fusion(x1.begin(), x1.end(), 8);
        }
        c.parar();
        std::cout << "El tiempo de ordenacion por fusion con tamaño " << i << " es " << (c.tiempo() / 20) << std::endl;
        c.activar();
        for(int iteraciones = 0; iteraciones < 10; ++iteraciones)
        {
            std::vector<double> x1 = v;
            std::shuffle(x1.begin(), x1.end(), gnp);
            std::vector<double> x2 = x1;
            ordenacion_rapida(x1.begin(), x1.end(), 4);
        }
        c.parar();
        std::cout << "El tiempo de ordenacion rápida con tamaño " << i << " es " << (c.tiempo() / 20) << std::endl;
        std::cout << "Fin con tamaño " << i << std::endl;
    }
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

void P4ej1()
{
    Tablero t(8);
    t.coloca(4, 4);
    std::cout << t[4] << std::endl << t << std::endl;
    t.elimina(4, 4);
    std::cout << "Va a mostrar con la dama eliminada" << std::endl << t << std::endl;
}

void P4ej2()
{
    Tablero t(7);
    std::list<Tablero> soluciones = damas(t);
    int i = 1;
    for(auto s: soluciones)
    {
        std::cout << "Solución " << i << ":" << std::endl;
        std::cout << s << std::endl << std::endl;
        ++i;
    }
}