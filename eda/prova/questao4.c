#include <stdlib.h>
#include <stdio.h>
#include "questao4.h"

float calcula_media_das_medias(aluno *info)
{
    aluno *aux;
    aux = info;
    int num = 0;
    float mediaAluno;
    float mediatotal;
    while (aux != NULL)
    {
        mediaAluno = (aux->p1 + aux->p2 + aux->p3) / 3;
        aux->media = mediaAluno;
        mediatotal = mediatotal + mediaAluno;
        aux = aux->prox;
        num++;
    }
    mediatotal = mediatotal / num;
    return mediatotal;
}
void acimaDaMedia(aluno *info)
{
    aluno *aux;
    aux = info;
    float mediaDaTurma = calcula_media_das_medias(info);

    while (aux != NULL)
    {
        if (aux->media > mediaDaTurma)
        {
            printf("PARABENS, NOTA ACIMA DA MEDIA DA TURMA: ALUNO = %s | MATRICULA = %d | Media da turma = %.2f |MEDIA DO ALUNO = %.2f\n", aux->nome, aux->matricula, mediaDaTurma, aux->media);
        }
        aux = aux->prox;
    }
}