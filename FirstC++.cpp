# include<iostream>
# include<conio.h>
# include<stdlib.h>
# include <queue>
using namespace std;
// Definición de la estructura de un nodo del árbol
struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
};

// Función para crear un nuevo nodo del árbol
Nodo* crearNodo(int dato) {
    Nodo* nodo = new Nodo();
    nodo->dato = dato;
    nodo->izquierda = NULL;
    nodo->derecha = NULL;
    return nodo;
}

// Función para insertar un nuevo nodo en el árbol
Nodo* insertarNodo(Nodo* raiz, int dato) {
    if (raiz == NULL) {
        return crearNodo(dato);
    } else {
        if (dato <= raiz->dato) {
            raiz->izquierda = insertarNodo(raiz->izquierda, dato);
        } else {
            raiz->derecha = insertarNodo(raiz->derecha, dato);
        }
        return raiz;
    }
}

// Función para buscar un dato en el árbol
bool buscarDato(Nodo* raiz, int dato) {
    if (raiz == NULL) {
        return false;
    } else if (raiz->dato == dato) {
        return true;
    } else if (dato <= raiz->dato) {
        return buscarDato(raiz->izquierda, dato);
    } else {
        return buscarDato(raiz->derecha, dato);
    }
}

// Función para mostrar el contenido del árbol en orden
void mostrarArbol(Nodo* raiz) {
    if (raiz != NULL) {
        mostrarArbol(raiz->izquierda);
        cout << raiz->dato << " ";
        mostrarArbol(raiz->derecha);
    }
}
int obtenerAltura(Nodo* raiz) {
    if (raiz == nullptr) {
        return 0;
    } else {
        int alturaIzquierda = obtenerAltura(raiz->izquierda);
        int alturaDerecha = obtenerAltura(raiz->derecha);
        return max(alturaIzquierda, alturaDerecha) + 1;
    }
}

// Función auxiliar para imprimir espacios en blanco
void imprimirEspacios(int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << " ";
    }
}

// Función para mostrar el árbol de manera visual en la consola
void mostrarArbolVisual(Nodo* raiz) {
    if (raiz == nullptr) {
        cout << "El árbol está vacío." << endl;
        return;
    }

    int altura = obtenerAltura(raiz);
    int espaciosEntreNodos = 4;

    queue<Nodo*> nodos;
    nodos.push(raiz);

    while (!nodos.empty()) {
        int nodosEnNivel = nodos.size();
        int espaciosAntes = (1 << (altura - 1)) - 1;
        int espaciosEntre = (1 << altura) - 1;

        imprimirEspacios(espaciosAntes);

        for (int i = 0; i < nodosEnNivel; i++) {
            Nodo* nodoActual = nodos.front();
            nodos.pop();

            if (nodoActual != nullptr) {
                cout << nodoActual->dato;
                nodos.push(nodoActual->izquierda);
                nodos.push(nodoActual->derecha);
            } else {
                cout << "-";
                nodos.push(nullptr);
                nodos.push(nullptr);
            }

            imprimirEspacios(espaciosEntre);
        }

        altura--;
        espaciosAntes /= 2;
        espaciosEntre /= 2;

        cout << endl;

        if (nodosEnNivel == 1 && nodos.front() == nullptr) {
            break;
        }
    }
}
int main() {
    Nodo* raiz = nullptr;
    int opcion;
    int dato;

    do {
        cout << "------- Menú -------" << endl;
        cout << "1. Insertar dato" << endl;
        cout << "2. Buscar dato" << endl;
        cout << "3. Mostrar árbol" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el dato a insertar: ";
                cin >> dato;
                raiz = insertarNodo(raiz, dato);
                cout << "Dato insertado correctamente." << endl;
                break;
            case 2:
                cout << "Ingrese el dato a buscar: ";
                cin >> dato;
                if (buscarDato(raiz, dato)) {
                    cout << "El dato " << dato << " está en el árbol." << endl;
                } else {
                    cout << "El dato " << dato << " no está en el árbol." << endl;
                }
                break;
            case 3:
                cout << "Contenido del árbol: ";
                mostrarArbol(raiz);
                mostrarArbolVisual(raiz);
                cout << endl;
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
            break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
            break;
        }
    } while (opcion != 4);
    return 0;
    /*
    Nodo* raiz = NULL;
    // Insertar nodos en el árbol
    raiz = insertarNodo(raiz, 50);
    raiz = insertarNodo(raiz, 30);
    raiz = insertarNodo(raiz, 20);
    raiz = insertarNodo(raiz, 40);
    raiz = insertarNodo(raiz, 70);
    raiz = insertarNodo(raiz, 60);
    raiz = insertarNodo(raiz, 80);

    // Mostrar el árbol en orden
    std::cout << "Contenido del árbol: ";
    mostrarArbol(raiz);
    std::cout << std::endl;

    // Buscar un dato en el árbol
    int datoBuscado = 40;
    if (buscarDato(raiz, datoBuscado)) {
        std::cout << datoBuscado << " está en el árbol." << std::endl;
    } else {
        std::cout << datoBuscado << " no está en el árbol." << std::endl;
    }
    */
}
/*
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
******************************************
using namespace std;
struct Nodo{
        int dato;
        Nodo *siguiente;
    };
void insertarLista(Nodo *&, int);
void mostrarLista(Nodo *);
void buscarLista(Nodo *,int);
void mostrarMenu();

Nodo *lista = NULL;
int dato,datobuscar,opcion;

int main(int argc, char const *argv[])
{ 
    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
            	cout<<"ingrese el dato para la lista"<<endl;
            	cin>>dato;
            	insertarLista(lista,dato);
            	break;
            case 2:
            	cout<<"Mostrando Lista"<<endl;
            	mostrarLista(lista);
            	break;
			case 3:
				cout << "Saliendo..." << endl;
                break;   
            default:
                cout << "Opcion invalida" << endl;
        }

    } while (opcion != 3);
    /*
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
    mostrarLista(lista);
    return 0;
} 

/*
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
*/
/*
// Función para insertar un elemento al inicio de la lista "lista DoblementeEnlasada"
void insertarAlInicio(Node** head, int newData) {
    // Crear un nuevo nodo
    Node* newNode = new Node();
    
    // Asignar los datos al nuevo nodo
    newNode->data = newData;
    
    // Establecer el enlace next del nuevo nodo al antiguo head
    newNode->next = (*head);
    
    // Establecer el enlace prev del nuevo nodo como nullptr
    newNode->prev = nullptr;
    
    // Cambiar el enlace prev del antiguo head al nuevo nodo
    if ((*head) != nullptr) {
        (*head)->prev = newNode;
    }
    
    // Establecer el nuevo nodo como el head
    (*head) = newNode;
}*/
/*
// Función para insertar un elemento al final de la lista circular
void insertar(Nodo** cabeza, int nuevoDato) {
    // Crear un nuevo nodo
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = nuevoDato;
    
    // Verificar si la lista está vacía
    if (*cabeza == nullptr) {
        nuevoNodo->siguiente = nuevoNodo;  // El nuevo nodo apunta a sí mismo
        *cabeza = nuevoNodo;  // El nuevo nodo se convierte en el cabeza
    } else {
        Nodo* temp = *cabeza;
        
        // Avanzar hasta el último nodo de la lista
        while (temp->siguiente != *cabeza) {
            temp = temp->siguiente;
        }
        
        // Insertar el nuevo nodo al final de la lista
        temp->siguiente = nuevoNodo;
        nuevoNodo->siguiente = *cabeza;  // El nuevo nodo apunta al cabeza
    }
}

// Función para imprimir la lista circular
void imprimirLista(Nodo* cabeza) {
    if (cabeza != nullptr) {
        Nodo* temp = cabeza;
        do {
            std::cout << temp->dato << " ";
            temp = temp->siguiente;
        } while (temp != cabeza);
    }
    std::cout << std::endl;
}

// Ejemplo de uso
int main() {
    // Crear una lista circular vacía
    Nodo* cabeza = nullptr;
    
    // Insertar elementos en la lista circular
    insertar(&cabeza, 1);
    insertar(&cabeza, 2);
    insertar(&cabeza, 3);
    
    // Imprimir la lista circular
    imprimirLista(cabeza);
    
    return 0;
}
En este ejemplo, la función insertar se encarga de crear un nuevo nodo y, dependiendo de si la lista está vacía o no, lo inserta al final de la lista circular. La función imprimirLista se utiliza para mostrar los elementos de la lista circular en orden.

Espero que este ejemplo te sea útil. Si tienes alguna otra pregunta, no dudes en hacerla.
*/
/*
struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

// Función para insertar un elemento al final de la lista circular doblemente enlazada
void insertar(Nodo** cabeza, int nuevoDato) {
    // Crear un nuevo nodo
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = nuevoDato;

    // Verificar si la lista está vacía
    if (*cabeza == nullptr) {
        nuevoNodo->siguiente = nuevoNodo;  // El nuevo nodo apunta a sí mismo
        nuevoNodo->anterior = nuevoNodo;   // El nuevo nodo apunta a sí mismo
        *cabeza = nuevoNodo;  // El nuevo nodo se convierte en el cabeza
    } else {
        Nodo* ultimo = (*cabeza)->anterior;  // Obtener el último nodo de la lista

        // Insertar el nuevo nodo al final de la lista
        nuevoNodo->siguiente = *cabeza;      // El nuevo nodo apunta al cabeza
        nuevoNodo->anterior = ultimo;        // El nuevo nodo apunta al último nodo
        ultimo->siguiente = nuevoNodo;       // El último nodo apunta al nuevo nodo
        (*cabeza)->anterior = nuevoNodo;     // El cabeza apunta al nuevo nodo
    }
}

// Función para imprimir la lista circular doblemente enlazada en orden
void imprimirLista(Nodo* cabeza) {
    if (cabeza != nullptr) {
        Nodo* temp = cabeza;
        do {
            std::cout << temp->dato << " ";
            temp = temp->siguiente;
        } while (temp != cabeza);
    }
    std::cout << std::endl;
}*/
/*
void insertarLista(Nodo *&lista, int n) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL; // Establecer el siguiente nodo como NULL, ya que se agregará al final

    if (lista == NULL) {
        lista = nuevo_nodo; // Si la lista está vacía, el nuevo nodo se convierte en el primer nodo
    } else {
        Nodo *aux = lista;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente; // Recorrer hasta el último nodo
        }
        aux->siguiente = nuevo_nodo; // Enlazar el nuevo nodo al último nodo existente
    }
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
void mostrarMenu() {
    cout << "Menu:" << endl;
    cout << "1. Agregar a lista" << endl;
    cout << "2. Mostrar lista" << endl;
    cout << "3. Salir" << endl;
}


# include<iostream>
# include<conio.h>
# include<stdlib.h>
using namespace std;
struct Contenedor{
	int codigo;
	string empresa;
	Contenedor*siguiente;
};
bool buscarpila(Contenedor*&pila,int n){
	Contenedor*aux1=pila;
	while(aux1!=NULL){
		if(aux1->codigo==n){
			cout<<"El contenedor se enecuentra en la pila"<<endl;
			return true;
		}
		aux1=aux1->siguiente;
	}
	cout<<"El contenedor NO se encuentra en la pila"<<endl;
	return false;
}
void agregarpila(Contenedor*&pila , int n,string nombre_de_empresa){
	if (buscarpila(pila,n)==false){
        Contenedor*nuevo_contenedor=new Contenedor();
        nuevo_contenedor-> codigo=n;
        nuevo_contenedor-> empresa=nombre_de_empresa;
        nuevo_contenedor-> siguiente=pila;
        pila=nuevo_contenedor;
        cout<<"El contenedor "<<n<<" se ha agregado correctamente"<<endl;
	}else{
        cout<<"No puedes agregar este contenedor porque ya existe uno igual"<<endl;
    }
    
}
void mostrar_pila(Contenedor*&pila){
	Contenedor*aux1=pila;
    if(aux1==NULL){
		cout<<"ingrese elementos a la pilaOriginal porque esta [VACIA]"<<endl;
	}
	while(aux1!=NULL){
		cout<<"<<<<<<<<<["<<aux1->codigo<<":"<<aux1->empresa<<"]    ";
		aux1=aux1->siguiente;
	}
    cout<<endl;
}

void mostrar_pila_aux(Contenedor*&pila_aux){
	Contenedor*aux1=pila_aux;
    if(aux1==NULL){
		cout<<"ingrese elementos a la pilaAuxiliar porque esta [VACIA]"<<endl;
	}
	while(aux1!=NULL){
		cout<<"<<<<<<<<<["<<aux1->codigo<<":"<<aux1->empresa<<"]    ";
		aux1=aux1->siguiente;
	}
    cout<<endl;
}
void eliminar_contenedor(Contenedor*&pila,Contenedor*&pila_aux,int n){
	if(buscarpila(pila,n)){
		Contenedor*actual=pila;
		Contenedor*anterior=NULL;
		while(actual!=NULL){
			if (actual->codigo==n){
				pila=actual->siguiente;
				break;
			}
			anterior=actual;
			actual=actual->siguiente;
			anterior->siguiente=pila_aux;
			pila_aux=anterior;
		}
        cout<<"El contenedor fue eliminado"<<endl;
	}
    
}

void mostrarMenu() {
    cout << "Menu:" << endl;
    cout << "1. Agregar contenedor" << endl;
    cout << "2. Buscar contenedor" << endl;
    cout << "3. Eliminar contenedor" << endl;
    cout << "4. Salir" << endl;
}

int main() {
	Contenedor*pila=NULL;
	Contenedor*pila_aux;
	int n;
	string nombre_de_empresa;
    int opcion;
    do {
        mostrarMenu();
        cout<<"Mostrando almacenamiento actual"<<endl;
        mostrar_pila(pila);
        mostrar_pila_aux(pila_aux);
        cin >> opcion;

        switch (opcion) {
            case 1:
            	cout<<"ingrese el codigo del contenedor"<<endl;
            	cin>>n;
            	cout<<"ingrese el nombre de la empresa"<<endl;
            	cin>>nombre_de_empresa;
            	agregarpila(pila,n,nombre_de_empresa);
            	break;
            case 2:
            	cout<<"ingrese el codigo del contenedor"<<endl;
            	cin>>n;
            	buscarpila(pila,n);
            	break;
            case 3:
            	cout<<"ingrese el codigo del contenedor"<<endl;
            	cin>>n;
                if (buscarpila(pila,n))
                {
                    eliminar_contenedor(pila,pila_aux,n);
                }
                if (buscarpila(pila_aux,n))
                {
                    eliminar_contenedor(pila_aux,pila,n);
                }
            	break;
			case 4:
				cout << "Saliendo..." << endl;
                break;   
            default:
                cout << "Opcion invalida" << endl;
        }

    } while (opcion != 4);

    return 0;
}
________________________________________________________________
#include <iostream>
using namespace std;

struct Contenedor {
    int numero;
    Contenedor* siguiente;
};

struct Almacen {
    Contenedor* pila;
    Almacen* siguiente;
};

void agregarContenedor(Contenedor*& pila, int num) {
    Contenedor* nuevo = new Contenedor();
    nuevo->numero = num;
    nuevo->siguiente = pila;
    pila = nuevo;
}

void retirarContenedor(Contenedor*& pila) {
    if (pila == NULL) {
        cout << "No hay contenedores para retirar." << endl;
    } else {
        Contenedor* temp = pila;
        pila = pila->siguiente;
        delete temp;
    }
}
void mostrarPila(Contenedor* pila) {
    if (pila == NULL) {
        cout << "[PILA VACIA]" << endl;
    } else {
        cout << "[";
        Contenedor* contenedor = pila;
        while (contenedor != NULL) {
            cout << contenedor->numero;
            if (contenedor->siguiente != NULL) {
                cout << ", ";
            }
            contenedor = contenedor->siguiente;
        } 
        cout << "]" << endl;
    }
}

void agregarAlmacen(Almacen*& top, Contenedor* pila) {
    Almacen* nuevo = new Almacen();
    nuevo->pila = pila;
    nuevo->siguiente = top;
    top = nuevo;
}

void retirarAlmacen(Almacen*& top) {
    if (top == NULL) {
        cout << "No hay almacenes para retirar." << endl;
    } else {
        Almacen* temp = top;
        top = top->siguiente;
        delete temp;
    }
}

void mostrarAlmacen(Almacen* top) {
    if (top == NULL) {
        cout << "[ALMACEN VACIO]" << endl;
    } else {
        while (top != NULL) {
            cout << "Pila de contenedores: ";
            mostrarPila(top->pila);
            top = top->siguiente;
        }
    }
}

int main() {
    int n, m;
    cout << "Ingrese el numero maximo de contenedores por pila: ";
    cin >> n;
    cout << "Ingrese el numero maximo de pilas de contenedores: ";
    cin >> m;
    Almacen* top = NULL;
    Contenedor* pila = NULL;
    int opcion, num;
    do {
        // Mostrar estado actual del almacenamiento
        cout << "Estado actual del almacenamiento:" << endl;
        mostrarAlmacen(top);
        // Mostrar opciones del menu
        cout << endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Agregar contenedor" << endl;
        cout << "2. Retirar contenedor" << endl;
        cout << "3. Agregar pila de contenedores" << endl;
        cout << "4. Retirar pila de contenedores" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                cout << "Ingrese el numero de contenedor: ";
                cin >> num;
                // Buscar la primera pila con espacio para el nuevo contenedor
                bool pilaEncontrada = false;
                Almacen* aux = top;
                while (aux != NULL && !pilaEncontrada) {
                    if (aux->pila == NULL || aux->pila->numero < n) {
                        agregarContenedor(aux->pila, num);
                        pilaEncontrada = true;
                    } else {
                        aux = aux->siguiente;
                    }
                }
                // Si no se encontró una pila con espacio, crear una nueva
                if (!pilaEncontrada) {
                    if (m == 0) {
                        cout << "No se pueden agregar mas pilas de contenedores." << endl;
                    } else {
                        Contenedor* nuevaPila = NULL;
                        agregarContenedor(nuevaPila, num);
                        agregarAlmacen(top, nuevaPila);
                        m--;
                    }
                }
                break;
            }
            case 2: {
                // Retirar el contenedor de la ultima pila
                if (top == NULL) {
                    cout << "No hay contenedores para retirar." << endl;
                } else {
                    retirarContenedor(top->pila);
                    if (top->pila == NULL) {
                        retirarAlmacen(top);
                        m++;
                    }
                }
                break;
            }
            case 3: {
                if (m == 0) {
                    cout << "No se pueden agregar mas pilas de contenedores." << endl;
                } else {
                    Contenedor* nuevaPila = NULL;
                    agregarAlmacen(top, nuevaPila);
                    m--;
                }
                break;
            }
            case 4: {
                retirarAlmacen(top);
                m++;
                break;
            }
            case 5: {
                cout << "Saliendo del programa." << endl;
                break;
            }
            default: {
                cout << "Opcion no valida." << endl;
                break;
            }
        }
    } while (opcion != 5);
    // Liberar memoria
    while (top != NULL) {
        while (top->pila != NULL) {
            retirarContenedor(top->pila);
        }
        retirarAlmacen(top);
    }
    return 0;
}
______________________________________________
#include <iostream>

using namespace std;

struct Contenedor {
    int empresa;
    Contenedor* siguiente;
};

const int n = 10;  // número máximo de contenedores por pila
const int m = 5;   // número máximo de pilas

// función para agregar un contenedor a una pila
void push(Contenedor*& tope, int empresa) {
    if (tope == NULL) {
        // si la pila está vacía, crear el primer nodo
        tope = new Contenedor;
        tope->empresa = empresa;
        tope->siguiente = NULL;
    } else {
        // si la pila no está vacía, agregar el nodo al inicio
        Contenedor* nuevo = new Contenedor;
        nuevo->empresa = empresa;
        nuevo->siguiente = tope;
        tope = nuevo;
    }
}

// función para sacar el tope de una pila
void pop(Contenedor*& tope) {
    if (tope != NULL) {
        Contenedor* temp = tope;
        tope = tope->siguiente;
        delete temp;
    }
}

int main() {
    // inicializar las pilas como punteros nulos
    Contenedor* pilas[m];
    for (int i = 0; i < m; i++) {
        pilas[i] = NULL;
    }

    while (true) {
        // mostrar el estado actual del almacén
        cout << "Estado actual del almacén:" << endl;
        for (int i = 0; i < m; i++) {
            cout << "Pila " << i+1 << ": ";
            Contenedor* temp = pilas[i];
            while (temp != NULL) {
                cout << temp->empresa << " ";
                temp = temp->siguiente;
            }
            cout << endl;
        }
        cout << endl;

        // preguntar al usuario si quiere ingresar o sacar un contenedor
        char accion;
        cout << "¿Quieres ingresar o sacar un contenedor? (i/s): ";
        cin >> accion;

        if (accion == 'i') {
            // ingresar un contenedor
            int empresa;
            cout << "Introduce el número de empresa del contenedor: ";
            cin >> empresa;

            // buscar la pila con menos contenedores
            int pila_min = 0;
            for (int i = 1; i < m; i++) {
                int size_pila_i = 0;
                Contenedor* temp = pilas[i];
                while (temp != NULL) {
                    size_pila_i++;
                    temp = temp->siguiente;
                }
                if (size_pila_i < n) {
                    if (pilas[pila_min] == NULL) {
                        pila_min = i;
                    } else {
                        int size_pila_min = 0;
                        temp = pilas[pila_min];
                        while (temp != NULL) {
                            size_pila_min++;
                            temp = temp->siguiente;
                        }
                        if (size_pila_i < size_pila_min) {
                            pila_min = i;
                        }
                    }
                }
            }
            if (pilas[pila_min] == NULL || pilas[pila_min]->empresa != empresa) {
            // si la pila está vacía o el contenedor no está en el tope de la pila
                if (pilas[pila_min] != NULL) {
                cout << "Para ingresar este contenedor es necesario sacar los contenedores que están encima." << endl;
                }
                cout << "El contenedor se ha ingresado en la pila " << pila_min+1 << "." << endl;
                push(pilas[pila_min], empresa);
            } else {
            cout << "El contenedor ya está en la pila " << pila_min+1 << "." << endl;
                }
            } else if (accion == 's') {
            // sacar un contenedor
            int empresa;
            cout << "Introduce el número de empresa del contenedor que quieres sacar: ";
            cin >> empresa;
                    bool encontrado = false;
        for (int i = 0; i < m; i++) {
            Contenedor* temp = pilas[i];
            Contenedor* prev = NULL;
            while (temp != NULL) {
                if (temp->empresa == empresa) {
                    encontrado = true;
                    cout << "El contenedor se ha sacado de la pila " << i+1 << "." << endl;
                    if (prev == NULL) {
                        // si el contenedor estaba en el tope de la pila
                        pop(pilas[i]);
                    } else {
                        // si el contenedor estaba en el medio de la pila
                        prev->siguiente = temp->siguiente;
                        delete temp;
                    }
                    break;
                }
                prev = temp;
                temp = temp->siguiente;
            }
            if (encontrado) {
                break;
            }
        }
        if (!encontrado) {
            cout << "El contenedor no está en ninguna pila." << endl;
        }
        } else {
        // si el usuario introduce una acción inválida
        cout << "Acción inválida. Introduce i o s." << endl;
        }

        // preguntar al usuario si quiere continuar o salir del programa
        char respuesta;
        cout << "¿Quieres continuar? (s/n): ";
        cin >> respuesta;
        if (respuesta == 'n') {
        break;
        }
    }

// liberar la memoria de los nodos de las pilas
    for (int i = 0; i < m; i++) {
        while (pilas[i] != NULL) {
            pop(pilas[i]);
        }
    }

    return 0;
}
____________________________________________________________
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
________________________________________________________________
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