#include <stdio.h>
#include <stdlib.h>
#define tam_max 50000

typedef int item;
#define key(a) (a)
#define less(a,b) (key(a) < key(b))  

void insertion_sort (item *v, int l, int r);
void exch (int *a, int *b);

int main (){

    int *v = malloc (tam_max * sizeof (int));
    int num, i = 0;

    while (scanf ("%d", &num) != EOF){
        v[i] = num;
        i++;
    }
    insertion_sort (v, 0, i-1);

    for (int j = 0; j < i; j++){
        if (j != i-1)
            printf ("%d ", v[j]);
        else
            printf ("%d\n", v[j]);
    }
    return 0;
}

void insertion_sort (item *v, int l, int r){

    for (int i = r; i > l; i--)
        if (v[i] < v[i-1])
            exch (&v[i], &v[i-1]);

    for (int i = l+2; i <= r; i++){
        int j = i;
        item tmp = v[j];
        while (less (tmp, v[j-1])){
            v[j] = v[j-1];
            j--;
        }
        v[j] = tmp;
    }
}

void exch (int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
