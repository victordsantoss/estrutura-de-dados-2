#include <stdio.h>
#include <stdlib.h>
#define tam 500

void mergeSort(int *v, int l, int r);

int main (){

    int *v = malloc (tam * sizeof (int));
    for (int i = 0; i < tam; i++)
        v[i] = rand () % 1000;

    mergeSort (v, 0, tam-1);

    for (int i = 0; i < tam; i++)
        printf ("%d ", v[i]);

    return 0;
}

void mergeSort(int *v, int l, int r) {

    int i, j, k, m, *vetorTemporario; 
    
    if(l == r) return;
    m = (l + r ) / 2;

    mergeSort(v, l, m);
    mergeSort(v, m + 1, r);

    i = l;
    j = m + 1;
    k = 0;
    vetorTemporario = (int *) malloc(sizeof(int) * (r - l + 1));

    while(i < m + 1 || j  < r + 1){
        if (i == m + 1 ) { 
            vetorTemporario[k] = v[j];
            j++;
            k++;
        }
        else{
            if (j == r + 1){
                vetorTemporario[k] = v[i];
                i++;
                k++;
            }
            else{
                if (v[i] < v[j]){
                    vetorTemporario[k] = v[i];
                    i++;
                    k++;
                }
                else{
                    vetorTemporario[k] = v[j];
                    j++;
                    k++;
                }
            }
        }
    }

    for(i = l; i <= r; i++)
        v[i] = vetorTemporario[i - l];

    free(vetorTemporario);
}