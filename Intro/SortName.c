#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
  char sdn[50][10];
  char ssdn[50][10];

  for (int i = 0;i < 50;i++)
    for (int j = 0;j < 10;j++)
      ssdn[i][j] = 95;

  int pos = 0,spos,nPs = 0;
  int x,y,col,row;;

  FILE *fi;
  FILE *fo;

  srand(time(NULL));

  if ((fi = fopen("Input.txt","r")) == NULL || ((fo = fopen("Output.txt","w")) == NULL))
    printf("Error\n");
  else{
    //fscanf(fi,"%d%d",&col,&row);
    while(!feof(fi)){
      fscanf(fi,"%s",sdn[pos]);
      pos += 1;
    }
    if (pos > 50){
      printf("Seat isn't enough.\n");
    }else{
      scanf("%d%d",&col,&row);
      for (int i = 0;i < pos;i++){
        while(1){
          x = rand() % 5;
          y = rand() % 10;
          spos = y * 5 + x;
          if (ssdn[spos][0] == 95){
            for (int j = 0;j < 10;j++){
              if (sdn[i][j] != 0){
                ssdn[spos][j] = sdn[i][j];
              }else{
                break;
              }
            }
            break;
          }
        }
      }
      for (int i = 0;i < 50;i++){
        for (int j = 0;j < 10;j++){
          fprintf(fo,"%c",ssdn[i][j]);
        }
        if ((i+1)/col > nPs){
          fprintf(fo,"\n");
          nPs += 1;
          if (nPs == row)
            break;
        }else{
          fprintf(fo," \t");
        }
      }
    }
  }
}
