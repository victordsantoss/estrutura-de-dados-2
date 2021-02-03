#include <stdio.h>
#include <stdlib.h>

struct numeros{
    int num;
};

int p = 262139;
int a = 157223;
int b = 95412;

typedef struct hash{
    int qtd, TABLE_SIZE;
    struct numeros ** itens;
}Hash;

Hash* criaHash (int TABLE_SIZE){
    Hash* ha = (Hash*) malloc (sizeof (Hash));

    if (ha != NULL){
        int i;
        ha->TABLE_SIZE = TABLE_SIZE;
        ha->itens = (struct numeros**) malloc(TABLE_SIZE * sizeof(struct numeros*));

        if (ha->itens == NULL){
            free(ha);
            return NULL;
        }
        ha->qtd = 0; 
        
        for (i = 0; i < ha->TABLE_SIZE; i++)
            ha->itens[i] = NULL;
    }
    return ha;
}

int hashUnivesal (int a, int b, int k, int TABLE_SIZE, int p){
    return ((a * k + b) % p) % TABLE_SIZE;
}

int chaveMul (int chave, int TABLE_SIZE){
    float a = 0.6180339887;
    float val = chave * a;
    val = val - (int)val;
    return (int)(TABLE_SIZE * val);
}

int sondagemQuadratica(int pos, int i, int TABLE_SIZE){
    pos = pos + 2*i + 5*i*i;
    return (pos & 0x7FFFFFFF) % TABLE_SIZE;
}

int duploHash (int h1, int chave, int i, int TABLE_SIZE){
    int h2 = chaveMul (chave, TABLE_SIZE-1) + 1;
    return ((h1 + i*h2) & 0x7FFFFFFF) % TABLE_SIZE;
}

int insereHash_EnderAberto (Hash* ha, struct numeros al){

    if (ha == NULL || ha->qtd == ha->TABLE_SIZE)
        return 0;

    int chave = al.num;
    int i, pos, newPos;

    pos = hashUnivesal(a, b, chave, ha->TABLE_SIZE, p);

    for (i = 0; i < ha->TABLE_SIZE; i++){
        int a;
        a = sondagemQuadratica (pos, i, ha->TABLE_SIZE);
        newPos = duploHash (a, chave, i, ha->TABLE_SIZE);
        if (ha->itens[newPos] == NULL){
            struct numeros* novo;
            novo = (struct numeros*) malloc (sizeof(struct numeros));

            if (novo == NULL)
                return 0;

            *novo = al;
            ha->itens[newPos] = novo;
            ha->qtd++;
            return 1;
        }
    }
    return 0;
}

int buscaHash_EnderAberto (Hash* ha, int mat, struct numeros* al){

    if (ha == NULL)
        return 0;

    int i, pos, newPos;

    pos = hashUnivesal(a, b, mat, ha->TABLE_SIZE, p);

    for (i = 0; i < ha->TABLE_SIZE; i++){
        int a;
        a = sondagemQuadratica (pos, i, ha->TABLE_SIZE);
        newPos = duploHash (a, mat, i, ha->TABLE_SIZE);

        if (ha->itens[newPos] == NULL)
            return 0;
        if (ha->itens[newPos]->num == mat){
            *al = *(ha->itens[newPos]);
            return 1;
        }
    }
    return 0;

}

int main (){

    Hash* ha = criaHash(262139);
    int n;

    struct numeros al;

    scanf ("%d", &n);

    for (int i = 0; i < n; i++){
        int num;
        scanf ("%d", &num);
        al.num = num;
        insereHash_EnderAberto (ha, al);
    }

    int c;

    while (scanf ("%d", &c) == 1){
        if (buscaHash_EnderAberto(ha, c, &al))
            printf ("sim\n");
        else
            printf("nao\n");
    }
    return 0;
}