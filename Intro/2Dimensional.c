#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  //stdn is NUMBER OF STUDENT,subn is NUBMER OF SUBJECTS
  short stdn,subn,avg,regin;
  short ttl = 0;
  char strs[] = "AVG";

  FILE *fi;

  if ((fi = fopen("Input.txt","r")) == NULL)
    printf("Error\n");
  else{
    fscanf(fi,"%hd%hd",&stdn,&subn);
    char nos[stdn][10],sbn[subn+1][10];
    short sos[stdn][subn],avgn[stdn],cpre[stdn];
    for (int i = 0;i < stdn;i++){
      fscanf(fi,"%s",nos[i]);
      for (int j = 0;j < subn;j++)
        fscanf(fi,"%hd",&sos[i][j]);
    }
    for (int i = 0;i < subn;i++)
      fscanf(fi,"%s",sbn[i]);
    for (int i = 0;i < stdn;i++){
      for (int j = 0;j < subn;j++)
        ttl += sos[i][j];
      avgn[i] = ttl / subn;
      cpre[i] = avgn[i];
      ttl = 0;
    }
    for (int i = 0;i < stdn;i++)
      for (int j = 0;j < stdn;j++)
        if (cpre[i] > cpre[j]){
          regin = cpre[i];
          cpre[i] = cpre[j];
          cpre[j] = regin;
        }
    printf("NAME\t");
    for (int i = 0;i < subn;i++)
      printf("%s\t",sbn[i]);
    printf("%s\n",strs);
    for (int i = 0;i < stdn;i++){
      for (int j = 0;j < stdn;j++)
        if (cpre[i] == avgn[j]){
          printf("%s\t",nos[j]);
          for (int n = 0;n < subn;n++)
            printf("%d\t",sos[j][n]);
          printf("%d\t",avgn[j]);
          break;
        }
      printf("\n");
    }
  }
}
