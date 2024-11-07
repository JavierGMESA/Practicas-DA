#ifndef MOCHILADISCRETA
#define MOCHILADISCRETA
#include <string>
#include <vector>
#include <iostream>

class Objeto
{
public:
    Objeto(std::string nom, int pes, int val): nombre{nom}, peso{pes}, valor{val}{}
    Objeto(){}
    std::string Nombre() const {return nombre;}
    std::string& Nombre(){return nombre;}
    int Peso() const {return peso;}
    int& Peso() {return peso;}
    int Valor() const{return valor;}
    int& Valor(){return valor;}
private:
    std::string nombre;
    int peso, valor;
};

using Objetos = std::vector<Objeto>; //IMPORTANTE: ESTO SE TIENE QUE DECLARAR DESPUÉS DE LA CLASE
                                     //DEL TIPO DEL VECTOR

using namespace std;

istream& operator >>(istream& is, Objeto& o);
istream& operator >>(istream& is, Objetos& o);
ostream& operator <<(ostream& os, const Objeto& o);
ostream& operator <<(ostream& os, const Objetos& o);

inline int maximo(int a, int b)
{
    return (a > b ? a : b);
}

Objetos mochila(const Objetos& objetos, unsigned int capacidad);

#endif
