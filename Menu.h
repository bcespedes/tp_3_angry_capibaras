# ifndef MENU_H
# define MENU_H


# include "constantes.h"
# include "Lector.h"
# include "LectorEscritores.h"
# include "LectorLecturas.h"
# include "ProcesadorDeOpciones.h"


class Menu {

private:

     // ATRIBUTOS
     int opcion_elegida;
     bool cerrar_menu;

     // METODOS
     void mensaje_bienvenida();
     void mensaje_despedida();
     void tecla_continuar();
     void mostrar_menu(); 
     void mantener_abierto_menu(Utilidades validador, Utilidades limpiador, ProcesadorDeOpciones *procesador_opciones);
     bool procesar_opcion(ProcesadorDeOpciones* procesador_opciones);
     ProcesadorDeOpciones* cargar_archivos(LectorEscritores lector_escritores, LectorLecturas lector_lecturas);

public:

     // PRE: -
     // POST: Construye y pone en funcionamiento el menu.
     Menu();

     // PRE: -
     // POST: Destruye el menu
     ~Menu();

};


# endif