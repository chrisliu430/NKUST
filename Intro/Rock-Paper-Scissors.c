/***********************/
/*Rock-Paper-Scissors **/
/***********************/
/*Asking Condition *****/
/*USING RANDOM FUNCTION*/
/*CAN BET & CHIP IS 100*/
/***********************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int coin = 100,num,coipt,ipt;

int judge(){
	if (ipt == num){
		if (ipt == 1){
			printf("玩家為：剪刀\n");
			printf("電腦為：剪刀\n");
		}
		if (ipt == 2){
			printf("玩家為：石頭\n");
			printf("電腦為：石頭\n");
		}
		if (ipt == 3){
			printf("玩家為：布\n");
			printf("電腦為：布\n");
		}
		printf("結果為平手\n");
	}
	else if ((ipt == 1 && num == 2)||(ipt == 2 && num == 3)||(ipt == 3 && num == 1)){
		if (ipt == 1){
			printf("玩家為：剪刀\n");
			printf("電腦為：石頭\n");
		}
		if (ipt == 2){
			printf("玩家為：石頭\n");
			printf("電腦為：布\n");
		}
		if (ipt == 3){
			printf("玩家為：布\n");
			printf("電腦為：剪刀\n");
		}
		printf("結果為電腦勝\n");
		coin -= coipt;
	}
	else{
		if (ipt == 1){
			printf("玩家為：剪刀\n");
			printf("電腦為：布\n");
		}
		if (ipt == 2){
			printf("玩家為：石頭\n");
			printf("電腦為：剪刀\n");
		}
		if (ipt == 3){
			printf("玩家為：布\n");
			printf("電腦為：石頭\n");
		}
		printf("結果為玩家勝\n");
		coin += coipt;
	}
	return 0;
}

int main(){
	srand(time(NULL));
	while(coin > 0){
		printf("籌碼：%d\n",coin);
		num = (rand() % 3) + 1;
		printf("輸入籌碼\n");
		scanf("%d",&coipt);
		if (coin >= coipt){
			printf("1:剪刀\n");
			printf("2:石頭\n");
			printf("3:布\n");
			printf("亂數產生：%d\n",num);
			scanf("%d",&ipt);
			if (ipt < 4 && ipt > 0)
				judge();
		}
	}
	printf("遊戲結束");
}
