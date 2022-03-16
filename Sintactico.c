#include "Sintactico.h"
//---------------------------------------------------------------------------------
//---------------------------------------------------------------------------------
//VARIABLES EXTERNAS DE FLEX
extern int yylex(tipoelem* tipo);
extern FILE* yyin;
//-----------------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------------
/*
	 Funci�n: imprime los componentes léxicos que le devuelve el léxico
	 Valor de retorno: no tiene
*/
void print_comp_lex(){
    int cond=0;
    //reservo memoria para tipoelem
    tipoelem *t=(tipoelem*)malloc(sizeof(tipoelem));
    t->lexema=(char*)malloc(sizeof(char)*64);
    //leo el archivo
    yyin = fopen("wilcoxon.py", "r" );
    printf("|TOKENS ECONTRADOS|\n");
    printf("-----------------------------------\n");
    //mientras no devuelva sig_com_lex una tupla con complemento lexico = -1 sigo pidiendo componentes
    while(cond==0){
        yylex(t);
        if(t->compLex!=-1){
        
            printf("[ %d , %s ] Linea=%d\n",t->compLex,t->lexema,t->linea);
        }
        else{
            cond=1;
        }
    }
    printf("-----------------------------------\n");
    //libero memoria para tipoelem
    free(t->lexema);
    free(t);
}
