#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef long long ll;
typedef struct Seed { ll id, score; } Seed;
Seed array[10000000];
clock_t begin;
void start() { begin = clock(); }
void end() { printf("\nTime elpased is %f seconds\n", (double)(clock()-begin)/CLOCKS_PER_SEC); }

// ============================================================ //

ll HEAP_SIZE = 10000001LL;

struct Heap{
    Seed *arr;
    ll count;
    ll capacity;
    ll heap_type; // for min heap , 1 for max heap
};
typedef struct Heap Heap;

Heap *CreateHeap(ll capacity,ll heap_type);
void insert(Heap *h, Seed key);
void insert2(Heap *h, Seed key);
void print(Heap *h);
void heapify_bottom_top(Heap *h, ll index);
void heapify_bottom_top2(Heap *h, ll index);
void heapify_top_bottom(Heap *h, ll parent_node);
void heapify_top_bottom2(Heap *h, ll parent_node);
Seed PopMin(Heap *h);
Seed PopMin2(Heap *h);

Heap* CreateHeap(ll capacity, ll heap_type) {
    Heap *h = (Heap *) malloc(sizeof(Heap));

    if(h == NULL) { return NULL; } // memory fail

    h->heap_type = heap_type;
    h->count = 0;
    h->capacity = capacity;

    h->arr = (Seed *) malloc(capacity*sizeof(Seed)); //size in bytes

    //check if allocation succeed
    if ( h->arr == NULL ){ return NULL; }
    return h;
}

void insert(Heap *h, Seed key) {
    if( h->count < h->capacity) {
        h->arr[h->count] = key;
        heapify_bottom_top(h, h->count);
        h->count++;
    }
}

void insert2(Heap *h, Seed key) {
    if( h->count < h->capacity) {
        h->arr[h->count] = key;
        heapify_bottom_top2(h, h->count);
        h->count++;
    }
}

void heapify_bottom_top(Heap *h, ll index) {
    ll parent_node = (index-1)/2;

    if( (h->arr[parent_node].score > h->arr[index].score) || 
        (h->arr[parent_node].score == h->arr[index].score && h->arr[parent_node].id > h->arr[index].id)
      )
    {
        //swap and recursive call
        Seed temp = h->arr[parent_node];
        h->arr[parent_node] = h->arr[index];
        h->arr[index] = temp;

        heapify_bottom_top(h, parent_node);
    }
}

void heapify_bottom_top2(Heap *h, ll index) {
    ll parent_node = (index-1)/2;

    if(h->arr[parent_node].id > h->arr[index].id) 
    {
        //swap and recursive call
        Seed temp = h->arr[parent_node];
        h->arr[parent_node] = h->arr[index];
        h->arr[index] = temp;
        heapify_bottom_top2(h, parent_node);
    }
}

void heapify_top_bottom(Heap *h, ll parent_node){
    
    ll left  = parent_node*2 + 1;
    ll right = parent_node*2 + 2;

    ll min;

    if(left >= h->count  || left  < 0) left = -1;
    if(right >= h->count || right < 0) right = -1;

    if( (left!=-1) && 
        ( (h->arr[left].score < h->arr[parent_node].score) ||  
          (h->arr[left].score == h->arr[parent_node].score && h->arr[left].id < h->arr[parent_node].id)
        )
    ) min=left;
    else min = parent_node;
    if( (right!=-1) && 
        ( (h->arr[right].score < h->arr[parent_node].score) ||  
          (h->arr[right].score == h->arr[parent_node].score && h->arr[right].id < h->arr[parent_node].id)
        )
    ) min = right;
    else min = parent_node;

    if(min != parent_node) {
        Seed temp = h->arr[min];
        h->arr[min] = h->arr[parent_node];
        h->arr[parent_node] = temp;
        heapify_top_bottom(h, min);
    }
}

void heapify_top_bottom2(Heap *h, ll parent_node){
    
    ll left = parent_node*2+1;
    ll right = parent_node*2+2;
    ll min;

    if(left >= h->count  || left  < 0) left = -1;
    if(right >= h->count || right < 0) right = -1;

    if(left!=-1 && h->arr[left].id < h->arr[parent_node].id) {
        min=left;
    }  else { min = parent_node; }

    if(right!=-1 && h->arr[right].id < h->arr[min].id) {
        min = right;
    } else { min = parent_node; }

    if(min != parent_node) {
        Seed temp = h->arr[min];
        h->arr[min] = h->arr[parent_node];
        h->arr[parent_node] = temp;

        heapify_top_bottom2(h, min);
    }
}

Seed PopMin(Heap *h) {
    Seed pop = h->arr[0];
    h->arr[0] = h->arr[h->count-1];
    h->count--;
    
    heapify_top_bottom(h, 0);

    return pop;
}

Seed PopMin2(Heap *h) {
    Seed pop = h->arr[0];
    h->arr[0] = h->arr[h->count-1];
    h->count--;
    
    heapify_top_bottom2(h, 0);

    return pop;
}

// void print(Heap *h){
//     for(ll i=0; i < h->count; i++) {
//         printf("%lld %lld\n", h->arr[i].id, h->arr[i].score);
//     }
// }


int main(){
    start();

    Heap *heap = CreateHeap(HEAP_SIZE, 0); //Min Heap

    ll Q;
    scanf("%lld", &Q);

    Seed s;
    while(scanf("%lld %lld", &s.id, &s.score) == 2) {
        insert(heap, s);
    }

    Heap * heap2 = CreateHeap(HEAP_SIZE, 0);

    Q = (Q < heap->count ? Q : heap->count);

    for(ll i=0; i<Q; i++) {
        Seed d = PopMin(heap);
        printf("%lld %lld\n", d.id, d.score);
        // insert2(heap2, d);
    }
    return 0;

    while(Q--) {
        Seed d = PopMin2(heap2);
        printf("%lld %lld\n", d.id, d.score);
    }

    end();
    return 0;
}
