#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
  char nF[100][10];
  char nB[100][10];

  for (int i = 0;i < 100;i++){
    for (int j = 0;j < 10;j++){
      nF[i][j] = 0;
      nB[i][j] = 0;
    }
  }

  int posF = 0,posB = 0;
  int ipt = 0;
  int noF = 0,noB = 0;
  int ckSta = 0,regiP = 0;

  FILE *fi1;
  FILE *fi2;

  srand(time(NULL));

  if ((fi1 = fopen("Input1.txt","r")) == NULL || ((fi2 = fopen("Input2.txt","r")) == NULL))
    printf("Error\n");
  else{
    while(!feof(fi1)){
      fscanf(fi1,"%s",nF[posF]);
      posF += 1;
    }
    while(!feof(fi2)){
      fscanf(fi2,"%s",nB[posB]);
      posB += 1;
    }
    while(1){
      scanf("%d",&ipt);
      if (ipt == 0)
        break;
      int nFP[100] = {-1},nBP[100] = {-1};
      char nT[100][20] = {0};
      noF = rand() % posF;
      nFP[0] = noF;
      noB = rand() % posB;
      nBP[0] = noB;
      for (int i = 0;i < ipt-1;i++){
        while(1){
          noF = rand() % 10;
          noB = rand() % 10;
          for (int j = 0;j < ipt;j++){
            if (nFP[i] == -1)
              break;
            else{
              if (nFP[i] != noF || nBP[i] != noB)
                ckSta = 1;
              else{
                ckSta = 0;
                break;
              }
            }
          }
          if (ckSta == 1)
            break;
        }
        nFP[i+1] = noF;
        nBP[i+1] = noB;
      }
      for (int i = 0;i < ipt;i++){
        //regiP = nFP[i];
        for (int j = 0;j < 10;j++){
          if (nF[regiP][j] != "\0")
            printf("%c",nF[nFP[i]][j]);
          else
            break;
        }
        //regiP = nBP[i];
        for (int j = 0;j < 10;j++){
          if (nB[regiP][j] != "\0")
            printf("%c",nB[nBP[i]][j]);
          else
            break;
        }
        printf("\n");
      }
    }
  }
}
