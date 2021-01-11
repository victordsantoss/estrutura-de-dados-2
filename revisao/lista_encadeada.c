#include <stdio.h>
#include <stdlib.h>

typedef struct lista_encadeada{
    int dado;
    struct lista_encadeada *prox;
}celula;

celula *inicia_celula ();
void insere_elemento (celula *le, int novo_elemento);
void insere_em_qualquer_pos (celula *le, int novo_elemento, int pos);
void busca_e_insere (celula *le, int novo_elemento, int sucessor);
celula *busca_elemento (celula *le, int elemento_buscado);
void busca_e_remove (celula *le, int elemento);
void remove_primeiro_elemento (celula *le);
void imprime_lista (celula *le);
void destroi_lista (celula *le);

int main (){

    int dado, pos, sucessor;

    // Iniciando Lista Encadeada 
    celula *le;
    celula *p;
    le = inicia_celula ();

    // Inserindo Elemento um após o outro
    printf ("Digite os valores para serem inseridos: ");
    while (scanf ("%d", &dado) != EOF)
        insere_elemento (le, dado);

    // Imprimindo elementos da lista
    imprime_lista (le);

    // Inserindo elemento na lista em uma posição específica
    printf ("Digite o valor a ser inserido: ");
    scanf ("%d", &dado);
    printf ("Insira a posição que o elemento será inserido: ");
    scanf ("%d", &pos);
    insere_em_qualquer_pos (le, dado, pos);
    imprime_lista (le);

    // Inserindo elemento antes de um determinado sucessor
    printf ("Digite o valor a ser inserido: ");
    scanf ("%d", &dado);
    printf ("Insira o sucessor ao elemento que será inserido: ");
    scanf ("%d", &sucessor);
    busca_e_insere (le, dado, sucessor);
    imprime_lista (le);
    
    // Buscando elemento na lista
    printf ("Digite o dado a ser buscado: ");
    scanf ("%d", &dado);
    p = busca_elemento (le, dado);
    if (p->dado == dado)
        printf ("O elemento %d foi encontrado na lista!\n", p->dado);    
    else
        printf ("O elemento %d não foi encontrado na lista!\n", dado);

    // Buscando e removendo elemento específico da lista
    printf ("Digite o dado a ser removido: ");
    scanf ("%d", &dado);
    busca_e_remove (le, dado);
    printf ("Removendo o elemento %d: ", dado);
    imprime_lista (le);

    // Removendo primeiro Elemento
    printf ("Removendo primeiro elemento da lista: ");
    remove_primeiro_elemento (le);
    imprime_lista (le);

    // Destruindo Lista
    destroi_lista (le);

    return 0;
}

celula *inicia_celula (){
    celula *le = malloc (sizeof(celula));
    le->prox = NULL;
    printf ("Lista Encadeada iniciada com Sentinela (Nó Cabeça)\n");

    return le;
}

void insere_elemento (celula *le, int novo_dado){
    celula *nova_celula = malloc (sizeof(celula));

    if (nova_celula == NULL)
        exit (EXIT_FAILURE);

    while (le->prox != NULL)
        le = le->prox;

    nova_celula->dado = novo_dado;
    nova_celula->prox = le->prox;
    le->prox = nova_celula;
}

void insere_em_qualquer_pos (celula *le, int novo_elemento, int pos){
    celula *nova_celula = malloc (sizeof (celula));
    celula *aux = le;
    int contador = 1;

    if (nova_celula == NULL)
        exit (EXIT_FAILURE);

    // Caso a posição passada seja maior que a quantidade de elementos na lista, o elemento é inserido no final. 
    while (contador < pos){
        aux = aux->prox;
        contador++;
        if (aux->prox == NULL)
            break;
    }
    
    nova_celula->dado = novo_elemento;
    nova_celula->prox = aux->prox;
    aux->prox = nova_celula;
}

void busca_e_insere (celula *le, int novo_elemento, int sucessor){
    /*Essa função insere uma nova célula imediatamente antes do sucessor,
    caso não encontre-o, a célula será inserida no final*/

    celula *aux, *aux2, *nova_celula;
    nova_celula = malloc (sizeof(celula));  

    if (nova_celula == NULL)
        exit (EXIT_FAILURE);

    aux = le;
    aux2 = le->prox;

    while (aux2 != NULL && aux2->dado != sucessor){
        aux = aux2;
        aux2 = aux2->prox;
    }
    nova_celula->dado = novo_elemento;
    nova_celula->prox = aux2;
    aux->prox = nova_celula;
}

celula *busca_elemento (celula *le, int elemento_buscado){
    for (le = le->prox; le->prox != NULL && le->dado != elemento_buscado; le = le->prox);
    return le;
}

void busca_e_remove (celula *le, int elemento){
    celula *aux, *aux2;
    aux = le; 
    aux2 = le->prox;

    while (aux2 != NULL && aux2->dado != elemento){
        aux = aux2;
        aux2 = aux2->prox;
    }   
    if (aux2 != NULL){
        aux->prox = aux2->prox;
        free (aux2);
    }
}

void remove_primeiro_elemento (celula *le){
    int dado;
    celula *lixo = le->prox;
    if (le->prox != NULL){
        le->prox = lixo->prox;
        dado = lixo->dado;
        free (lixo);
    } 
}

void imprime_lista (celula *le){
    celula *p = le->prox;

    if (p == NULL)
        printf ("[]->NULL\n");
    else{
        while (p != NULL){
            printf ("%d->", p->dado);
            p = p->prox;
        }
        printf ("NULL\n");
    }
}

void destroi_lista (celula *le){
    celula *aux;
    for (aux = le->prox; aux != NULL; aux = aux->prox)
        free (aux);
}