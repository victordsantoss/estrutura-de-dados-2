#include <stdio.h>
#include <stdlib.h>

void insertionSort (int *v, int tam);
void troca (int *a, int *b);

int main (){

    int *v = malloc (50000 * sizeof (int));
    int num, contador = 0;

    while (scanf("%d", &num) != EOF){
        v[contador] = num;
        contador++;
    }   

    insertionSort (v, contador);

    return 0;
}

void insertionSort (int *v, int tam){

    for (int i = 1; i < tam; i++){
        for (int j = i; j > 0 && v[j] < v[j-1]; j--)
            troca (&v[j], &v[j-1]);
    }
    
    for (int i = 0; i < tam; i++){
        if (i != tam-1)
            printf ("%d ", v[i]);
        else 
            printf ("%d\n", v[i]);
    }
}

void troca (int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}