#include <stdio.h>
#include <stdlib.h>

typedef int item;
#define key(a) (a)
#define less(a,b) (key(a) < key(b))
#define exch(a,b) {item t = a; a = b; b = t;}
#define cmpexch(a,b) {if (less(b,a)) exch(a,b);}
#define tam 15

void insertion_sort (item *v, int l, int r, int salto);
void shell_sort (item *v, int l, int r);

int main (){

    int *v = malloc (tam * sizeof (int));
    for (int i = 0; i < tam; i++)
        v[i] = rand () % 1000;

    shell_sort (v, 0, tam-1);

    for (int i = 0; i < tam; i++)
        printf ("%d ", v[i]);

    return 0;
}

void shell_sort (item *v, int l, int r){
    int salto;

    for (salto = 1; salto <= (r-l)/9; salto = 3*salto+1);

    for ( ;salto > 0; salto = salto/3){
        insertion_sort (v, r, l, salto);
    }
}

void insertion_sort (item *v, int l, int r, int salto){

    for (int i = l+salto; i <= r; i++){
        int j = i;
        item tmp = v[j];
        while (j >= l+salto && less(tmp, v[j-salto])){
            v[j] = v[j+salto];
            j -= salto;
        }
        v[j] = tmp;
    }
}