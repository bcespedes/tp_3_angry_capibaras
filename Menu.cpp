# include "Menu.h"
# include <iostream>


using namespace std;


Menu::Menu() {

     Utilidades limpiador, validador;
     limpiador.limpiar_pantalla();
     mensaje_bienvenida();
     opcion_elegida = 0;
     cerrar_menu = false;
     LectorEscritores lector_escritores;
     LectorLecturas lector_lecturas;
     ProcesadorDeOpciones* procesador_opciones = cargar_archivos(lector_escritores, lector_lecturas);

     mantener_abierto_menu(validador, limpiador, procesador_opciones);

     delete procesador_opciones;
}


void Menu::mantener_abierto_menu(Utilidades validador, Utilidades limpiador, ProcesadorDeOpciones *procesador_opciones){
     while (!cerrar_menu) {
          mostrar_menu();
          opcion_elegida = validador.validar_ingreso_entero(opcion_elegida, ESCRIBA_OPCION_MENU, OPCION_MINIMA);
          limpiador.limpiar_pantalla();
          cerrar_menu = procesar_opcion(procesador_opciones);
     }
}


ProcesadorDeOpciones* Menu::cargar_archivos(LectorEscritores lector_escritores, LectorLecturas lector_lecturas) {

     Hash* tabla_escritores = lector_escritores.procesar_escritores();
     Lista<Lectura*>* lista_lecturas = lector_lecturas.procesar_lecturas(tabla_escritores);
     ProcesadorDeOpciones* procesador_opciones = new ProcesadorDeOpciones(tabla_escritores, lista_lecturas);

     return procesador_opciones;
}


void Menu::mostrar_menu() {

     cout << OPCION_1 << endl;
     cout << OPCION_2 << endl;
     cout << OPCION_3 << endl;
     cout << OPCION_4 << endl;
     cout << OPCION_5 << endl;
     cout << OPCION_6 << endl;
     cout << OPCION_7 << endl;
     cout << OPCION_8 << endl;
     cout << OPCION_9 << endl;
     cout << OPCION_10 << endl;
     cout << OPCION_11 << endl;
     cout << OPCION_12 << endl;
     cout << OPCION_13 << endl;
}


bool Menu::procesar_opcion(ProcesadorDeOpciones* procesador_opciones) {

     Utilidades validador;
     switch (opcion_elegida) {
          case AGREGAR_LECTURA: 
               procesador_opciones -> agregar_lectura();
               break;
          case QUITAR_LECTURA:
               procesador_opciones -> quitar_lectura();
               break;
          case AGREGAR_ESCRITOR:
               procesador_opciones -> agregar_escritor();
               break;
          case CAMBIAR_FALLECIMIENTO:
               procesador_opciones -> asignar_fallecimiento_escritor();
               break;
          case LISTAR_ESCRITORES:
               procesador_opciones -> listar_escritores();
               break;
          case SORTEAR_LECTURA:
               procesador_opciones -> sortear_lectura();
               break;
          case LISTAR_LECTURAS:
               procesador_opciones -> listar_lecturas();
               break;
          case LISTAR_LECTURAS_POR_PERIODOS:
               procesador_opciones -> listar_periodo_lecturas();
               break;
          case LISTAR_LECTURA_POR_ESCRITOR:
               procesador_opciones -> listar_lecturas_de();
               break;
          case LISTAR_NOVELAS_POR_GENERO:
               procesador_opciones -> listar_novelas_genero();
               break;
          case ARMAR_COLA:
               procesador_opciones -> crear_cola_ordenada();
               break;
          case MENOR_TIEMPO_LECTURA:
               procesador_opciones -> menor_tiempo_lectura();
               break;
          case SALIR:
               cerrar_menu = true;
               mensaje_despedida();
               break;
          case COCINAR_PASTEL_DE_PAPA:
               procesador_opciones -> cocinar_pastel_de_papa();
               break;
          default:
               cout << OPCION_INVALIDA_MENU << endl;
               cout << endl; 
     }         

     if(opcion_elegida != SALIR && validador.validar_opcion(opcion_elegida, OPCION_MAXIMA_MENU))
          tecla_continuar();
          

     return cerrar_menu;
}


void Menu::mensaje_bienvenida() {

     cout << MENSAJE_BIENVENIDA_MENU << endl;
}


void Menu::mensaje_despedida() {

     cout << MENSAJE_DESPEDIDA_MENU << endl;
}


void Menu::tecla_continuar() {

     Utilidades limpiador;
     cout << endl;
     cout << PRESIONE_ENTER;
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     limpiador.limpiar_pantalla();
}


Menu::~Menu() {

}