/*
    Encontrar elementos específicos em um vetor 
*/
#include <stdio.h>
#include <stdlib.h>

typedef int item;
#define key(a) (a)
#define less(a,b) (key(a) < key(b))
#define exch(a,b) {item t = a; a = b; b = t;}
typedef int item;

void quick_select (item *v, int l, int r, int k);
int separa (item *v, int l, int r);

int main (){

    int num, elem, i = 0;

    int *v = malloc (100 * sizeof(int));

    while (scanf ("%d", &num) != EOF){
        v[i] = num;
        i++;
    }

    scanf ("%d", &elem);

    quick_select (v, 0, i-1, elem);

    for (int j = 0; j < i; j++)
        printf ("%d ", v[j]);

    printf ("\n%d", v[elem]);

    return 0;
}

void quick_select (item *v, int l, int r, int k){

    int i;

    if (r <= l)
        return;

    i = separa (v, l, r);

    if (i > k)
        quick_select (v, l, i-1, k);
    if (i < k)
        quick_select (v, i+1, r, k);

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
