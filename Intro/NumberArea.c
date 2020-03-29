/******************//* 33333 */
/*Number Area *****//* 32223 */
/******************//* 32123 */
/*Input:2 *********//* 32223 */
/******************//* 33333 */
#include <stdlib.h>
#include <stdio.h>

int main(){
	int ipt,count = 0;
	scanf("%d",&ipt);
	for (int i = ipt+1;i > 0;i--){
		for (int j = 0;j < count;j++)
			printf("%d",(ipt+1)-j);
		for (int j = ((ipt*2)+1)-(count*2);j > 0;j--)
			printf("%d",(ipt+1)-count);
		for (int j = 1;j <= count;j++)
			printf("%d",ipt+j-(count-1));
		count += 1;
		printf("\n");
	}
	count -= 1;
	for (int i = ipt;i > 0;i--){
		count -= 1;
		for (int j = 0;j < count;j++)
			printf("%d",(ipt+1)-j);
		for (int j = ((ipt*2)+1)-(count*2);j > 0;j--)
			printf("%d",(ipt+1)-count);
		for (int j = 1;j <= count;j++)
			printf("%d",ipt+j-(count-1));
		printf("\n");
	}
}
