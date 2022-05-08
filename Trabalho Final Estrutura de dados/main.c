
/*TRABALHO 1 - DUPLA: Henrique Klug e Paulo Henrique Goncalves*/

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(void)
{
    float valor, novo_valor;
    int op = -1, mediaMovel1, mediaMovel2, id;
    dado *lista;
    dado *aux;
    lista = inicia();

    do
    {
        printf("\n----------------MENU-----------------\n");
        printf("\n1 -> Criar novo no");
        printf("\n2 -> Remover no");
        printf("\n3 -> Atualizar no");
        printf("\n4 -> Imprimir lista de nos");
        printf("\n5 -> Calcular media movel");
        printf("\n6 -> Calcular tendencia");
        printf("\n7 -> Gerar grafico");

        printf("\n0 -> SAIR");
        printf("\nDigite: ");
        scanf("%i", &op);
        //analistar a opção do usuario
        switch (op)
        {
        case 0:
            break;
        case 1: //opção 1
            printf("\nDigite o valor do no que deseja criar: ");
            scanf("%f", &valor);
            lista = novoNo(lista, valor);
            break;
        case 2: //opção 2
            printf("\nDigite o id do no que deseja remover: ");
            scanf("%d", &id);
            lista = removeNO(lista, id);
            break;
        case 3: //opção 3
            printf("\nDigite o id do no que deseja atualizar: ");
            scanf("%d", &id);
            printf("\nDigite o novo valor deste no: ");
            scanf("%f", &novo_valor);
            lista = atualizaNo(lista, id, novo_valor);
            break;
        case 4: //opção 4
            imprimeLista(lista);
            break;
        case 5:
            printf("Qual o tempo de analise da media movel 1?\n");
            scanf("%d", &mediaMovel1);
            printf("\nQual o tempo de analise da media movel 2?\n");
            scanf("%d", &mediaMovel2);
            lista = mmn(mediaMovel1, mediaMovel2, lista);
            aux = lista;
            while (aux != NULL)
            {
                printf("Valor: %f\n", aux->valor);
                printf("Media movel 1 (%d dias):%f\n ", mediaMovel1, aux->mm1);
                printf("Media movel 2 (%d dias):%f\n ", mediaMovel2, aux->mm2);
                printf("-----------------------------------------------------\n");
                aux = aux->prox;
            }
            break;
        case 6:
            printf("Calculando tendencia\n");
            lista = tendencia(lista);
            aux = lista;
            while (aux != NULL)
            {
                if (aux->tendencia == 'Q')
                {
                    printf("Valor: %f\n", aux->valor);
                    printf("Tendencia: Queda\n");
                }
                if (aux->tendencia == 'A')
                {
                    printf("Valor: %f\n", aux->valor);
                    printf("Tendencia: Alta\n");
                }
                if (aux->tendencia == 'C')
                {
                    printf("Valor: %f\n", aux->valor);
                    printf("Tendencia: Constante\n");
                }
                aux = aux->prox;
            }
            break;
        case 7:
            printf("Gerando grafico\n");
            gerar_grafico(lista);
            break;
        default:
            break;
        }
    } while (op != 0);
    return 0;
}
