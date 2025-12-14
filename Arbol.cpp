#include "Arbol.hpp"
#include "Aficionado.hpp"
#include <iostream>
using namespace std;

Arbol::Arbol() 
{ 
    raiz = nullptr; 
}

void Arbol::insertar(Aficionado afic) 
{ 
    raiz = insertar(raiz, afic); 
}

void Arbol::insertar1(Aficionado afic) 
{ 
    raiz = insertar1(raiz, afic); 
}

pnodoAbb Arbol::insertar(pnodoAbb nodo, Aficionado afic)
{
    if(!nodo)
        return new NodoArbol(afic);
    if(afic.getID() <= nodo->afic.getID())
        nodo->izq = insertar(nodo->izq, afic);
    else
        nodo->der = insertar(nodo->der, afic);
    return nodo;
}

pnodoAbb Arbol::insertar1(pnodoAbb nodo, Aficionado afic)
{
    if(!nodo)
        return new NodoArbol(afic);
    if(afic.esSocio())
        nodo->izq = insertar(nodo->izq, afic);
    else
        nodo->der = insertar(nodo->der, afic);
    return nodo;
}

void Arbol::pintar()
{
    pintar(raiz);
    cout << '\n';
}

void Arbol::pintar(pnodoAbb nodo)
{
    if(!nodo)
        return;
    pintar(nodo->izq);
    cout << nodo->afic.getID() << " ";
    pintar(nodo->der);
}

int Arbol::altura(pnodoAbb nodo)
{
    if(!nodo)
        return 0;
    return 1 + max(altura(nodo->izq), altura(nodo->der));
}

void Arbol::dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int p, char linkChar)
{
    if(!nodo)
        return;

    int h = output.size();
    string SP = " ";

    if(p < 0) {
        string extra(-p, ' ');
        for(string& s : output)
            if(!s.empty())
                s = extra + s;
        for(string& s : linkAbove)
            if(!s.empty())
                s = extra + s;
    }
    if(nivel < h - 1)
        p = max(p, (int)output[nivel + 1].size());
    if(nivel > 0)
        p = max(p, (int)output[nivel - 1].size());
    p = max(p, (int)output[nivel].size());

    if(nodo->izq) {
        int numeroQueQuieroImprimirEnElArbol = nodo->izq->afic.getID();
        string izqdato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
        dibujarNodo(output, linkAbove, nodo->izq, nivel + 1, p - izqdato.size(), 'L');
        p = max(p, (int)output[nivel + 1].size());
    }

    int space = p - output[nivel].size();
    if(space > 0)
        output[nivel] += string(space, ' ');
    int numeroQueQuieroImprimirEnElArbol = nodo->afic.getID();
    string nododato = SP + to_string(numeroQueQuieroImprimirEnElArbol) + SP;
    output[nivel] += nododato;

    space = p + SP.size() - linkAbove[nivel].size();
    if(space > 0)
        linkAbove[nivel] += string(space, ' ');
    linkAbove[nivel] += linkChar;

    if(nodo->der)
        dibujarNodo(output, linkAbove, nodo->der, nivel + 1, output[nivel].size(), 'R');
}

void Arbol::dibujar()
{
    int h = altura(raiz);
    vector<string> output(h), linkAbove(h);
    dibujarNodo(output, linkAbove, raiz, 0, 5, ' ');

    for(int i = 1; i < h; i++) {
        for(int j = 0; j < linkAbove[i].size(); j++) {
            if(linkAbove[i][j] != ' ') {
                int size = output[i - 1].size();
                if(size < (size_t)(j + 1))
                    output[i - 1] += string(j + 1 - size, ' ');
                int jj = j;
                if(linkAbove[i][j] == 'L') {
                    while(output[i - 1][jj] == ' ')
                        jj++;
                    for(int k = j + 1; k < jj - 1; k++)
                        output[i - 1][k] = '_';
                } else if(linkAbove[i][j] == 'R') {
                    while(output[i - 1][jj] == ' ')
                        jj--;
                    for(int k = j - 1; k > jj + 1; k--)
                        output[i - 1][k] = '_';
                }
                linkAbove[i][j] = '|';
            }
        }
    }

    cout << '\n' << '\n';
    for(int i = 0; i < h; i++) {
        if(i)
            cout << linkAbove[i] << '\n';
        cout << output[i] << '\n';
    }
    cout << '\n' << '\n';
}

// Opción N: Mostrar en inorden
void Arbol::inOrden()
{
    inOrden(raiz);
}

void Arbol::inOrden(pnodoAbb nodo)
{
    if (!nodo)
        return;

    inOrden(nodo->izq);
    nodo->afic.mostrar();
    inOrden(nodo->der);
}

// Opción L: Mostrar socios ordenados por ID
void Arbol::mostrarSociosOrden()
{
    mostrarSociosOrden(raiz);
}

void Arbol::mostrarSociosOrden(pnodoAbb nodo)
{
    if (!nodo) 
        return;

    mostrarSociosOrden(nodo->izq);

    if (nodo->afic.esSocio() && nodo->afic.getID() != 0)
        nodo->afic.mostrar();

    mostrarSociosOrden(nodo->der);
}

// Opción M: Mostrar simpatizantes ordenados por ID
void Arbol::mostrarSimpatizantesOrden()
{
    mostrarSimpatizantesOrden(raiz);
}

void Arbol::mostrarSimpatizantesOrden(pnodoAbb nodo)
{
    if (!nodo) 
        return;

    mostrarSimpatizantesOrden(nodo->izq);

    if (!nodo->afic.esSocio())
        nodo->afic.mostrar();

    mostrarSimpatizantesOrden(nodo->der);
}

// Opción O: Buscar aficionados especiales
void Arbol::buscarEspeciales(
        Aficionado &primero,
        Aficionado &ultimoSocio,
        Aficionado &primerSimpatizante,
        Aficionado &ultimo)
{
    bool encontradoPrimero = false;
    bool encontradoUltSoc = false;
    bool encontradoPrimSimp = false;
    bool encontradoUlt = false;

    buscarEspeciales(raiz,
        primero, ultimoSocio, primerSimpatizante, ultimo,
        encontradoPrimero, encontradoUltSoc, encontradoPrimSimp, encontradoUlt);
}

void Arbol::buscarEspeciales(
        pnodoAbb nodo,
        Aficionado &primero,
        Aficionado &ultimoSocio,
        Aficionado &primerSimpatizante,
        Aficionado &ultimo,
        bool &okPrimero,
        bool &okUltSoc,
        bool &okPrimSimp,
        bool &okUlt)
{
    if (!nodo) 
        return;

    // Recorrer subárbol izquierdo
    buscarEspeciales(nodo->izq, primero, ultimoSocio, primerSimpatizante, ultimo,
                     okPrimero, okUltSoc, okPrimSimp, okUlt);

    Aficionado a = nodo->afic;

    // Saltar el nodo ficticio (ID == 0)
    if(a.getID() == 0) {
        buscarEspeciales(nodo->der, primero, ultimoSocio, primerSimpatizante, ultimo,
                         okPrimero, okUltSoc, okPrimSimp, okUlt);
        return;
    }

    // Primer aficionado en acceder (menor hora)
    if (!okPrimero || a.getHora() < primero.getHora())
    {
        primero = a;
        okPrimero = true;
    }

    // Último socio en acceder (mayor hora entre socios)
    if (a.esSocio())
    {
        if (!okUltSoc || a.getHora() > ultimoSocio.getHora())
        {
            ultimoSocio = a;
            okUltSoc = true;
        }
    }

    // Primer simpatizante en acceder (menor hora entre simpatizantes)
    if (!a.esSocio())
    {
        if (!okPrimSimp || a.getHora() < primerSimpatizante.getHora())
        {
            primerSimpatizante = a;
            okPrimSimp = true;
        }
    }

    // Último aficionado en acceder (mayor hora)
    if (!okUlt || a.getHora() > ultimo.getHora())
    {
        ultimo = a;
        okUlt = true;
    }

    // Recorrer subárbol derecho
    buscarEspeciales(nodo->der, primero, ultimoSocio, primerSimpatizante, ultimo,
                     okPrimero, okUltSoc, okPrimSimp, okUlt);
}

// Opción P: Contar IDs pares
int Arbol::contarIDPares()
{
    return contarIDPares(raiz);
}

int Arbol::contarIDPares(pnodoAbb nodo)
{
    if (!nodo) 
        return 0;

    int cont = 0;
    if (nodo->afic.getID() % 2 == 0 && nodo->afic.getID() != 0)
        cont = 1;

    return cont + contarIDPares(nodo->izq) + contarIDPares(nodo->der);
}

// Opción Q: Mostrar hojas
void Arbol::mostrarHojas()
{
    mostrarHojas(raiz);
}

void Arbol::mostrarHojas(pnodoAbb nodo)
{
    if (!nodo) 
        return;

    // Si es hoja y no es el nodo ficticio
    if (!nodo->izq && !nodo->der && nodo->afic.getID() != 0)
    {
        nodo->afic.mostrar();
        return;
    }

    mostrarHojas(nodo->izq);
    mostrarHojas(nodo->der);
}

// Opción R: Eliminar aficionado
void Arbol::eliminar(int id)
{
    raiz = eliminar(raiz, id);
}

pnodoAbb Arbol::eliminar(pnodoAbb nodo, int id)
{
    if (!nodo) 
        return nullptr;

    if (id < nodo->afic.getID())
        nodo->izq = eliminar(nodo->izq, id);

    else if (id > nodo->afic.getID())
        nodo->der = eliminar(nodo->der, id);

    else // Encontrado
    {
        // Caso 1: Nodo sin hijo izquierdo
        if (!nodo->izq)
        {
            pnodoAbb temp = nodo->der;
            delete nodo;
            return temp;
        }
        // Caso 2: Nodo sin hijo derecho
        else if (!nodo->der)
        {
            pnodoAbb temp = nodo->izq;
            delete nodo;
            return temp;
        }
        // Caso 3: Nodo con dos hijos
        else
        {
            // Buscar el sucesor inorden (mínimo del subárbol derecho)
            pnodoAbb sucesor = nodo->der;
            while (sucesor->izq)
                sucesor = sucesor->izq;

            // Copiar el valor del sucesor
            nodo->afic = sucesor->afic;

            // Eliminar el sucesor
            nodo->der = eliminar(nodo->der, sucesor->afic.getID());
        }
    }

    return nodo;
}

Arbol::~Arbol() 
{

}