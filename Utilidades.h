# ifndef UTILIDADES_H
# define UTILIDADES_H


# include "constantes.h"
# include "Lectura.h"

# include <limits>


class Utilidades {

public:

    // PRE:
    // POST:
    Utilidades();

    // PRE: -
    // POST: Limpia la pantalla.
    void limpiar_pantalla();

    void mostrar_tipo_error();

    // PRE: a_validar debe ser entero.
    // POST: Devuelve el entero validando que sea del tipo de dato y valor correcto.
    int validar_ingreso_entero(int a_validar, string instruccion, int valor_minimo, int valor_maximo);

    // PRE: Las lecturas deben ser validas y debe existir su lista.
    // POST: Inserta las lecturas ordenadas por anio a la lista.
    void insertar_lectura_ordenada(Lectura* lectura, Lista<Lectura*>* lista_lectura);

    // PRE: -
    // POST: Le asigna a cada indice del enumerado de generos, su cadena correspondiente.
    string obtener_nombre_genero(generos genero);



};


# endif