#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int item;
#define key(a) (a)
#define less(a,b) (key(a) < key(b))
#define exch(a,b) {item t = a; a = b; b = t;}
#define cmpexch(a,b) {if (less(b,a)) exch(a,b);}
#define tam 500

int quick_trap_stop = 0;

void intro_sort (item *v, int l, int r);
void quick_sort (item *v, int l, int r, int max_rec);
int separa (item *v, int l, int r);
void merge_sort (item *v, int l, int r);
void merge (item *v, int l, int r1, int r2);
void insertion_sort (item *v, int l, int r);

int main (){

    int *v = malloc (tam * sizeof (int));
    for (int i = 0; i < tam; i++)
        v[i] = rand () % 1000;

    intro_sort (v, 0, tam-1);

    for (int i = 0; i < tam; i++)
        printf ("%d ", v[i]);

    return 0;
}

void intro_sort (item *v, int l, int r){

    int max_rec = 2 * log2((r-l+1));

    quick_sort(v, l, r, max_rec);

    if (quick_trap_stop == 1)
        merge_sort (v, l, r);
    else
        insertion_sort (v, l, r);

}

void quick_sort (item *v, int l, int r, int max_rec){
    
    int j;

    if (max_rec == 0)
        quick_trap_stop = 1;
        return;

    if (quick_trap_stop == 1)
        return;

    if (l - r <= 32)
        return;

    exch (v[(l+r)/2], v[r-1]);
    cmpexch (v[l], v[r-1]);
    cmpexch (v[l], v[r]);
    cmpexch (v[r-1], v[r]);

    j = separa (v, l+1, r-1); 
    quick_sort (v, l, j-1, max_rec - 1);
    quick_sort (v, j+1, r, max_rec - 1);
}

int separa (item *v, int l, int r){
    int pivo = v[r];
    int j = l;

    for (int k = l; k < r; k++)
        if (less(v[k], pivo)){
            exch (v[k], v[j]);
            j++;
        }
        exch (v[j], v[r]);

    return j;
} 

void merge_sort (item *v, int l, int r){

    if (l >= r) return;

    int meio = (r + l) / 2;
    merge_sort (v, l, meio);
    merge_sort (v, meio + 1, r);
    merge (v, l, meio, r);

}

void merge (item *v, int l, int r1, int r2){

    item *v2 = malloc (sizeof (item) * (r2-l+1));
    int k = 0;
    int i = l;
    int j = r1 + 1;

    while (i <= r1 && j <= r2){
        if (less (v[i], v[j]))
            v2[k++] = v[i++];
        else
            v2[k++] = v[j++];
    }

    while (i <= r1)
        v2[k++] = v[i++];

    while (j <= r2)
        v2[k++] = v[j++];

    k = 0;

    for (i = l; i <= r2; i++)
        v[i] = v2[k++];

    free (v2);

}

void insertion_sort (item *v, int l, int r){

    for (int i = r; i > l; i--)
        cmpexch (v[i-1], v[i]);

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


