#include <iostream>
#include <conio.h>
using namespace std;
struct Nodo{
    int dato;
    Nodo *siguiente;
};
//
void menu();
void funcionSwitch(int);
void insertarCola(Nodo *&,Nodo *&,int);
bool colaVacia(Nodo *&);
void mostrarCola(Nodo *&);
void buscarCola(Nodo *&, int);
void sumarColaSinX(Nodo *&,int);

//Variables globales
Nodo *frente = NULL;
int dato;
string pregunta;
int x;
Nodo *final = NULL; 
    
int main(int argc, char const *argv[])
{ 
    menu();
    getch();//Para que se suspenda la pantalla gracias a <conio.h>
    return 0;
}
void menu(){
    cout<<"******************************************"<<endl;
    cout<<"1. Insertar datos a la COLA.\n2. Mostrar datos de la COLA.\n3. Hacer suma de los numeros que estan antes del buscado\n4. Finalizar programa."<<endl;

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
        cin >> dato;
        insertarCola(frente,final,dato);
        cout<<"¿Desea ingresar otro número? s/n: ";
        cin>>pregunta;

    } while (pregunta == "S" || pregunta == "s");
        cout<<"Elementos agregados a pila"<<endl;
        menu();
        break;

    case 2:
        cout<<"Los datos de la COLA son:"<<endl;
        mostrarCola(frente);//Esta funcion muestra los datos de la cola (se puede repeti las veces que quieras)
    //Lo bueno de esta funcion esque no elimina los datos para mostrarlos.
    //se crea un aux para recorrerla por completo igual que las pilas.
        menu();
        break;

    case 3:
        cout<<"Cual dato quieres buscar en la cola?:"<<endl;
        cin>>x;
        sumarColaSinX(frente,x);
        menu();
        break;

    case 4:
        cout<<"Programa finalizado...";
        break;

    default:
        cout<<"Seleccione una opción correcta"<<endl<<endl;
        menu();
        break;
    }
}

void insertarCola(Nodo *&frente,Nodo *&final,int n){
    Nodo *nuevo_nodo = new Nodo(); //reservamos el espacio en memoria para nuevo_nodo
    nuevo_nodo ->dato = n; // igualar la parte dato a n y ponerlo en el nuevo nodo
    nuevo_nodo ->siguiente = NULL; // poner el puntero e igualarlo a NULL
    if (colaVacia(frente)){
        frente = nuevo_nodo;//Proceso si esta vacia
    }else{
        final -> siguiente = nuevo_nodo;//Proceso si hay mas de un dato
    }
    final = nuevo_nodo;//y siempre se va a pasar al final el nodo (final) para seguir con la insercion.
    cout<<"Se ingreso el dato correctamente"<<endl;
}
bool colaVacia(Nodo *&frente){
    return (frente == NULL)? true : false ;//Esta funcion devuelve true o false
    //para identificar si la pila esta vacia y poder hacer un proceso si no y un proceso si si.
}

void mostrarCola(Nodo *&frente){  //    |5|->|6|->null
    cout<<"Mostrando los datos de la cola..."<<endl;
    Nodo *aux = frente;
    while (aux != NULL)
    {
        cout<<"Dato: "<<aux->dato<<endl;
        aux = aux->siguiente;
    }
}

void sumarColaSinX(Nodo *&frente,int x){ 
    Nodo *aux = frente;
    int suma = 0;
    bool encontrado;// Variable para indicar si se encontró el dato buscado
    while (aux != NULL)
    {
        if (aux->dato==x){
            encontrado = true;
            break; // Salir del ciclo cuando se encuentra el dato buscado  
        }
        suma = suma + aux->dato;
        aux = aux->siguiente;//si no es igual que pase al siguiente nodo a revisar
    }
    if (encontrado){ //true
        cout<<"El dato '"<<x<<"' se encuetra en la cola"<<endl;
        cout<<"y la suma de los numeros que estan antes del buscado es..."<<suma<<" TOTAL"<<endl;
    }else{ //false
        cout<<"El dato "<<x<<" NO se encuetra en la cola"<<endl;
    }
}