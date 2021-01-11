### T1: Estabilidade de um algoritimo de Ordenação
A estabilidade de um algoritimo de ordenação baseia-se na forma a qual ele trata a ordem relativa dos itens iguais. Um algoritimo de ordenação é estável se a ordem relativa dos itens iguais não se altera durante o processo de ordenação, já um algoritimo instável tem a ordem relativa dos itens iguais mudada durante esse processo. 

Pelo InsertionSort ser um algoritimo Estável, um exemplo que exercicta sua estabilidade é quando ele recebe um conjunto de N números aleatórios. Como por exemplo:

Suponha i como um indicador de índice. 

1. Ordem do vetor: 
    |0|1|2|3|4| 
2. Vetor:
    |5|10|7|4|10|

* 1º
    |5|10|7|4|10|
* 2º
    |5|7|10|4|10|
* 3º
    |4|5|7|10|10|
* 4º
    |4|5|7|10|10| -> Nesse passo não ocorre a troca de posião entre os elementos iguais, comprovando ser um algoritimo estável.


Funcionamento: O insertion Sort irá em cada passo a partir do elemento i + 1 realizar uma comparação com sequência de elementos anteriores, fazendo comparações e colocando os elementos no local apropriado, ao chegar em um comparação com elementos iguais (10 e 10) ele não irá realizar a troca de posição dos elementos, comprovando ser um algoritimo estável.


### T2: Separa

Essa função mostra um resultado errado ao receber um vetor de itens aleatorios contendo ou não números repetidos. 

Ao trocarmos o return para i-1, a ordenação continua ineficiente para casos de vetores reversos ou aleatórios.

Sim, ao aplicarmos uma função recursiva baseada na condicional do "pivô".

    int sep ( int v[], int p, int r) {
        
        int q, i, j, t;
        i = p; 
        q = v[(p + r) / 2]; 
        j = r;
        
        while (i <= j) {

            while (v[i] < q && i < r) i++;

            while (v[j] > q && j > p) j--;

            if(i <= j) {

                t = v[i];
                v[i] = v[j];
                v[j] = t;
                i++;
                j--;
                
            }
        }
        
        if (j > p) sep (v, p, j);
        if (i < r) sep (v, i, r);
    }

