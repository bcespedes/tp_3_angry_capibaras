# include "Grafo.h"


Grafo::Grafo() {

    matriz_adyacencia = NULL;
    vertices = new Lista<Lectura*>();
}


int Grafo::obtener_tamanio() {

    return vertices -> obtener_cantidad();
}


void Grafo::inicializar_vertice(int** matriz) {

    for(int i = 0; i < vertices -> obtener_cantidad(); i++) {
        matriz[vertices -> obtener_cantidad()][i] = INFINITO;
        matriz[i][vertices -> obtener_cantidad()] = INFINITO;
    }

    matriz[vertices -> obtener_cantidad()][vertices -> obtener_cantidad()] = INFINITO;
}


void Grafo::copiar_matriz(int** matriz_aux) {

    for(int i = 0; i < vertices -> obtener_cantidad(); i++) {
        for(int j = 0; j < vertices -> obtener_cantidad(); j++) {
            matriz_aux[i][j] = matriz_adyacencia[i][j];
        }
    }
}


void Grafo::liberar_matriz_adyacencia() {

    for(int i = 0; i < vertices -> obtener_cantidad(); i++) {
        delete [] matriz_adyacencia[i];
    }
    delete [] matriz_adyacencia;
}


void Grafo::agrandar_matriz_adyacencia() {

    int nuevo_tamanio = vertices -> obtener_cantidad() + 1;

    int** matriz_aux = new int*[nuevo_tamanio];

    for(int i = 0; i < nuevo_tamanio; i++) {
        matriz_aux[i] = new int[nuevo_tamanio];
    }

    copiar_matriz(matriz_aux);
    inicializar_vertice(matriz_aux);
    liberar_matriz_adyacencia();
    matriz_adyacencia = matriz_aux;
}


void Grafo::mostrar_matriz_adyacencia() {

    cout << "Matriz de adyacencia del grafo:" << endl << endl;
    for(int i = 0; i < vertices -> obtener_cantidad(); i++) {
        for(int j = 0; j < vertices -> obtener_cantidad(); j++) {
            if(matriz_adyacencia[i][j] == INFINITO)
                cout << "| -- |";
            else if(matriz_adyacencia[i][j] >= 10)
                cout << "| " << matriz_adyacencia[i][j] << " |";
            else
                cout << "|  " << matriz_adyacencia[i][j] << " |";
        }
        cout << endl;
    }
    cout << endl;
}


void Grafo::agregar_vertice(Lectura* d) {
    
    agrandar_matriz_adyacencia();
    vertices -> alta(d, vertices -> obtener_cantidad());
}


void Grafo::agregar_camino(Lectura* origen, Lectura* destino, int peso) {

    int pos_origen = vertices -> obtener_posicion(origen);
    int pos_destino = vertices -> obtener_posicion(destino);

    if(pos_origen == NO_ENCONTRADO) {
        cout << "El vertice de origen no fue encontrado" << endl;
        return;
    }

    if(pos_destino == NO_ENCONTRADO) {
        cout << "El vertice de destino no fue encontrado" << endl;
        return;
    }

    matriz_adyacencia[pos_origen][pos_destino] = peso;
    matriz_adyacencia[pos_destino][pos_origen] = peso;
}


struct operador {

  bool operator()( Arista& origen,  Arista& destino) const {

    return origen.obtener_peso() > destino.obtener_peso();
  }
};


priority_queue< Arista, vector<Arista>, struct operador >* Grafo::guardar_aristas() {

    priority_queue< Arista, vector<Arista>, operador >* cola_prioridad = new priority_queue< Arista, vector<Arista>, operador >;

    for(int i = 0; i < vertices -> obtener_cantidad(); i++) {
        for(int j = i; j < vertices -> obtener_cantidad(); j++) {
            if(i != j) {
                Arista arista(vertices -> consulta(j) , vertices -> consulta(i), matriz_adyacencia[i][j]);
                cola_prioridad -> push(arista);
            }
        }
    }

    return cola_prioridad;

}


void Grafo::mostrar_grafo(bool mostrar_solo_matriz) {

    int tiempo_lectura = 0, tiempo_siesta = 0;
    Lectura* vertice1;
    Lectura* vertice2;
    if(vertices -> obtener_cantidad() > 1 && !mostrar_solo_matriz) {
        for(int i = 0; i < vertices -> obtener_cantidad(); i++) {
            vertice1 = vertices -> consulta(i);

            for(int j = i; j < vertices -> obtener_cantidad(); j++) {
                if(i != j && matriz_adyacencia[i][j] != INFINITO) {
                    vertice2 = vertices -> consulta(j);
                    cout << vertice1 -> obtener_titulo() << " (Duracion de: "<< vertice1 -> obtener_minutos() << " minutos)";
                    cout << " -----> Siesta de: "<< matriz_adyacencia[i][j] << " minutos -----> ";
                    cout << vertice2 -> obtener_titulo() << " (Duracion de: "<< vertice2 -> obtener_minutos() << " minutos)" << endl << endl;

                    tiempo_siesta += matriz_adyacencia[i][j];
                    tiempo_lectura += vertice1 -> obtener_minutos() + vertice2 -> obtener_minutos();
                }
            }
        }
        cout << "Se ha dormido siesta durante " << tiempo_siesta << " minutos." << endl;
        cout << "Se ha leido aproximadamente durante " << tiempo_lectura << " minutos." << endl;
        cout << "Tiempo total estimado: " << tiempo_siesta + tiempo_lectura << " minutos." << endl << endl;
    }
    else if(!mostrar_solo_matriz) {
        vertice1 = vertices -> consulta(0);
        cout << endl << "Solo hay una lectura cargada por lo que se leera -----> " << vertice1 -> obtener_titulo() <<
        " (Duracion de: " << vertice1 -> obtener_minutos() << " minutos)\n" << endl << endl;
    }
    mostrar_matriz_adyacencia();

}


Grafo* Grafo::crear_arbol_expansion_minima() {

    Grafo* arbol_expansion_min;
    if(vertices -> obtener_cantidad() > 1) {

        arbol_expansion_min = new Grafo();

        priority_queue< Arista, vector<Arista>, struct operador >* cola_prioridad = guardar_aristas();

        while (arbol_expansion_min -> vertices -> obtener_cantidad() != vertices -> obtener_cantidad()) {
            Arista a = cola_prioridad -> top();

            bool pos_origen = arbol_expansion_min -> vertices -> obtener_posicion(a.devolver_origen()) == NO_ENCONTRADO;
            bool pos_destino = arbol_expansion_min -> vertices -> obtener_posicion(a.devolver_destino()) == NO_ENCONTRADO;
                    
            if(pos_origen || pos_destino) {

                if(pos_origen)
                    arbol_expansion_min -> agregar_vertice(a.devolver_origen());
                if(pos_destino)
                    arbol_expansion_min -> agregar_vertice(a.devolver_destino());
                
                arbol_expansion_min -> agregar_camino(a.devolver_origen(), a.devolver_destino(), a.obtener_peso());
            }

            cola_prioridad -> pop();
        }
        delete cola_prioridad;
    }
    else
        arbol_expansion_min = NULL;

    return arbol_expansion_min;
}


Grafo::~Grafo() {

    liberar_matriz_adyacencia();
    vertices -> no_eliminar_dato();
    delete vertices;
}