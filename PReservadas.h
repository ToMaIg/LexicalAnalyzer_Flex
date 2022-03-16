#pragma once
#include <stdio.h>
#include <string.h>
#include "TablaSimbolos.h"
#define tamLinea 100
#define KEYTAM 36
//llena la hashtable con las palabras clave de python
void fill_keywords();
//comprueba si es una palabra reservada
int is_keyword(char *cadena);
//devuelve el componente lexico de una palabra clave
int asigna_compLex(char *cadena);