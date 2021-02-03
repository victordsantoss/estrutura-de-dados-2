#include <stdio.h>
#include <stdlib.h>

typedef struct Grafo {
    int eh_ponderado; 
    int nro_vertices; 
    int grau_max; 
    int **arestas; 
    float **pesos; 
    int *grau; 
} Grafo;

Grafo *criaGrafo (int nro_vertices, int grau_max, int eh_ponderado);
void libera_Grafo (Grafo *gr);

int insereAresta (Grafo *gr, int orig, int dest, int eh_digrafo, float peso);
void imprimeGrafo (Grafo *gr);
int remove_Aresta (Grafo *gr, int orig, int dest, int eh_digrafo);

void busca_em_profundidade (Grafo *gr, int ini, int *visitado);
void auxiliar_busca_em_profundidade (Grafo *gr, int ini, int *visitado, int cont);
void busca_em_largura (Grafo *gr, int ini, int *visitado);
void busca_menor_caminho (Grafo *gr, int ini, int *ant, float *dist);
int procura_menor_distancia (float *dist, int *visitado, int NV);


int main (void){

    int nroVertices, grauMax, digrafo = 0, ponderado = 0;
    int verticeA, verticeB, verticeInicial = 0;

    scanf ("%d", &nroVertices);

    int *verticeVisitado = malloc (nroVertices * sizeof (int));
    int *verticeAnterior = malloc (nroVertices * sizeof (int));
    float *distanciaVertice = malloc (nroVertices * sizeof (int));
    
    // Criando grafo bi-direcional
    Grafo *gr = criaGrafo (nroVertices, nroVertices, ponderado);

    // Inserção de Arestas Ligando dois vértices
    while (scanf ("%d", &verticeA) != EOF){
        scanf ("%d", &verticeB);
        insereAresta (gr, verticeA, verticeB, digrafo, ponderado);
        imprimeGrafo (gr);
    }

    // Remoção de Arestas que ligam dois vértices
    while (scanf ("%d", &verticeA) != EOF){
        scanf ("%d", &verticeB);
        remove_Aresta (gr, verticeA, verticeB, digrafo);
        imprimeGrafo (gr);
    }

    // Realizando Busca em profundidade
    printf ("Realizando Busca em Profundidade bi-direcional para a posição do vértice no grafo: \n");
    busca_em_profundidade (gr, 0, verticeVisitado);
    for (int i = 0; i < 5; i++)
        printf ("%d: %d\n", i, verticeVisitado[i]);

    // Busca em Largura
    printf ("Realizando Busca em Largura bi-direcional para a posição do vértice: \n");
    busca_em_profundidade (gr, 0, verticeVisitado);
    for (int i = 0; i < 5; i++)
        printf ("%d: %d\n", i, verticeVisitado[i]);

    // Busca pelo menor caminho
    printf ("Realizando Busca pelo menor caminho: \n");
    busca_menor_caminho (gr, verticeInicial, verticeAnterior, distanciaVertice);

    libera_Grafo (gr);

    return 0;
}

Grafo *criaGrafo (int nro_vertices, int grau_max, int eh_ponderado){

    Grafo *gr = malloc (sizeof (Grafo));

    if (gr != NULL){
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0) ?1:0;
        
        gr->grau = calloc (nro_vertices, sizeof (int));
        
        // Inicializa os Vértices do grafo
        gr->arestas = malloc (nro_vertices * sizeof (int*));

        // Matriz de Arestas
        for (i = 0; i < nro_vertices; i++)
            gr->arestas[i] = malloc (grau_max * sizeof (int));

            // Matriz de Pesos
            if (gr->eh_ponderado){
                gr->pesos = malloc (nro_vertices * sizeof (float*));
                for (i = 0; i < nro_vertices; i++)
                    gr->pesos[i] = malloc (grau_max * sizeof (float));
            }
    }

    printf ("Grafo de %d Vértices e de grau máximo %d criado com sucesso!\n", nro_vertices, grau_max);
    return gr;
}
int insereAresta (Grafo *gr, int orig, int dest, int digrafo, float peso){

    // Verifica se o grafo existe
    if (gr == NULL)
        return 0;

    // Verifica se o vértice existe
    if (orig < 0 || orig >= gr->nro_vertices)
        return 0;

    if (dest < 0 || dest >= gr->nro_vertices)
        return 0;

    // Insere no final da Linha
    gr->arestas[orig][gr->grau[orig]] = dest;
    if (gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;

    // Aumenta em 1 o número de conexões    
    gr->grau[orig]++;

    if (digrafo == 0)
        insereAresta (gr, dest, orig, 1, peso);

    return 1;
}

int remove_Aresta (Grafo *gr, int orig, int dest, int eh_digrafo){

    // Verifica se o grafo existe
    if (gr == NULL)
        return 0;

    // Verifica se o vértice existe
    if (orig < 0 || orig >= gr->nro_vertices)
        return 0;

    if (dest < 0 || dest >= gr->nro_vertices)
        return 0;

    int i = 0;

    while (i < gr->grau[orig] && gr->arestas[orig][i] != dest)
        i++;
        
    if (i == gr->grau[orig]) //elemento nao encontrado
        return 0;

    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
    
    if (gr->eh_ponderado)
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];
    
    if (eh_digrafo == 0)
        remove_Aresta(gr,dest,orig,1);

    return 1;
}

void imprimeGrafo (Grafo *gr){

    if (gr == NULL)
        return;

    int i, j;
    for (i = 0; i < gr->nro_vertices; i++){
        printf ("%d: ", i);
        for (j = 0; j < gr->grau[i]; j++){
            if (gr->eh_ponderado)
                printf ("%d(%.2f), ", gr->arestas[i][j], gr->pesos[i][j]);
            else
                printf ("%d, ", gr->arestas[i][j]);
        }
        printf ("\n");
    }
}

void auxiliar_busca_em_profundidade (Grafo *gr, int ini, int *visitado, int cont){

    int i;
    // Marca o vértice como visitado
    // Visita os vizinhos ainda não visitados
    visitado[ini] = cont;
    for (i = 0; i < gr->grau[ini]; i++){
        if (!visitado[gr->arestas[ini][i]])
            auxiliar_busca_em_profundidade (gr, gr->arestas[ini][i], visitado, cont+1);
    }
}

void busca_em_profundidade (Grafo *gr, int ini, int *visitado){
    int i, cont = 1;
    // Marca vértices como não visitados
    for (i = 0; i < gr->nro_vertices; i++)
        visitado[i] = 0;
    auxiliar_busca_em_profundidade (gr, ini, visitado, cont);
}

/*
    Partindo de um vértice inicial, ela explora todos os vértices vizinhos. 
    Em seguida, para cada vértice vizinho, ela repete esse processo, visitando
    os vértices inexplorados. 
    Usada para:
        Achar componentes conectados.
        Achar todos os vértices conectados por apenas 1 componente.
        Achar o menor caminho entre dois vértices
        Testar bipartição em grafos. 
*/
void busca_em_largura (Grafo *gr, int ini, int *visitado){

    int i, vert, NV, cont = 1, *fila, IF = 0, FF = 0;

    // Marca vértices como não visitados
    for (i = 0; i < gr->nro_vertices; i++)
        visitado[i] = 0;

    // Cria fila.
    // Insere "ini" na fila
    NV = gr->nro_vertices;
    fila = malloc (NV * sizeof (int));
    FF++;
    fila[FF] = ini;
    visitado[ini] = cont;

    // Enquanto a fila não estiver vazia
    while (IF != FF){
        // Pega o primeiro elemento da fila
        IF = (IF + 1) % NV;
        vert = fila[FF];
        cont ++;
        // Visita os vizinhos ainda não visitados e coloca na fila
        for (i = 0; i < gr->grau[vert]; i++){
            if (!visitado[gr->arestas[vert][i]]){
                FF = (FF + 1) % NV;
                fila[FF] = gr->arestas[vert][i];
                visitado[gr->arestas[vert][i]] = cont;
            }
        }
    }
    free (fila);
}

// Função Auxiliar para procurar o vértice com a menor distância até o momento e não foi visitado
int procura_menor_distancia (float *dist, int *visitado, int NV){

    int i, menor = -1, primeiro = 1;
    for (i=0; i < NV; i++){
        if (dist[i] >= 0 && visitado[i] == 0){
            if (primeiro){
                menor = i;
                primeiro = 0;
            }else{
                if (dist[menor] > dist[i])
                    menor = i;
            }
        }
    }
    return menor;
}

void busca_menor_caminho (Grafo *gr, int ini, int *ant, float *dist){

    int i, cont, NV, ind, *visitado, vert;
    cont = NV = gr->nro_vertices;
    visitado = malloc(NV * sizeof(int));

    for(i=0; i < NV; i++){
        ant[i] = -1;
        dist[i] = -1;
        visitado[i] = 0;
    }

    dist[ini] = 0;

    while(cont > 0){
        vert = procura_menor_distancia (dist, visitado, NV);
        
        if(vert == -1)
            break;

        visitado[vert] = 1;
        cont--;

        for (i = 0; i<gr->grau[vert]; i++){
            ind = gr->arestas[vert][i];
            if (dist[ind] < 0){
               dist[ind] = dist[vert] + 1; 
               //ou peso da aresta
               // dist[ind] = dist[vert] + gr->pesos[vert][i];
               ant[ind] = vert;
            }else{
                if (dist[ind] > dist[vert] + 1){
                    dist[ind] = dist[vert] + 1; 
                    //ou peso da aresta
                    // dist[ind] = dist[vert] + gr->pesos[vert][i];
                    ant[ind] = vert;
                }
            }
        }
    }

    printf ("Distancia do Inicio até o vértice: \n");
    for (i = 0; i < 5; i++)
        printf ("%d: %1.f\n", i, dist[i]);

    printf ("Vertíces Anteriores: \n");
    for (i = 0; i < 5; i++)
        printf ("%d: %d\n", i, ant[i]);

    free(visitado);
}

void libera_Grafo (Grafo *gr){

    if (gr != NULL){

        int i;
        for (i = 0; i < gr->nro_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);

        if (gr->eh_ponderado){
            for (i = 0; i < gr->nro_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }

        free(gr->grau);
        free(gr);
        printf ("Grafo liberado com sucesso!\n");
    }
}
