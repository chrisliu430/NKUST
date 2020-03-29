/******************/
/*Fibonacci *******/
/******************/
/*Asking Condition*/
/*USING FUNCTION **/
/*USING RECURSIVE */
/******************/
#include <stdlib.h>
#include <stdio.h>

int out = 0;
int regi[4] = {1,1,2,0};

int Cal(int num){
	for (int i = 0;i < num-3;i++){
		for (int j = 0;j < 3;j++)
			regi[3] += regi[j];
		for (int j = 0;j < 3;j++)
			regi[j] = regi[j+1];
		regi[3] = 0;
	}
	regi[3] = 0;
	for (int i = 0;i < 3;i++){
		//printf("%d : %d\n",i,regi[i]);
		regi[3] += regi[i];
	}
	return regi[3];
}

int Initial(){
	regi[0] = 1;
	regi[1] = 1;
	regi[2] = 2;
	regi[3] = 0;
}

int main(){
	while(1){
		int ipt;
		scanf("%d",&ipt);
		if (ipt < 0)
			break;
		if (ipt > -1 && ipt < 3){
			regi[3] = regi[ipt];
		}
		else{
			regi[3] = 0;
			regi[3] = Cal(ipt);
		}
		printf("OUTPUT:%d\n",regi[3]);
		Initial();
	}
}
