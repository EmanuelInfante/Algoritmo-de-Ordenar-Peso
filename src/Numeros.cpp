#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include "Numeros.h"

using namespace std;

// Los números generados son de entre 1 a 999.999, si no se pasan parámetros
Numeros::Numeros()
{
    /* En caso de no especificar la cantidad de números, se generara una cantidad de entre 1 a 500 números */

    //Actualizamos la semilla
    srand(time(NULL));

    //Definimos la cantidad de números y llamamos al constructor paramétrico
    this ->cantidadNumeros = (1 + rand() % (200));

    this ->crearArray();
}


Numeros::Numeros(int cantidadNumeros)
{
    //Si se indica la cantidad de números se usa ese valor
    this ->cantidadNumeros = cantidadNumeros;

    //Creamos el array de forma dinámica
    this ->crearArray();
}


Numeros::~Numeros()
{
    delete [] this ->arregloNumeros;

}


void Numeros::imprimirNumeros()
{
    /* Método que imprime por pantalla los números del arreglo */

    for(int i = 0; i < this ->cantidadNumeros; i++)
    {
        cout << this ->arregloNumeros[i] << " ";
    }

}


void Numeros::crearArray()
{
    /* Método que crea y llena el arreglo con números aleatorios, la cantidad de números aleatorios de entre 1 a 9999
       está definida en la variable this ->cantidadNumeros
     */

    this ->arregloNumeros = new float[this ->cantidadNumeros];

    //Actualizamos la semilla
    srand(time(NULL));

    for(int i = 0; i < this ->cantidadNumeros; i++)
        arregloNumeros[i] = (1 + rand() % (9999));

}


void Numeros::algoritmoInsercion()
{
    /* Método que aplica el algoritmo de inserción para ordenar el arreglo this ->arregloNumeros */

    for(int i = 1; i < this ->cantidadNumeros; i++)
    {

        //Revisamos uno por uno los valores del arreglo y si el valor no está en su posición, lo ubíca
        for(int j = i; this ->arregloNumeros[j] < this ->arregloNumeros[j-1] && j > 0; j--)
        {
            float aux = this ->arregloNumeros[j];
            this ->arregloNumeros[j] = this ->arregloNumeros[j-1];
            this ->arregloNumeros[j-1] = aux;
        }
    }
}
