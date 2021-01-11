#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
    char cidade[27];
    struct celula *prox;
} celula;

celula *inicializa (){
    celula *f = malloc (sizeof (celula));
    f->prox = NULL;
    return f;
}

celula *insere (celula* l, char word[], int size){
    celula *nova = malloc (sizeof (celula));
    int i;
    for (i = 0; i < size; i++) {
        nova->cidade[i] = word[i];
    }
    nova->cidade[size] = '\0';
    nova->prox = NULL;

    if (l == NULL)
        return nova;

    celula* aux = l;
    while (aux->prox != NULL)
        aux = aux->prox;
    aux->prox = nova;
    return l;
}

void reorganiza (celula *l){
    
  
}

void imprime (celula* l){
    while (l != NULL){
        printf ("%s\n", l->cidade);
        l = l->prox;
    }
}

int main (){

    celula *f;
    char cidades[27];

    f = inicializa ();

    while (scanf ("%s", cidades) != EOF)
        f = insere (f, cidades, strlen (cidades));

    reorganiza (f);

    imprime (f);

    return 0; 
}