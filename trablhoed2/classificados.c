#include <stdio.h>
#include <stdlib.h>

#define less(a,b)(a < b)
#define lesseq(a,b)(a <= b)
#define exch(a,b) {int t = a; a = b; b = t;}
#define cmpexch(a,b) if(less(b,a)) exch(a,b)

int elem_rep = 0;

typedef struct semente{
	int s;
	int n;

} semente;

//exchs(c, d) {struct semente t = c; c = d; d = t;}

int separa (semente *v, int l, int r){
	int a, b;
	int temp = l;
	int j = l;
	semente tmp;

	a = v[r].n;
	b = v[r].s;

	while(temp < r){
		if(lesseq(v[temp].n, a)){
			if(v[temp].n == a){
				if(v[temp].s < b){
					tmp = v[j];
					v[j] = v[temp];
					v[temp] = tmp; 			
					j++;
				}
			}
			else{
				tmp = v[j];
				v[j] = v[temp];
				v[temp] = tmp; 			
				j++;
			}

		}

		temp++;
	}

	tmp = v[j];
	v[j] = v[r];
	v[r] = tmp;

	return j;
}

int separa2 (semente *v, int l, int r){
	int temp = l;
	int j = l;
	semente tmp;

	while(temp < r){
		if(lesseq(v[temp].s, v[r].s)){
			tmp = v[j];
			v[j] = v[temp];
			v[temp] = tmp; 			
			j++;
		} 

		temp++;
	}

	tmp = v[j];
	v[j] = v[r];
	v[r] = tmp;

	return j;
}

void result(semente *v, int l, int r, int k){

		//cmpexch(v[(l+r)/2].n, v[r].n);
	if(v[r].s < v[(l+r)/2].s){
		semente aux = v[r];
		v[r] = v[(l+r)/2];
		v[(l+r)/2] = aux;
	}
	//cmpexch(v[l].n, v[(l+r/2)].n);
	if(v[(l+r)/2].s < v[l].s){
		semente aux = v[l];
		v[l] = v[(l+r)/2];
		v[(l+r)/2] = aux;
	}
	//cmpexch(v[r].n, v[(l+r)/2].n);

	if(v[(l+r)/2].s < v[r].s){
		semente aux = v[r];
		v[r] = v[(l+r)/2];
		v[(l+r)/2] = aux;
	}

	int j = 0;
	j = separa(v, l, r);
	if(r <= l)
		return;

	if(k < j)
		result(v, l, j-1, k);
	else
		result(v, j+1, r, k);

	return;
	

}

void merge(semente *v, int l, int meio, int r){
	semente *v2;
	int i = 0;
	int j = l;
	int k = meio;
	v2 = malloc(sizeof(semente) * (r-l+1));

	while(j < meio && k < r){
		if(lesseq(v[j].s, v[k].s))
			v2[i++] = v[j++];
		else
			v2[i++] = v[k++];
	}
	
	while(j < meio)
		v2[i++] = v[j++];
	while(k < r)
		v2[i++] = v[k++];
	i = 0;
	for(int j = l; j < r; j++)
		v[j] = v2[i++];
	free(v2);
}


void mergesort(semente *v, int l, int r){

	if(l < r-1){

		int meio = (l + r) / 2;

		mergesort(v, l, meio);
		mergesort(v, meio, r);
		merge(v, l, meio, r);
	}
}



int main(){

	int n = 100000, l = 0, k, j = 0, eq = 0, i = 0;
	semente *v;

	//scanf("%d", &n);
	scanf("%d", &k);
	v = malloc(n * sizeof(semente));
	
	while(scanf("%d %d", &v[j].s, &v[j].n) != EOF){
		//printf("a\n");
		j++;
		if(j == n){
			v = realloc(v, 2 * n * sizeof (semente));
			n *= 2;
		}
	}
	

	result(v, 0, j-1, k);
	//printf("%d\n",r );

	//for(int i = 0; i < k; i++){
//		printf("%d %d\n",v[i].s, v[i].n );
	//}

	//printf("\n");
	mergesort(v, 0, k);



	for(int i = 0; i < k; i++){

		printf("%d %d\n",v[i].s, v[i].n);
	}



	return 0;
}