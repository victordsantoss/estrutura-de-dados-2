#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int conteudo;
    struct celula *prox;
} celula;

void criaPilha (celula *pilha);
void empilha (celula *topo, int novoConteudo);
int desempilha (celula *topo);

int main (){

    int *vetor;
    int num, contador = 0, limiteDaSoma, soma = 0, impressao, contadorAux = 0;
    celula *p = malloc (sizeof (celula));

    criaPilha (p);

    vetor = malloc (1000 * sizeof (int));

    while (1){
        scanf ("%d", &num);
        if (num == 0)
            break;
        vetor[contador] = num;
        contador++;
    }

    scanf ("%d", &limiteDaSoma);

    for (int i = 0; i < contador; i++){
        soma += vetor[i];
        if (soma > limiteDaSoma){
            empilha (p, vetor[i]);
            contadorAux++;
            soma = 0;
        }
    }
    for (int i = 0; i < contadorAux; i++){
        printf ("%d\n", desempilha (p));
    }

    return 0;
}

void criaPilha (celula *pilha){
    pilha = malloc(sizeof (celula));
    pilha->prox = NULL;
}

void empilha (celula *topo, int novoConteudo){
    celula *nova;
    nova = malloc (sizeof (celula));
    nova->prox = topo->prox;
    topo->prox = nova;
    nova->conteudo = novoConteudo;
}

int desempilha (celula *topo){
    celula *lixo = topo->prox;
    int aux = lixo->conteudo;
    topo->prox = lixo->prox;
    free (lixo);
    return aux;
}