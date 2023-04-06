#include <iostream>
#include <conio.h>
using namespace std;
struct Nodo{
        int dato;
        Nodo *siguiente;
    };
//prototipos
void menu();
void funcionSwitch(int);
void agregarPila(Nodo *&, int);
void mostrarPila(Nodo *&);   

Nodo *pila = NULL;int valor;string pregunta;
Nodo *pilaAux = NULL;    
    
int main(int argc, char const *argv[])
{ 
    menu();
    return 0;
}
void menu(){
    cout<<"******************************************"<<endl;
    cout<<"1. Insertar datos a la pila.\n2. Mostrar datos que contiene la pila.\n3. Finalizar programa."<<endl;

    int opcion;
    cout<<"¿Qué opción seleccionas?: "<<endl;
    cin>>opcion;
    cout<<"******************************************"<<endl;
    funcionSwitch(opcion);
}

void funcionSwitch(int opcion){
    switch (opcion)
    {
    case 1:
        do
    {
        cout<<"Ingrese el número: ";
        cin >> valor;
        agregarPila(pila,valor);

        cout<<"¿Desea ingresar otro número? s/n: ";
        cin>>pregunta;

    } while (pregunta == "S" || pregunta == "s");
        cout<<"Elementos agregados a pila"<<endl;
        menu();
        break;

    case 2:
        cout<<"Los datos de la pila son:"<<endl;
        mostrarPila(pila);
        menu();
        break;

    case 3:
        cout<<"Programa finalizado...";
        break;

    default:
        cout<<"Seleccione una opción correcta"<<endl<<endl;
        menu();
        break;
    }
}

void agregarPila(Nodo *&pila,int n){
    Nodo *nuevo_nodo = new Nodo(); //reservamos el espacio en memoria para nuevo_nodo
    nuevo_nodo ->dato = n; // igualar la parte dato a n y ponerlo en el nuevo nodo
    nuevo_nodo ->siguiente = pila; // poner el puntero e igualarlo a pila
    pila = nuevo_nodo; // igualar pila al nuevo nodo

}

void mostrarPila(Nodo *&pila){
    Nodo *aux = pila;
    while (aux != NULL)
    {
        agregarPila(pilaAux,aux->dato);
        aux = aux->siguiente;
    }
    Nodo *aux2 = pilaAux;
    while (aux2 != NULL)
    {
        cout<<"Dato: "<<aux2->dato<<endl;
        aux2 = aux2->siguiente;
    }
    
}