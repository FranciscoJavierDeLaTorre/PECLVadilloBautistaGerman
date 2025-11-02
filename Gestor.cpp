#include "Gestor.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;
Gestor::Gestor()
{
	// Inicializar las estructuras de datos
	pilaAficionados = new Pila();
	colaSocios = new Cola();
	colaSimpatizantes = new Cola();
	listaAficionados = new Lista();
	
	// Inicializar el contador para generar IDs
	contadorGeneracion = 0;
	
	// Inicializar semilla para números aleatorios
	srand(time(NULL));
}

Gestor::~Gestor()
{
	// Liberar memoria de las estructuras de datos
	delete pilaAficionados;
	delete colaSocios;
	delete colaSimpatizantes;
	delete listaAficionados;
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



// OPCIÓN A: Generar 10 aficionados aleatorios y almacenarlos en la pila
void Gestor::genera10Aficionados()
{
	cout << "\n\t=== GENERANDO 10 AFICIONADOS ALEATORIOS ===" << endl;
	
	// Calcular el rango de IDs para esta generación
	int idInicio = contadorGeneracion * 10 + 1;
	int idFin = idInicio + 9;
	
	cout << "\tRango de IDs: " << idInicio << " - " << idFin << endl;
	cout << "\t" << string(60, '-') << endl;
	
	// Generar 10 aficionados
	for(int i = 0; i < 10; i++)
	{
		int id = idInicio + i;

		int hora = rand() % 60;
		
		//(el constructor determina si es socio o simpatizante)
		Aficionado afic(id, hora);

		pilaAficionados->insertar(afic);

		cout << "\t" << (i+1) << ". ";
		afic.mostrar();
	
	}
	
	cout << "\t" << string(60, '-') << endl;
	cout << "\t 10 aficionados generados y almacenados en la pila." << endl;
	
	
	// Incrementar el contador para la próxima generación
	contadorGeneracion++;
}

// OPCIÓN B: Mostrar todos los aficionados almacenados en la pila
void Gestor::muestraAficionados()
{
	cout << "\n\t=== AFICIONADOS EN LA PILA ===\n" << endl;
	
	if(pilaAficionados->getLongitud() == 0)
	{
		cout << "\t La pila está vacía. Use la opción A para generar aficionados." << endl;
		return;
	}
	
	pilaAficionados->mostrar();
}

// OPCIÓN C: Borrar todos los aficionados de la pila
void Gestor::borraAficionadosPila()
{
	cout << "\n\t=== BORRANDO AFICIONADOS DE LA PILA ===" << endl;
	
	if(pilaAficionados->getLongitud() == 0)
	{
		cout << "\t La pila ya está vacía." << endl;
		return;
	}
	
	int cantidad = pilaAficionados->getLongitud();
	
	// Extraer todos los elementos de la pila
	while(pilaAficionados->getLongitud() > 0)
	{
		pilaAficionados->extraer();
	}
	//y si destruyo la pila y hago una nueva k?
	cout << "\t " << cantidad << " aficionados eliminados de la pila." << endl;
}

// OPCIÓN D: Encolar aficionados (extraer de pila e insertar en colas)
void Gestor::encolarAficionados()
{
	cout << "\n\t=== ENCOLANDO AFICIONADOS ===" << endl;
	
	if(pilaAficionados->getLongitud() == 0)
	{
		cout << "\t La pila está vacía. No hay aficionados para encolar." << endl;
		return;
	}
	
	int socios = 0;
	int simpatizantes = 0;
	
	// Extraer todos los aficionados de la pila
	while(pilaAficionados->getLongitud() > 0)
	{
		Aficionado afic = pilaAficionados->extraer();
		
		// Insertar en la cola correspondiente según el tipo
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
	cout << "\t Aficionados encolados:" << endl;
	cout << "\t  - Socios: " << socios << endl;
	cout << "\t  - Simpatizantes: " << simpatizantes << endl;
	cout << "\t  - Total: " << (socios + simpatizantes) << endl;
}

// OPCIÓN E: Mostrar la cola de socios
void Gestor::muestraSociosCola()
{
	cout << "\n\t=== COLA DE SOCIOS ===" << endl;
	
	if(colaSocios->getLongitud() == 0)
	{
		cout << "\t La cola de socios está vacía." << endl;
		return;
	}
	
	colaSocios->mostrar();
}

// OPCIÓN F: Mostrar la cola de simpatizantes
void Gestor::muestraSimpatizantesCola()
{
	cout << "\n\t=== COLA DE SIMPATIZANTES ===" << endl;
	
	if(colaSimpatizantes->getLongitud() == 0)
	{
		cout << "\t La cola de simpatizantes está vacía." << endl;
		return;
	}
	
	colaSimpatizantes->mostrar();
}

// OPCIÓN G: Borrar todos los aficionados de ambas colas
void Gestor::borraAficionadosColas()
{
	cout << "\n\t=== BORRANDO AFICIONADOS DE LAS COLAS ===" << endl;
	
	int sociosEliminados = colaSocios->getLongitud();
	int simpatizantesEliminados = colaSimpatizantes->getLongitud();
	
	if(sociosEliminados == 0 && simpatizantesEliminados == 0)
	{
		cout << "\t Ambas colas ya están vacías." << endl;
		return;
	}
	
	// Vaciar cola de socios
	while(colaSocios->getLongitud() > 0)
	{
		colaSocios->extraer();
	}
	
	// Vaciar cola de simpatizantes
	while(colaSimpatizantes->getLongitud() > 0)
	{
		colaSimpatizantes->extraer();
	}
	
	cout << "\t Aficionados eliminados:" << endl;
	cout << "\t  - Socios: " << sociosEliminados << endl;
	cout << "\t  - Simpatizantes: " << simpatizantesEliminados << endl;
	cout << "\t  - Total: " << (sociosEliminados + simpatizantesEliminados) << endl;
}

// OPCIÓN H: Enlistar aficionados (extraer de colas e insertar ordenados en lista)
void Gestor::enlistarAficionados()
{
	cout << "\n\t=== ENLISTANDO AFICIONADOS ===" << endl;
	
	if(colaSocios->getLongitud() == 0 && colaSimpatizantes->getLongitud() == 0)
	{
		cout << "\t Las colas están vacías. No hay aficionados para enlistar." << endl;
		return;
	}
	
	int sociosEnlistados = 0;
	int simpatizantesEnlistados = 0;
	
	// Primero extraer e insertar todos los SOCIOS (prioridad)
	cout << "\t Insertando socios ordenados por hora de llegada..." << endl;
	while(colaSocios->getLongitud() > 0)
	{
		Aficionado afic = colaSocios->extraer();
		listaAficionados->insertarOrdenado(afic);
		sociosEnlistados++;
	}
	
	// Luego extraer e insertar todos los SIMPATIZANTES (no prioridad)
	cout << "\t Insertando simpatizantes ordenados por hora de llegada..." << endl;
	while(colaSimpatizantes->getLongitud() > 0)
	{
		Aficionado afic = colaSimpatizantes->extraer();
		listaAficionados->insertarOrdenado(afic);
		simpatizantesEnlistados++;
	}
	
	cout << "\t" << string(60, '-') << endl;
	cout << "\ Aficionados enlistados ordenadamente:" << endl;
	cout << "\t  - Socios: " << sociosEnlistados << endl;
	cout << "\t  - Simpatizantes: " << simpatizantesEnlistados << endl;
	cout << "\t  - Total: " << (sociosEnlistados + simpatizantesEnlistados) << endl;
}

// OPCIÓN I: Buscar y mostrar aficionados específicos en la lista
void Gestor::buscarAficionados()
{
	cout << "\n\t=== BÚSQUEDA DE AFICIONADOS EN LA LISTA ===" << endl;
	
	if(listaAficionados->getLongitud() == 0)
	{
		cout << "\t La lista está vacía. No hay aficionados para buscar." << endl;
		return;
	}
	
	cout << "\t" << string(60, '-') << endl;
	
	// 1. Primer aficionado en acceder al estadio
	Aficionado primero = listaAficionados->getPrimero();
	cout << "\t1. PRIMER AFICIONADO en acceder:" << endl;
	cout << "\t   ";
	primero.mostrar();
	
	// 2. Último socio en acceder al estadio
	Aficionado ultimoSocio = listaAficionados->getUltimoSocio();
	cout << "\n\t2. ÚLTIMO SOCIO en acceder:" << endl;
	cout << "\t   ";
	ultimoSocio.mostrar();
	
	// 3. Primer simpatizante en acceder al estadio
	Aficionado primerSimp = listaAficionados->getPrimerSimpatizante();
	cout << "\n\t3. PRIMER SIMPATIZANTE en acceder:" << endl;
	cout << "\t   ";
	primerSimp.mostrar();
	
	// 4. Último aficionado en acceder al estadio
	Aficionado ultimo = listaAficionados->getUltimo();
	cout << "\n\t4. ÚLTIMO AFICIONADO en acceder:" << endl;
	cout << "\t   ";
	ultimo.mostrar();
	
	cout << "\t" << string(60, '-') << endl;
}
//hay q mirar lo d q siempre coincidan


// OPCIÓN J: Reiniciar el programa a su estado inicial
void Gestor::reiniciar()
{
	cout << "\n\t=== REINICIANDO EL PROGRAMA ===" << endl;
	
	// Borrar todas las estructuras
	borraAficionadosPila();
	borraAficionadosColas();
	
	// Vaciar la lista
	if(listaAficionados->getLongitud() > 0)
	{
		listaAficionados->vaciar();
		cout << "\t Lista vaciada." << endl;
	}
	
	// Reiniciar el contador de generación
	contadorGeneracion = 0;
	
	cout << "\t" << string(60, '-') << endl;
	cout << "\t Programa reiniciado correctamente." << endl;
	cout << "\t  Todas las estructuras han sido vaciadas." << endl;
}