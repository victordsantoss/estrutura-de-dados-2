#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef long long ll;


ll qtdS, qtdF, qtdE;
ll votes_for_pres=0, votes_for_sena=0, votes_for_dFed=0, votes_for_dEst=0;


int main()
{
	scanf("%lld %lld %lld", &qtdS, &qtdF, &qtdE);

	ll vote;
	while(scanf("%lld", &vote) == 1)
	{
		if(vote <= 0) { ++invalid_votes; continue; };
		else          { ++valid_votes; }

		ll size = len(vote);
		if(size == 2)       { ++votes_for_pres; ++pres_cand[vote]; }
		else if(size == 3)  { ++votes_for_sena; ++sena_cand[vote]; }
		else if(size == 4)  { ++votes_for_dFed; ++defF_cand[vote]; }
		else if (size == 5) { ++votes_for_dEst; ++defE_cand[vote]; }
		else printf("SOMETHING WRONG\n");
	}

	ll mid = valid_votes>>1;

	ll presidente_number=0;
	ll presidente_count=0;

	for(ll i=10; i<=99; i++) {
		if(pres_cand[i] > presidente_count) {
			presidente_count = pres_cand[i];
			presidente_number = i;
		}
	}

	printf("%lld %lld\n", valid_votes, invalid_votes);

	if((100*presidente_count) / pres_votes > 50) {
		printf("%lld\n", presidente_number);
	}
	else printf("Segundo turno\n");

	printf("Needed to elect %lld\n", sena_votes>>1);

	int j=0;
	for(ll i=100; i<=999; ++i) {
		if(sena_cand[i] >= (sena_votes>>1)) {
			sena_eleitos[j++] = i;
		}

		if(sena_cand[i] != 0) {
			printf("Senador n° %lld teve %lld votos\n", i, sena_cand[i]);
		}
	}


    qsort(sena_eleitos, j, sizeof(ll), compareSenador);

	j = (j < S) ? j : S;
    for(int i=0; i<j; i++) {
    	printf("%lld%s", sena_eleitos[i], i+1==j ? "\n" : " ");
    }


	// for(ll i=1000; i<=9999; ++i) {

	// }

	// for(ll i=10000; i<=99999; ++i) {
	// }









	// printf("Most voted pres = %lld (with %lld votes)\n", presidente_number, presidente_count);


	return 0;
}