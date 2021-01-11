#include <stdio.h>
#include <stdlib.h>

typedef int item;
#define key(a) (a)
#define less(a,b) (key(a) < key(b))
#define exch(a,b) {item t = a; a = b; b = t;}
#define cmpexch(a,b) {if (less(b,a)) exch(a,b);}

typedef struct semente{
    int codigo;
    int nota;
}semente;

semente vetor_semente[1000000];
semente vetor_final[10000000];

void insertion_sort_nota (semente *vetor_semente, int n);
void insertion_sort_codigo (semente *vetor_final, int n);

int main (){

    int qtde_sementes, codigo, nota, i = 0, contador = 0;

    scanf ("%d", &qtde_sementes);
    
    while (scanf ("%d", &codigo) != EOF){
        vetor_semente[i].codigo = codigo;
        scanf ("%d", &nota);
        vetor_semente[i].nota = nota;
        i++;
    }
    
    printf ("\n");

    insertion_sort_nota (vetor_semente, i);

    for (int j = 0; j < i; j++){
        if (j < qtde_sementes || vetor_semente[j].nota <=  vetor_semente[0].nota){
            vetor_final[j] = vetor_semente[j];
            contador++;
        }
    }

    insertion_sort_codigo (vetor_final, contador);

    for (int j = 0; j < qtde_sementes; j++){
        printf ("%d %d\n", vetor_final[j].codigo, vetor_final[j].nota);
    }
    return 0;
}

void insertion_sort_nota (semente *vetor_semente, int n){
    int i, j;
    semente aux;

    for (i = 1; i < n; i++){
        aux = vetor_semente[i];
        for (j = i; (j>0) && (aux.nota<vetor_semente[j-1].nota); j--)
            vetor_semente[j] = vetor_semente[j-1];
        vetor_semente[j] = aux;
    }
}

void insertion_sort_codigo (semente *vetor_final, int n){
    int i, j;
    semente aux;

    for (i = 1; i < n; i++){
        aux = vetor_final[i];
        for (j = i; (j>0) && (aux.codigo<vetor_final[j-1].codigo); j--)
            vetor_final[j] = vetor_final[j-1];
        vetor_final[j] = aux;
    }
}