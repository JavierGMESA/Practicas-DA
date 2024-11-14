#include <iostream>
#include <map>

#include "cronometro.hpp"

#include "fajo.hpp"
#include "particion.hpp"
#include "grafo-ponderado.hpp"
#include "kruskal.hpp"

#include "mochilaDiscreta.hpp"
#include "carreteras.hpp"

void P1ej1();
void P1ej2();
void P1ej3();
void P1ej4();
void P1ej5();

void P2ej1();
void P2ej2();


int main() {
    //P1ej1();
    //P1ej2();
    //P1ej3();
    //P1ej4();
    //P1ej5();

    //P2ej1();
    P2ej2();

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

    MatrizCaminos c = Floyd(p); // Calcula los caminos mínimos.

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
    std::cout << "Comprueba que ambas ciudades existen" << std::endl;
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
        std::cout << "Comprueba que existe ruta entre ambas ciudades" << std::endl;
        if(p[co][cd] == MatrizPesos::INFINITO) //Se comprueba que exista una ruta
        {
            std::cout << "No existe ruta entre las ciudades introducidas" << std::endl;
        }
        else
        {
            //std::cout << p[co][cd] << std::endl;
            std::cout << "Calcula el camino mínimo" << std::endl;
            Camino l = CaminoMinimo(c, co, cd);
            std::cout << "La ruta más corta (" << p[co][cd] << "km) es:" << std::endl << std::endl << origen << " ";
            for (auto e: l)
            {
                std::cout << ciudad[e] << " ";
            }
            std::cout << destino << std::endl;
        }
    }
    // ... obtiene el camino mínimo codificado.
    // ... muestra la longitud de la ruta y las ciudades que la integran.
    dgt.close();
}