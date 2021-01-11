#include <stdio.h>
#include <stdlib.h>

typedef int item;
#define key(a) (a)
#define less(a,b) (key(a) < key(b))
#define exch(a,b) {item t = a; a = b; b = t;}

#define tam 15

typedef struct semente{
    int codigo;
    int nota;
}semente;

void troca (semente *v, int l, int r);
void quickSelect (semente *v, int l, int r, int k);
int separa (semente *v, int l, int r);
void mergeSort (semente *v, int l, int r);
void mergeSemente (semente *v, int l, int r, int k);

int main (void){

    int qtdeSementes;
    int contador = 0;
    semente *vetorSemente = malloc(sizeof(semente));

    scanf ("%d", &qtdeSementes);

    while (scanf ("%d %d", &vetorSemente[contador].codigo, &vetorSemente[contador].nota) != EOF){
        contador++;
        vetorSemente = realloc (vetorSemente, (contador+tam) * sizeof(semente));
    }

    quickSelect (vetorSemente, 0, contador-1, qtdeSementes);
    mergeSort (vetorSemente, 0, qtdeSementes);

    for (contador = 0; contador < qtdeSementes; contador++) printf ("%d %d\n", vetorSemente[contador].codigo, vetorSemente[contador].nota);
    
    free(vetorSemente);

    return 0;
}

void troca (semente *v, int l, int r){
    semente tmp; 
    tmp = v[r];
    v[r] = v[l];
    v[l] = tmp;
}

void quickSelect (semente *v, int l, int r, int k){

    int mediana, i;

    // Cálculo da Mediana
    mediana = (r+l)/2;

    if (v[l].codigo < v[r].codigo) troca (v, r, l);
    if (v[mediana].codigo < v[l].codigo) troca (v, mediana, l);
    if (v[r].codigo < v[l].codigo) troca (v, l, r);

    i = separa (v, l, r);

    if (i == k) return;

    if (i < k) quickSelect (v, i+1, r, k);
    else quickSelect (v, l, i-1, k);
}

int separa (semente *v, int l, int r){

    semente tmp;
    int i;
    int k = l;

    int *vetTemporario = malloc (tam * sizeof (int));

    vetTemporario[1] = v[r].nota;
    vetTemporario[2] = v[r].codigo;

    for (i = l; i < r; i++){
        if (v[i].nota <= vetTemporario[1]){
            if (v[i].nota == vetTemporario[1]){
                if (v[i].codigo < vetTemporario[2]){
                    troca (v, i, k);
                    k++;
                }
            }
            else {
                troca (v, i, k);
                k++;
            }
        }
    }
    free(vetTemporario);
    troca (v, r, k);
    return k;
}

void mergeSort (semente *v, int l, int r){

    int mediana;

    if (l < r-1){
        mediana = (l+r)/2;
        mergeSort (v, l, mediana);
        mergeSort (v, mediana, r);
        mergeSemente (v, l, r, mediana); 
    }
}

void mergeSemente (semente *v, int l, int r, int k){

    int i, a, b;
    semente *vetTemporario = malloc ((r-l) * sizeof(semente));

    i = 0;
    a = l;
    b = k;

    while (b < r && a < k){
        if (v[a].codigo <= v[b].codigo){
            vetTemporario[i] = v[a];
            a++;
            i++;
        }else{
            vetTemporario[i] = v[b];
            b++;
            i++;
        }
    } 

    while (a < k){
        vetTemporario[i] = v[a];
        a++;
        i++;
    }

    while (b < r){
        vetTemporario[i] = v[b];
        b++;
        i++;
    }

    for (a = l; a < r; a++) v[a] = vetTemporario[a-l];

    free(vetTemporario);
}
