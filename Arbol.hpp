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
    void inOrden();
    void mostrarSimpatizantesOrden();
    void mostrarSociosOrden();
    
    // Opción O: Buscar aficionados especiales
    void buscarEspeciales(
        Aficionado &primero,
        Aficionado &ultimoSocio,
        Aficionado &primerSimpatizante,
        Aficionado &ultimo);
    
    // Opción P: Contar IDs pares
    int contarIDPares();
    
    // Opción Q: Mostrar hojas
    void mostrarHojas();
    
    // Opción R: Eliminar aficionado
    void eliminar(int id);
    
    ~Arbol();

private:
    pnodoAbb raiz;
    
    pnodoAbb insertar(pnodoAbb, Aficionado);
    pnodoAbb insertar1(pnodoAbb, Aficionado);
    void pintar(pnodoAbb);
    int altura(pnodoAbb);
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int minPos, char linkChar);
    void inOrden(pnodoAbb nodo);
    void mostrarSimpatizantesOrden(pnodoAbb nodo);
    void mostrarSociosOrden(pnodoAbb nodo);
    
    void buscarEspeciales(
        pnodoAbb nodo,
        Aficionado &primero,
        Aficionado &ultimoSocio,
        Aficionado &primerSimpatizante,
        Aficionado &ultimo,
        bool &okPrimero,
        bool &okUltSoc,
        bool &okPrimSimp,
        bool &okUlt);
    
    int contarIDPares(pnodoAbb nodo);
    void mostrarHojas(pnodoAbb nodo);
    pnodoAbb eliminar(pnodoAbb nodo, int id);
	void destruirArbol(pnodoAbb nodo);
};

#endif // ARBOL_HPP