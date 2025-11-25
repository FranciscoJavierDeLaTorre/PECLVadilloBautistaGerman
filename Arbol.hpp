#ifndef ARBOL_HPP
#define ARBOL_HPP

#include "NodoArbol.hpp"

#include <vector>
using namespace std;

class Arbol
{
public:
    Arbol();
    void insertar(Aficionado afic);
	void insertar1(Aficionado afic);
    void pintar();
    void dibujar();
    ~Arbol();

private:
    pnodoAbb raiz;
    pnodoAbb insertar(pnodoAbb, Aficionado);
	pnodoAbb insertar1(pnodoAbb, Aficionado);
    void pintar(pnodoAbb);
    int altura(pnodoAbb);
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int minPos,
                     char linkChar);
};

#endif // ARBOL_HPP
