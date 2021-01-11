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
semente vetor_final[tam_max];

int separa (semente *v, int l, int r);
void quick_select (semente *v, int l, int r, int k);
void mergeSort(semente *v, int l, int r);

int main (){

    int qtde_sementes , i = 0, contador = 0, maior;
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

    if (qtde_sementes != 0){
        quick_select (vetor_semente, 0, i-1, qtde_sementes);

        if (qtde_sementes > i)
            qtde_sementes = i;

        for (int j = 0; j < i; j++){
            if (j < qtde_sementes){
                vetor_final[j] = vetor_semente[j];
                contador++;
            }
        }

        mergeSort (vetor_final, 0, contador-1);

        for (int j = 0; j < qtde_sementes; j++){
            printf ("%lld %lld\n", vetor_final[j].codigo, vetor_final[j].nota);
        }
    }else
        printf ("\n");

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

void mergeSort(semente *v, int l, int r) {

    int i, j, k, m;
    semente *vetorTemporario; 
    
    if(l == r) return;
    m = (l + r ) / 2;

    mergeSort(v, l, m);
    mergeSort(v, m + 1, r);

    i = l;
    j = m + 1;
    k = 0;
    vetorTemporario = malloc(sizeof(int) * (r - l + 1));

    while(i < m + 1 || j  < r + 1){
        if (i == m + 1 ) { 
            vetorTemporario[k].codigo = v[j].codigo;
            vetorTemporario[k].nota = v[j].nota;
            j++;
            k++;
        }
        else{
            if (j == r + 1){
                vetorTemporario[k].codigo = v[i].codigo;
                vetorTemporario[k].nota = v[i].nota;
                i++;
                k++;
            }
            else{
                if (v[i].codigo < v[j].codigo){
                    vetorTemporario[k].codigo = v[i].codigo;
                    vetorTemporario[k].nota = v[i].nota;
                    i++;
                    k++;
                }
                else{
                    vetorTemporario[k].codigo = v[j].codigo;
                    vetorTemporario[k].nota = v[j].nota;
                    j++;
                    k++;
                }
            }
        }
    }

    for(i = l; i <= r; i++){
        v[i].codigo = vetorTemporario[i - l].codigo;
        v[i].nota = vetorTemporario[i - l].nota;
    }

    free(vetorTemporario);
}
