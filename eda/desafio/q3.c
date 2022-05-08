#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "q3.h"

nome dificilOuFacil(nome *lista)
{
    nome *l;
    l = lista;
    char nome[30];
    int aux = 0;
    scanf("%s", nome);
    for (int i = 0; i < 30; i++)
    {
        l->letra = nome[i];
        l = l->prox;
    }
    l = lista;
    while (l->prox != NULL)
    {
        if (tolower(l->letra) != ('a' || 'e' || 'i' || 'o' || 'u'))
        {
            if (tolower(l->prox->letra) == ('a' || 'e' || 'i' || 'o' || 'u'))
            {
                aux = 1;
            }
        }
        else
        {
            aux = 0;
        }
        if (aux = 0)
        {
            printf("Nome dificil");
            break;
        }
        l = l->prox;
    }
    if (aux = 1)
    {
        printf("Nome facil");
    }
}