/***************************************/
/*Random Number Counter ****************/
/***************************************/
/*Asking Condition *********************/
/*FILE OPEN READ & WRITE # CHOOSE MODE */
/*RANDOM NUMBER RANGE IS DESIGNATION ***/
/***************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int dat,cnt,num[100] = {0},max,min;
  FILE *fi;
  FILE *fo;
  while(1){
    printf("1:Radom Number\t\n2:Count Number\t\n3:Exit\t\n");
    scanf("%d",&cnt);
    if (cnt == 1){
      for (int i = 0;i < 100;i++){
        num[i] = 0;
      }
      if ((fi = fopen("Input.txt","w")) == NULL){
        printf("Error\n");
      }else{
        scanf("%d%d%d",&min,&max,&cnt);
        for (int i = 0;i < cnt;i++){
          dat = rand() % (max-min+1) + min;
          if(i != cnt-1)
            fprintf(fi,"%d\n",dat);
          else
            fprintf(fi,"%d",dat);
        }
      }
      fclose(fi);
    }
    if (cnt == 2){
      cnt = 0;
      if ((fi = fopen("Input.txt","r")) == NULL || (fo = fopen("Output.txt","w")) == NULL)
        printf("Error\n");
      else{
        while(!feof(fi)){
          fscanf(fi,"%d",&dat);
          for (int i = 0;i < 100;i++){
            if (i+1 == dat){
              num[i] += 1;
              break;
            }
          }
        }
        for (int i = 0;i < 100;i++){
          if (num[i] != 0){
            fprintf(fo,"%d\t出現次數:%d\t\n",i+1,num[i]);
            printf("%d\t出現次數:%d\t\n",i+1,num[i]);
            cnt += 1;
          }
        }
        fprintf(fo,"次數共計:%d\n",cnt);
        printf("次數共計:%d\n",cnt);
      }
      fclose(fi);
      fclose(fo);
    }
    if (cnt == 3)
      break;
  }
}
