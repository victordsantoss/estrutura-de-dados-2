#include <stdio.h>
#include <stdlib.h>

int main (){
    int num_linhas, num, total = 0;
    scanf ("%d", &num_linhas);

    while (num_linhas > 0){
        scanf ("%d", &num);
        total += num;
        num_linhas --;
    }
    printf ("%d\n", total);

    return 0;
}