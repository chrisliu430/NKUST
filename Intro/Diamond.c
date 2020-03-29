/**********//*    *    */
/*Diamond *//*   * *   */
/**********//*  *   *  */
/*Input:3 *//*   * *   */
/**********//*    *    */

#include <stdlib.h>
#include <stdio.h>

int main(){
	int ipt,num,count = 1;
	scanf("%d",&ipt);
	num = ipt*2;
	while (count != num){
		if (count <= ipt){
			if (count % 2 == 1){
				for (int i = 0;i < (num-count*2)/2;i++)
					printf(" ");
				for (int i = 0;i < count;i++){
					printf("*");
					if (count != 1)
						printf(" ");
				}
				for (int i = 0;i < (num-count*2)/2;i++)
					printf(" ");
			}
			else{
				for (int i = 0;i < (num-count*2)/2;i++)
					printf(" ");
				for (int i = 0;i < count;i++){
					printf("*");
					printf(" ");
				}
				for (int i = 0;i < (num-count*2)/2;i++)
					printf(" ");
			}
			printf("\n");
		}
		else {
			if (count % 2 == 1){
				for (int i = 0;i < (num-((num-count)*2))/2;i++)
					printf(" ");
				for (int i = 0;i < (num-count);i++){
					printf("*");
					if ((num-count) != 1)
						printf(" ");
				}
				for (int i = 0;i < (num-((num-count)*2))/2;i++)
					printf(" ");
			}
			else{
				for (int i = 0;i < (num-((num-count)*2))/2;i++)
					printf(" ");
				for (int i = 0;i < (num-count);i++){
					printf("*");
					printf(" ");
				}
				for (int i = 0;i < (num-((num-count)*2))/2;i++)
					printf(" ");
			}
			printf("\n");
		}
		count += 1;
	}
}
