#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "hash_encadenamiento.h"
// Función para inicializar la tabla de simbolos
void InicializarTablaSimbolos ();

// Función para destruir la tabla de simbolos
void DestruirTablaSimbolos ();

// Función para buscar un elemento en la tabla de simbolos que lo devuelve en el puntero de tipoelem si existe, sino ese puntero será NULL
int BusquedaTablaSimbolos(char *clave, tipoelem *e);

// Función para comprobar si el elemento pertenece a la tabla de simbolos
int MiembroHashTablaSimbolos (tipoelem e);

// Función para comprobar si la cadena pertenece a la tabla de simbolos
int MiembroHashClaveTablaSimbolos(char * clave);

// Función para insertar en la tabla de simbolos un elemento
void InsertarHashTablaSimbolos (tipoelem elemento);

// Función para borrar de la tabla de simbolos un elemento
void BorrarHashTablaSimbolos (tipoelem elemento);

// Función para imprimir el contenido de la Tabla de Símbolos
void Imprimir_TablaSimbolos();