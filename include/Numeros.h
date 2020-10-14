#ifndef NUMEROS_H
#define NUMEROS_H


class Numeros
{
    public:
        Numeros();
        Numeros(int cantidadNumeros);

        ~Numeros();

        //Métodos
        void algoritmoInsercion();
        void imprimirNumeros();

        //Metodos get
        int getCantidadNumeros() { return cantidadNumeros; };


    protected:

    private:
        void crearArray();

        //Variables
        int cantidadNumeros;
        float *arregloNumeros;

};

#endif // NUMEROS_H

