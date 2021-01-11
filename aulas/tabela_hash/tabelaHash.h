struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct hash Hash;
Hash* criaHash (int TABLE_SIZE);
void liberaHash (Hash* ha);
int valorString (char *str); // Converte string para um valor 
int insereHash_semColisao (Hash* ha,  struct aluno al);
int buscaHash_semColisao (Hash* ha, int mat, struct aluno* al);
int insereHash_EnderAberto (Hash* ha, struct aluno al);
int buscaHash_EnderAberto (Hash* ha, int mat, struct aluno* al);


