#include "Cola.hpp"
#include <iostream>
#include <cstddef>
using namespace std;

Cola::Cola()
{
    primeroPtr = NULL;
    ultimo = NULL;
    longitud = 0;
}

void Cola::insertar(Aficionado afic)
{
    pnodoCola nuevo = new NodoCola(afic);
    
    if(ultimo)
        ultimo->siguiente = nuevo;
    
    ultimo = nuevo;
    
    if(!primeroPtr)
        primeroPtr = nuevo;
    
    longitud++;
}

Aficionado Cola::extraer()
{
    pnodoCola nodo;
    Aficionado afic;
    
    if(!primeroPtr)
        return Aficionado(); // Retorna un aficionado vacío si la cola está vacía
    
    nodo = primeroPtr;
    primeroPtr = nodo->siguiente;
    afic = nodo->aficionado;
    
    if(!primeroPtr)
        ultimo = NULL;
    
    longitud--;
    delete nodo;
    return afic;
}

Aficionado Cola::primero()
{
    if(!primeroPtr)
        return Aficionado(); // Retorna un aficionado vacío si la cola está vacía
    
    return primeroPtr->aficionado;
}

void Cola::mostrar()
{
    pnodoCola aux = primeroPtr;
    
    if(!aux)
    {
        cout << "\t La cola está vacía." << endl;
        return;
    }
    
    cout << "\t" << string(60, '-') << endl;
    int contador = 1;
    while(aux) {
        cout << "\t" << contador << ". ";
        aux->aficionado.mostrar();
        aux = aux->siguiente;
        contador++;
    }
    cout << "\t" << string(60, '-') << endl;
    cout << "\tTotal en cola: " << longitud << endl;
}

int Cola::getLongitud()
{
    return this->longitud;
}

bool Cola::estaVacia()
{
    return primeroPtr == NULL;
}

Cola::~Cola()
{
    pnodoCola aux;
    while(primeroPtr) {
        aux = primeroPtr;
        primeroPtr = primeroPtr->siguiente;
        delete aux;
    }
}
