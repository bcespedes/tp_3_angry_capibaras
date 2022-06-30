# include "ProcesadorDeOpciones.h"


ProcesadorDeOpciones::ProcesadorDeOpciones(Hash* tabla_escritores, Lista<Lectura*>* lista_lecturas) {

    tabla_escritores_ = tabla_escritores;
    lista_lecturas_ = lista_lecturas;
}


char ProcesadorDeOpciones::ingresar_tipo_lectura() {

    string tipo_lectura_ingresada = "XX";
    char tipo_lectura = 'X';
    cout << "Tipos de lectura disponibles:" << endl;
    cout << "\n[N] - Novela\n\n[C] - Cuento\n\n[P] - Poema" << endl << endl;
    
    while((tipo_lectura != CUENTO && tipo_lectura != POEMA && tipo_lectura != NOVELA) || tipo_lectura_ingresada.length() > 1) {

        cout << "Ingrese la letra segun el tipo de lectura a agregar: ";
        getline(cin, tipo_lectura_ingresada);
        tipo_lectura = (char) toupper(tipo_lectura_ingresada[0]);

        if((tipo_lectura != CUENTO && tipo_lectura != POEMA && tipo_lectura != NOVELA) || tipo_lectura_ingresada.length() > 1)
            cout << ERROR_INGRESO_INCORRECTO + VOLVER_A_INTENTAR;
    }
    
    return tipo_lectura;
}


char ProcesadorDeOpciones::ingresar_si_o_no(string instruccion) {

    string cadena_ingresada = "XX";
    char caracter = 'X';
    cout << endl;

    while((caracter != SI && caracter != NO) || cadena_ingresada.length() > 1) {
    
        cout << instruccion + SI_O_NO;
        getline(cin, cadena_ingresada);
        caracter = (char) toupper(cadena_ingresada[0]);
    
        if((caracter != SI && caracter != NO) || cadena_ingresada.length() > 1)
            cout << ERROR_INGRESO_INCORRECTO + VOLVER_A_INTENTAR;
    }

    return caracter;
}


Escritor* ProcesadorDeOpciones::no_es_escritor_anonimo(int isni) {

    Utilidades validador, limpiador;
    Escritor* escritor;
    cout << endl;

    tabla_escritores_ -> imprimir_escritores(true);

    while(!tabla_escritores_ -> esta_el_elemento(isni) && isni != OPCION_ALTERNATIVA) {
        isni = validador.validar_ingreso_entero(isni, "Ingrese el ISNI del escritor de la lectura correspondiente."
        " Si su escritor no aparece en la lista ingrese -1: ", OPCION_ALTERNATIVA);
        if(isni > ISNI_MAXIMO)
            cout << ERROR_TIPO_DE_DATO << VOLVER_A_INTENTAR;
        else if(isni < ISNI_MINIMO && isni != OPCION_ALTERNATIVA)
            cout << ERROR_TIPO_DE_DATO << VOLVER_A_INTENTAR;
        else if(!tabla_escritores_ -> esta_el_elemento(isni) && isni != OPCION_ALTERNATIVA)
            cout << ERROR_ISNI_INVALIDO + VOLVER_A_INTENTAR;
    }

    if(isni == OPCION_ALTERNATIVA) {
        limpiador.limpiar_pantalla();
        cout << "Proceda a agregar un nuevo escritor:\n" << endl;
        isni = agregar_escritor();
        cout << "\nAhora prosiga creando su lectura." << endl;
    }

    escritor = tabla_escritores_-> consulta(isni);

    return escritor;
}


int ProcesadorDeOpciones::ingresar_genero() {

    Utilidades validador;
    int genero = 0;
    cout << "Generos disponibles:" << endl;
    cout << "\n[1] - Drama\n\n[2] - Comedia\n\n[3] - Ficcion\n\n[4] - Suspenso\n\n[5] - Terror\n\n[6] - Romantica \n\n[7] - Historica" << endl << endl;
    while(!validador.validar_opcion(genero, HISTORICA)) {

        genero = validador.validar_ingreso_entero(genero, "Ingrese el indice correspondiente al genero de la novela: ", OPCION_MINIMA);

        if(!validador.validar_opcion(genero, HISTORICA))
            cout << ERROR_INGRESO_INCORRECTO + VOLVER_A_INTENTAR;
    }

    return genero;
}


Lectura* ProcesadorDeOpciones::crear_novela_historica(string titulo, int duracion, int anio, Escritor* escritor, bool leido) {

    Lectura* novela_historica;
    string tema;
    cout << "\nIngrese el tema historico de la novela: ";
    getline(cin, tema);
    char* tema_historico = new char[tema.length() + 1];
    strcpy(tema_historico, tema.c_str());
    novela_historica = new Historica(titulo, duracion, anio, escritor, leido, HISTORICA, tema_historico);

    return novela_historica;
}


Lectura* ProcesadorDeOpciones::crear_novela(string titulo, int duracion, int anio, Escritor* escritor, bool leido) {

    Lectura* novela;
    cout << endl;
    int genero = ingresar_genero();

    if(genero == 7)
        novela = crear_novela_historica(titulo, duracion, anio, escritor, leido);
    else
        novela = new Novela(titulo, duracion, anio, escritor, leido, (generos) genero);

    return novela;
}


Lectura* ProcesadorDeOpciones::crear_cuento(string titulo, int duracion, int anio, Escritor* escritor, bool leido) {

    Lectura* cuento;
    cout << "\nIngrese el libro donde se publico el cuento: ";
    string libro_publicado;
    getline(cin, libro_publicado);
    cuento = new Cuento(titulo, duracion, anio, escritor, leido, libro_publicado);

    return cuento;
}


Lectura* ProcesadorDeOpciones::crear_poema(string titulo, int duracion, int anio, Escritor* escritor, bool leido) {

    Utilidades validador;
    Lectura* poema;
    int cant_versos = 0;

    cout << endl;
    cant_versos = validador.validar_ingreso_entero(cant_versos, "Ingrese la cantidad de versos del poema: ", OPCION_MINIMA);

    poema = new Poema(titulo, duracion, anio, escritor, leido, cant_versos);

    return poema;
}


Lectura* ProcesadorDeOpciones::crear_lectura(char tipo_lectura, string titulo, int duracion, int anio, Escritor* escritor) {
    
    Lectura* lectura;
    bool leido = false;

    if(toupper(tipo_lectura) == NOVELA)
        lectura = crear_novela(titulo, duracion, anio, escritor, leido);
    else if(toupper(tipo_lectura) == CUENTO)
        lectura = crear_cuento(titulo, duracion, anio, escritor, leido);
    else
        lectura = crear_poema(titulo, duracion, anio, escritor, leido);
    cout << "\n\nSe agrego la lectura " << titulo << " a la lista correctamente.\n" << endl;

    return lectura;
}


void ProcesadorDeOpciones::agregar_lectura() {

    Utilidades validador, insertador;
    string titulo;
    unsigned int duracion = 0, anio = 0;
    char anonimo = 'X';
    int isni = 0;
    Escritor* escritor = NULL;
    Lectura* lectura;

    char tipo_lectura = ingresar_tipo_lectura();

    cout << "\nIngrese el titulo de la lectura: ";
    getline(cin, titulo);

    cout << endl;
    duracion = validador.validar_ingreso_entero(duracion, "Ingrese la duracion en minutos de su lectura: ", OPCION_MINIMA);

    cout << endl;
    anio = validador.validar_ingreso_entero(anio, "Ingrese el anio de publicacion: ", OPCION_MINIMA);

    if(!tabla_escritores_ -> vacia())
        anonimo = ingresar_si_o_no("Su escritor es anonimo?");
    else
        cout << "\nNo hay escritores cargados, por lo tanto su lectura se creara con escritor anonimo." << endl;

    if(toupper(anonimo) == NOVELA)
        escritor = no_es_escritor_anonimo(isni);

    lectura = crear_lectura(tipo_lectura, titulo, duracion, anio, escritor);
    insertador.insertar_lectura_ordenada(lectura, lista_lecturas_);

}


int ProcesadorDeOpciones::ingresar_indice_lista(string instruccion, int cantidad_datos) {

    Utilidades validador;
    int indice = 0;
    while(!validador.validar_opcion(indice, cantidad_datos)) {

        indice = validador.validar_ingreso_entero(indice, instruccion, OPCION_MINIMA);

        if(!validador.validar_opcion(indice, cantidad_datos))
            cout << ERROR_INGRESO_INCORRECTO + VOLVER_A_INTENTAR;
    }

    return indice;
}


void ProcesadorDeOpciones::quitar_lectura() {

    if(!lista_lecturas_ -> vacia()) {

        lista_lecturas_ -> imprimir_lista_lecturas();

        int indice = ingresar_indice_lista("Ingrese el indice de la lectura a eliminar: ", lista_lecturas_ -> obtener_cantidad());
        cout << "\nSe ha eliminado " << lista_lecturas_ -> consulta(indice - 1) -> obtener_titulo() << " correctamente." << endl;
        lista_lecturas_ -> baja(indice - 1);
    }
    else
        cout << LISTA_LECTURAS_VACIA;
}


int ProcesadorDeOpciones::agregar_escritor() {

    Utilidades validador;
    string nombre, apellido, nacionalidad;
    int isni = 0, anio_nacimiento = 0, anio_fallecimiento = 0;

    while(tabla_escritores_ -> esta_el_elemento(isni) || (isni < ISNI_MINIMO || isni > ISNI_MAXIMO)) {
        isni = validador.validar_ingreso_entero(isni, "Ingrese el ISNI correspondiente al autor: ", ISNI_MINIMO);
        if(isni > ISNI_MAXIMO)
            cout << ERROR_TIPO_DE_DATO << VOLVER_A_INTENTAR;
        else if(tabla_escritores_ -> esta_el_elemento(isni))
            cout << ERROR_ISNI_USADO + VOLVER_A_INTENTAR;

    }
    cout << endl;

    cout << "Ingrese el nombre del escritor a agregar: ";
    getline(cin, nombre);

    cout << "\nIngrese el apellido del escritor a agregar: ";
    getline(cin, apellido);

    cout << "\nIngrese la nacionalidad del escritor a agregar: ";
    getline(cin, nacionalidad);

    cout << endl;
    anio_nacimiento = validador.validar_ingreso_entero(anio_nacimiento, "Ingrese el anio de nacimiento del escritor a agregar (-1 en caso de desconocerlo): ", OPCION_ALTERNATIVA);

    cout << endl;
    anio_fallecimiento = validador.validar_ingreso_entero(anio_fallecimiento, "Ingrese el anio de fallecimiento del escritor a agregar (-1 en caso de no poseerlo): ", OPCION_ALTERNATIVA);

    Escritor* escritor = new Escritor(isni, nombre, apellido, nacionalidad, anio_nacimiento, anio_fallecimiento);
    tabla_escritores_-> alta(escritor);

    cout << "\n\nSe agrego a " << nombre << " " << apellido << " a la lista correctamente.\n" << endl;

    return isni;
}


void ProcesadorDeOpciones::asignar_fallecimiento_escritor() {

    if(!tabla_escritores_-> vacia()) {
        Utilidades validador;
        int isni = 0, anio_fallecimiento = 0;

        tabla_escritores_ -> imprimir_escritores(false);

        while(!tabla_escritores_ -> esta_el_elemento(isni)) {
            isni = validador.validar_ingreso_entero(isni, "Ingrese el ISNI del escritor a asignarle el anio: ", ISNI_MINIMO);
            if(isni > ISNI_MAXIMO)
                cout << ERROR_TIPO_DE_DATO << VOLVER_A_INTENTAR;
            else if(!tabla_escritores_ -> esta_el_elemento(isni))
                cout << ERROR_ISNI_INVALIDO + VOLVER_A_INTENTAR;
        }

        if(tabla_escritores_-> consulta(isni) -> verificar_fallecimiento()) {

            cout << endl;
            anio_fallecimiento = validador.validar_ingreso_entero(anio_fallecimiento, "Ingrese el anio de fallecimiento del escritor: ", OPCION_MINIMA);

            tabla_escritores_-> consulta(isni) -> asignar_fallecimiento(anio_fallecimiento);
            cout << "\nSe ha asignado el anio de fallecimiento en " << anio_fallecimiento <<
            " para " << tabla_escritores_ -> consulta(isni) -> obtener_nombre_completo() << " correctamente." << endl;
        }
        else
            cout << "\nEste escritor ya tiene anio de fallecimiento asignado" << endl;
    }
    else
        cout << TABLA_ESCRITORES_VACIA;
}


void ProcesadorDeOpciones::listar_escritores() {

    if(!tabla_escritores_ -> vacia())
        tabla_escritores_ -> imprimir_escritores(false);
    else
        cout << TABLA_ESCRITORES_VACIA;
}


void ProcesadorDeOpciones::sortear_lectura() {

    if(!lista_lecturas_ -> vacia()) {
        srand((unsigned int) time(NULL));
        int sorteo = rand() % (lista_lecturas_ -> obtener_cantidad() + 0);
        cout << "Se leera la lectura numero: " << sorteo + 1 << " - " << lista_lecturas_ -> consulta(sorteo) -> obtener_titulo() << endl;
        lista_lecturas_->consulta(sorteo)->leido(true);
    }
    else
        cout << LISTA_LECTURAS_VACIA;
}


void ProcesadorDeOpciones::listar_lecturas() {

    if(!lista_lecturas_ -> vacia())
        lista_lecturas_ -> imprimir_lista_lecturas();
    else
        cout << LISTA_LECTURAS_VACIA;
}


int ProcesadorDeOpciones::ingresar_anio_correcto(int anio_inferior) {

    Utilidades validador;
    int anio_superior = 0;

    cout << endl;
    while(anio_superior <= anio_inferior) {

        anio_superior = validador.validar_ingreso_entero(anio_superior, "Ingrese el anio hasta donde desea mostrar las lecturas: ", OPCION_MINIMA);

        if(anio_superior <= anio_inferior)
            cout << ERROR_INGRESO_INCORRECTO + VOLVER_A_INTENTAR;
    }

    return anio_superior;
}


void ProcesadorDeOpciones::listar_periodo_lecturas() {

    if(!lista_lecturas_ -> vacia()) {

        Utilidades validador;
        int contador = 0, cantidad_lecturas = lista_lecturas_ -> obtener_cantidad();
        unsigned int anio_inferior = 0;

        anio_inferior = validador.validar_ingreso_entero(anio_inferior, "Ingrese el anio desde donde desea mostrar las lecturas: ", OPCION_MINIMA);

        unsigned int anio_superior = ingresar_anio_correcto(anio_inferior);

        for(int i = 0; i < cantidad_lecturas; i++) {
            if(lista_lecturas_ -> consulta(i) -> obtener_anio() >= anio_inferior && lista_lecturas_ -> consulta(i) -> obtener_anio() <= anio_superior) {
                contador++;
                if(contador == 1)
                    cout << "\nLas lecturas en ese periodo de tiempo son:" << endl;
                cout << endl << contador << " - " << lista_lecturas_ -> consulta(i) -> obtener_titulo() << " - " << lista_lecturas_ -> consulta(i) -> obtener_anio() << endl;
            }
        }

        if(contador == 0)
            cout << "\nNo se han encontrado lecturas en ese periodo de tiempo." << endl;
    }
    else
        cout << LISTA_LECTURAS_VACIA;
}


Escritor* ProcesadorDeOpciones::ingresar_escritor() {

    Utilidades validador;
    int isni = 0;

    tabla_escritores_ -> imprimir_escritores(true);

    while(!tabla_escritores_ -> esta_el_elemento(isni)) {
        isni = validador.validar_ingreso_entero(isni, "Ingrese el ISNI del escritor del cual desea conocer las obras: ", ISNI_MINIMO);
        if(isni > ISNI_MAXIMO)
            cout << ERROR_TIPO_DE_DATO << VOLVER_A_INTENTAR;
        else if(!tabla_escritores_ -> esta_el_elemento(isni))
            cout << ERROR_ISNI_INVALIDO + VOLVER_A_INTENTAR;
    }
    
    Escritor* escritor = tabla_escritores_ -> consulta(isni);

    return escritor;
}


void ProcesadorDeOpciones::listar_lecturas_de() {

    if(!lista_lecturas_ -> vacia()) {

        int contador_lecturas = 0,
        cantidad_lecturas = lista_lecturas_ -> obtener_cantidad();

        Escritor* escritor = ingresar_escritor();

        for(int i = 0; i < cantidad_lecturas; i++) {

            if(lista_lecturas_ -> consulta(i) -> obtener_escritor() == escritor) {
                contador_lecturas++;

                if(contador_lecturas == 1)
                    cout << "\nLas obras de " << escritor -> obtener_nombre_completo() << " son:" << endl;

                cout << endl << contador_lecturas << " - " << lista_lecturas_ -> consulta(i) -> obtener_titulo() << endl;
            }
        }

        if(contador_lecturas == 0)
            cout << "\nEste escritor no tiene cargada ninguna lectura." << endl;
    }
    else
        cout << LISTA_LECTURAS_VACIA;
}


void ProcesadorDeOpciones::listar_novelas_genero() {

    if(!lista_lecturas_ -> vacia()) {

        int contador_novelas = 0, cantidad_lecturas = lista_lecturas_ -> obtener_cantidad();
        Utilidades conversor_a_genero;

        int genero = ingresar_genero();

        for(int i = 0; i < cantidad_lecturas; i++) {
            if(lista_lecturas_ -> consulta(i) -> coinciden_generos(genero)) {
                contador_novelas++;
                if(contador_novelas == 1)
                    cout << "\nLas novelas del genero " << conversor_a_genero.obtener_nombre_genero((generos) genero) << " son:" << endl;
                cout << endl << contador_novelas << " - " << lista_lecturas_ -> consulta(i) -> obtener_titulo() << endl;
            }
        }

        if(contador_novelas == 0)
            cout << "\nNo se han encontrado novelas de ese genero." << endl;
    }
    else
        cout << LISTA_LECTURAS_VACIA;
}


int ProcesadorDeOpciones::obtener_indice_mayor_duracion() {

    int cantidad_elementos = lista_lecturas_->obtener_cantidad();
    int indice_maximos_minutos = 0;
    Lectura* lectura = lista_lecturas_ -> consulta(0);

    for(int i = 0; i < cantidad_elementos; i++) {
        if((lectura -> comparar_por_duracion(lista_lecturas_ -> consulta(i)) == -1)) {
            indice_maximos_minutos = i;
            lectura = lista_lecturas_ -> consulta(indice_maximos_minutos);
        }
    }

    return indice_maximos_minutos;
}


int ProcesadorDeOpciones::obtener_cantidad_lecturas_sin_leer() {

    int no_leidos = 0;

    for(int i = 0; i < lista_lecturas_ -> obtener_cantidad(); i++) {
        if(!lista_lecturas_ -> consulta(i) -> fue_leido())
            no_leidos++;
    }

    return no_leidos;
}


void ProcesadorDeOpciones::insertar_en_cola_ordenada(Cola<Lectura*>* cola_lecturas, unsigned int menor_duracion) {

    if(cola_lecturas -> obtener_cantidad() == obtener_cantidad_lecturas_sin_leer())
        return;

    Lectura* lectura_menor_duracion = lista_lecturas_ -> consulta(obtener_indice_mayor_duracion());
    int cantidad_elementos = lista_lecturas_ -> obtener_cantidad();

    for(int i = 0; i < cantidad_elementos; i++) {

        if((lectura_menor_duracion -> comparar_por_duracion(lista_lecturas_ -> consulta(i)) == 1)
            && lista_lecturas_ -> consulta(i)->obtener_minutos() > menor_duracion
            && !lista_lecturas_ -> consulta(i)->fue_leido()) {
            
            lectura_menor_duracion = lista_lecturas_ -> consulta(i);
        }
    }

    cola_lecturas -> alta(lectura_menor_duracion);
    menor_duracion = lectura_menor_duracion -> obtener_minutos();
    insertar_en_cola_ordenada(cola_lecturas, menor_duracion);

}


void ProcesadorDeOpciones::ingresar_reinicio_de_cola() {

    char reiniciar_cola = 'X';
    cout << "Ya has leido todas las lecturas de la cola :(" << endl <<
    "Para seguir leyendo, puedes ingresar mas lecturas o reiniciar la cola de lecturas." << endl;
    reiniciar_cola = ingresar_si_o_no("Desea reiniciar la cola?");
    if(reiniciar_cola == SI)
        reiniciar_cola_lecturas();
    else
        cout << "\nDe acuerdo, puedes volver a esta opcion cuando desees para reiniciar la cola de lecturas.\n";
}


void ProcesadorDeOpciones::reiniciar_cola_lecturas() {

    for(int i = 0; i < lista_lecturas_ -> obtener_cantidad(); i++){
        lista_lecturas_ -> consulta(i) -> leido(false);
    }
    cout << "\nSe ha reiniciado la cola, ya puedes volver a armarla y leer de la misma!" << endl;
}


void ProcesadorDeOpciones::crear_cola_ordenada() {

    if(!lista_lecturas_ -> vacia()) {

        Cola<Lectura*>* cola_lecturas = new Cola<Lectura*>();
        insertar_en_cola_ordenada(cola_lecturas, 0);
        Utilidades limpiador;
        char seguir_leyendo = 'X';

        while(!cola_lecturas -> vacia() && seguir_leyendo != NO) {

            cout << "Cantidad de lecturas sin leer: " << cola_lecturas -> obtener_cantidad() << endl << endl;
            cola_lecturas -> consulta() -> mostrar_lectura();
            seguir_leyendo = ingresar_si_o_no("Quiere leer esta lectura?");
            if(seguir_leyendo == SI) {
                Lectura* lectura_leida = cola_lecturas -> baja();
                lectura_leida -> leido(true);
                limpiador.limpiar_pantalla();
                cout << "Has leido " << lectura_leida -> obtener_titulo() << "! En un lapso de: " 
                << lectura_leida -> obtener_minutos() << " minutos.\n" << endl;
            }
            else
                cout << "\nHas dejado de leer." << endl;
        }
        if(cola_lecturas -> vacia())
            ingresar_reinicio_de_cola();

        delete cola_lecturas;
    }
    else
        cout << LISTA_LECTURAS_VACIA;
}

int ProcesadorDeOpciones::validar_peso_arista(Lectura* vertice1, Lectura* vertice2) {

    int peso = 0;
    if(vertice1 -> tipo_lectura() == CUENTO) {
        if(vertice2 -> tipo_lectura() == CUENTO)
            peso = 8;
        if(vertice2 -> tipo_lectura() == NOVELA)
            peso = 10;
        if(vertice2 -> tipo_lectura() == NOV_HISTORICA)
            peso = 15;
        if(vertice2 -> tipo_lectura() == POEMA)
            peso = 0;
    }
    if(vertice1->tipo_lectura() == POEMA) {
        if(vertice2 -> tipo_lectura() == CUENTO)
            peso = 0;
        if(vertice2 -> tipo_lectura() == NOVELA)
            peso = 5;
        if(vertice2 -> tipo_lectura() == NOV_HISTORICA)
            peso = 20;
        if(vertice2 -> tipo_lectura() == POEMA)
            peso = 1;
    }
    if(vertice1 -> tipo_lectura() == NOVELA) {
        if(vertice2 -> tipo_lectura() == CUENTO)
            peso = 10;
        if(vertice2 -> tipo_lectura() == NOVELA)
            peso = 30;
        if(vertice2 -> tipo_lectura() == NOV_HISTORICA)
            peso = 60;
        if(vertice2 -> tipo_lectura() == POEMA)
            peso = 5;
    }
    if(vertice1 -> tipo_lectura() == NOV_HISTORICA) {
        if(vertice2 -> tipo_lectura() == CUENTO)
            peso = 15;
        if(vertice2 -> tipo_lectura() == NOVELA)
            peso = 60;
        if(vertice2 -> tipo_lectura() == NOV_HISTORICA)
            peso = 80;
        if(vertice2 -> tipo_lectura() == POEMA)
            peso = 20;
    }

    return peso;
}


void ProcesadorDeOpciones::conectar_grafo(Grafo* grafo) {

    Lectura* vertice1 = NULL;
    Lectura* vertice2 = NULL;
    int peso = 0;
    for(int pos_vertice = 0; pos_vertice < grafo -> obtener_tamanio(); pos_vertice++) {

        vertice1 = lista_lecturas_ -> consulta(pos_vertice);

        for(int i = 0; i < grafo->obtener_tamanio(); i++) {

            if(pos_vertice != i) {
                vertice2 = lista_lecturas_ -> consulta(i);
                peso = validar_peso_arista(vertice1, vertice2);
                grafo -> agregar_camino(vertice1, vertice2, peso);
            }

        }
        pos_vertice++;
    }
}


Grafo* ProcesadorDeOpciones::crear_grafo() {

    Grafo* grafo = new Grafo();
    lista_lecturas_ -> inicializar();
    while(lista_lecturas_ -> hay_siguiente()) {
        grafo->agregar_vertice(lista_lecturas_ -> siguiente());
    }
    conectar_grafo(grafo);

    return grafo;
}


void ProcesadorDeOpciones::menor_tiempo_lectura() {

    if(!lista_lecturas_ -> vacia()) {
        Grafo* grafo = crear_grafo();
        cout << "Para leer todas las lecturas en el menor tiempo, debemos seguir lo siguiente: " << endl << endl;
        Grafo* arbol_expansion_min = grafo -> Kruskal();
        arbol_expansion_min -> mostrar_grafo();
        delete grafo;
        delete arbol_expansion_min;
    }
}


void ProcesadorDeOpciones::cocinar_pastel_de_papa() {

    #ifdef _WIN32
        srand((unsigned int) time(NULL));
        if ((rand() % 2) + 1 ==  2)
            system("start https://drive.google.com/file/d/16aB2L2z-jo0O5vIcl8S3cao04Ud5Tdba/view");
        else 
            system("start https://drive.google.com/file/d/1YzOFCVS56FlnMrrh09RDS3z-jXlnJHw3/view");

     #else
        srand((unsigned int) time(NULL));
        if ((rand() % 2) + 1 ==  2)
            system("xdg-open https://drive.google.com/file/d/16aB2L2z-jo0O5vIcl8S3cao04Ud5Tdba/view");
        else 
            system("xdg-open https://drive.google.com/file/d/1YzOFCVS56FlnMrrh09RDS3z-jXlnJHw3/view");
     #endif

     cout << "---> ---> ---> Has descubierto un secreto <--- <--- <---" << endl;
}


ProcesadorDeOpciones::~ProcesadorDeOpciones() {

    delete tabla_escritores_;
    delete lista_lecturas_;
}