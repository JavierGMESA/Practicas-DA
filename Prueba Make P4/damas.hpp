#ifndef DAMAS
#define DAMAS

#include <list>
#include <vector>
#include <iostream>

class Tablero
{
public:
    explicit Tablero(int n);
    int dimension() const {return n;}
    bool amenazada(int i, int j) const;
    void coloca(int i, int j);
    void elimina(int i, int j);
    int operator [](int i) const;
    bool operator==(const Tablero& t)
    {
        return (this->columna_dama == t.columna_dama);
    }
private:
    bool valida(int k) const;
    bool valida(int i, int j) const;
    int n;
    std::vector<int> columna_dama;
    std::vector<bool> columna_amenazada, diagonal_creciente_amenazada, diagonal_decreciente_amenazada;
};

std::ostream& operator <<(std::ostream& fs, const Tablero& t);

std::list<Tablero> damas(Tablero& t);

#endif