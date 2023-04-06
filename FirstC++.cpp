#include <iostream>
#include <conio.h>
using namespace std;
struct Nodo{
        int dato;
        Nodo *siguiente;
    };
void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
void buscarLista(Nodo *,int);

Nodo *lista = NULL;
int dato,datobuscar;

int main(int argc, char const *argv[])
{ 
    //insercion de datos basico..

    insertarLista(lista,9);
    insertarLista(lista,5);
    insertarLista(lista,1);
    insertarLista(lista,6);
    insertarLista(lista,2);
    insertarLista(lista,8);
    insertarLista(lista,4);
    //mostrarLista(lista);
    
    buscarLista(lista,6);
    return 0;
} 

void insertarLista(Nodo *&lista,int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while ((aux1 != NULL) && (aux1->dato < n)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }
    if (lista == aux1)
    {
        lista = nuevo_nodo;
    }else{
        aux2->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = aux1;
}
void mostrarLista(Nodo *lista){
    Nodo *aux = lista;
    while (aux != NULL)
    {
        cout<<"Dato: "<<aux->dato<<endl;
        aux = aux->siguiente;
    } 
}
void buscarLista(Nodo *lista, int n){
    bool band = false;
    //Nodo *actual = new Nodo();
    Nodo *actual = lista;
    while((actual != NULL) && (actual->dato <= n)){
        if(actual->dato == n){
            band = true;
        }
        actual = actual->siguiente;
    }
    if (band == true)
    {
        cout<<"Elemento "<<n<<" SI se encuentra en la lista\n";
    }
    else{
        cout<<"Elemento "<<n<<" NO se encuentra en la lista\n";
    }
}
/*
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
__________________________________________________________
struct Nodo{
    int dato;
    Nodo *siguiente;
};
//prototipos
void insertarCola(Nodo *&,Nodo *&,int);
bool colaVacia(Nodo *&);
void mostrarCola(Nodo *&);
void buscarCola(Nodo *&, int);

//Variables globales
Nodo *frente = NULL;
int dato;
Nodo *final = NULL;

int main(int argc, char const *argv[])
{ 
    //insercion de datos basico..
    cout<<"Ingrese un DATO: ";
    cin>>dato;
    insertarCola(frente,final,dato);
    cout<<"Ingrese un DATO: ";
    cin>>dato;
    insertarCola(frente,final,dato);
    cout<<"Ingrese un DATO: ";
    cin>>dato;
    insertarCola(frente,final,dato);

    mostrarCola(frente);//Esta funcion muestra los datos de la cola (se puede repeti las veces que quieras)
    //Lo bueno de esta funcion esque no elimina los datos para mostrarlos.
    //se crea un aux para recorrerla por completo igual que las pilas.
    cout<<"Que dato quieres buscar de la cola?: ";
    cin>>dato;
    buscarCola(frente,dato);

    getch();//Para que se suspenda la pantalla gracias a <conio.h>
    return 0;
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
void buscarCola(Nodo *&frente,int datoBuscar){
    Nodo *aux = frente;
    bool encontrado;// Variable para indicar si se encontró el dato buscado
    while (aux != NULL)
    {
        if (aux->dato==datoBuscar){
            encontrado = true;
            break; // Salir del ciclo cuando se encuentra el dato buscado  
        }
        aux = aux->siguiente;//si no es igual que pase al siguiente nodo a revisar
    }
    if (encontrado){ //true
        cout<<"El dato "<<datoBuscar<<" se encuetra en la cola"<<endl;
    }else{ //false
        cout<<"El dato "<<datoBuscar<<" NO se encuetra en la cola"<<endl;
    }
}
_________________________________________
//void eliminarCola(Nodo *&,Nodo *&,int &);
void eliminarCola(Nodo *&frente,Nodo *&final,int &n){
    n = frente->dato;
    Nodo *aux = frente;
    if (frente==final){
        frente == NULL;
        final == NULL;
    }else{
        frente = frente ->siguiente;
    }
    delete aux;
}
_______________________________
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
void buscarElemento(Nodo *&, int);
void eliminarPila(Nodo *&, int &);   

Nodo *pila = NULL;int valor;string pregunta;
Nodo *pilaAux = NULL;    
    
int main(int argc, char const *argv[])
{ 
    menu();
    return 0;
}
void menu(){
    cout<<"******************************************"<<endl;
    cout<<"1. Insertar datos a la pila.\n2. Mostrar datos que contiene la pila.\n3. Buscar un elemento en la pila.\n4. Eliminar datos de la pila.\n5. Finalizar programa."<<endl;

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
        buscarElemento(pila,valor);
        menu();
        break;

    case 4:
        if (pregunta == "N" || pregunta == "n"){
        while (pila != NULL){
            eliminarPila(pila,valor);
            if (pila != NULL)
            {
                cout<<valor<<endl;
            }
            else{
                cout<<valor<<endl;
            }
        }
        }
        menu();
        break;
    
    case 5:
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

void buscarElemento(Nodo *&pila, int n){
    Nodo *actual_nodo = new Nodo();
    actual_nodo = pila;
    int nodoBuscado = 0;
    bool encontrado = false;
    cout<<"Ingrese el nodo a buscar: ";
    cin >> nodoBuscado;
    if (pila != NULL){
        while (actual_nodo != NULL && encontrado != true){
            if (actual_nodo->dato == nodoBuscado)
            {
                cout<<"El nodo con dato "<<nodoBuscado<<" fue encontrado"<<endl<<endl;
                encontrado = true;
            }
            actual_nodo = actual_nodo->siguiente;
        }
        if (encontrado == false)
        {
            cout<<"Nodo con dato "<<nodoBuscado<<" no fue encontrado"<<endl<<endl;
        }   
    }else{
        cout<<"La pila se encuentra vacía."<<endl;
    }

}

void eliminarPila(Nodo *&pila, int &n){
    Nodo *aux = pila;
    n = aux ->dato;
    pila = aux ->siguiente;
    delete aux;

    cout << "Elemento eliminado de la pila: ";
}
______________________________________________________
//prototipo de funcion
    void agregarPila(nodo *&,int);
    void sacarPila(nodo *&,int &);
    void mostrarPila(nodo *&);
    void SacarYMostrar();
    void buscarEnPila();
    
    nodo *pila = NULL;
    //Proto de pila auxiliar
    nodo *PilaAux = NULL;
int dato;
    cout<<"\nIngrese primer dato: ";
    cin>>dato;
    agregarPila(pila,dato);
    cout<<"\nIngrese segundo dato: ";
    cin>>dato;
    agregarPila(pila,dato);
    cout<<"\nIngrese tercer dato: ";
    cin>>dato;
    agregarPila(pila,dato);
    mostrarPila(pila);
    buscarEnPila();
void agregarPila(nodo *&pila,int n){
        nodo *nuevo_nodo = new nodo();
        nuevo_nodo->dato = n;
        nuevo_nodo->siguiente = pila;
        pila = nuevo_nodo;
        //cout<<"El elemento fue agregado a la pila con EXITO"<<endl;
    };
void sacarPila(nodo *&pila,int &n){
        nodo *aux = pila;
        n = aux->dato;
        pila = aux->siguiente;
        delete aux;
    }
void mostrarPila(nodo *&pila){
        nodo *aux = pila;
        cout<<"\nMostrando el contenido de la pila: "<<endl;
        while (aux != NULL)
        {
            //cout<<"Dato: "<<aux->dato<<endl;
            agregarPila(PilaAux,aux->dato);
            aux = aux->siguiente; 
        }
        nodo *aux2 = PilaAux;
        while (aux2 != NULL)
        {
            cout<<"Dato: "<<aux2->dato<<endl;
            aux2 = aux2->siguiente;
        }    
       
        nodo* actual = new nodo();
	actual = primero;
	if(primero!=NULL){
		while(actual!=NULL){
			cout << endl << " " << actual->dato; 
			actual = actual->siguiente;
		}
	}else{
		cout << endl << " La Pila se encuentra vacia" << endl << endl;
	}
          
    }
void buscarEnPila(){
    nodo* aux = new nodo();
	aux = pila;
	int datoBuscar = 0;
	bool encontrado = false;
	cout << " Ingrese el dato a Buscar: ";
	cin >> datoBuscar;
	if(pila!=NULL){
		while(aux!=NULL && encontrado != true){
			if(aux->dato == datoBuscar){
				cout << endl << " La Pila contiene el dato ( " << datoBuscar << " ) en su interior" << endl << endl;
				encontrado = true;
			}
			aux = aux->siguiente;
		}
		if(encontrado==false){
			cout << endl << " DATO no Encontrado" << endl << endl;
		}
	}else{
		cout << endl << " La Pila se encuentra vacia" << endl << endl;
	}
}
void SacarYMostrar(){
        cout<<"\nSancando elementos de pila: ";
        int dato;
        while(pila != NULL){
        sacarPila(pila,dato);
        if (pila != NULL)
        {
            cout<<dato<<" , ";
        }
        else{
            cout<<dato<<" . ";
        }
        }
    }
    
    ____________________________________________
    void mostrarPila(nodo *&pila){
        nodo *aux = NULL;
        cout<<"\nMostrando el contenido de la pila: ";
        while (aux != pila)
        {
            cout<<"Dato: "<<aux->dato<<endl;
            aux = aux->siguiente;
        }
        /*nodo *aux2 = PilaAux;
        while (aux2 != NULL)
        {
            cout<<"Dato: "<<aux2->dato<<endl;
            aux2 = aux2->siguiente;
        }        
    }
    _____________________________________
    void sacarPila(nodo *&,int &);
    void sacarPila(nodo *&pila,int &n){
        nodo *aux = pila;
        n = aux->dato;
        pila = aux->siguiente;
        delete aux;
    }
    int dato;
    cin>>dato;
    agregarPila(pila,dato);
    cin>>dato;
    agregarPila(pila,dato);
    cout<<"\nSancando elementos de pila: ";
    while(pila != NULL){
        sacarPila(pila,dato);
        if (pila != NULL)
        {
            cout<<dato<<" , ";
        }
        else{
            cout<<dato<<" . ";
        }
    }
    ________________________________
    //saber si un numero es par o impar
    int num,*dir_num;
    cout<<"Digite un numero: ";
    cin>>num;
    dir_num=&num; //Meto el valor y la posicion aqui
    if (*dir_num%2 == 0)
    {
        cout<<"El numero "<<*dir_num<<" es par\n"; //Cuando esta el *trae numero
        cout<<"La posicion en memoria es: "<<dir_num<<"\n";//Cuando no esta * trae direccion memoria
    }else{
        cout<<"El numero "<<*dir_num<<" es impar\n";
        cout<<"La posicion en memoria es: "<<dir_num<<"\n";
    }
    ________________________________
    //Ordenamiento por seleccion
    int numeros[] = {4,2,3,1,5};
    int i,j,aux,min;
    for ( i = 0; i < 5; i++)
    {
        min = i;
        for (j=i+1; j < 5; j++)
        {
            if (numeros[j] < numeros[min])
            {
                min = j;
            }
        }
        aux = numeros[i];
        numeros[i] = numeros[min];
        numeros[min] = aux;
    }
    cout<<"Orden Ascendente: ";
    for (i = 0; i < 5; i++)
    {
        cout<<numeros[i]<<" ";
    }
    cout<<"\nOrden Descendente: ";
    for (i = 4; i >= 0; i--)
    {
        cout<<numeros[i]<<" ";
    } 
    ________________________________
    //Algoritmo del ordenamiento por insercion
    int numeros[] = {4,2,3,1,5};
    int i,pos,aux;
    for (i = 0; i < 5; i++)
    {
        pos = i;
        aux = numeros[i];

        while ((pos>0) && (numeros[pos-1]>aux))
        {
            numeros[pos]=numeros[pos-1];
            pos--;
        }
        numeros[pos] = aux;
    }
    cout<<"Orden Ascendente: ";
    for (i = 0; i < 5; i++)
    {
        cout<<numeros[i]<<" ";
    }
    cout<<"\nOrden Descendente: ";
    for (i = 4; i >= 0; i--)
    {
        cout<<numeros[i]<<" ";
    } 
    _______________________________________
    Algoritmo burbuja
    int numeros[] = {4,1,2,3,5};
    int i,j,aux;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; i++){
            if (numeros[j] > numeros[j+1]){
                aux = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = aux;
            }
        }
    }
    cout<<"Orden Ascendente: ";
    for (int i = 0; i < 5; i++)
    {
        cout<<numeros[i]<<" ";
    }
    cout<<"\nOrden Descendente: ";
    for (int i = 4; i > 0; i--)
    {
        cout<<numeros[i]<<" ";
    }
    
    (para encontrar la longitud de una cadena   strlen(palabra)....)
    ____________________________
    int n,Nmayor=0,elemento[100];
    cout<<"Digita el numero de elementos= \n";
    cin>>n;
    for (int i = 0; i <= n; i++)
    {
        cout<<"*Ingresa el numero "<<i+1<< " del indice "<<i<<" = ";
        cin>>elemento[i];
        if (elemento[i]>Nmayor) 
        {
            Nmayor=elemento[i];
        }
    }
    cout<<"El mayor elemento del vector es: "<<Nmayor<<endl;
    ______________________________________
    int numero,dato,contador=0;
    srand(time(NULL));
    dato = 1 + rand()%(100);
    do
    {
        cout<<"Digite un numero: "; cin>>numero;
        if (numero>dato){
            cout<<"\nDigite un numero menor\n";
        }
        if (numero<dato){
            cout<<"\nDigite un numero mayor\n";
        }
        contador++; 
    } while (numero!=dato);
    cout<<"\nFELICIDADES ADIVINASTE EL NUMERO\n";
    cout<<"Numero de intentos: "<<contador;
    
    __________________________________
    float x,y,resultado =0;
    cout<<"Esta es la funcion que vamos a resolver= \n";
    cout<<"F (X,Y) =  √x/y2-1"<<endl;
    cout<<"Ingresa el valor de X = ";
    cin>>x;
    cout<<"\nIngresa el valor de Y = ";
    cin>>y;
    resultado = ((sqrt(x)))/(pow(y,2)-1);
    cout<<"\n"<<resultado;
    ________________________
    int i;
    i=10;
    while (i>=1)
    {
        cout<<i<<endl;
        i--;
    }
    __________________
    char canena1[]="nombre";
    char cadena2[]={'A','n','d','r','e','s'};
    cout<<canena1<<endl;
    cout<<cadena2;
    _________________________
    int Saldo_inicial= 1000,opc;
    float extra,saldo,retiro;

    cout<<"\tBienvenido a su cajero automatico Virtual"<<endl;
    cout<<"1. Ingresar Dinero a la cuenta."<<endl;
    cout<<"2. Retirar Dinero de la cuenta"<<endl;
    cout<<"3. Salir del programa"<<endl;
    cout<<"Escoje una Opción"<<endl;
    cin>>opc;

    switch (opc)
    {
    case 1:
        cout<<"Digite cuanto dinero quiere consignar?= \n";
        cin>>extra;
        saldo = Saldo_inicial + extra ;
        cout<<"Su nuevo saldo es: "<<saldo;
        break;
    case 2:
        cout<<"Digite cuanto dinero quiere retirar?= \n";
        cin>>retiro;
        if (retiro>Saldo_inicial)
        {
            cout<<"El dinero que quiere retirar es mayor al saldo de la cuenta NO se puede realizar";
            break;
        }else{
            saldo= Saldo_inicial - retiro;
            cout<<"El retiro fue aceptado, su nuevo saldo es: "<<saldo;
        }
    case 3:
        break;    
    
    default:
        break;
    }
    _________________________
    int numero= 15;
    float flotante= 15.63;
    double Mayor = 16.8925;
    char letra = '5';
    cout <<numero<<endl;
    cout <<flotante<<endl;
    cout <<Mayor<<endl;
    cout <<letra<<endl;
    _______________________________
    cout << "Hello, World!/n"<<endl;  //endl es para dar un espacion con /n
    //std::cout << "Hello, World!" << std::endl;
    int UsuaNumero ;
    cout <<"Ingresa un numero ";
    cin>>UsuaNumero;
    cout <<"El numero que escribio es: "<<UsuaNumero;
    
   int n1,n2,suma=0,resta=0,multiplicacion=0,divicion=0;
   cout<<"Ingresa el primer numero= ";cin>>n1;
   cout<<"Ingresa el segundo numero= ";cin>>n2;

   suma=n1+n2;
   resta=n1-n2;
   multiplicacion=n1*n2;
   divicion=n1/n2;
   cout<<"\nLa suma es: "<<suma<<endl;
   cout<<"La resta es: "<<resta<<endl;
   cout<<"La multiplicación es: "<<multiplicacion<<endl;
   cout<<"La divición es: "<<divicion<<endl;

*/