#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tabelaHash.h"

int p = 262139;
int a = 157223;
int b = 95412;

// Definição do tipo Hash
struct hash{
    int qtd, TABLE_SIZE;
    struct aluno ** itens;
};

// Criação da Tabela Hash
Hash* criaHash (int TABLE_SIZE){
    Hash* ha = (Hash*) malloc (sizeof (Hash));

    if (ha != NULL){
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct aluno**) malloc(TABLE_SIZE * sizeof(struct aluno*));

        if (ha->itens == NULL){
            free(ha);
            return NULL;
        }
        ha->qtd = 0; // quantidade de itens na tabela
        
        for (i = 0; i < ha->TABLE_SIZE; i++)
            ha->itens[i] = NULL;
    }
    printf ("Tabela Criada com sucesso!\n");
    return ha;
}

// Liberação de memória
void liberaHash (Hash *ha){
    if (ha != NULL){

        int i;
        for (i = 0; i < ha->TABLE_SIZE; i++){
            if (ha->itens[i] != NULL)
                free(ha->itens[i]);
        }
        free(ha->itens);
        free(ha);
    }
    printf ("Tabela Destruida com sucesso!\n");
}

// Transforma um caracter char em valor inteiro 
int valorString (char *str){
    int i, valor = 7;
    int tam = strlen(str);

    for (i = 0; i < tam; i++){
        valor = 31*valor+(int)str[i];
        printf ("%d ", valor);
    }

    return valor;
}

// Função Hashing de multiplicação
int chaveMul (int chave, int TABLE_SIZE){
    float a = 0.6180339887;
    float val = chave * a;
    val = val - (int)val;
    return (int)(TABLE_SIZE * val);
}

// Função Hashing Universal 
int hashUnivesal (int a, int b, int k, int TABLE_SIZE, int p){
    return ((a * k + b) % p) % TABLE_SIZE;
}   

// Inserção sem tratamento de colisão
int insereHash_semColisao (Hash* ha, struct aluno al){

    if(ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;

    int chave = al.matricula;
    // int chave = valorString(al.nome);

    int pos = hashUnivesal (a, b, chave, ha->TABLE_SIZE, p);
    // int pos = chaveMul(chave, ha->TABLE_SIZE);
    printf ("Posição na Hash: %d ", pos);
    struct aluno* novo;

    novo = (struct aluno*) malloc(sizeof( struct aluno));

    if (novo == NULL)
        return 0;

    *novo = al;
    ha->itens[pos] = novo;
    ha->qtd++;
    return 1;
}

// Busca sem tratamento de colisão
int buscaHash_semColisao (Hash* ha, int mat, struct aluno* al){

    if (ha == NULL)
        return 0;

    int pos = hashUnivesal (a, b, mat, ha->TABLE_SIZE, p);
    // int pos = chaveMul(mat, ha->TABLE_SIZE);

    if (ha->itens[pos] == NULL)
        return 0;

    struct aluno aux;

    aux = *(ha->itens[pos]);

    if (aux.matricula = al->matricula)
        return 1;
    else 
        return 0;
}

// Tratamento de colisões 
int sondagemLinear(int pos, int i, int TABLE_SIZE){
    return ((pos + i) & 0x7FFFFFFF) & TABLE_SIZE;
}

int sondagemQuadratica(int pos, int i, int TABLE_SIZE){
    pos = pos + 2*i + 5*i*i;
    return (pos & 0x7FFFFFFF) % TABLE_SIZE;
}

// Implementação da função de Duplo Hash para evitar possiveis colisões 
int duploHash (int h1, int chave, int i, int TABLE_SIZE){
    int h2 = chaveMul (chave, TABLE_SIZE-1) + 1;
    return ((h1 + i*h2) & 0x7FFFFFFF) % TABLE_SIZE;
}

// Inserção com tratamento de colisões
int insereHash_EnderAberto (Hash* ha, struct aluno al){

    if (ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;

    int chave = al.matricula;
    int i, pos, newPos;

    pos = chaveMul(chave, ha->TABLE_SIZE);

    for (i = 0; i < ha->TABLE_SIZE; i++){
        newPos = sondagemLinear (pos, i, ha->TABLE_SIZE);
        if (ha->itens[newPos] == NULL){
            struct aluno* novo;
            novo = (struct aluno*) malloc (sizeof(struct aluno));

            if (novo == NULL)
                return 0;

            *novo = al;
            ha->itens[newPos] = novo;
            ha->qtd++;
            printf ("Posição na Hash: %d", pos);
            return 1;
        }
    }
    return 0;
}

// Busca com tratamento de colisões na forma de Endereçamento Aberto
int buscaHash_EnderAberto (Hash* ha, int mat, struct aluno* al){

    if (ha == NULL)
        return 0;

    int i, pos, newPos;

    pos = chaveMul (mat, ha->TABLE_SIZE);

    for (i = 0; i < ha->TABLE_SIZE; i++){
        newPos = sondagemLinear(pos, i, ha->TABLE_SIZE);

        if (ha->itens[newPos] == NULL)
            return 0;
        if (ha->itens[newPos]->matricula == mat){
            *al = *(ha->itens[newPos]);
            return 1;
        }
    }
    return 0;

}

