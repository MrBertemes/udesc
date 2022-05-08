
/*TRABALHO 1 - DUPLA: Henrique Klug e Paulo Henrique Goncalves*/

typedef struct nodo dado;

//dado == cada nodo da lista contendo o valor para calculo da media movel
// valor == o valor dentro do dado

struct nodo
{
    dado *ant;
    int id;
    float valor;
    float mm1;
    float mm2;
    char tendencia;
    dado *prox;
};

dado *novoNo(dado *lista, float valor);
dado *removeNO(dado *lista, float valor);
dado *atualizaNo(dado *lista, float valor, float novo_valor);
void imprimeLista(dado *lista);
dado *inicia();
dado *mmn(int mediamovel1, int mediamovel2, dado *lista);
dado *tendencia(dado *lista);
void gerar_grafico(dado *lista);
