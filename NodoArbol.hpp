#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP
#include <iostream>
class NodoArbol
{
public:
    NodoArbol(Aficionado afic);
    ~NodoArbol();

private:
    Aficionado afic; // Aquí se almacenan enteros pero en vuestra práctica lo tenéis que cambiar
    NodoArbol* izq;
    NodoArbol* der;

    friend class Arbol;
};
typedef NodoArbol* pnodoAbb;
#endif // NODOARBOL_HPP
