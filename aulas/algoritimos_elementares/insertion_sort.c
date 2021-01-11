#include <stdio.h>
#include <stdlib.h>
#define tam 100

void insertion_sort (int *v, int l, int r);
void exch (int *a, int *b);

int main (){

    int *v = malloc (tam * sizeof (int));

    for (int i = 0; i < tam; i++)
        v[i] = rand () % 1000;

    insertion_sort (v, 0, tam-1);

    for (int i = 0; i < tam; i++)
        printf ("%d ", v[i]);

    return 0;
}
void insertion_sort (int *v, int l, int r){
    /*
        Complexidade O(n) no melhor caso e O(n²) no médio e pior caso
        Algorítimo Estável
        Ordenações parciais comparando um elemento N com os seus elementos a esquerda
        1 - Compara o elemento de posição n+1 com o de posição n, realizando trocas enquanto a condição de parada não for atendida
        2 - Ocorre a incrementação nos loops e o processo é feito novamente
        3 - Isso ocorre até o vetor estar completamente ordenado
    */
    for (int i = l; i < r; i++){
        for (int j = i; j > l && v[j] < v[j-1]; j--)
            exch (&v[j], &v[j-1]);
    }
}

void exch (int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}