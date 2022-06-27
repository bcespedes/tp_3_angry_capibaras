#ifndef GRAFO_H
#define GRAFO_h


#include "Nodo.h"
#include "Lista.h"
#include "Lectura.h"
#include "Arista.h"
#include <queue>

using namespace std;

const int INFINITO = 99999999;


class Grafo{

private:
    int **matriz_adyacencia;
    Lista<Lectura *> *vertices;

    void agrandar_matriz_adyacencia();
    void copiar_matriz(int **matriz_aux);
    void inicializar_vertice(int **matriz);
    void liberar_matriz_adyacencia();
    void mostrar_vertices();
    void mostrar_matriz_adyacencia();
    void copiar_vertices(Grafo *nuevo_grafo);
    void copiar_pesos_padres(int *pesos, int *padres);
    //devuelve la POSICION del peso minimo
    int buscar_peso_minimo(int *pesos);
    priority_queue< Arista, vector<Arista>, struct operador_boliviano > *guardar_aristas();


    

public:

    Grafo();

    void agregar_vertice(Lectura *d);

    void agregar_camino(Lectura* origen, Lectura* destino, int peso);

    void mostrar_grafo();

    Grafo* Kruskal();
     
    ~Grafo();

};



#endif
