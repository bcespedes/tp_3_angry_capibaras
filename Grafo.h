# ifndef GRAFO_H
# define GRAFO_H


# include "constantes.h"
# include "Nodo.h"
# include "Lista.h"
# include "Lectura.h"
# include "Arista.h"
# include <queue>


using namespace std;


class Grafo {

private:

    int** matriz_adyacencia;
    Lista<Lectura*>* vertices;
    void agrandar_matriz_adyacencia();
    void copiar_matriz(int** matriz_aux);
    void inicializar_vertice(int** matriz);
    void liberar_matriz_adyacencia();
    void mostrar_matriz_adyacencia();
    priority_queue< Arista, vector<Arista>, struct operador >* guardar_aristas();

public:

    // PRE: -
    // POST: Crea un grafo.
    Grafo();

    // PRE: d es un tipo valido.
    // POST: Agrega un vertice al grafo.
    void agregar_vertice(Lectura* d);

    // PRE: Origen, destino y peso son datos validos.
    // POST: Agrega un camino ponderado entre el origen y el destino (es no direccionado).
    void agregar_camino(Lectura* origen, Lectura* destino, int peso);

    // PRE: -
    // POST: Devuelve la cantidad de vertices del grafo.
    int obtener_tamanio();

    // PRE: -
    // POST: Muestra por pantalla los vertices y aristas con su peso.
    void mostrar_grafo(bool mostrar_solo_matriz);

    // PRE: -
    // POST: Crea el arbol de expansion minima y lo devuelve.
    Grafo* crear_arbol_expansion_minima();

    // PRE: -
    // POST: Destruye el grafo.
    ~Grafo();

};


# endif