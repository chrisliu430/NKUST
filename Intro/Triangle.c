/******************//*    1    */
/*Number Triangle *//*   2 2   */
/******************//*  3   3  */
/*Input:5 *********//* 4     4 */
/******************//*5 5 5 5 5*/
#include <stdlib.h>
#include <stdio.h>

int main(){
	int ipt,num,count = 1;
	scanf("%d",&ipt);
	while (count != ipt+1){
		if (count == 1){
			for (int i = 0;i < ipt-1;i++)
				printf(" ");
			printf("%d",count);
			for (int i = 0;i < ipt-1;i++)
				printf(" ");
		}
		else if (count < ipt && count > 1){
			for (int i = 0;i < ipt-count;i++)
				printf(" ");
			printf("%d",count);
			for (int i = 0;i < count*2-3;i++)
				printf(" ");
			printf("%d",count);
			for (int i = 0;i < ipt-count;i++)
				printf(" ");
		}
		else if (count == ipt){
			for (int i = 0;i < ipt;i++){
				printf("%d",count);
				printf(" ");
			}
		}
		printf("\n");
		count += 1;
	}
}
