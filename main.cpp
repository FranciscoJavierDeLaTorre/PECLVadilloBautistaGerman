#include "Gestor.hpp"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    Gestor gestor;
    char opcion;

    do {
        cout << "\n\n";
        cout << "\t|===============================================================|" << endl;
        cout << "\t|          SISTEMA DE CONTROL DE ACCESO AL ESTADIO              |" << endl;
        cout << "\t|===============================================================|" << endl;
        cout << "\n\t--- PARTE 1: GESTION DE PILA, COLAS Y LISTA ---" << endl;
        cout << "\tA. Generar 10 Aficionados aleatorios y almacenarlos en la Pila" << endl;
        cout << "\tB. Consultar todos los Aficionados en la Pila" << endl;
        cout << "\tC. Borrar los Aficionados de la pila" << endl;
        cout << "\tD. Simular llegada de Aficionados (Pila a Colas)" << endl;
        cout << "\tE. Consultar la cola de socios" << endl;
        cout << "\tF. Consultar la cola de simpatizantes" << endl;
        cout << "\tG. Borrar todos los Aficionados de las colas" << endl;
        cout << "\tH. Simular entrada al estadio (Colas a Lista ordenada)" << endl;
        cout << "\tI. Buscar aficionados especiales en la Lista" << endl;
        cout << "\tJ. Reiniciar el programa" << endl;
        
        cout << "\n\t--- PARTE 2: GESTION DEL ARBOL BINARIO ---" << endl;
        cout << "\tK. Crear y dibujar el ABB en consola" << endl;
        cout << "\tL. Mostrar Socios ordenados por ID (ABB)" << endl;
        cout << "\tM. Mostrar Simpatizantes ordenados por ID (ABB)" << endl;
        cout << "\tN. Mostrar todos los Aficionados en inorden (ABB)" << endl;
        cout << "\tO. Buscar aficionados especiales en el ABB" << endl;
        cout << "\tP. Contar aficionados con ID par" << endl;
        cout << "\tQ. Mostrar aficionados en nodos hoja" << endl;
        cout << "\tR. Eliminar aficionado por ID" << endl;
        
        cout << "\n\tS. Salir" << endl;
        cout << "\n\t" << string(64, '-') << endl;
        cout << "\tIndique la opcion deseada: ";
        cin >> opcion;
        opcion = toupper(opcion);
        
        system("clear");
        system("cls");

        switch(opcion) {

        case 'A':
            gestor.genera10Aficionados();
            cout << "\n\tPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
            system("clear");
            break;
            
        case 'B':
            gestor.muestraAficionados();
            cout << "\n\tPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
            system("clear");
            break;
            
        case 'C':
            gestor.borraAficionadosPila();
            cout << "\n\tPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
            system("clear");
            break;
            
        case 'D':
            gestor.encolarAficionados();
            cout << "\n\tPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
            system("clear");
            break;
            
        case 'E':
            gestor.muestraSociosCola();
            cout << "\n\tPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
            system("clear");
            break;
            
        case 'F':
            gestor.muestraSimpatizantesCola();
            cout << "\n\tPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
            system("clear");
            break;
            
        case 'G':
            gestor.borraAficionadosColas();
            cout << "\n\tPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
            system("clear");
            break;
            
        case 'H':
            gestor.enlistarAficionados();
            cout << "\n\tPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
            system("clear");
            break;
            
        case 'I':
            gestor.buscarAficionados();
            cout << "\n\tPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
            system("clear");
            break;
            
        case 'J':
            gestor.reiniciar();
            cout << "\n\tPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
            system("clear");
            break;
            
        case 'K':
            gestor.crearYdibujarABB();
            cout << "\n\tPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
            system("clear");
            break;
            
        case 'L':
            gestor.mostrarSociosOrdenadosID();
            cout << "\n\tPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
            system("clear");
            break;
            
        case 'M':
            gestor.mostrarSimpatizantesOrdenadosID();
            cout << "\n\tPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
            system("clear");
            break;
            
        case 'N':
            gestor.mostrarInOrden();
            cout << "\n\tPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
            system("clear");
            break;
            
        case 'O':
            gestor.buscarAficionadosABB();
            cout << "\n\tPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
            system("clear");
            break;
            
        case 'P':
            gestor.contarIDsPares();
            cout << "\n\tPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
            system("clear");
            break;
            
        case 'Q':
            gestor.mostrarHojasABB();
            cout << "\n\tPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
            system("clear");
            break;
            
        case 'R':
            gestor.eliminarAficionadoABB();
            cout << "\n\tPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
            system("clear");
            break;
            
        case 'S':
            cout << "\n\tSaliendo del programa..." << endl;
            cout << "\t¡Hasta pronto!" << endl;
            break;
            
        default:
            cout << "\n\t¡Opción incorrecta! Por favor elija una opción válida.\n" << endl;
            cout << "\n\tPresione Enter para continuar...";
            cin.ignore();
            cin.get();
            system("cls");
            system("clear");
            break;
        }
    } while(opcion != 'S');

    return 0;
}