%option nounput yylineno
%option noyywrap
%option noinput
%{
#include <string.h>
#include "Definiciones.h"
#include "PReservadas.h"
#include "TablaSimbolos.h"
#include "Error.h"
#define YY_DECL int yylex(tipoelem* tipo)
%}
ALPHA [a-zA-Z]
DIGITO [0-9]
BINDIGITO [0-1]
OCTDIGITO [0-7]
HEXDIGITO [a-fA-F]|{DIGITO}
NOCERODIGITO [1-9]
DIGITPART {DIGITO}(["_"]|{DIGITO})*
FRACTION  "."{DIGITPART}
EXPONENT      ("e"|"E")([+]|[-])?{DIGITPART}
POINTFLOAT    {DIGITPART}{FRACTION}|{DIGITPART}"."|{FRACTION}
EXPONENTFLOAT ({DIGITPART}|{POINTFLOAT}){EXPONENT}
%%
"#"[^\n]* {}
	
\"\"\"[^\"]*\"\"\" 	{}
	
<<EOF>> {tipo->compLex=-1;yyterminate();return 0;}
[\t]		;
		
[\n]        	;
			
" "		;

"$"|"?"|"`"	{print_Error(0,yytext,yylineno);return 0;}

\'[^\n\']*\'	{tipo->compLex=CAD;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}

\"[^\n\"]*\"	{tipo->compLex=CAD;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}

({ALPHA}|"_")+({ALPHA}|{DIGITO}|"_")* 	{strcpy(tipo->lexema,yytext);tipo->linea=yylineno;
					if(is_keyword(yytext)){
						tipo->compLex=asigna_compLex(yytext);
					}
					else{
						tipoelem aux;
						tipo->compLex=ID;
						aux.lexema=strdup(yytext);
						aux.compLex=ID;
						aux.linea=yylineno;
						if(!MiembroHashTablaSimbolos(aux)){
							InsertarHashTablaSimbolos(aux);
						}
					}return 0;}

{POINTFLOAT}|{EXPONENTFLOAT} {tipo->compLex=FLT;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}

"0"("b"|"B")(["_"]|{BINDIGITO})+ {tipo->compLex=BIN;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}

"0"("o"|"O")(["_"]|{OCTDIGITO})+ {tipo->compLex=OCT;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}

"0"("x"|"X")(["_"]|{HEXDIGITO})+ {tipo->compLex=HX;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}

{NOCERODIGITO}(["_"]|{DIGITO})*|"0"+(["_"]|"0")* {tipo->compLex=INT;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}


[<] {tipo->compLex=MENOR;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
[>] {tipo->compLex=MAYOR;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
[~] {tipo->compLex=VIRGULILLA;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
[%] {tipo->compLex=MODULO;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
[\^] {tipo->compLex=ELEVADO;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
[|] {tipo->compLex=BARRAV;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
[&] {tipo->compLex=AMPERSAND;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"//" {tipo->compLex=BARRABARRA;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
[/] {tipo->compLex=BARRA;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
[*] {tipo->compLex=POR;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
[-] {tipo->compLex=MENOS;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
[+] {tipo->compLex=MAS;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
[,] {tipo->compLex=COMA;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"@" {tipo->compLex=ARROBA;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
">>" {tipo->compLex=MAYORMAYOR;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"<=" {tipo->compLex=MENORIGUAL;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
">=" {tipo->compLex=MAYORIGUAL;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"**" {tipo->compLex=PORPOR;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"<<" {tipo->compLex=MENORMENOR;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
[=]  {tipo->compLex=IGUAL;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}


"==" {tipo->compLex=IGUALIGUAL;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"!=" {tipo->compLex=NOIGUAL;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"+=" {tipo->compLex=MASIGUAL;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"-=" {tipo->compLex=MENOSIGUAL;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"**=" {tipo->compLex=PORPORIGUAL;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"*=" {tipo->compLex=PORIGUAL;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"//=" {tipo->compLex=BARRABARRAIGUAL;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"/=" {tipo->compLex=BARRAIGUAL;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"%=" {tipo->compLex=MODULOIGUAL;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"&=" {tipo->compLex=AMPERSANDIGUAL;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"@=" {tipo->compLex=ARROBAIGUAL;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"->" {tipo->compLex=FLECHA;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"|=" {tipo->compLex=BARRAVIGUAL;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"^=" {tipo->compLex=ELEVADOIGUAL;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
">>=" {tipo->compLex=MAYORMAYORIGUALIGUAL;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"<<=" {tipo->compLex=MENORMENORIGUALIGUAL;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"." {tipo->compLex=PUNTO;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
";" {tipo->compLex=PUNTOCOMA;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
":" {tipo->compLex=DOSPUNTOS;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"(" {tipo->compLex=IPAR;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
")" {tipo->compLex=DPAR;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"[" {tipo->compLex=ICOR;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"]" {tipo->compLex=DCOR;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"{" {tipo->compLex=ICON;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}
"}" {tipo->compLex=DCON;strcpy(tipo->lexema,yytext);tipo->linea=yylineno;return 0;}

. {print_Error(1,yytext,yylineno);tipo->linea=yylineno;return 0;}
%%