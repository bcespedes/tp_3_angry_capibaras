# include "Hash.h"


Hash::Hash() {

    tamanio_tabla_ = CANTIDAD_CLAVES / FACTOR_CARGA;

    tabla_hash_ = new Lista<Escritor*>*[tamanio_tabla_];

    for(int i = 0; i < tamanio_tabla_; i++)
        tabla_hash_[i] = new Lista<Escritor*>;
}


int Hash::aplicar_division(int clave) {

    if(clave < 0)
        clave = clave * OPCION_ALTERNATIVA;
    return clave % tamanio_tabla_;
}


Lista<Escritor*>* Hash::obtener_lista(int posicion) {

    return tabla_hash_[posicion];
}


int Hash::obtener_posicion_elemento(int clave) {

    int posicion = -1, indice = aplicar_division(clave);
    bool esta = false;

    Lista<Escritor*>* lista_escritores = obtener_lista(indice);
    lista_escritores -> inicializar();
    while(lista_escritores -> hay_siguiente() && !esta) {
        posicion++;
        if(lista_escritores -> siguiente() -> obtener_isni() == clave)
            esta = true;
    }

    if(!esta)
        posicion = -1;

    return posicion;
}


bool Hash::vacia() {

    int contador_elementos = 0;

    for(int i = 0; i < tamanio_tabla_; i++) {
        tabla_hash_[i] -> inicializar();
        while(tabla_hash_[i] -> hay_siguiente() && contador_elementos == 0)
            contador_elementos++;
    }

    return (contador_elementos == 0);
}


bool Hash::esta_el_elemento(int clave) {

    return obtener_posicion_elemento(clave) != -1;
}


void Hash::alta(Escritor* escritor) {

    int clave = escritor -> obtener_isni();
    int posicion_tabla = aplicar_division(clave);

    tabla_hash_[posicion_tabla] -> alta(escritor, 0);
}


void Hash::baja(int clave) {

    int posicion_tabla = aplicar_division(clave);
    int posicion = obtener_posicion_elemento(clave);

    tabla_hash_[posicion_tabla] -> baja(posicion);
}


Escritor* Hash::consulta(int clave) {

    int posicion_tabla = aplicar_division(clave);
    int posicion = obtener_posicion_elemento(clave);
    Escritor* escritor = tabla_hash_[posicion_tabla] -> consulta(posicion);

    return escritor;
}


void Hash::imprimir_escritores(bool solo_nombres) {

    for(int i = 0; i < tamanio_tabla_; i++) {
        tabla_hash_[i] -> inicializar();
        while(tabla_hash_[i] -> hay_siguiente()) {
            Escritor* escritor = tabla_hash_[i] -> siguiente();
                cout << "ISNI: [" << escritor -> obtener_isni() << "] - ";
                if(solo_nombres)
                    cout << escritor -> obtener_nombre_completo() << endl << endl;
                else
                    escritor -> mostrar_escritor();
        }
    }
}


Hash::~Hash() {

    for(int i = 0; i < tamanio_tabla_; i++)
        delete tabla_hash_[i];

    delete[] tabla_hash_;
}