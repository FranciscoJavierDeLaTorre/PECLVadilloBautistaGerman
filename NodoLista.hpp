#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP
#include <cstddef>
#include "Aficionado.hpp"

class NodoLista
{
public:
    NodoLista(Aficionado afic, NodoLista* sig = NULL);
    ~NodoLista();
	Aficionado getAficionado() const { return aficionado; }
    NodoLista* getSiguiente() const { return siguiente; }

private:
    Aficionado aficionado;
    NodoLista* siguiente;
    friend class Lista;
};

typedef NodoLista* pnodoLista;

#endif // NODOLISTA_HPP