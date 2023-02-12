#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;
int main(int argc, char const *argv[])
{ 
    /*
    Algoritmo burbuja
    int numeros[] = {4,1,2,3,5};
    int i,j,aux;
    for (int i = 0; i < 5; i++){
        for (int j = 0; i < 5; i++){
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
    return 0;
}
