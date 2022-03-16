#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TablaSimbolos.h"
#include "Sintactico.h"
#include "PReservadas.h"
int main() {
	//reservo memoria tabla de simbolos
	InicializarTablaSimbolos();
	//lleno la tabla de simbolos con las palabras clave
	fill_keywords();
	//imprimo el contenido de la tabla de simbolos
	Imprimir_TablaSimbolos();
        //funcion que devuelve todos los componentes detectados
        print_comp_lex();
        //imprimo el contenido de la tabla de simbolos
	Imprimir_TablaSimbolos();
        //libero memoria tabla simbolos 
	DestruirTablaSimbolos();
}