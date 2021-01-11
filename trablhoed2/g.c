#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void buscaEmProfundidade (int a);
void imprimeCriaturas (int numCriaturas);
void iniciaMatVet (int numCriaturas);

#define tamNome 31
#define tamMax 5000

char criaturas[tamMax][tamNome];
int matrizAdj[tamMax][tamMax];
bool visitado[tamMax];

int tamLigacao = 0;

int main (void){

	int numCriaturas, numRelacoes;
	char nomeCriatura[tamNome];
    char nomeRelacao1[tamNome], nomeRelacao2[tamNome];

	int i, j;
	int i1, i2;
	int cont;

	while (scanf ("%d %d", &numCriaturas, &numRelacoes) == 2 && (numCriaturas !=0 || numRelacoes != 0)){

		iniciaMatVet (numCriaturas);

		for (i = 0; i < numCriaturas; ++i) {
			scanf("%s", nomeCriatura);
			strcpy (criaturas[i], nomeCriatura);
		}

		for (i = 0; i < numRelacoes; ++i) {
			scanf ("%s %s", nomeRelacao1, nomeRelacao2);

			i1 = 0;
			i2 = 0;

			for (j = 0; j < numCriaturas; ++j) {
				if (strcmp (nomeRelacao1, criaturas[j]) == 0){ 
					i1 = j; 
					break; 
				}
			}

			for (j = 0; j < numCriaturas; ++j) {
				if (strcmp (nomeRelacao2, criaturas[j]) == 0){
					i2 = j;
					break; 
				}
			}

			j = 0; 
			while (matrizAdj[i2][j] != -1) 
				++j;
			matrizAdj[i2][j] = i1;

			j = 0; 
			while (matrizAdj[i1][j] != -1)
				++j;
			matrizAdj[i1][j] = i2;
		}

		cont = 0;

		for(i = 0; i < numCriaturas; ++i){
			if (visitado[i]) 
				continue;

			tamLigacao = 0;
			buscaEmProfundidade(i);

			if (tamLigacao > cont)
				cont = tamLigacao;
			else 
				cont = cont;
		}

		printf("%d\n", cont);
	}
	return 0;
}

void buscaEmProfundidade(int vertice) {

	int j;

	if (visitado[vertice]) 
		return;

	visitado[vertice] = true;
	++tamLigacao;

	j = 0;
	while (matrizAdj[vertice][j] != -1) {
		buscaEmProfundidade(matrizAdj[vertice][j]);
		++j;
	}
}

void imprimeCriaturas (int numCriaturas){

    int i, j;

    for (i = 0; i < numCriaturas; i++){
        for (j = 0; j < tamNome; j++)
            printf ("%c", criaturas[i][j]);
        printf("\n");
    }
}

void iniciaMatVet (int numCriaturas){

	int i, j;

	for (i = 0; i < numCriaturas; i++) {
		for (j = 0; j < tamNome; j++) {
			criaturas[i][j]=0;
		}
	}

	for (i = 0; i< numCriaturas; i++) {
		for (j = 0; j < numCriaturas; j++) {
			matrizAdj[i][j]=-1;
		}
	}

	for (i = 0; i < numCriaturas; ++i)
		visitado[i] = false;
}