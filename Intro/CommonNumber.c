/**************************//****************/
/**************************//****************/
/* Maximum Common Factor  *//* Input:20 15  */
/* &                      *//****************/
/* Least Common Multiple  *//****************/
/**************************//****************/
/*    Asking Condition    *//*   OUTPUT     */
/* FILE OPEN READ & WRITE *//* MAX:60 MIN:5 */
/**************************//****************/
#include <stdio.h>
#include <stdlib.h>

int main(){
  int com1,com2,max,min,regi,cbi;
  FILE *fi;
  FILE *fo;

  if ((fi = fopen("Input.txt","r")) == NULL || (fo = fopen("Output.txt","w")) == NULL )
    printf("Error\n");
  else{
    while(!feof(fi)){
      fscanf(fi,"%d%d",&com1,&com2);
      /* Ternary Operate */
      regi = com1 > com2 ? com2 : com1;
      for (int i = regi;i > 0;i--){
        if((com1 % i == 0) && (com2 % i == 0)){
          max = i;
          break;
        }
      }
      cbi = com1 * com2;
      min = cbi / max;
      fprintf(fo,"%d\t&\t%d\t Max:%d\t Min:%d\t\n",com1,com2,max,min);
    }
  }
  fclose(fi);
  fclose(fo);
}
