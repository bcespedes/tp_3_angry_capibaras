#include "grafo.h"

Grafo::Grafo(){
    matriz_adyacencia = NULL;
    vertices = new Lista<Lectura *>();
}


void Grafo::inicializar_vertice(int **matriz){

    for(int i = 0; i < vertices->obtener_cantidad(); i++){
        matriz[vertices->obtener_cantidad()][i] = INFINITO;
        matriz[i][vertices->obtener_cantidad()] = INFINITO;
    }

    matriz[vertices->obtener_cantidad()][vertices->obtener_cantidad()] = 0;
}


void Grafo::copiar_matriz(int **matriz_aux){

    for(int i = 0; i < vertices->obtener_cantidad(); i++){
        for(int j = 0; i < vertices->obtener_cantidad(); j++){
            matriz_aux[i][j] = matriz_adyacencia[i][j];
        }
    }
}


void Grafo::liberar_matriz_adyacencia(){
    for(int i = 0; i < vertices->obtener_cantidad(); i++){
        delete [] matriz_adyacencia[i];
    }
    delete matriz_adyacencia;
}


void Grafo::agrandar_matriz_adyacencia(){
    int nuevo_tamanio = vertices->obtener_cantidad() + 1;

    int **matriz_aux = new int*[nuevo_tamanio];

    for(int i = 0; i < nuevo_tamanio; i++){
        matriz_aux[i] = new int[nuevo_tamanio];
    }
    copiar_matriz(matriz_aux);
    inicializar_vertice(matriz_aux);
    liberar_matriz_adyacencia();
    matriz_adyacencia = matriz_aux;
}


void Grafo::agregar_vertice(Lectura *d){
    
    agrandar_matriz_adyacencia();
    vertices->alta(d, vertices->obtener_cantidad());
}


void Grafo::agregar_camino(Lectura* origen, Lectura* destino, int peso){
    int pos_origen = vertices->obtener_posicion(origen);
    int pos_destino = vertices->obtener_posicion(destino);

    if(pos_origen == NO_ENCONTRADO){
        cout << "El vertice de origen no fue encontrado" << endl;
        return;
    }

    if(pos_destino == NO_ENCONTRADO){
        cout << "El vertice de destino no fue encontrado" << endl;
        return;
    }

    matriz_adyacencia[pos_origen][pos_destino] = peso;
    matriz_adyacencia[pos_destino][pos_origen] = peso;
}


void Grafo::mostrar_grafo(){
    mostrar_vertices();
    mostrar_matriz_adyacencia();
}

bool operator<(const Arista &arista,const Arista &arista2){
    return arista.peso_ < arista2.peso_;
}

void Grafo::guardar_aristas(priority_queue< Arista, vector<Arista>, greater<Arista> > cola_prioridad){
    for(int i = 0; i < vertices->obtener_cantidad(); i++){
        for(int j = i; j < vertices->obtener_cantidad(); j++){
            if(i != j){
                Arista *arista = new Arista(vertices->consulta(j) , vertices->consulta(i), matriz_adyacencia[i][j]);
                //Arista arista(vertices->consulta(j) , vertices->consulta(i), matriz_adyacencia[i][j]);
                cola_prioridad.push(*arista);
            }
        }
    }

}


Grafo* Grafo::Kruskal(){
    Grafo *arbol_expansion_min = new Grafo();
    priority_queue< Arista, vector<Arista>, greater<Arista> > cola_prioridad;

    while (!cola_prioridad.empty()){
        Arista a = cola_prioridad.top();
        cout << " " << a.peso_;
        cola_prioridad.pop();
    }

    return arbol_expansion_min;
}

Grafo::~Grafo(){

}