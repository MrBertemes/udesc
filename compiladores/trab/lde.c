#include <stdio.h>
#include <stdlib.h>
#include "lde.h"

nodo * inicializa(int id){

    nodo *l;
    l = (nodo *)malloc(sizeof(nodo));
    l->id = id;
    l->prox = NULL;
    l->ant = NULL;

    return l;
}

nodo * insere_nodo_fim_variavel(nodo * l, char * token){
    nodo * p;
    p = l;

    nodo * novo;
    novo = (nodo *) malloc(sizeof(nodo));
    novo->ant = NULL;
    novo->prox = NULL;
    novo->variavel = token;

    while (p->prox != NULL){
        p = p->prox;
    }

    p->prox = novo;
    novo->ant = p;

    return l;
    
}

nodo * insere_ordenado(nodo *l, int valor){
    nodo *n;
    nodo *p;

    p = l;

    n = (nodo *)malloc(sizeof(nodo));
    n->id = valor;
    n->prox = NULL;
    n->ant = NULL;

    while(p->prox != NULL && p->id < n->id){
        p = p->prox;
    }
    if(p->prox == NULL && p->id > n->id){

        
        if(p->ant != NULL){
            p->ant->prox = n;
            n->ant = p->ant;
            p->ant = n;
            n->prox = p;
        }
        else{
            n->ant = p->ant;
            p->ant=n;
            n->prox = p;
            l=n;
        }
        

    }
    else{
        if(p->prox == NULL ){
            n->ant = p;
            n->prox = p->prox;
            p->prox = n;
        }
        else{
            if(p->ant != NULL){
                p->ant->prox = n;
            }
            else{
                l=n;
            }
            n->ant = p->ant;
            n->prox = p;
            p->ant = n;
        }
    }

    return l;
}

int profundidade(nodo * l, int valor){

    int count = 0;
    nodo * p;
    p = l;

    while(p != NULL && valor != p->id){
        p = p->prox;
        count++;
    }
    if(p==NULL){
        return -1;
    }
    else{
        return (count);
    }
}

void imprime_lista(nodo *l){

    nodo * p;
    p=l;
    printf("---------\n");
    while(p != NULL ){
        printf("\n%d\n", p->id);
        p=p->prox;
    }
    printf("fim da lista\n\n");
}

int conta_nos(nodo * l){

    int count=0;
    nodo * p=l;

    while(p != NULL){
        count++;
        p=p->prox;
    }
    
    return count;
}

nodo * busca_rmv(nodo *l, int valor){

    nodo *p;
    p=l;

    while(p != NULL && p->id != valor){
       p = p->prox;
    }
    if(p == NULL){
        printf("Valor nao encontrado na lista\n");
        return l;
    }
    else{
        if(p->ant == NULL){
            l=p->prox;
            l->ant=NULL;
        }
        else{
            p->ant->prox = p->prox;
            if(p->prox != NULL){
                p->prox->ant = p->ant;
            }
        }
        free(p);
    }

    return l;
}

nodo * libera_lst(nodo *l){

    nodo *p;
    p=l;

    if(p == NULL){
        return NULL;
    }
    while(p->prox != NULL){
        p=p->prox;
        free(p->ant);
    }
    free(p);

    return NULL;
}

nodo * atualiza(nodo *l, int num_no, int valor){

    nodo *p;
    int count=0;

    p=l;

    while(p->prox != NULL && count != num_no){
        p = p->prox;
        count++;
    }
    if(p == NULL){
        printf("Nó nao encontrado\n");
    }
    else{
        p->id = valor;
    }

    return l;
}
