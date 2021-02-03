#include <stdio.h>
#include <stdlib.h>

typedef int item;
#define key(a) (a)
#define less(a,b) (key(a) < key(b))
#define exch(a,b) {item t = a; a = b; b = t;}
#define cmpexch(a,b) {if (less(b,a)) exch(a,b);}

void quick_sort (item *v, int l, int r);

int sep ( int v[], int p, int r) {
    
    int q, i, j, t;
    i = p; 
    q = v[(p + r) / 2]; 
    j = r;
    
    while (i <= j) {

        while (v[i] < q && i < r) i++;

        while (v[j] > q && j > p) j--;

        if(i <= j) {

            t = v[i];
            v[i] = v[j];
            v[j] = t;
            i++;
            j--;
            
        }
    }
     
    if (j > p) sep (v, p, j);
    if (i < r) sep (v, i, r);
}

int main (){

    int tam;

    scanf ("%d", &tam);

    int *v = malloc (tam * sizeof (int));
    int num;

    for (int i = 0; i < tam; i++){
        scanf ("%d", &num);
        v[i] = num;
    }

    quick_sort (v, 0, tam-1);

    for (int j = 0; j < tam; j++){
        if (j != tam-1)
            printf ("%d ", v[j]);
        else
            printf ("%d\n", v[j]);
    }

    return 0;
}

void quick_sort (item *v, int l, int r){
    
    int j;

    if (r <= l) return;
    
    cmpexch (v[(l+r)/2], v[r]);
    cmpexch (v[l], v[(l+r)/2]);
    cmpexch (v[r], v[(l+r)/2]);

    j = sep (v, l, r); 
    quick_sort (v, l, j-1);
    quick_sort (v, j+1, r);
}
