/* Programa de ordenar Peso, programa capaz de solicitar al usuario la cantidad de numeros positivos con los que desea trabajar y de no obtener un valor
valido entonces se procede a escoger un numero aleatorio, continuamente el programa comienza a iniciar el proceso llamando al constructor que corresponda,
despues para finalizar se imprimen los resultados de la cantidad de numeros escogidos, los numeros suministrados por el usuario desordenados y por ultimo
los numeros ordenados gracias al algoritmo de inserci�n
*/
#include <iostream>
#include <string>
#include <cmath>
#include <Numeros.h>

//Definimos si estamos en windows o linux para definir funcion d limpiar pantalla
#ifdef WIN32
    #define cls() system("cls");
#else
   #define cls() system("clear");
#endif // WIN32


using namespace std;

int main()
{
    //Se crean las variables básicas del programa
    string cantidadNumeros;
    int cantidadNum;
    Numeros *numer;

    cout << "Bienvenido al programa, ingresa la cantidad de números aleatorios que desees generar (Entero positivo). En caso de no ingresar un valor válido, se generara una cantidad aleatoria de números entre 1 a 500" << endl;
    cout << "Ingrese el número: ";

    getline(cin, cantidadNumeros);

    cls();

    // Obtemenos la cantidad de elementos que ingresa el usuario, si no ingresa un valor válido se da un valor aleatório
    try
    {
        cantidadNum = abs(stoi(cantidadNumeros));
    }
    catch(std::invalid_argument &)
    {
        cantidadNum = -1;
    }

    //Llamamos al constructor correspondiente, dependiendo de si tenemos o no la cantidad de números a generar
    if (cantidadNum == -1)
        numer = new Numeros();
    else
        numer = new Numeros(cantidadNum);

    //Imprimimos los resultados del programa
    cout << "CANTIDAD DE NÚMEROS: " << numer ->getCantidadNumeros() << endl << endl;
    cout << "NÚMEROS DESORDENADOS" << endl << endl;
    numer ->imprimirNumeros();

    cout << endl << endl;

    numer ->algoritmoInsercion();

    cout << "NÚMEROS ORDENADOS CON ALGORITMO DE INSERCIÓN" << endl << endl;
    numer ->imprimirNumeros();

    //Eliminamos memoria denámica
    delete numer;

    return 0;
}
