#include <stdio.h>
#include <stdlib.h>
#include "lde.h"
void main()
{
    int escolha, numero, lugar, posicao;
    nodo *lista;

    do
    {
        menu();
        scanf("%d", &escolha);
        switch (escolha)
        {

        case 1:
            lista = inicializa();
            printf("Entre com o valor que deseja inserir:\n");
            scanf("%d", &numero);
            lista = inserir(lista, numero);
            break;
        case 2:
            printf("Entre com o valor que deseja achar na lista\n");
            scanf("%d", &numero);
            lugar = busca(lista, numero);
            printf("O valor %d esta na posição:%d", numero, lugar);
            break;
        case 3:
            imprime_lista(lista);
            printf("\nQual nó voce deseja remover da lista\n");
            scanf("%d", &numero);
            lista = remover(lista, numero);
            break;
        case 4:
            imprime_lista(lista);
            printf("\nEscolha a posição do numero que voce deseja atualizar\n");
            scanf("%d", &posicao);
            printf("\n Agora entre com o dado q quer adicionar no lugar dele\n");
            scanf("%d", &numero);
            lista = atualiza(lista, numero, posicao);
            break;
        default:

            break;
        }
    } while (escolha != 0);
}