#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <string.h>

typedef long long ll;
typedef struct Seed { ll id, score; } Seed;

clock_t begin;
void start() { begin = clock(); }
void end() { printf("\nTime elpased is %f seconds\n", (double)(clock()-begin)/CLOCKS_PER_SEC); }


void switcharoo(Seed *array, ll index1, ll index2);
ll partition(Seed *array, ll left, ll right, ll pivotIndex);
Seed qselect(Seed *array, ll left, ll right, ll n);
Seed quickselect(Seed *array, ll array_size, ll k);

void switcharoo(Seed *array, ll index1, ll index2) {
    Seed temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

ll partition(Seed *array, ll left, ll right, ll pivotIndex) {
    Seed pivotValue = array[pivotIndex];
    ll storeIndex = left;
    ll i;
    /* Move pivot to end */
    switcharoo(array, pivotIndex, right);
    for(i=left; i < right; i = i + 1 ){
        if( (array[i].score < pivotValue.score) || 
        	(array[i].score == pivotValue.score && array[i].id == pivotValue.id)
          )
        {
            switcharoo(array, storeIndex, i);
            storeIndex += 1;
        }
    }
    /* Move pivot to its final place */
    switcharoo(array, storeIndex, right);

    return storeIndex;
}

Seed qselect(Seed *array, ll left, ll right, ll n) {
    if(left == right) { return array[n]; }

    ll pivotIndex = left + (rand() % (right-left+1));
    pivotIndex = partition(array, left, right, pivotIndex);

    if(n == pivotIndex) { return array[n]; }
    else if(n < pivotIndex) { return qselect(array, left, pivotIndex-1, n); }
    else { return qselect(array, pivotIndex+1, right, n); }
}

Seed quickselect(Seed *array, ll array_size, ll k){
    return qselect(array, 0, array_size-1, k-1);
}

Seed arr[10005000];
ll size=0;

int compare(const void*a, const void*b) {
    Seed x = *((Seed*) a);
    Seed y = *((Seed*) b);
    return x.id < y.id ? -1 : 1;
}

int main()
{
	// start();

	ll Q;
	scanf("%lld", &Q);

    Seed s;
    while(scanf("%lld %lld", &arr[size].id, &arr[size].score) == 2) ++size;
    Q = (Q < size ? Q : size);

    quickselect(arr, size, Q);
    qsort(arr, Q, sizeof(Seed), compare);

    for(ll i=0; i<size; i++) {
    	printf("%lld %lld\n", arr[i].id, arr[i].score);
    }

    // end();
	
	return 0;
}