#include <stdio.h>
#include <stdlib.h>

typedef struct Aresta{
    int verticeA;
    int verticeB;
} Aresta;

typedef struct Grafo {
    int qtdeVertices;  
    int qtdeArestas; 
    int **matrizAdj;
    int **tc;
} Grafo;

int **criaMatriz (int tam);
Aresta criaAresta (int verticeA, int verticeB);
Grafo *criaGrafo (int qtdeVertices);
void insereGrafo (Grafo *g, Aresta e, int dado);

void GrafoTc (Grafo *g);
int GrafoR (Grafo *g, int a, int b);

int main (void){

    int qtdeVertices, verticeA, verticeB, codigo;
    int rotaA, rotaB;

    scanf ("%d", &qtdeVertices);

    Grafo *g = criaGrafo (qtdeVertices);

    while (1) {
        scanf ("%d %d %d", &verticeA, &verticeB, &codigo);
        if (verticeA == 0 && verticeB == 0 && codigo == 0) break;           
        if (codigo > 0) insereGrafo (g, criaAresta (verticeA, verticeB), codigo);
    }
    GrafoTc (g);
   
    while (scanf("%d %d", &verticeA, &verticeB) != EOF){

        rotaA = GrafoR (g, verticeA, verticeB);
        rotaB = GrafoR (g, verticeB, verticeA);

        if (rotaA && rotaB) printf("Ida e Volta\n"); 
        else if (rotaA && rotaB == 0) printf("Apenas Ida\n"); 
        else if (rotaB && rotaA == 0) printf("Apenas Volta\n"); 
        else if (rotaA == 0 && rotaB == 0) printf("Impossibru\n"); 
    }
    return 0;
}

Aresta criaAresta (int verticeA, int verticeB){
    Aresta e;
    e.verticeA = verticeA;
    e.verticeB = verticeB;
    return e;
}

int **criaMatriz (int tam){
    int i, **m;
    m = malloc (tam * sizeof (int*));
    for (i = 0; i < tam; i++) m[i] = malloc (tam * sizeof (int));

    return m;
}

Grafo *criaGrafo (int qtdeVertices){
    Grafo *g = malloc (sizeof(g));
    g->qtdeVertices = qtdeVertices;
    g->qtdeArestas = 0;
    g->matrizAdj = criaMatriz (qtdeVertices);
    return g;
}

void insereGrafo (Grafo *g, Aresta e, int codigo){

    int verticeA = e.verticeA, verticeB = e.verticeB;
    
    if (g->matrizAdj[verticeA][verticeB] == 0) g->qtdeArestas++;
    
    if (codigo == 1) g->matrizAdj[verticeA][verticeB] = 1;
    
    else if (codigo == 2){
        g->matrizAdj[verticeA][verticeB] = 1;
        g->matrizAdj[verticeB][verticeA] = 1;
    }
}

// Implementação Floyd Marshall
void GrafoTc (Grafo *g){
    int i, s = 0, t;

    g->tc = criaMatriz(g->qtdeVertices);

    for (s = 0; s < g->qtdeVertices; s++) for(t = 0; t < g->qtdeVertices; t++) g->tc[s][t] = g->matrizAdj[s][t];
    
    for (s = 0; s < g->qtdeVertices; s++) g -> tc[s][s]=1;

    for (i = 0; i < g->qtdeVertices; i++){
        for (s = 0; s < g->qtdeVertices; s++){
            if (g->tc[s][i] == 1)
                for (t = 0; t < g->qtdeVertices; t++) if (g->tc[i][t] == 1) g->tc[s][t] = 1;
            
        }
    }
}

int GrafoR (Grafo *g, int a, int b){
    return g->tc[a][b];
}
