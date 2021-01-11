#include <stdio.h>
#include <stdlib.h>

typedef struct pilha_estatica{
    int *dados;
    int topo;
    int n;
}pilha;

void cria_pilha (pilha *p, int tam);
int pilha_cheia (pilha *p);
int pilha_vazia (pilha *p);
void empilha (pilha *p, int novo_elemento);
int desempilha (pilha *p);


int main (){

    int tamanho, dado, aux;
    char opc;
    pilha *p = malloc (sizeof(pilha));

    printf ("Digite o tamanho da pilha: ");
    scanf ("%d", &tamanho);

    // Criando pilha
    cria_pilha (p, tamanho);

    // Inserindo elementos
    printf ("Digite os elementos a serem inseridos:\n");
    while (scanf ("%d", &dado) != EOF){
        empilha (p, dado);
    }

    // Removendo Elementos
    printf ("Removendo elementos: ");
    while (1){
        aux = desempilha (p);
        printf ("Saiu: %d\n", aux);
        printf ("Deseja remover mais um elemento? [S] [N]\n");
        scanf ("%s", &opc);
        if (opc != 'S' && opc != 's')
            break;
    }
    return 0;
}

void cria_pilha (pilha *p, int tam){
    p->n = tam;
    p->dados = malloc (p->n * sizeof (int));
    if (p->dados == NULL)
        exit (EXIT_FAILURE);
    printf ("A pilha de tamanho %d foi criada com sucesso!\n", tam);
    p->topo = 0;
}

int pilha_cheia (pilha *p){
    if (p->topo == p->n)
        return 1;
    return 0;
}

int pilha_vazia (pilha *p){
    if (p->topo == 0)
        return 1;
    return 0;
}

void empilha (pilha *p, int novo_elemento){
    if (pilha_cheia(p)){
        p->dados = realloc (p->dados, 2 * p->n * sizeof (int));
        if (p->dados == NULL)
            exit (EXIT_FAILURE);
        p->n *= 2;
    }
    p->dados[p->topo] = novo_elemento;
    printf ("O elemento %d foi adicionado a posição %d da Pilha!\n", novo_elemento, p->topo);
    p->topo ++;
}

int desempilha (pilha *p){
    int aux;
    if (pilha_vazia (p)){
        printf ("A pilha está vazia!\n");
        exit(1);
    }
    p->topo--;
    aux = p->dados[p->topo];
    return aux;
}
