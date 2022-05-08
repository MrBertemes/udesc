
/*TRABALHO 1 - DUPLA: Henrique Klug e Paulo Henrique Goncalves*/

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

//dado == cada nodo da lista contendo o valor para calculo da media movel
// valor == o valor dentro do dado

/*adciona um novo nodo no fim da lista(para manter a ordem por datas)*/
dado *novoNo(dado *lista, float valor)
{
    dado *novo;
    dado *l;
    l = lista;
    /*aloca uma nova struct dado para salvar o valor*/
    novo = (dado *)malloc(sizeof(dado));
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = NULL;
    /*varre a lista pra chegar no fim*/
    if (l != NULL)
    {
        while (l->prox != NULL)
        {
            l = l->prox;
        }
        /*coloca o novo dado no fim da lista*/
        l->prox = novo;
        novo->ant = l;
        novo->prox = NULL;
    }
    else
    {
        /*Se a lista e vazia so coloca o novo valor*/
        lista = novo;
    }
    return (lista);
}

/*Remove o No relativo ao valor passado*/
dado *removeNO(dado *lista, float id)
{
    dado *l;
    l = lista;
    /*Se a lista e vazia*/
    if (l == NULL)
    {
        printf("\nLISTA VAZIA!!!");
        return lista;
    }
    /*Percorre a lista ate chegar na posicao valor ou ate a ultima posicao*/
    while (l->id != id && l->prox != NULL)
    {
        l = l->prox;
    }
    if (l->id == id)
    {
        /*se estiver no fim da lista, o anterior aponta como proximo NULL*/
        if (l->prox == NULL && l->ant != NULL)
        {
            l->ant->prox = NULL;
        }
        else
        {
            /*se estiver no comeco da lista, o proximo aponta como anterior NULL e a lista aponta pro proxixo*/
            if (l->ant == NULL && l->prox != NULL)
            {
                l->prox->ant = NULL;
                lista = l->prox;
            }
            else
            {
                /*Se ele for o unico elemento da lista*/
                if (l->ant == NULL && l->prox == NULL)
                {
                    lista = NULL;
                }
                else
                {
                    /*Se estiver no meio da lista*/
                    if (l->id == id)
                    {
                        l->ant->prox = l->prox;
                        l->prox->ant = l->ant;
                    }
                }
            }
        }
        free(l);
        return (lista);
    }
    /*Se nao estiver na lista*/
    else
    {
        printf("O VALOR PASSADO NAO ESTA NA LISTA!!!");
        return (lista);
    }
}

/*Cria um No atualizado e substitui o antigo*/
dado *atualizaNo(dado *lista, float id, float novo_valor)
{
    int confere = 0;
    dado *l, *novo;
    l = lista;
    /*Se a lista e vazia*/
    if (l == NULL)
    {
        printf("\nLISTA VAZIA!!!");
        return lista;
    }
    novo = (dado *)malloc(sizeof(dado));
    novo->valor = novo_valor;
    /*Percorre a lista ate chegar na posicao valor ou ate a ultima posicao*/
    while (l->id != id && l->prox != NULL)
    {
        l = l->prox;
    }
    /*Se o valor estiver na lista*/
    if (l->id == id)
    {
        /*se estiver no fim da lista, o anterior aponta como prox o novo*/
        if (l->prox == NULL && l->ant != NULL)
        {
            l->ant->prox = novo;
            novo->ant = l->ant;
            novo->prox = NULL;
        }
        else
        {
            /*se estiver no comeco da lista, o prox aponta como ant o novo e alista aponta pro prox*/
            if (l->ant == NULL && l->prox != NULL)
            {
                l->prox->ant = novo;
                novo->prox = l->prox;
                novo->ant = NULL;
                lista = novo;
            }
            else
            {
                /*Se ele for o unico elemento da lista*/
                if (l->ant == NULL && l->prox == NULL)
                {
                    lista = novo;
                }
                /*Se estiver no meio da lista*/
                else
                {
                    l->ant->prox = novo;
                    l->prox->ant = novo;
                    novo->prox = l->prox;
                    novo->ant = l->ant;
                }
            }
        }
        free(l);
        return (lista);
    }
    /*Se nao estiver na lista*/
    else
    {
        printf("O VALOR PASSADO NAO ESTA NA LISTA!!!");
        return (lista);
    }
}

/*Imprime os valores de cada no*/
void imprimeLista(dado *lista)
{
    dado *l;
    l = lista;
    /*Se a lista e vazia*/
    if (l == NULL)
    {
        printf("\nLISTA VAZIA!!!");
    }
    /*Percorre ate o fim da lista*/
    while (l != NULL)
    {
        /*Mostra os valores de cada no*/
        printf("\nid -> %d\n", l->id);
        printf("\nvalor -> %f\n", l->valor);
        l = l->prox;
    }
}

/*Inicia uma lista do tipo dado*/
dado *inicia()
{
    dado *lista = NULL;
    return (lista);
}

dado *mmn(int mediamovel1, int mediamovel2, dado *lista)
{
    dado *l = lista;
    dado *aux = lista;
    float movel1, movel2;
    int cont = 0;
    while (l != NULL)
    {
        movel1 = 0;
        if (cont == 0)
        {
            l->mm1 = l->valor;
        }
        else
        {
            for (int i = 0; i < mediamovel1 && (aux != NULL); i++)
            {
                movel1 = aux->valor + movel1;
                aux = aux->ant;
            }
            movel1 = movel1 / mediamovel1;
            l->mm1 = movel1;
        }
        cont++;
        l = l->prox;
        aux = l;
    }

    l = lista;
    aux = lista;

    cont = 0;

    while (l != NULL)
    {
        movel2 = 0;
        if (cont == 0)
        {
            l->mm2 = l->valor;
        }
        else
        {
            for (int i = 0; i < mediamovel2 && (aux != NULL); i++)
            {
                movel2 = aux->valor + movel2;
                aux = aux->ant;
            }
            movel2 = movel2 / mediamovel2;
            l->mm2 = movel2;
        }
        cont++;
        l = l->prox;
        aux = l;
    }
    return lista;
}

dado *tendencia(dado *lista)
{
    dado *l = lista;
    int cont = 0;
    while (l != NULL)
    {
        if (cont == 0)
        {
            l->tendencia = 'C';
        }
        else
        {
            if (l->mm1 > l->mm2)
            {

                if (l->mm1 > l->ant->mm1)
                {
                    l->tendencia = 'A';
                }
                if (l->mm1 < l->ant->mm1)
                {
                    l->tendencia = 'Q';
                }
                if (l->mm1 == l->ant->mm1)
                {
                    l->tendencia = 'C';
                }
            }
            else
            {
                if (l->mm2 > l->ant->mm2)
                {
                    l->tendencia = 'A';
                }
                if (l->mm2 < l->ant->mm2)
                {
                    l->tendencia = 'Q';
                }
                if (l->mm2 == l->ant->mm2)
                {
                    l->tendencia = 'C';
                }
            }
        }
        l = l->prox;
        cont++;
    }
    return lista;
}

void gerar_grafico(dado *lista)
{

    int i = 0;
    dado *l;
    FILE *arq1, *arq2, *arq3;
    FILE *gnuplot;
    l = lista;
    if ((arq1 = fopen("dados1.dat", "w")) == NULL)
    {
        printf("ARQUIVO NAO PODE SER ABERTO \n");
        system("pause");
    }
    else
    {
        while (l != NULL)
        {
            fprintf(arq1, "%d\t%lf\n", i, l->mm1);
            l = l->prox;
            i++;
        }
    }
    i = 0;
    l = lista;
    if ((arq2 = fopen("dados2.dat", "w")) == NULL)
    {
        printf("ARQUIVO NAO PODE SER ABERTO \n");
    }
    else
    {
        while (l != NULL)
        {
            fprintf(arq2, "%d\t%lf\n", i, l->mm2);
            l = l->prox;
            i++;
        }
    }
    i = 0;
    l = lista;
    if ((arq3 = fopen("ativos.dat", "w")) == NULL)
    {
        printf("ARQUIVO NAO PODE SER ABERTO \n");
    }
    else
    {
        while (l != NULL)
        {
            fprintf(arq3, "%d\t%lf\n", i, l->valor);
            l = l->prox;
            i++;
        }
    }
    fclose(arq1);
    fclose(arq2);
    fclose(arq3);
    gnuplot = popen("gnuplot -persist", "w");
    if (gnuplot != NULL)
    {
        fprintf(gnuplot, "plot 'dados1.dat' title 'mm1' lt 17 lc 5 w lp, 'dados2.dat' title 'mm2' lt 19 lc 9 w lp, 'ativos.dat' title 'ativos' lt 26 lc -1 w line\n");
    }
}