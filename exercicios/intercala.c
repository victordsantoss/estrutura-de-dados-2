#include <stdio.h>
#include <stdlib.h>

typedef int item;
#define key(a) (a)
#define less(a,b) (key(a) < key(b))
#define exch(a,b) {item t = a; a = b; b = t;}
#define cmpexch(a,b) {if (less(b,a)) exch(a,b);}
#define tam 1000

void merge_sort (item *v, int l, int r);
void merge (item *v, int l, int r1, int r2);
int separa (item *v, int l, int r);

int main (){

    int tam_vetor, num, i = 0, tam_total_vetor = 0, contador = 0;
    int *v = malloc (1000000 * sizeof(int));
    int *v_final = malloc (1000000 * sizeof(int));

    while (contador < 8){
        scanf("%d", &tam_vetor);
        contador ++;
        tam_total_vetor += tam_vetor;
        for (int j = 0; j < tam_vetor; j++){
            scanf ("%d", &num);
            v[i] = num;
            i++;
        }  
    }

    merge_sort (v, 0, tam_total_vetor-1);

    for (int k = 0; k < tam_total_vetor; k++){
        if (k == tam_total_vetor-1)
            printf ("%d\n", v[k]);
        else
            printf ("%d ", v[k]);
    }

    return 0;
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

