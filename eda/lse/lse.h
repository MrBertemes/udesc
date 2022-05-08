#ifndef LSE_H
#define LSE_H
typedef struct reg nodo;

struct reg
{
    int dado;
    nodo *prox;
};
void menu();
nodo *insere_fim(nodo *l, int valor);
int profundidade(nodo *l, int valor);
void imprime_lista(nodo *l);
nodo *inicializa();
int conta_nos(nodo *l);
nodo *libera_lst(nodo *l);
nodo *busca_rmv(nodo *l, int valor);
#endif