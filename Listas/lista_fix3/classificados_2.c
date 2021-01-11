#include <stdio.h>
#include <stdlib.h>

typedef int item;
#define key(a) (a)
#define less(a,b) (key(a) < key(b))

#define exch(a,b) {item t = a; a = b; b = t;}
#define cmpexch(a,b) {if (less(b,a)) exch(a,b);}
#define tam_max 10000000

typedef struct semente{
    long long int codigo;
    long long int nota;
}semente;

semente vetor_semente[tam_max];

int separa (semente *v, int l, int r);
void quick_select (semente *v, int l, int r, int k);
void insertion_sort_codigo (semente *vetor_final, int n);

int main (){

    int qtde_sementes, i = 0;
    long long int codigo, nota; 


    scanf ("%d", &qtde_sementes);
    
    while (scanf ("%lld", &codigo) != EOF){
        vetor_semente[i].codigo = codigo;
        scanf ("%lld", &nota);
        vetor_semente[i].nota = nota;
        i++;
    }

    printf ("\n");

    if (qtde_sementes > i)
        qtde_sementes = i;

    semente vetor_final[qtde_sementes];

    quick_select (vetor_semente, 0, i-1, qtde_sementes);

    for (int j = 0; j < qtde_sementes; j++)
        vetor_final[j] = vetor_semente[j];

    insertion_sort_codigo (vetor_final, qtde_sementes);

    for (int j = 0; j < qtde_sementes; j++){
        printf ("%lld %lld\n", vetor_final[j].codigo, vetor_final[j].nota);
    }
    return 0;
}

void quick_select (semente *v, int l, int r, int k){

    int i;

    if (r <= l)
        return;

    i = separa (v, l, r);

    if (i > k)
        quick_select (v, l, i-1, k);
    if (i < k)
        quick_select (v, i+1, r, k);
}

int separa (semente *v, int l, int r){

    int pivo_nota = v[r].nota;
    int pivo_codigo = v[r].codigo;

    int j = l;

    for (int k = l; k < r; k++)
        if (less(v[k].nota, pivo_nota) || v[k].nota == pivo_nota && v[k].codigo < pivo_codigo ){
            exch (v[k].nota, v[j].nota);
            exch (v[k].codigo, v[j].codigo);
            j++;
        }
        exch (v[j].nota, v[r].nota);
        exch (v[j].codigo, v[r].codigo);

    return j;
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

