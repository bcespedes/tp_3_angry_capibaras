# ifndef FUNCIONALIDAD_H
# define FUNCIONALIDAD_H


# include "constantes.h"
# include "Utilidades.h"
# include "LectorLecturas.h"
# include "Cola.h"
# include "grafo.h"
# include "stdlib.h"
# include "time.h"
# include <string.h>


class ProcesadorDeOpciones {

private:

    // ATRIBUTOS
    Hash* tabla_escritores_;
    Lista<Lectura*>* lista_lecturas_;

    // METODOS
    char ingresar_tipo_lectura();
    char ingresar_si_o_no(string instruccion);
    int ingresar_genero();
    Escritor* no_es_escritor_anonimo(int isni);
    Lectura* crear_novela_historica(string titulo, int duracion, int anio, Escritor* escritor, bool leido);
    Lectura* crear_novela(string titulo, int duracion, int anio, Escritor* escritor, bool leido);
    Lectura* crear_cuento(string titulo, int duracion, int anio, Escritor* escritor, bool leido);
    Lectura* crear_poema(string titulo, int duracion, int anio, Escritor* escritor, bool leido);
    Lectura* crear_lectura(char tipo_lectura, string titulo, int duracion, int anio, Escritor* escritor);
    int ingresar_indice_lista(string instruccion, int cantidad_datos);
    int ingresar_anio_correcto(int anio_inferior);
    Escritor* ingresar_escritor();
    int obtener_indice_mayor_duracion();
    void insertar_en_cola_ordenada(Cola<Lectura*>* cola_lecturas, unsigned int menor_duracion);
    bool seguir_leyendo();
    int obtener_cantidad_lecturas_sin_leer();
    void ingresar_reinicio_de_cola();
    void reiniciar_cola_lecturas();
    Grafo* crear_grafo();
    void conectar_grafo(Grafo *grafo);
    int validar_peso_arista(Lectura *vertice1, Lectura *vertice2);
    Lectura *copiar_lectura(Lectura *lectura);

public:

    // PRE: -
    // POST: Crea un procesador de opciones. 
    ProcesadorDeOpciones(Hash* tabla_escritores, Lista<Lectura*>* lista_lecturas);

    // PRE: La lista_lectura esta creada.
    // POST: Agrega una lectura a la lista.
    void agregar_lectura();

    // PRE: La lista_lectura esta creada.
    // POST: Quita una lectura de la lista.
    void quitar_lectura();

    // PRE: La lista_escritores esta creada.
    // POST: Agrega un escritor a la lista. Devuelve su ISNI.
    int agregar_escritor();

    // PRE: La lista_escritores esta creada.
    // POST: Si el escritor no tiene un fallecimiento asignado, se le pide un anio al usuario y se actualiza.
    void asignar_fallecimiento_escritor();

    // PRE: La lista_escritores esta creada.
    // POST: Muestra por pantalla todos los escritores. En caso de no haber, se le informa al usuario
    void listar_escritores();

    // PRE:La lista_lectura esta creada.
    // POST: muestra una lectura aleatoria y se marca como leida si no lo estaba. 
    void sortear_lectura();

    // PRE: La lista_lectura esta creada.
    // POST: muestra por pantalla todas las lecturas. En caso de no haber se le informa al usuario
    void listar_lecturas();

    // PRE: La lista_lectura esta creada.
    // POST: imprime las lecturas entre periodos de tiempo ingresados por el usuario
    void listar_periodo_lecturas();

    // PRE: La lista_lectura esta creada.
    // POST: imprime las lecturas del autor determinado por el usuario
    void listar_lecturas_de();

    // PRE: La lista_lectura esta creada.
    // POST: imprime las novelas del genero determinado por el usuario.
    void listar_novelas_genero();

    // PRE: -
    // POST: Crea una cola ordenada por duracion en base a las lecturas no leidas.
    void crear_cola_ordenada();

    void menor_tiempo_lectura();

    // PRE: -
    // POST: 50% de posibilidades de cocinar un delicioso pastel de papa.
    //       50% de posibilidades de que ocurra la desgracia, fatalidad e infortunio de no tener los suficientes ingredientes.
    void cocinar_pastel_de_papa();

    // PRE:
    // POST: Destruye el procesador de opciones, eliminando las listas y liberando su memoria. 
    ~ProcesadorDeOpciones();

};


# endif