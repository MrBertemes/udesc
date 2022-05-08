#include <stdio.h>
#include <stdlib.h>
#incluse "questao3.h"

int calcular(celula *lista, int id)
{
    celula *p = lista;
    int aux = 0;
    while (p != NULL)
    {
        if (p->chefe->id == id)
        {
            aux = 1;
            return (1 + (calcular(lista, p->id)));
        }
        p = p->prox;
    }
    if (aux == 0)
    {
        return (0);
    }
}
