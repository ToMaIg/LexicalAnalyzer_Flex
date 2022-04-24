
#include <stdlib.h>
#include "Definiciones.h"
#pragma once


struct celda{ // Estructura de una celda de la lista
    tipoelem elemento;
    struct celda *sig;
};

typedef struct celda * posicion;

struct l{ // Estructura de la lista
    posicion inicio;
    unsigned longitud;
    posicion fin;
};

typedef struct l * lista;

// Función para crear una lista
void crea(lista *l);

// Función para destruir una lista
void destruye(lista *l);

// Función para devolver el puntero inicio de la lista
posicion primero(lista l);

// Función para devolver el puntero al siguiente elemento de la lista
posicion siguiente(lista l, posicion p);

// Función qpara devolver el puntero fin de la lista
posicion fin(lista l);

// Función para devolver el puntero al siguiente elemento de la lista
posicion anterior(lista l, posicion p);

// Función para devolver la existencia no de la lista
unsigned existe(lista l);

// Función para devolver si la lista está vacía o no
unsigned esvacia(lista l);

// Función para recuperar el elemento de la lista en una posición concreta
void recupera(lista l, posicion p, tipoelem *e);

// Función para devolver la longitud de la lista
unsigned longitud(lista l);

// Función para insertar en la lista en una posición concreta
void inserta (lista *l, posicion p, tipoelem e);

// Función para eliminar un elemento de la lista en una posición concreta
void suprime (lista *l, posicion p);

// Función para modificar un elemento de la lista en una posición concreta
void modifica (lista *l, posicion p, tipoelem e);