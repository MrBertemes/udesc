#include <stdio.h>
#include <stdlib.h>

typedef struct tokens nodo;
struct tokens{
    nodo *prox;
    nodo *ant;
    int id;
    char * variavel;

};

nodo * insere_nodo_fim_variavel(nodo * l, char * token);
nodo* inicializa(int id); // feito
nodo * insere_ordenado(nodo *l, int valor); // feito
int profundidade(nodo *l, int valor); // feito
void imprime_lista(nodo *l); //feito
int conta_nos(nodo *l); //feito
nodo * libera_lst(nodo *l); //feito 
nodo * atualiza(nodo *l, int num_no, int valor); // feito
nodo * busca_rmv(nodo *l, int valor); // feito
