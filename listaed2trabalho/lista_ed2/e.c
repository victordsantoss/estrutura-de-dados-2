#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef long long ll;
typedef struct Candidate { ll number, votes; } Candidate;

////////////////////////////////////////////////////////////////////////
void switcharoo(Candidate *array, ll index1, ll index2);
ll partition(Candidate *array, ll left, ll right, ll pivotIndex);
Candidate qselect(Candidate *array, ll left, ll right, ll n);
Candidate quickselect(Candidate *array, ll array_size, ll k);
int compare(const void*a, const void*b);
////////////////////////////////////////////////////////////////////////

ll qtd_digits(ll v) { ll s=0; while(v) { s++; v/=10; } return s; }

ll qtdS, qtdF, qtdE;
ll valid_votes=0;
ll invalid_votes=0;

ll pres_votes=0, sena_votes=0, fede_votes=0, esta_votes=0;

ll votes[100000];

void election_log();
void compute_president();
void compute_senator();
void compute_federal();
void compute_estadual();

int main()
{
	scanf("%lld %lld %lld", &qtdS, &qtdF, &qtdE);

	ll v;
	while(scanf("%lld", &v) == 1) {

		if(v <= 9 || v > 99999) { ++invalid_votes; continue; }
		++valid_votes;

		ll qDigits = qtd_digits(v);
		// printf("val = %lld (qDigits: %lld)\n", v, qDigits);

		if(qDigits == 2)    { ++pres_votes; }
		else if(qDigits==3) { ++sena_votes; }
		else if(qDigits==4) { ++fede_votes; }
 		else if(qDigits==5) { esta_votes++; }

 		++votes[v];
	}

	// election_log();

	printf("%lld %lld\n", valid_votes, invalid_votes);

	compute_president();
	compute_senator();
	compute_federal();
	compute_estadual();

	return 0;
}

void election_log() {
	printf("President votes\n");
	for(ll i=10; i<=99; ++i) {
		if(votes[i] == 0) continue;
		printf("Candidate n° %lld got %lld votes\n", i, votes[i]);
	}

	printf("\nSenator votes\n");
	for(ll i=100; i<=999; ++i) {
		if(votes[i] == 0) continue;
		printf("Candidate n° %lld got %lld votes\n", i, votes[i]);
	}

	printf("\nFederal votes\n");
	for(ll i=1000; i<=9999; ++i) {
		if(votes[i] == 0) continue;
		printf("Candidate n° %lld got %lld votes\n", i, votes[i]);
	}

	printf("\nEstadual votes\n");
	for(ll i=10000; i<=99999; ++i) {
		if(votes[i] == 0) continue;
		printf("Candidate n° %lld got %lld votes\n", i, votes[i]);
	}
	printf("\n\n");
}

void compute_president() {
	ll most_voted_candidate=0;
	ll number_of_votes=0;

	for(ll i=10; i<=99; ++i) {
		if(votes[i] == 0) continue;

		if(votes[i] > number_of_votes) {
			number_of_votes = votes[i];
			most_voted_candidate = i;
		}
	}

	// printf("pres_votes = %lld\n", pres_votes);

	ll percentage = (number_of_votes*100) / pres_votes;

	// printf("Most voted President Candidate\n");
	// printf("N° %lld, with %lld votes (%lld %%)\n", most_voted_candidate, number_of_votes, percentage);

	if(percentage > 50) {
		printf("%lld\n", most_voted_candidate);
	}
	else {
		printf("Segundo turno\n");
	}
}


ll cSize;
Candidate got_votes[100000000];

void compute_senator()
{
	cSize=0;

	// printf("\nSenator votes\n");
	for(ll i=100; i<=999; ++i) {
		if(votes[i] == 0) continue;

		// printf("Senador N° %lld got %lld votes\n", i, votes[i]);

		got_votes[cSize].number = i;
		got_votes[cSize].votes = votes[i];
		cSize++;
	}

	// printf("\n");
	quickselect(got_votes, cSize, qtdS);
    qsort(got_votes, qtdS, sizeof(Candidate), compare);


	for(ll i=0; i<qtdS && i<cSize; i++) {
		printf("%lld%s", got_votes[i].number, (i+1==qtdS || i+1==cSize) ?"\n":" ");
		// printf("Senador N° %lld got %lld votes\n", got_votes[i].number, got_votes[i].votes);
	}


	// for(int i=0; i<qtdS; i++) {
	// 	printf("votes: %lld (N° %lld)\n", got_votes[i].votes, got_votes[i].number);
	// }
}

void compute_federal()
{
	cSize=0;

	// printf("\nFederal votes\n");
	for(ll i=1000; i<=9999; ++i) {
		if(votes[i] == 0) continue;

		// printf("Federal N° %lld got %lld votes\n", i, votes[i]);

		got_votes[cSize].number = i;
		got_votes[cSize].votes = votes[i];
		cSize++;
	}

	// printf("\n");
	quickselect(got_votes, cSize, qtdF);
    qsort(got_votes, qtdF, sizeof(Candidate), compare);

	for(ll i=0; i<qtdF && i<cSize; i++) {
		printf("%lld%s", got_votes[i].number, (i+1==qtdF || i+1==cSize) ?"\n":" ");
		// printf("Senador N° %lld got %lld votes\n", got_votes[i].number, got_votes[i].votes);
	}

	// for(int i=0; i<qtdS; i++) {
	// 	printf("votes: %lld (N° %lld)\n", got_votes[i].votes, got_votes[i].number);
	// }
}

void compute_estadual()
{
	cSize=0;

	// printf("\nFederal votes\n");
	for(ll i=10000; i<=99999; ++i) {
		if(votes[i] == 0) continue;

		// printf("Federal N° %lld got %lld votes\n", i, votes[i]);

		got_votes[cSize].number = i;
		got_votes[cSize].votes = votes[i];
		cSize++;
	}

	// printf("\n");
	quickselect(got_votes, cSize, qtdE);
    qsort(got_votes, qtdE, sizeof(Candidate), compare);

	for(ll i=0; i<qtdE && i<cSize; i++) {
		printf("%lld%s", got_votes[i].number, (i+1==qtdE || i+1==cSize) ?"\n":" ");
		// printf("Senador N° %lld got %lld votes\n", got_votes[i].number, got_votes[i].votes);
	}

	// for(int i=0; i<qtdS; i++) {
	// 	printf("votes: %lld (N° %lld)\n", got_votes[i].votes, got_votes[i].number);
	// }
}











































void switcharoo(Candidate *array, ll index1, ll index2) {
    Candidate temp = array[index1];
    array[index1] = array[index2];
    array[index2] = temp;
}

ll partition(Candidate *array, ll left, ll right, ll pivotIndex) {
    Candidate pivotValue = array[pivotIndex];
    ll storeIndex = left;
    ll i;
    /* Move pivot to end */
    
    switcharoo(array, pivotIndex, right);
    for(i=left; i < right; i = i + 1 ){
        if( (array[i].votes > pivotValue.votes) || 
        	(array[i].votes == pivotValue.votes && array[i].number > pivotValue.number)
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

Candidate qselect(Candidate *array, ll left, ll right, ll n) {
    if(left == right) { return array[n]; }

    ll pivotIndex = left + (rand() % (right-left+1));
    pivotIndex = partition(array, left, right, pivotIndex);

    if(n == pivotIndex) { return array[n]; }
    else if(n < pivotIndex) { return qselect(array, left, pivotIndex-1, n); }
    else { return qselect(array, pivotIndex+1, right, n); }
}

Candidate quickselect(Candidate *array, ll array_size, ll k){
    return qselect(array, 0, array_size-1, k-1);
}












int compare(const void*a, const void*b) {
    Candidate x = *((Candidate*) a);
    Candidate y = *((Candidate*) b);

    if(x.votes != y.votes) {
        return x.votes > y.votes ? -1 : 1;
    }
    
    return x.number > y.number ? -1 : 1;
}