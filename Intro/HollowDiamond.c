/******************//***********/
/******************//* OUTPUT  */
/* Hollow Diamond *//*    #    */
/******************//*   # #   */
/*    Input:5     *//*  #   #  */
/******************//* #     # */
/******************//*#       #*/
/******************//* #     # */
/******************//*  #   #  */
/******************//*   # #   */
/******************//*    #    */
/******************//***********/
#include <stdlib.h>
#include <stdio.h>

int main(){
    int ipt;
    while (1){
        scanf("%d",&ipt);
        if (ipt < 1)
            break;
        for (int i = 0;i < ipt-1;i++)
            printf(" ");
        printf("*\n");
        for (int i = 1;i < ipt;i++){
            for (int j = ipt-i-1;j > 0;j--)
                printf(" ");
            printf("*");
            if (i != 1){
                for (int j = (i-1)*2+1;j > 0;j--)
                    printf(" ");
            }
            else
                printf(" ");
            printf("*\n");
        }
        if (ipt-1 > 1){
            for (int i = ipt-2;i > 0;i--){
                for (int j = ipt-i-1;j > 0;j--)
                    printf(" ");
                printf("*");
                for (int j = i*2-1;j > 0;j--)
                    printf(" ");
                printf("*\n");
            }
        }
        if (ipt > 1){
            for (int i = 0;i < ipt-1;i++)
                printf(" ");
            printf("*\n");
        }
    }
}
