# ifndef ESCRITOR_H
# define ESCRITOR_H


# include <iostream>
# include "constantes.h"


using namespace std;


class Escritor {

private:

    int isni_;
    string nombre_;
    string apellido_;
    string nacionalidad_;
    int anio_nacimiento_;
    int anio_fallecimiento_;



public:

    // PRE: -
    // POST: Crea un escritor vacio.
    Escritor();

    // PRE: Los datos son validos.
    // POST: Crea un escritor.
    Escritor(int isni, string nombre, string apellido, string nacionalidad, int anio_nacimiento, int anio_fallecimiento);

    // PRE: -
    // POST: Devuelve el ISNI del escritor.
    int obtener_isni();

    // PRE: - 
    // POST: Devuelve el nombre y apellido del escritor.
    string obtener_nombre_completo();

    // PRE: -
    // POST: Devuelve la nacionalidad del autor.
    string obtener_nacionalidad();

    // PRE: -
    // POST: Devuelve true si el fallecimiento es desconocido, false en caso contrario.
    bool verificar_fallecimiento();

    // PRE: Anio es mayor a 0.
    // POST: Se le asigna el anio al escritor.
    void asignar_fallecimiento(int anio);

    // PRE: -
    // POST: Muestra por pantalla las caracteristicas del escritor.
    void mostrar_escritor();

};


# endif