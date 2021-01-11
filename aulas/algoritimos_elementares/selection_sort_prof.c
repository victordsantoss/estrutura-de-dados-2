#include <stdio.h>
#include <stdlib.h>
#define tam 1000

void selection_sort (int *v, int l, int r);
void exch (int *a, int *b);

int main (){

    int *v = malloc (tam * sizeof (int));

    for (int i = 0; i < tam; i++)
        v[i] = rand () % 1000;

    selection_sort (v, 0, tam);

    for (int i = 0; i < tam; i++)
        printf ("%d ", v[i]);

    return 0;
}

void selection_sort (int *v, int l, int r){
    /*
        Complexidade O(n²)
        Algorítimo Instável
        Busca pelo menor elemento
        1 - Seleciona o menor elemento e coloca na primeira posição
        2 - Seleciona o segundo menor elemento do vetor restante e coloca na segunda posição
        3 - Faz isso até o vetor estar ordenado
    */
    for (int i = l; i < r; i++){
        int min = i;
        for (int j = i+1; j < r; j++){
            if (v[j] < v[min])
                min = j;
        }
        exch (&v[i], &v[min]);
    }
}

void exch (int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}