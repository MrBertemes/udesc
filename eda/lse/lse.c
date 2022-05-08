#include <stdio.h>
#include <stdlib.h>
#include "lse.h"

nodo *insere_fim(nodo *l, int valor)
{
    nodo *novo, *next;
    novo = (nodo *)malloc(sizeof(nodo));
    novo->dado = valor;
    novo->prox = NULL;
    if (l != NULL)
    {
        next = l;
        while (next->prox != NULL)
        {
            next = next->prox;
        }
        next->prox = novo;
    }
    else
    {
        l = novo;
    }
    return (l);
}
int profundidade(nodo *l, int valor)
{
    int cont = 0;
    nodo *n = l;
    while (n != NULL && n->dado != valor)
    {
        n = n->prox;
        cont++;
    }
    if (n = NULL)
    {
        return (-1);
    }
    else
    {
        return (cont);
    }
}
void imprime_lista(nodo *l)
{
    nodo *n;
    n = l;

    while (n != NULL)
    {
        printf("%d ", n->dado);
        n = n->prox;
    }
}
nodo *inicializa()
{
    return (NULL);
}
int conta_nos(nodo *l)
{
    int cont = 0;
    nodo *n = l;
    while (n != NULL)
    {

        n = n->prox;
        cont++;
    }
    return (cont);
}
nodo *libera_lst(nodo *l)
{
    nodo *alok;
    alok = l;
    while (alok != NULL)
    {
        nodo *aux = alok->prox;

        free(alok);
        alok = aux;
    }
    return (l);
}
nodo *busca_rmv(nodo *l, int valor)
{
    nodo *n = l;
    nodo *alok = NULL;
    while (n != NULL && n->dado != valor)
    {
        alok = n;
        n = n->prox;
    }
    if (n == NULL)
    {
        printf("Este valor nao pertence a essa lista\n");
        return (l);
    }
    else
    {
        if (alok == NULL)
        {
            l = n->prox;
        }
        else
        {
            alok->prox = n->prox;
        }
        free(n);
    }
    return (l);
}
void menu()
{
    printf("\n\n");
    printf("|             !ATENCAO!              |\n");
    printf("|INICIALIZE A LISTA ANTES DE ALTERAR |\n");
    printf("|____________________________________|\n");
    printf("|           MENU DE OPCOES           |\n");
    printf("|------------------------------------|\n");
    printf("| 1 - Inicializar lista              |\n");
    printf("| 2 - Adicionar valor na lista       |\n");
    printf("| 3 - Achar posicao do valor na lista|\n");
    printf("| 4 - Imprimir lista                 |\n");
    printf("| 5 - Quantidade de nos na lista     |\n");
    printf("| 6 - Remover no da lista            |\n");
    printf("| 7 - Limpar lista completamente     |\n");
    printf("| 0 - SAIR                           |\n");
    printf("|------------------------------------|\n");
}
