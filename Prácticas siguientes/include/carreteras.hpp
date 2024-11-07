#ifndef CARRETERAS
#define CARRETERAS

#include <vector>
#include <list>
#include <limits>
#include <iostream>
#include <map>
#include <string>

template <typename T>
class MatrizCuadrada
{
public:
    MatrizCuadrada(){}
    MatrizCuadrada(int g): grado(g), v(std::vector<std::vector<T>>(g, std::vector<T>(g))){} //IMPORTANTE
    MatrizCuadrada(int g, T defecto): grado(g), v(std::vector(g, std::vector(g, defecto))){}
    int Grado() const{return grado;}
    int& Grado(){return grado;}
    const std::vector<T> operator[](int i)const{return v[i];}
    std::vector<T>& operator[](int i){return v[i];}
private:
    std::vector<std::vector<T>> v;
    int grado;
};

class MatrizPesos: public MatrizCuadrada<double>
{
public:
    static const double INFINITO;
    MatrizPesos(): MatrizCuadrada<double>(){}
    MatrizPesos(int g): MatrizCuadrada<double>(g, INFINITO){}
private:
};

const double MatrizPesos::INFINITO = std::numeric_limits<double>::max();

class MatrizCaminos:public MatrizCuadrada<int>
{
public:
    MatrizCaminos(): MatrizCuadrada<int>(){}
    MatrizCaminos(int grado): MatrizCuadrada<int>(grado){}
private:
};

using Camino = std::list<std::size_t>;

MatrizCaminos Floyd(MatrizPesos& p);

Camino CaminoMinimo(const MatrizCaminos& c, std::size_t i, std::size_t j);

using namespace std;
ostream& operator <<(ostream& os, const std::map<std::size_t, std::string>& m);
ostream& operator <<(ostream& os, const std::list<std::string> l);
//Devuelve el número de ciudades
size_t leerCiudades(map<string, size_t>& codigo, map<size_t, string>& ciudad);

#endif