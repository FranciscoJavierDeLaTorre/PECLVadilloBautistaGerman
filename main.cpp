#include "Gestor.hpp"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	Gestor gestor;
	char opcion;

	do {

		cout << "\tA. Generar 10 Aficionados de forma aleatoria y almacenarlos en la Pila.\n";
		cout << "\tB. Consultar todos los Aficionados generados en la Pila.\n";
		cout << "\tC. Borrar los Aficionados generados en la pila.\n";
		cout << "\tD. Simular llegada de los Aficionados en las colas.\n";
		cout << "\tE. Consultar los Aficionados en las cola de socios.\n";
		cout << "\tF. Consultar los Aficionados en la cola de simpatizantes.\n";
		cout << "\tG. Borrar todos los Aficionados de las colas.\n";
		cout << "\tH. Simular la entrada de los Aficionados a la lista.\n";
		cout << "\tI. Buscar en la lista el primer Aficionado, "
				"el ultimo socio, el primer simpatizante y "
				"el ultimo Aficionado que acceden al estadio.\n";
		cout << "\tJ. Reiniciar el programa.\n";
		cout << "\tS. Salir.\n\n";

		cout << "\tIndique la opcion deseada: ";
		cin >> opcion;
		opcion = toupper(opcion);
		system("clear");
		system("cls");

		switch(opcion) {

		case 'A':
			gestor.genera10Aficionados();
			system("pause");
			break;
		case 'B':
			gestor.muestraAficionados();
			system("pause");
			break;
		case 'C':
			gestor.borraAficionadosPila();
			system("pause");
			break;
		case 'D':
			gestor.encolarAficionados();
			system("pause");
			break;
		case 'E':
			gestor.muestraSociosCola();
			system("pause");
			break;
		case 'F':
			gestor.muestraSimpatizantesCola();
			system("pause");
			break;
		case 'G':
			gestor.borraAficionadosColas();
			system("pause");
			break;
		case 'H':
			gestor.enlistarAficionados();
			system("pause");
			break;
		case 'I':
			gestor.buscarAficionados();
			system("pause");
			break;
		case 'J':
			gestor.reiniciar();
			system("pause");
			break;
	
		case 'S':
			cout << "Saliendo del programa...\n";
			break;
		default:
			cout << "Opcion incorrecta!\n\n";
			system("pause");
			break;
		}
	} while(opcion != 'S');

	return 0;
}