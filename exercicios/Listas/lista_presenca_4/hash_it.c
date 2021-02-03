#include<stdio.h>
#include<stdlib.h>

int strcomparision(char *str1,char *str2);
int Hash(char *str);
int isfound(char *str,char *hashtable[101]);
void insert(char *str,char *hashtable[101]);
void delete(char *str,char *hashtable[101]);
void intialise_hashtable(char *hash_table[101]);
int type_of_operation(char *str);

int main(){
    int num_test;
    int num_operations;
    int i;
    int op;
    char *str=NULL;
    int sum;
    char *hash_table[101];
    scanf("%d",&num_test);
    while(num_test--){
        intialise_hashtable(hash_table);
        scanf("%d",&num_operations);
        for(i=0;i<num_operations;i++){
            str=(char *)malloc(sizeof(char)*20);
            scanf("%s",str);
            op=type_of_operation(str);
            
            if(op==0) insert(str+4,hash_table);
            else if(op==1) delete(str+4,hash_table);
        }
        for(i=0,sum=0;i<101;i++)
        if(hash_table[i]!=0) sum++;
        printf("%d\n",sum);
        for(i=0;i<101;i++)
            if(hash_table[i]!=0) printf("%d:%s\n",i,hash_table[i]);
   }
   return 0;
}

int strcomparision(char *str1,char *str2){
  int i;
  int value=1;
  for(i=0;(str1[i])&&(str2[i]);i++)
      if(str1[i]!=str2[i]) return 1;

  if(str1[i]==0 && str2[i]==0) return 0;
  return 1;
}

int Hash(char *str){
   int i;
   long long int h=0;

   for(i=0;str[i];i++) h=h+(str[i]*(i+1));
   h=(h*19);
   h=h%101;
   
   return h;
}

int isfound(char *str,char *hashtable[101]){
   int hashvalue=Hash(str);
   int j;
   int temph;
   
   for(j=0;j<=19;j++){
       temph=(hashvalue+(j*j)+(23*j));
       temph=temph%101;
       if(hashtable[temph]!=NULL && (strcomparision(str,hashtable[temph])==0)) return 1; 
   }
   return 0;
}

void insert(char *str,char *hashtable[101]){
   int hashvalue=Hash(str);
   int j;
   int temph;

   if(isfound(str,hashtable)==1)
   return;

    for(j=0;j<=19;j++){
        temph=(hashvalue+(j*j)+(23*j));
        temph= temph%101;
        if(hashtable[temph]==NULL){
            hashtable[temph]=str;
            return;
        }
   }
  return;
}

void delete(char *str,char *hashtable[101]){
   int hashvalue=Hash(str);
   int temph;
   int j;

   for(j=0;j<=19;j++){
    temph=(hashvalue+(j*j)+(23*j));
    temph = temph%101;

    if(hashtable[temph]==NULL);
    else if(strcomparision(str,hashtable[temph])==0){
       free(hashtable[temph]-4);
       hashtable[temph]=NULL;
    }
   }
   free(str-4);
   return;
}

void intialise_hashtable(char *hash_table[101]){
  int i;
  for(i=0;i<101;i++) hash_table[i]=0;
}

int type_of_operation(char *str){
   if(str[0]=='A') return 0; 
   else if(str[0]=='D') return 1; 
}
