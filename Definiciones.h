#pragma once
//-------------------------------------------------------
//-------------------------------------------------------
//ESTRUCTURA
struct tipo{ // Estructura de los elementos de la lista
    char * lexema;
    int compLex;
    int linea;
};

typedef struct tipo tipoelem;
//-------------------------------------------------------
//-------------------------------------------------------
//COMPONENTES LÉXICOS
//identificador
#define ID 336
//entero
#define INT 337
//hexadecimal
#define HX 338
//octal
#define OCT 339
//binario
#define BIN 340
//float
#define FLT 341
//literal cadena
#define CAD 342
//OPERADORES
#define MAS 350  // +  
#define MENOS 351 // -
#define POR 352 // *
#define PORPOR 353 //**
#define BARRA 354 // /
#define BARRABARRA 355 // //
#define MODULO 356 // %
#define ARROBA 357 //@
#define MENORMENOR 358 // <<
#define MAYORMAYOR 359 //>>
#define AMPERSAND 360 //&
#define BARRAV 361 // |
#define ELEVADO 362 //^
#define VIRGULILLA 363 //~
#define ASIGNACION 364 //:=
#define MENOR 365 //<
#define MAYOR 366 //>
#define MAYORIGUAL 367 //>=
#define MENORIGUAL 368 //<=
#define IGUALIGUAL 369 //==
#define NOIGUAL 370 //!=
//DELIMITADORES
#define IPAR 380 //(
#define DPAR 381 //)
#define ICOR 382 //[
#define DCOR 383 //]
#define ICON 384 //{
#define DCON 385 //}
#define COMA 386 //,
#define DOSPUNTOS 387 //:
#define PUNTO 388 //.
#define PUNTOCOMA 389 //;
#define IGUAL 390 //=
#define FLECHA 391 //->
#define MASIGUAL 392 //+=
#define MENOSIGUAL 393 //-=
#define PORIGUAL 394 //*=
#define BARRAIGUAL 395 // /=
#define BARRABARRAIGUAL 396 // //=
#define MODULOIGUAL 397 // %=
#define ARROBAIGUAL 398 //@=
#define AMPERSANDIGUAL 399 //&=
#define BARRAVIGUAL 400 //|=
#define ELEVADOIGUAL 401 //^=
#define VIRGULILLAIGUAL 402 //^=
#define MAYORMAYORIGUALIGUAL 403 //>>==
#define MENORMENORIGUALIGUAL 404 //<<==
#define PORPORIGUAL 405 //**=
