/*********************//***************/
/*********************//***************/
/* Slice Cake Number *//***************/
/*********************//***************/
/*      Input:5      *//*  OUTPUT:16  */
/*********************//***************/
/*      Input:6      *//*  OUTPUT:22  */
/*********************//***************/
#include <stdlib.h>
#include <stdio.h>

int num = 1;

int recu(int regi){
    if (regi == 1)
        return num+regi;
    else
        return regi+recu(regi-1);
}

int main(){
    int ipt;
    scanf("%d",&ipt);
    printf("%d\n",recu(ipt));
}
