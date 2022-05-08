typedef struct no nodo;
struct no
{
    nodo *ant;
    int dado;
    nodo *prox;
};
nodo *inserir(nodo *lista, int valor); //insere o numero no fim da lista
nodo *inserir_fim(nodo *lista, int valor);
nodo *inserir_inic(nodo *lista, int valor);
int busca(nodo *lista, int valor);
nodo *atualiza(nodo *lista, int novo, int posicao);
nodo *remover(nodo *l, int alvo);
void menu();
nodo *inicializa();
void imprime_lista(nodo *l);
