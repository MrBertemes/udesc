typedef struct funcionario celula;

struct funcionario
{
    int id;
    celula *chefe;
    celula *prox;
};

int calcular(celula *lista, int id);