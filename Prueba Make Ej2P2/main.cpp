#include <iostream>
#include <map>
#include <fstream>

#include "carreteras.hpp"

void P2ej2();

int main()
{
    P2ej2();

    std::cout << std::endl << std::endl << "System pause" << std::endl;
}

void P2ej2()
{
    using namespace std;
    ifstream dgt("dgt.dat");

    map<string, size_t> codigo; // Código asociado a una ciudad.
    map<size_t, string> ciudad; // Ciudad asociada a un código.
    string origen, destino; // Ciudades de origen y destino.
    double distancia; // Distancia entre ambas.
    size_t n = 0; // Número de ciudades.

    std::cout << "Empieza la primera pasada" << std::endl;  //La distancia se desecha
    while(dgt >> origen >> destino >> distancia)            
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
