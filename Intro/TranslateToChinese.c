/******************************//**************/
/*Translate Number To Chinese *//**************/
/******************************//* OUTPUT *****/
/*Asking Condition ************//*壹萬 *********/
/*NUMBER IS LESS THAN 1000000 *//**************/
/*NUMBER IS BIGGER THAN 0 *****//**************/
/******************************//*玖萬玖千玖十玖*/
/*Input:10000 . 999999 ********//**************/
/******************************//**************/
#include <stdio.h>
#include <stdlib.h>

int regi[6] = {0},regipos = 0,jud = 0,sta = 0;

int Chinese(int num,int pos){
	if (num == 1 && pos != 5){
		printf("%s","壹");
		regipos = 0;
	}
	if (num == 2){
		printf("%s","貳");
		regipos = 0;
	}
	if (num == 3){
		printf("%s","參");
		regipos = 0;
	}
	if (num == 4){
		printf("%s","肆");
		regipos = 0;
	}
	if (num == 5){
		printf("%s","伍");
		regipos = 0;
	}
	if (num == 6){
		printf("%s","陸");
		regipos = 0;
	}
	if (num == 7){
		printf("%s","柒");
		regipos = 0;
	}
	if (num == 8){
		printf("%s","捌");
		regipos = 0;
	}
	if (num == 9){
		printf("%s","玖");
		regipos = 0;
	}
	if (num == 0){
		if (pos > 1){
			for (int i = pos-1;i >= 0;i--){
				if(regi[i] != 0){
					jud = 1;
					break;
				}
				else
					jud = 0;
			}
		}
		else {
			if (regi[0] != 0){
				jud = 1;
			}
			else
				jud = 0;
		}
		if (jud == 1 && regipos == 0){
			printf("%s","零");
			regipos = 1;
		}
	}
	if (pos == 5){
		for (int i = pos-1;i >= 0;i--){
			if (regi[i] != 0){
				sta = 1;
			}
			if (num != 0 && sta == 1){
				printf("%s","拾");
				break;
			}
			else{
				printf("%s","拾萬");
				break;
			}
		}
		sta = 0;
	}
	if (pos == 4 && num != 0)
		printf("%s","萬");
	if (pos == 3 && num != 0)
		printf("%s","仟");
	if (pos == 2 && num != 0)
		printf("%s","佰");
	if (pos == 1 && num != 0)
		printf("%s","拾");
}
int Process(int num){
	for (int i = num;i >= 0;i--){
		Chinese(regi[i],i);
	}
}

int main(){
	int ipt,count = 0;
	while(1){
		scanf("%d",&ipt);
		if (ipt < 1)
			break;
		while(ipt > 0 && ipt < 1000000){
			regi[count] = ipt%10;
			ipt /= 10;
			count += 1;
		}
		for (int i = 1;i <= count;i++){
			if (count == i)
				Process(i-1);
		}
		count = 0;
		for (int i = 0;i < 6;i++){
			regi[i] = 0;
		}
		if (ipt > 999999)
			printf("%s","重新輸入");
		printf("\n");
	}
	return 0;
}
