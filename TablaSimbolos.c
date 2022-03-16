#include "TablaSimbolos.h"
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//VARIABLE GLOBAL
TablaHash TablaSimbolos;
//---------------------------------------------------------------------
//---------------------------------------------------------------------
//FUNCIONES

// Función para inicializar la tabla de simbolos
void InicializarTablaSimbolos (){
	InicializarTablaHash (TablaSimbolos);
}

// Función para destruir la tabla de simbolos
void DestruirTablaSimbolos (){
	DestruirTablaHash(TablaSimbolos);
}

// Función para buscar un elemento en la tabla de simbolos que lo devuelve en el puntero de tipoelem si existe, sino ese puntero será NULL
int BusquedaTablaSimbolos(char *clave, tipoelem *e){
	return Busqueda(TablaSimbolos, clave, e);
}

// Función para comprobar si el elemento pertenece a la tabla de simbolos
int MiembroHashTablaSimbolos (tipoelem e){
	return MiembroHash (TablaSimbolos,e);
}

// Función para comprobar si la cadena pertenece a la tabla de simbolos
int MiembroHashClaveTablaSimbolos(char * clave){
	return MiembroHashClave(TablaSimbolos,clave);
}

// Función para insertar en la tabla de simbolos un elemento
void InsertarHashTablaSimbolos (tipoelem elemento){
	InsertarHash (&TablaSimbolos,elemento);
}

// Función para borrar de la tabla de simbolos un elemento
void BorrarHashTablaSimbolos (tipoelem elemento){
	BorrarHash (&TablaSimbolos,elemento);
}

// Función para imprimir el contenido de la Tabla de Símbolos
void Imprimir_TablaSimbolos(){
	ImprimirTablaSimbolos(TablaSimbolos);
}