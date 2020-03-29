/**************************//* Input:5 . 3 . 2 */
/*Counter Number Triangle *//*        *        */
/**************************//*       * *       */
/*Input:5 *****************//*      * * *      */
/**************************//*     * * * *     */
/*INPUT IS BIGGER THAN 0 **//*    * * * * *    */
/**************************//*        *        */
/*0 IS STOPING EXECUTE ****//*       * *       */
/**************************//*      * * *      */
/*NUMBER TRIANGLE IS FORM *//*        *        */
/*OF INPUT NUMBER *********//*       * *       */
/**************************//*                 */
#include <stdlib.h>
#include <stdio.h>

int main(){
	int ipt,arr[100] = {0},pos = 0,max = 0,sta = 0,posregi = 0;
	while(1){
		scanf("%d",&ipt);
		if (ipt == 0)
			break;
		while(ipt > 0){
			arr[pos] = ipt % 10;
			ipt /= 10;
			pos += 1;
		}
		for (int i = 99;i >= 0;i--){
			if (arr[i] != 0){
				if (arr[i] > max)
					max = arr[i];
				if (sta == 0){
					sta = 1;
					posregi = i;
				}
			}
		}
		//printf("MAX%d\n",max);
		for (int i = 0;i < 100;i++){
			if (arr[i] != 0){
				//printf("%d\n",arr[i]);
				for (int j = 0;j < arr[i];j++){
					for (int k = 0;k < max-(j+1);k++)
						printf(" ");
					for (int k = 0;k < j+1;k++){
						printf("*");
						if(j != 0)
							printf(" ");
					}
					printf("\n");
				}
			}
		}
		for (int i = posregi-1;i >= 0;i--){
			if (arr[i] != 0){
				//printf("%d\n",arr[i]);
				for (int j = 0;j < arr[i];j++){
					for (int k = 0;k < max-(j+1);k++)
						printf(" ");
					for (int k = 0;k < j+1;k++){
						printf("*");
						if(j != 0)
							printf(" ");
					}
					printf("\n");
				}
			}
		}
	}
}
