%{
    
    // includes

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela.h"

    
nodo * tabela;


%}

ID {LETRA}|{LETRA}{ID}|{DIGITO}{ID}
SELETOR_ "[" {EXP} "]"|
SELETOR "[" {EXP} "]" {SELETOR_}
VARIAVEL {ID} {SELETOR}
BOOL_LIT true|false
TIPO_SIMP integer|real|boolean
TIPO_AGRE array"["{LITERAL}".."{LITERAL}"]"of{TIPO}
TIPO {TIPOAGRE}|{TIPO_SIMP}
INT_LIT_ {DIGITO}{INT_LIT_}|{DIGITO}
INT_LIT  {DIGITO}{INT_LIT_}
FLOAT_LIT {INT_LIT}"."{INT_LIT}|{INT_LIT}"."|"."{INT_LIT}
LITERAL {BOOLLIT}|{INT_LIT}|{FLOAT_LIT}
LISTA_EXP_ "," {EXP}{LISTA_EXP_}|{EXP}
LISTA_EXP {EXP}{LISTA_EXP_}
DENTROFUNCAO {LISTA_EXP}|
CHAMADAFUNC {ID} "(" {DENTROFUNCAO} ")"
FATOR {VARIAVEL}|{LITERAL}|"(" {EXP} ")"|{CHAMADAFUNC}
TERMO_ {OPMULTI}{TERMO_}|{FATOR}
TERMO {FATOR}{TERMO_}
EXP_SIMP_ {OPAD}{EXP_SIMP_}|{TERMO}
EXP_SIMP {TERMO}{EXP_SIMP_}
EXP {EXP_SIMP}|{EXP_SIMP}{OPREL}{EXP_SIMP}
ATRIBUICAO {VARIAVEL}":="{EXP}
OUTROS !|@|#|...
VAZIO  [ ]
DIGITO [0-9]
LETRA [a-z]
OPAD +|-|or
OPMULTI *|/|and
OPREL <|>|<=|>=|=|<>
PARAMETROS ({VARIAVEL} |{VAZIO}) {LISTA_DE_ID} : {TIPO_SIMP}
LISTA_DE_ID {ID} | {LISTA_DE_ID} "," {ID} 
%%


{TIPO} {
    printf( "Tipo: %s\n", yytext );
}

{INTLIT} {
printf( "Um valor inteiro: %s (%d)\n", yytext,
atoi( yytext ) );
}

{FLOATLIT} {
printf( "Um valor real: %s (%g)\n", yytext,
atof( yytext ) );
}

if|then|begin|end|procedure|function {
printf( "Uma palavra-chave: %s\n", yytext );
}

{ID} {
    printf( "Um ID: %s\n", yytext );
    tabela = forma_lista("id", yytext, tabela);
}

"{"[^}\n]*"}" /* Lembre-se... comentários não tem utilidade! */

[ \t\n]+ /* Lembre-se... espaços em branco não tem utilidade! */

. printf( "Caracter não reconhecido: %s\n", yytext );

%%

int main(void){


    yyin = fopen( "code.braia", "r" ); // Escrever o codigo no arquivo code.braia

    
    yylex();

return 0;
}