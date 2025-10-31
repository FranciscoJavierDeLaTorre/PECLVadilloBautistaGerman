#include "NodoLista.hpp"
#include <cstddef>

NodoLista::NodoLista(Aficionado afic, NodoLista* sig)
{
    aficionado = afic;
    siguiente = sig;
}

NodoLista::~NodoLista()
{
}