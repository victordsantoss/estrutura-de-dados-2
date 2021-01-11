#include <stdio.h>
#include <stdlib.h>
#define tam 100

void bubble_sort (int *v, int l, int r);
void exch (int *a, int *b);

int main (){

    int *v = malloc (tam * sizeof (int));

    for (int i = 0; i < tam; i++)
        v[i] = rand () % 1000;

    bubble_sort (v, 0, tam-1);

    for (int i = 0; i < tam; i++)
        printf ("%d ", v[i]);

    return 0;
}
void bubble_sort (int *v, int l, int r){
    /*
        Complexidade O(n²) 
        Algorítimo Estável
        Comparações 2 a 2
        1 - Compara o elemento j com o elemento j+1 e troca as posições se a condição for verdadeira
        2 - j é incrementado e é realizada outra comparação
        3 - O procedimento é realizado até o algorítimo estar ordenado
    */
    for (int i = l; i < r; i++){
        for (int j = l; j < r; j++){
            if (v[j+1] < v[j])
                exch (&v[j+1], &v[j]);
        }
    }
}

void exch (int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}