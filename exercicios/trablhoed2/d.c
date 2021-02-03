#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

typedef struct str{
    char s[100];
    char p[100];
} str;

int main(){
    int n;

    str *a, *b;
    int *w;
    int k = 0, cont = 0;
    scanf("%d", &n);
    a = malloc(n * sizeof(str));
    b = malloc(n * sizeof(str));
    w = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        scanf(" %[^@]%s", a[i].s, a[i].p);
       // printf("%s %s\n",a[i].s, a[i].p);
    }

    for(int i = 0; i < n; i++){
        k = 0;
        for(int j = 0; j < strlen(a[i].s); j++){
            if(a[i].s[j] != '.'){
                if(a[i].s[j] != '+'){
                    b[i].s[k++] = a[i].s[j];
                }
                else{
                    b[i].s[k++] = '\0';
                    break;
                }
            }
        }
        strcat(b[i].s, a[i].p);

    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(strcmp(b[i].s, b[j].s) == 0){
              b[j].s[0] = '+';
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(b[i].s[0]!= '+')
            cont++;
    }

    printf("%d\n",cont );
}
