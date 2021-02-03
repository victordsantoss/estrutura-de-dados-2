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

void swap(Seed* a, Seed* b) { Seed temp = *b; *b = *a; *a = temp; }

bool is_smaller(const Seed lhs, const Seed rhs) {
    return ( 
        (lhs.score < rhs.score) || 
        (lhs.score == rhs.score && lhs.id < rhs.id )
    );
}

Seed median3(Seed *arr, ll left, ll right) {
    ll mid = left + (right - left) / 2;

    if (!is_smaller(arr[left], arr[mid])) swap(&arr[left], &arr[mid]);
    // if (arr[left] > arr[mid]) swap(&arr[left], &arr[mid]);

    if (!is_smaller(arr[mid], arr[right])) swap(&arr[mid], &arr[right]);
    // if (arr[mid] > arr[right]) swap(&arr[mid], &arr[right]);

    if (!is_smaller(arr[left], arr[mid])) swap(&arr[left], &arr[mid]);
    // if (arr[] > arr[mid]) swap(&arr[left], &arr[mid]);

    swap(&arr[mid], &arr[right - 1]);

    return arr[right - 1];
}

int partition (Seed arr[], int low, int high)
{
    Seed pivot = median3(arr, low, high);    // pivot
    int i = low,j;  // Index of smaller element
 
    for (j = low+1; j <= high; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if ( (arr[j].score < pivot.score) || 
        	 (arr[j].score == pivot.score && arr[j].id < pivot.id ) 
           )
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i], &arr[low]);
    return i;
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSelect(Seed arr[], int low, int high, int k)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
       // int i;
        // Separately sort elements before
        // partition and after partition
        if(k <= pi) quickSelect(arr, low,pi - 1, k);
        if(k == pi+1) return;
        else quickSelect(arr,pi + 1, high, k);
       /* for (i=low; i < high; i++)
        printf("%d ", arr[i]);
        printf("\n");*/
    }
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
	start();

	ll Q;
	scanf("%lld", &Q);

    Seed s;
    while(scanf("%lld %lld", &arr[size].id, &arr[size].score) == 2) ++size;
    Q = (Q < size ? Q : size);

    quickSelect(arr, 0, size-1, Q);

    // qsort(arr, Q, sizeof(Seed), compare);

    // for(ll i=0; i<Q; i++) {
    // 	printf("%lld %lld\n", arr[i].id, arr[i].score);
    // }

    end();
	
	return 0;
}