#include <stdio.h>
#include <stdlib.h>
#include "lde.h"
nodo *inserir_inic(nodo *lista, int valor)
{
    nodo *new;
    new = (nodo *)malloc(sizeof(nodo));
    new->dado = valor;
    new->ant = NULL;
    new->prox = lista;
    if (new->prox != NULL)
    {
        new->prox->ant = new;
    }
    return (new);
}
nodo *inserir_fim(nodo *lista, int valor)
{
    nodo *l, *new;
    new = (nodo *)malloc(sizeof(nodo));
    l = lista;
    new->dado = valor;
    new->prox = NULL;
    if (l != NULL)
    {
        while (l->prox != NULL)
        {
            l = l->prox;
        }
        l->prox = new;
        new->ant = l;
        new->ant->prox = new;
    }
    else
    {
        lista = new;
    }

    return (lista);
}
nodo *inserir(nodo *lista, int valor)
{
    nodo *l, *new, *aux;
    new = (nodo *)malloc(sizeof(nodo));
    aux = NULL;
    new->dado = valor;
    new->prox = NULL;
    new->ant = NULL;
    l = lista;

    while (l != NULL && l->dado < new->dado)
    {
        aux = l;
        l = l->prox;
    } //1 2 4 5
    if (aux == NULL)
    {
        lista = inserir_inic(lista, valor);
    }
    if (l == NULL)
    {
        lista = inserir_fim(lista, valor);
    }

    else
    {
        new->prox = l;
        new->ant = aux;
        l->ant = new;
        aux->prox = new;
    }

    return (lista);
}
int busca(nodo *lista, int valor)
{
    int cont = 1;
    nodo *l;
    l = lista;
    while (l->prox != NULL && l->dado != valor)
    {
        l = l->prox;
        cont++;
    }

    if (l == NULL)
    {
        return (-1);
    }
    else
    {
        return (cont);
    }
}
nodo *atualiza(nodo *lista, int novo, int posicao)
{
    nodo *l;
    l = lista;
    if (l != NULL)
    {
        for (int i = 1; i < posicao; i++)
        {
            l = l->prox;
        }
        l->dado = novo;
    }
    else
    {
        return (l);
    }
    return (l);
}
nodo *remover(nodo *l, int alvo)
{
    nodo *p = l;
    while (p != NULL && p->dado != alvo)
    {
        p = p->prox;
    }
    if (p == NULL)
    {
        printf("\nvalor nao encontrado!\n");
        return l;
    }
    else
    {
        if (p->ant == NULL)
        {
            l = p->prox;
            l->ant = NULL;
        }
        else
        {
            p->ant->prox = p->prox;
            if (p->prox != NULL)
            {
                p->prox->ant = p->ant;
            }
        }
        free(p);
    }
    return l;
}
void menu()
{
    printf("\n\n");
    printf("|             !ATENCAO!              |\n");
    printf("|____________________________________|\n");
    printf("|           MENU DE OPCOES           |\n");
    printf("|------------------------------------|\n");
    printf("| 1 - Adicionar valor na lista       |\n");
    printf("| 2 - Achar posicao do valor na lista|\n");
    printf("| 3 - Remover no da lista            |\n");
    printf("| 4 - Atualizar valor da lista       |\n");
    printf("| 0 - SAIR                           |\n");
    printf("|------------------------------------|\n");
}
nodo *inicializa()
{
    nodo *lista = NULL;
    return (lista);
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