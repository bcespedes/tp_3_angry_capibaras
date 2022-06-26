# include "Utilidades.h"


Utilidades::Utilidades() {

}


void Utilidades::limpiar_pantalla() {

    #ifdef _WIN32
            system("cls");
    #else
            system ("clear");
    #endif
}


bool Utilidades::validar_opcion(int opcion, int opcion_max) {

    return (OPCION_MINIMA <= opcion && opcion <= opcion_max);
}


int Utilidades::validar_ingreso_entero(int a_validar, string instruccion, int valor_minimo) {

    cout << instruccion;
    cin >> a_validar;
    while(!cin.good() || a_validar < valor_minimo) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << ERROR_TIPO_DE_DATO + VOLVER_A_INTENTAR;
        cout << instruccion;
        cin >> a_validar;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return a_validar;
}


void Utilidades::insertar_lectura_ordenada(Lectura* lectura, Lista<Lectura*>* lista_lectura) {

    int pos = 0;
    bool avanzar = true;

    lista_lectura -> inicializar();
    if(!lista_lectura -> vacia()) {
    
        while(avanzar) {
            if(lectura -> comparar_por_anio(lista_lectura -> consulta(pos)) == -1) {
                avanzar = false;
                pos--;
            }
            lista_lectura -> siguiente();
            if(!lista_lectura -> hay_siguiente()) {
                pos++;
                avanzar = false;
            }
            else
                pos++;
        }
    }

    lista_lectura -> alta(lectura, pos);
}


string Utilidades::obtener_nombre_genero(generos genero) {

    string nombre_genero;
    if(genero == DRAMA)
        nombre_genero = "drama";
    else if(genero == COMEDIA)
        nombre_genero = "comedia";
    else if(genero == FICCION)
        nombre_genero = "ficcion";
    else if(genero == SUSPENSO)
        nombre_genero = "suspenso";
    else if(genero == TERROR)
        nombre_genero = "terror";
    else if(genero == ROMANTICA)
        nombre_genero = "romantica";
    else if(genero == HISTORICA)
        nombre_genero = "historica";

    return nombre_genero;
}
