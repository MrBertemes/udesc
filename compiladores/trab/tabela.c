#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "tabela.h"


nodo * forma_lista(char * tipo, char * token, nodo * tabela){
    
    if(strcmp(tipo,"id")){
        tabela = insere_nodo_fim_variavel(tabela, token);
    }
}
