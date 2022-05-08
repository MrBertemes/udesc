#include <stdio.h>
#include <stdlib.h>
#include "lse.h"
void main()
{
    nodo *lista;
    int entrada = 1;
    while (entrada != 0)
    {
        menu();
        scanf("%d", &entrada);

        switch (entrada)
        {
        case 0:; //fechar programa
            entrada = 0;
            printf("Fechando programa, obrigado por usar!\n");
            lista = libera_lst(lista);
            break;
        case 1: //inicializar lista
            printf("Inicializando lista...\n");
            lista = inicializa();
            printf("Lista inicializada!\n");
            break;
        case 2:; //add valor na lista no fim mas no começo caso seja vazia...
            int desejo;
            printf("Entre com o valor de nodo que deseja colocar na lista\n");
            scanf("%d", &desejo);
            lista = insere_fim(lista, desejo);
            break;
        case 3:; //achar valor na lista e falar sua posição
            int achar, achado;
            printf("Entre com o valor que deseja achar na lista\n");
            scanf("%d", &achar);
            achado = profundidade(lista, achar);
            printf("A posição de %d é: %d\n", achar, achado);
            break;
        case 4: //imprimir lista
            printf("Imprimindo lista:\n");
            imprime_lista(lista);
            break;
        case 5:; //contar nos
            int nos;
            printf("Contando os nos...\n");
            nos = conta_nos(lista);
            printf("A lista cadastrada tem %d no(s)\n", nos);
            break;
        case 6:; //remover no
            int normv;
            printf("Por favor entre com o valor do no que deseja retirar\n");
            imprime_lista(lista);
            printf("\n");
            scanf("%d", &normv);
            busca_rmv(lista, normv);
            break;

        case 7: //limpar lista voluntariamente
            printf("limpando lista\n");
            lista = libera_lst(lista);
            printf("lista limpa por favor inicialize uma nova caso queira continuar\n");
            break;
        default:
            printf("Por favor entre com um valor valido!\n");
            break;
        }
    }
}