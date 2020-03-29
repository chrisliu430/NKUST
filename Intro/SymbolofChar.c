/******************//* \%%%|%%%/ */
/******************//* %\$@|@$/% */
/*Symbol of * CHAR*//* %$\$|$/$% */
/******************//* %@$\|/$@% */
/******************//* ----#---- */
/******************//* %@$/|\$@% */
/*Input:5 *********//* %$/$|$\$% */
/******************//* %/$@|@$\% */
/******************//* /%%%|%%%\ */
#include <stdlib.h>
#include <stdio.h>

int main(){
	int ipt;
	int count = 2;
	scanf("%d",&ipt);
	//Up Block
	//while (ipt > 0){
		for (int i = 0;i < ipt;i++){
			//Up-Left Block
			for (int j = 0;j < ipt;j++){
				if (i != j && j == 0){
					printf("%%");
				}
				else if (i == j){
					printf("\\");
					count = 2;
				}
				else{
					if (i == 0)
						printf("%%");
					else if(count % 2 == 0)
						printf("$");
					else
						printf("@");
					count += 1;
				}
			}
			printf("|");
			//Up-Right Block
			for (int j = ipt;j > 0;j--){
				if ((j == 1)&&(i != j-1))
					printf("%%");
				else if (i == j-1){
					printf("/");
					count = 1;
				}
				else{
					if (i == 0)
						printf("%%");
					else if (count % 2 == 0)
						printf("@");
					else
						printf("$");
					count += 1;
				}
			}
			count += 1;
			printf("\n");
		}
		//Slice Line
		for (int i = 0;i < 1;i++){
			for (int j = 0;j < ipt;j++)
				printf("-");
			printf("#");
			for (int j = 0;j < ipt;j++)
				printf("-");
			printf("\n");
		}
		//Down Block
		for (int i = ipt;i > 0;i--){
			//Down-Left Block
			for (int j = 0;j < ipt;j++){
				if ((j == 0)&&(i != j+1))
					printf("%%");
				else if (i == j+1){
					printf("/");
					count = 1;
				}
				else{
					if (i == 1)
						printf("%%");
					else if(count%2 == 0)
						printf("@");
					else
						printf("$");
					count += 1;
				}
			}
			printf("|");
			//Down-Right Block
			for (int j = ipt;j > 0;j--){
				if ((j == 1)&&(j != i))
					printf("%%");
				else if (j == i){
					printf("\\");
					count = 2;
				}
				else{
					if (i == 1)
						printf("%%");
					else if((count%2) == 0)
						printf("$");
					else
						printf("@");
					count += 1;
				}
			}
			count += 1;
			printf("\n");
		}
		//scanf("%d",&ipt);
	//}
}
