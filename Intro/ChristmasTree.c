/************************//*    4    *//*    5    */
/*Christmas Tree ********//*    *    *//*    *    */
/************************//*   ***   *//*   ***   */
/************************//*    *    *//*    *    */
/*Asking Condition ******//*    *    *//*   ***   */
/*INPUT IS BIGGER THAN 0*//*  *****  *//*  *****  */
/*0 IS STOPING EXECUTE **//* ******* *//* ******* */
/************************//*    *    *//*    *    */
/************************//*    *    *//*    *    */
/*Input:4 . 5 ***********//*    *    *//*    *    */
/************************//*    *    *//*    *    */
/************************//*         *//*    *    */
#include <stdlib.h>
#include <stdio.h>

int main(){
	int ipt;
	while(1){
		scanf("%d",&ipt);
		if (ipt < 3)
			break;
		for (int i = 2;i < ipt+1;i+=2){
			for (int j = 0;j < i;j++){
				for (int k = 0;k < (ipt-j)-1;k++)
					printf(" ");
				for (int k = 0;k < (j+1)*2-1;k++)
					printf("*");
				printf("\n");
			}
		}
		for (int i = 0;i < ipt;i++){
			for (int k = 0;k < ipt-1;k++)
				printf(" ");
			printf("*\n");
		}
	}
}
