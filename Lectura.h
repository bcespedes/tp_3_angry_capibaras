#ifndef LECTURA_H
#define LECTURA_H


# include <iostream>
# include "Escritor.h"
# include "Lista.h"
# include "constantes.h"


using namespace std;


class Lectura {

protected:

    //ATRIBUTOS
    string titulo_;
    unsigned int minutos_;
    unsigned int anio_;
    Escritor* escritor_;
    bool leido_;

public:

    // PRE: Los datos son validos.
    // POST: Crea una lectura. 
    Lectura(string titulo, unsigned int minutos, unsigned int anio, Escritor* escritor, bool leido);   

    // PRE: -
    // POST: Devuelve el titulo de la lectura.
    string obtener_titulo();

    // PRE: -
    // POST: Devuelve los minutos estimados de lectura.
    unsigned int obtener_minutos();

    // PRE: -
    // POST: Devuelve el anio de publicacion.
    unsigned int obtener_anio();

    // PRE: -
    // POST: Devuelve el autor de la lectura.
    Escritor* obtener_escritor();

    // PRE: -
    // POST: Devuelve true si la lectura fue leida.
    bool fue_leido();

    // PRE: -
    // POST: Le asigna a la lectura correspondiente si fue leido o no.
    void leido(bool leido);

    // PRE: Recibe una lectura valida.
    // POST: Devuelve -1 si el año de la lectura que llama es menor al año de la que se pasa por parametro.
    //       Devuelve 1 si el año de la que llama es mayor al año de la que se pasa por parametro.
    //       Devuelve 0 si son iguales.
    int comparar_por_anio(Lectura* a_comparar);

    // PRE: Recibe una lectura valida.
    // POST: Devuelve -1 si la duracion de la lectura que llama es menor a la duracion de la que se pasa por parametro.
    //       Devuelve 1 si la duracion de la que llama es mayor a la duracion de la que se pasa por parametro.
    //       Devuelve 0 si son iguales.
    int comparar_por_duracion(Lectura* a_comparar);

    // PRE: -
    // POST: Muestra por pantalla la lectura.
    virtual void mostrar_lectura() = 0;

    // PRE: -
    // POST: Devuelve true si genero es igual al genero de la lectura, false en caso contrario (solo aplica para novelas).
    virtual bool coinciden_generos(int genero) = 0;

    // PRE: -
    // POST: Destruye la lectura.
    virtual ~Lectura() = 0;

};


# endif