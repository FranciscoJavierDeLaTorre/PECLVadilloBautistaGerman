#include "Gestor.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

Gestor::Gestor()
{
    pilaAficionados = new Pila();
    colaSocios = new Cola();
    colaSimpatizantes = new Cola();
    listaAficionados = new Lista();
    arbolAficionados = new Arbol();
    
    contadorGeneracion = 0;
    
    srand(time(NULL));
}

Gestor::~Gestor()
{
    delete pilaAficionados;
    delete colaSocios;
    delete colaSimpatizantes;
    delete listaAficionados;
    delete arbolAficionados;
}

int Gestor::AficionadosEnPila()
{
    return pilaAficionados->getLongitud();
}

int Gestor::SociosEnCola()
{
    return colaSocios->getLongitud();
}

int Gestor::SimpatizantesEnCola()
{
    return colaSimpatizantes->getLongitud();
}

int Gestor::AficionadosEnLista()
{
    return listaAficionados->getLongitud();
}

// OPCIÓN A: Generar 10 aficionados aleatorios
void Gestor::genera10Aficionados()
{
    cout << "\n\t=== GENERANDO 10 AFICIONADOS ALEATORIOS ===" << endl;
    
    int idInicio = contadorGeneracion * 10 + 1;
    int idFin = idInicio + 9;
    
    cout << "\tRango de IDs: " << idInicio << " - " << idFin << endl;
    cout << "\t" << string(60, '-') << endl;
    
    for(int i = 0; i < 10; i++)
    {
        int id = idInicio + i;
        int hora = rand() % 60;
        
        Aficionado afic(id, hora);
        pilaAficionados->insertar(afic);
        
        cout << "\t" << (i+1) << ". ";
        afic.mostrar();
    }
    
    cout << "\t" << string(60, '-') << endl;
    cout << "\t10 aficionados generados y almacenados en la pila." << endl;
    
    contadorGeneracion++;
}

// OPCIÓN B: Mostrar aficionados en la pila
void Gestor::muestraAficionados()
{
    cout << "\n\t=== AFICIONADOS EN LA PILA ===\n" << endl;
    
    if(pilaAficionados->getLongitud() == 0)
    {
        cout << "\tLa pila está vacía. Use la opción A para generar aficionados." << endl;
        return;
    }
    
    pilaAficionados->mostrar();
}

// OPCIÓN C: Borrar aficionados de la pila
void Gestor::borraAficionadosPila()
{
    cout << "\n\t=== BORRANDO AFICIONADOS DE LA PILA ===" << endl;
    
    if(pilaAficionados->getLongitud() == 0)
    {
        cout << "\tLa pila ya está vacía." << endl;
        return;
    }
    
    int cantidad = pilaAficionados->getLongitud();
    
    while(pilaAficionados->getLongitud() > 0)
    {
        pilaAficionados->extraer();
    }
    
    cout << "\t" << cantidad << " aficionados eliminados de la pila." << endl;
}

// OPCIÓN D: Encolar aficionados
void Gestor::encolarAficionados()
{
    cout << "\n\t=== ENCOLANDO AFICIONADOS ===" << endl;
    
    if(pilaAficionados->getLongitud() == 0)
    {
        cout << "\tLa pila está vacía. No hay aficionados para encolar." << endl;
        return;
    }
    
    int socios = 0;
    int simpatizantes = 0;
    
    while(pilaAficionados->getLongitud() > 0)
    {
        Aficionado afic = pilaAficionados->extraer();
        
        if(afic.esSocio())
        {
            colaSocios->insertar(afic);
            socios++;
        }
        else
        {
            colaSimpatizantes->insertar(afic);
            simpatizantes++;
        }
    }
    
    cout << "\t" << string(60, '-') << endl;
    cout << "\tAficionados encolados:" << endl;
    cout << "\t  - Socios: " << socios << endl;
    cout << "\t  - Simpatizantes: " << simpatizantes << endl;
    cout << "\t  - Total: " << (socios + simpatizantes) << endl;
}

// OPCIÓN E: Mostrar cola de socios
void Gestor::muestraSociosCola()
{
    cout << "\n\t=== COLA DE SOCIOS ===" << endl;
    
    if(colaSocios->getLongitud() == 0)
    {
        cout << "\tLa cola de socios está vacía." << endl;
        return;
    }
    
    colaSocios->mostrar();
}

// OPCIÓN F: Mostrar cola de simpatizantes
void Gestor::muestraSimpatizantesCola()
{
    cout << "\n\t=== COLA DE SIMPATIZANTES ===" << endl;
    
    if(colaSimpatizantes->getLongitud() == 0)
    {
        cout << "\tLa cola de simpatizantes está vacía." << endl;
        return;
    }
    
    colaSimpatizantes->mostrar();
}

// OPCIÓN G: Borrar aficionados de las colas
void Gestor::borraAficionadosColas()
{
    cout << "\n\t=== BORRANDO AFICIONADOS DE LAS COLAS ===" << endl;
    
    int sociosEliminados = colaSocios->getLongitud();
    int simpatizantesEliminados = colaSimpatizantes->getLongitud();
    
    if(sociosEliminados == 0 && simpatizantesEliminados == 0)
    {
        cout << "\tAmbas colas ya están vacías." << endl;
        return;
    }
    
    while(colaSocios->getLongitud() > 0)
    {
        colaSocios->extraer();
    }
    
    while(colaSimpatizantes->getLongitud() > 0)
    {
        colaSimpatizantes->extraer();
    }
    
    cout << "\tAficionados eliminados:" << endl;
    cout << "\t  - Socios: " << sociosEliminados << endl;
    cout << "\t  - Simpatizantes: " << simpatizantesEliminados << endl;
    cout << "\t  - Total: " << (sociosEliminados + simpatizantesEliminados) << endl;
}

// OPCIÓN H: Enlistar aficionados ordenadamente
void Gestor::enlistarAficionados()
{
    cout << "\n\t=== ENLISTANDO AFICIONADOS ===" << endl;
    
    if(colaSocios->getLongitud() == 0 && colaSimpatizantes->getLongitud() == 0)
    {
        cout << "\tLas colas están vacías. No hay aficionados para enlistar." << endl;
        return;
    }
    
    int sociosEnlistados = 0;
    int simpatizantesEnlistados = 0;
    
    cout << "\tInsertando socios ordenados por hora de llegada..." << endl;
    while(colaSocios->getLongitud() > 0)
    {
        Aficionado afic = colaSocios->extraer();
        listaAficionados->insertarOrdenado(afic);
        sociosEnlistados++;
    }
    
    cout << "\tInsertando simpatizantes ordenados por hora de llegada..." << endl;
    while(colaSimpatizantes->getLongitud() > 0)
    {
        Aficionado afic = colaSimpatizantes->extraer();
        listaAficionados->insertarOrdenado(afic);
        simpatizantesEnlistados++;
    }
    
    cout << "\t" << string(60, '-') << endl;
    cout << "\tAficionados enlistados ordenadamente:" << endl;
    cout << "\t  - Socios: " << sociosEnlistados << endl;
    cout << "\t  - Simpatizantes: " << simpatizantesEnlistados << endl;
    cout << "\t  - Total: " << (sociosEnlistados + simpatizantesEnlistados) << endl;
}

// OPCIÓN I: Buscar aficionados en la lista
void Gestor::buscarAficionados()
{
    cout << "\n\t=== BÚSQUEDA DE AFICIONADOS EN LA LISTA ===" << endl;
    
    if(listaAficionados->getLongitud() == 0)
    {
        cout << "\tLa lista está vacía. No hay aficionados para buscar." << endl;
        return;
    }
    
    cout << "\t" << string(60, '-') << endl;
    
    Aficionado primero = listaAficionados->getPrimero();
    cout << "\t1. PRIMER AFICIONADO en acceder:" << endl;
    cout << "\t   ";
    primero.mostrar();
    
    Aficionado ultimoSocio = listaAficionados->getUltimoSocio();
    cout << "\n\t2. ÚLTIMO SOCIO en acceder:" << endl;
    cout << "\t   ";
    ultimoSocio.mostrar();
    
    Aficionado primerSimp = listaAficionados->getPrimerSimpatizante();
    cout << "\n\t3. PRIMER SIMPATIZANTE en acceder:" << endl;
    cout << "\t   ";
    primerSimp.mostrar();
    
    Aficionado ultimo = listaAficionados->getUltimo();
    cout << "\n\t4. ÚLTIMO AFICIONADO en acceder:" << endl;
    cout << "\t   ";
    ultimo.mostrar();
    
    cout << "\t" << string(60, '-') << endl;
}

// OPCIÓN J: Reiniciar el programa
void Gestor::reiniciar()
{
    cout << "\n\t=== REINICIANDO EL PROGRAMA ===" << endl;
    
    borraAficionadosPila();
    borraAficionadosColas();
    
    if(listaAficionados->getLongitud() > 0)
    {
        listaAficionados->vaciar();
        cout << "\tLista vaciada." << endl;
    }
    
    delete arbolAficionados;
    arbolAficionados = new Arbol();
    cout << "\tÁrbol reiniciado." << endl;
    
    contadorGeneracion = 0;
    
    cout << "\t" << string(60, '-') << endl;
    cout << "\tPrograma reiniciado correctamente." << endl;
}

// OPCIÓN K: Crear y dibujar ABB
void Gestor::crearYdibujarABB()
{
    cout << "\n\t=== CREANDO Y DIBUJANDO EL ABB ===" << endl;
    
    if(listaAficionados->getLongitud() == 0)
    {
        cout << "\tLa lista está vacía. No hay aficionados para crear el árbol." << endl;
        return;
    }
    
    // Crear un nuevo árbol
    delete arbolAficionados;
    arbolAficionados = new Arbol();
    
    // Crear el nodo raíz socio ficticio
    Aficionado Ficticio;
    Ficticio.setID(0);
    Ficticio.setHora_llegada(0);
    Ficticio.setEs_socio(true);
    arbolAficionados->insertar1(Ficticio);
    
    // Recorrer la lista e insertar en el árbol
    pnodoLista aux = listaAficionados->getPrimeroNodo();
    int socios = 0;
    int simpatizantes = 0;
    
    while(aux != nullptr)
    {
        Aficionado afic = aux->getAficionado();
        arbolAficionados->insertar1(afic);
        
        if(afic.esSocio())
            socios++;
        else
            simpatizantes++;
        
        aux = aux->getSiguiente();
    }
    
    cout << "\t" << string(60, '-') << endl;
    cout << "\tÁrbol creado con:" << endl;
    cout << "\t  - Socios: " << socios << endl;
    cout << "\t  - Simpatizantes: " << simpatizantes << endl;
    cout << "\t  - Total: " << (socios + simpatizantes) << endl;
    cout << "\t" << string(60, '-') << endl;
    
    arbolAficionados->dibujar();
}

// OPCIÓN L: Mostrar socios ordenados por ID
void Gestor::mostrarSociosOrdenadosID()
{
    cout << "\n\t=== SOCIOS ORDENADOS POR ID (ABB) ===" << endl;
    
    cout << "\t" << string(60, '-') << endl;
    arbolAficionados->mostrarSociosOrden();
    cout << "\t" << string(60, '-') << endl;
}

// OPCIÓN M: Mostrar simpatizantes ordenados por ID
void Gestor::mostrarSimpatizantesOrdenadosID()
{
    cout << "\n\t=== SIMPATIZANTES ORDENADOS POR ID (ABB) ===" << endl;
    
    cout << "\t" << string(60, '-') << endl;
    arbolAficionados->mostrarSimpatizantesOrden();
    cout << "\t" << string(60, '-') << endl;
}

// OPCIÓN N: Mostrar todos en inorden
void Gestor::mostrarInOrden()
{
    cout << "\n\t=== AFICIONADOS EN INORDEN (ABB) ===" << endl;
    
    cout << "\t" << string(60, '-') << endl;
    arbolAficionados->inOrden();
    cout << "\t" << string(60, '-') << endl;
}

// OPCIÓN O: Buscar aficionados especiales en el ABB
void Gestor::buscarAficionadosABB()
{
    cout << "\n\t=== BÚSQUEDA DE AFICIONADOS EN EL ABB ===" << endl;
    
    Aficionado primero, ultimoSocio, primerSimpatizante, ultimo;
    
    arbolAficionados->buscarEspeciales(primero, ultimoSocio, primerSimpatizante, ultimo);
    
    cout << "\t" << string(60, '-') << endl;
    
    cout << "\t1. PRIMER AFICIONADO en acceder:" << endl;
    cout << "\t   ";
    primero.mostrar();
    
    cout << "\n\t2. ÚLTIMO SOCIO en acceder:" << endl;
    cout << "\t   ";
    ultimoSocio.mostrar();
    
    cout << "\n\t3. PRIMER SIMPATIZANTE en acceder:" << endl;
    cout << "\t   ";
    primerSimpatizante.mostrar();
    
    cout << "\n\t4. ÚLTIMO AFICIONADO en acceder:" << endl;
    cout << "\t   ";
    ultimo.mostrar();
    
    cout << "\t" << string(60, '-') << endl;
}

// OPCIÓN P: Contar IDs pares
void Gestor::contarIDsPares()
{
    cout << "\n\t=== CONTANDO AFICIONADOS CON ID PAR ===" << endl;
    
    int cantidad = arbolAficionados->contarIDPares();
    
    cout << "\t" << string(60, '-') << endl;
    cout << "\tTotal de aficionados con ID par: " << cantidad << endl;
    cout << "\t" << string(60, '-') << endl;
}

// OPCIÓN Q: Mostrar hojas del ABB
void Gestor::mostrarHojasABB()
{
    cout << "\n\t=== AFICIONADOS EN NODOS HOJA ===" << endl;
    
    cout << "\t" << string(60, '-') << endl;
    arbolAficionados->mostrarHojas();
    cout << "\t" << string(60, '-') << endl;
}

// OPCIÓN R: Eliminar aficionado del ABB
void Gestor::eliminarAficionadoABB()
{
    cout << "\n\t=== ELIMINAR AFICIONADO DEL ABB ===" << endl;
    
    int id;
    cout << "\n\tIngrese el ID del aficionado a eliminar: ";
    cin >> id;
    
    if(id == 0)
    {
        cout << "\n\tNo se puede eliminar el nodo raíz ficticio." << endl;
        return;
    }
    
    cout << "\n\t--- ÁRBOL ANTES DE LA ELIMINACIÓN ---" << endl;
    arbolAficionados->dibujar();
    
    arbolAficionados->eliminar(id);
    
    cout << "\n\t--- ÁRBOL DESPUÉS DE LA ELIMINACIÓN ---" << endl;
    arbolAficionados->dibujar();
    
    cout << "\tAficionado con ID " << id << " eliminado correctamente." << endl;
}