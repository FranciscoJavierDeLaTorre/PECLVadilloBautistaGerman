#include "NodoArbol.hpp"

NodoArbol::NodoArbol(Aficionado afic)
{
    this->afic = afic;
    this->izq = nullptr;
    this->der = nullptr;
}

NodoArbol::~NodoArbol() {}
