#include <stdio.h>
#include <stdlib.h>

typedef int item;
#define key(a) (a)
#define less(a,b) (key(a) < key(b))
#define lesseq(a,b) (key(a) <= key(b))

item * intercala2 (item *v1, int n1, item *v2, int n2);
item *intercala4 (item *v1, int n1, item *v2, int n2, item *v3, int n3, item *v4, int n4);
item *intercala8 (item *v1, int n1, item *v2, int n2, item *v3, int n3, item *v4, int n4, item *v5, int n5, item *v6, int n6, item *v7, int n7, item *v8, int n8);

int main (){

    int v1[] = {1,3,5};
    int n1 = 3;
    int v2[] = {2,4,6};
    int n2 = 3;
    int v3[] = {7,9,12};
    int n3 = 3;
    int v4[] = {14,6,11};
    int n4 = 3;
    int v5[] = {1,3,5};
    int n5 = 3;
    int v6[] = {2,4,6};
    int n6 = 3;
    int v7[] = {7,9,12};
    int n7 = 3;
    int v8[] = {14,6,11};
    int n8 = 3;

    int *v = intercala8(v1,n1,v2,n2, v3, n3, v4, n4, v5, n5, v6, n6, v7, n7, v8, n8);

    for (int i = 0; i < n1+n2+n3+n4+n5+n6+n7+n8; i++){
        printf ("%d ", v[i]);
    }
    return 0;
}

item * intercala2 (item *v1, int n1, item *v2, int n2){

    item *result = malloc ((n1+n2)*sizeof(item));
    int p1 = 0, p2 = 0, resultP = 0;

    while (p1 < n1 && p2 < n2){

        if (less(v1[p1], v2[p2])){

            result[resultP] = v1[p1];
            p1++;
            
        }else{

            result[resultP] = v2[p2];
            p2++;

        } 

        resultP++;

    }

    while (p1 < n1){

        result[resultP] = v1[p1];
        p1++;
        resultP++;

    }

    while (p2 < n2){

        result[resultP] = v2[p2];
        p2++;
        resultP++;

    }
    return result;
}

item *intercala4 (item *v1, int n1, item *v2, int n2, item *v3, int n3, item *v4, int n4){

    item *left = intercala2 (v1, n1, v2, n2);
    int tamLeft = n1 + n2;

    item *right = intercala2 (v3, n3, v4, n4);
    int tamRight = n3+n4;

    item *result = intercala2 (left, tamLeft, right, tamRight);

    return result;
}

item *intercala8 (item *v1, int n1, item *v2, int n2, item *v3, int n3, item *v4, int n4, item *v5, int n5, item *v6, int n6, item *v7, int n7, item *v8, int n8){

    item *left = intercala4 (v1, n1, v2, n2, v3, n3, v4, n4);
    int tamLeft = n1 + n2 + n3 + n4;

    item *right = intercala4 (v5, n5, v6, n6, v7, n7, v8, n8);
    int tamRight = n5 + n6 + n7 + n8;

    item *result = intercala2 (left, tamLeft, right, tamRight);

    return result;
}

