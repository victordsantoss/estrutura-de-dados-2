#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tamMax 2000
bool naoSeguro[tamMax];

int **criaMatriz (int tamMatriz);

int main (void){

	int numLocaisBairro, numLocaisJaEsteve, numLocaisEstara; // N, M, J
	int i, j, aux, lugarInseguro;
    int **locais = criaMatriz (tamMax);

	scanf ("%d %d %d", &numLocaisBairro, &numLocaisJaEsteve, &numLocaisEstara);

	for (i = 0; i < numLocaisBairro; i++){
		scanf ("%d", &locais[i][0]);
		for (j = 1; j <= locais[i][0]; j++) scanf ("%d", &locais[i][j]);
	}

	for (i = 0; i < numLocaisJaEsteve; i++){
		scanf ("%d", &aux);

		naoSeguro[aux] = true;
		for (j = 1; j <= locais[aux][0]; j++){
			lugarInseguro = locais[aux][j];
			naoSeguro[lugarInseguro] = true;
		}
	}

	for (i = 0; i < numLocaisEstara; i++){
		scanf ("%d", &aux);

		if (naoSeguro[aux]) printf ("Eu vou estar la\n");
		else printf ("Nao vou estar la\n");
	}
	return 0;
}

int **criaMatriz (int tamMatriz){

    int i, j, **m;
    m = malloc (tamMatriz * sizeof(int*));

    for (i = 0; i < tamMatriz; i++){
        m[i] = malloc (tamMatriz * sizeof (int));
        for (j = 0; j < tamMatriz; j++) m[i][j] = 0;
    }
    return m;
}
