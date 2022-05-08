typedef struct no aluno;
struct no
{
    aluno *ant;
    int matricula;
    char nome[100];
    float p1;
    float p2;
    float p3;
    float media;
    aluno *prox;
};
float calcula_media_das_medias(aluno *info);
void acimaDaMedia(aluno *info);