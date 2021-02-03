#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main (){
    
    // Variáveis Auxiliares
    int eh_digrafo = 0;
    int vis[5], ant[5];
    float dist[5];
    
    // Criando grafo bi-direcional
    Grafo *gr;
    gr = cria_Grafo (5, 5, 0);

    // Inserção 
    insere_Aresta (gr, 0, 1, eh_digrafo, 0);
    insere_Aresta (gr, 1, 3, eh_digrafo, 0);
    insere_Aresta (gr, 1, 2, eh_digrafo, 0);
    insere_Aresta (gr, 2, 4, eh_digrafo, 0);
    insere_Aresta (gr, 3, 0, eh_digrafo, 0);
    insere_Aresta (gr, 3, 4, eh_digrafo, 0);
    insere_Aresta (gr, 4, 1, eh_digrafo, 0);

    imprime_Grafo (gr);

    // Busca em Profundidade 
    printf ("Realizando Busca em Profundidade bi-direcional para a posição do vértice: \n");
    busca_em_profundidade (gr, 0, vis);
    for (int i = 0; i < 5; i++)
        printf ("%d: %d\n", i, vis[i]);

    // Busca em Largura
    printf ("Realizando Busca em Largura bi-direcional para a posição do vértice: \n");
    busca_em_profundidade (gr, 0, vis);
    for (int i = 0; i < 5; i++)
        printf ("%d: %d\n", i, vis[i]);

    // Busca pelo menor caminho
    printf ("Realizando Busca pelo menor caminho: \n");
    busca_menor_caminho (gr, 0, ant, dist);

    // Removendo Aresta 
    printf ("Removendo Aresta: \n");
    remove_Aresta (gr, 4, 1, 0);
    imprime_Grafo (gr);

    // Criando Grafo Dígrafo
    eh_digrafo = 1;
    gr = cria_Grafo (5, 5, 0);

    // Inserção 
    insere_Aresta (gr, 0, 1, eh_digrafo, 0);
    insere_Aresta (gr, 1, 3, eh_digrafo, 0);
    insere_Aresta (gr, 1, 2, eh_digrafo, 0);
    insere_Aresta (gr, 2, 4, eh_digrafo, 0);
    insere_Aresta (gr, 3, 0, eh_digrafo, 0);
    insere_Aresta (gr, 3, 4, eh_digrafo, 0);
    insere_Aresta (gr, 4, 1, eh_digrafo, 0);

    imprime_Grafo (gr);

    // Busca em Profundidade 
    printf ("Realizando Busca em Profundidade direcional para a posição do vértice: \n");
    busca_em_profundidade (gr, 0, vis);
    for (int i = 0; i < 5; i++)
        printf ("%d: %d\n", i, vis[i]);

    // Busca em Largura
    printf ("Realizando Busca em Largura direcional para a posição do vértice: \n");
    busca_em_profundidade (gr, 0, vis);
    for (int i = 0; i < 5; i++)
        printf ("%d: %d\n", i, vis[i]);

    // Busca pelo menor caminho
    printf ("Realizando Busca pelo menor caminho: \n");
    busca_menor_caminho (gr, 0, ant, dist);

    // Removendo Aresta 
    printf ("Removendo Aresta: \n");
    remove_Aresta (gr, 4, 1, 0);
    imprime_Grafo (gr);

    libera_Grafo(gr);

    return 0;
}
