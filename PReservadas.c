#include "PReservadas.h"
//variable global que contiene todas las palabras clave de python
char keywords[KEYTAM][10]={"False","await","else","import","pass","None","break","except","in","raise","True","class","finally","is","return","and","continue","for","lambda","try","as","def","from","nonlocal","while","assert","del","global","not","with","async","elif","if","yield","match","case"};
/*
	 Funci�n: inserta en el HashTable todas las palabras reservadas
	 Valor de retorno: no tiene
*/
void fill_keywords(){
    int i=0;
    tipoelem elemento;
    //recorro la variable global
    for(i=0;i<KEYTAM;i++){
    	memset(elemento.lexema,0,SIZE);
	strcat(elemento.lexema,keywords[i]);
    	elemento.compLex=300+i;
    	InsertarHashTablaSimbolos(elemento);
    }
}
/*
	 Funci�n: compara una cadena dada con las palabras reservadas para saber si lo es o no
	 Valor de retorno: 0 si no es una palabra reservada y 1 si lo es
*/
int is_keyword(char *cadena){
    int i=0,resultado=0;
    //recorro la variable global
    for(i=0;i<KEYTAM;i++){
    	if(strcmp(cadena,keywords[i])==0){
    		resultado=1;
    	}
    }
    return resultado;
}
/*
	 Funci�n: compara cadena con las palabras clave y devuelve su complex
	 Valor de retorno: componente lexico de la palabra clave
*/
int asigna_compLex(char *cadena){
	int i=0;
	for(i=0;i<KEYTAM;i++){
		if(strcmp(cadena,keywords[i])==0){
			return 300+i;
		}
	}
	return 0;
}