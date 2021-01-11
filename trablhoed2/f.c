#include<stdio.h>
#include <stdlib.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B);}

int separa (long int *v, int l, int r);
void quickSelect (long int *v, int l, int r, int k);
void quickSortM3 (long int *v, int l, int r);

int main(void){
    
    int qtdeProdutos, pagina, produtosPagina;
    int i, aux, k; // Indice procurado
    long int id;

    scanf ("%d %d %d", &qtdeProdutos, &pagina, &produtosPagina);

    long int *idsProdutos = malloc (qtdeProdutos * sizeof(long int));
    
    for (i = 0; i < qtdeProdutos; i++){
        scanf ("%ld", &id);
        idsProdutos[i] = id;
    }

    k = pagina * produtosPagina;
    aux = k + produtosPagina - 1;

    quickSelect (idsProdutos, 0, qtdeProdutos-1, k);
    
    while (aux > k){
        if (aux < qtdeProdutos){
            quickSelect (idsProdutos, k, qtdeProdutos-1, aux);
            break;
        }
        else
            aux--;
    }

    quickSortM3 (idsProdutos, k, aux);
    
    for (int i = k; i <= aux; i++) printf("%ld\n",idsProdutos[i]);

    return 0;
}

int separa(long int *v, int l, int r){

    int pivo = v[r];
    int j = l;

    for (int k = l; k < r; k++){
        if (lesseq(v[k], pivo)){
        exch (v[k], v[j]);
        j++;
        }   
    }
    exch(v[j],v[r]);

    return j;
}

void quickSelect (long int *v,  int l,  int r,  int k){

    int i;

    if (r <= l) return;

    i = separa (v, l, r);

    if (i > k ) quickSelect (v,l, i-1, k);
    if (i < k ) quickSelect (v, i+1, r, k);  
}


void quickSortM3 (long int *v,int l, int r){
  
    if (r<=l) return;

    cmpexch (v[(l+r)/2], v[r]);
    cmpexch (v[l], v[(l+r)/2]);
    cmpexch (v[r], v[(l+r)/2]);

  int j = separa (v, l, r);
  quickSortM3 (v, l, j-1);
  quickSortM3 (v, j+1, r);
}