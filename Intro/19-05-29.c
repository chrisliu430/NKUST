#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function */
/* 1 All Person Data */
/* 2 All Item Data */
/* 3 Buy Process */
/* 4 All Buy Data */
/* 1 Personal Buy Data */
/* 6 Exit */

typedef struct{
    int id;
    char *name;
    char *ads;
}person;

typedef struct{
    int id;
    char *name;
    int cost;
    int num;
}item;

int main(void){
    int status = 0,check,cost;
    int perCuter = 0,itemCuter = 0,iptS,iptPID,iptIID,iptNum;
    int tPID,tIID,tNum,searchID;
    /* Person Data & Item Data*/
    int perD1,itemD1,itemD2,itemD3;
    char perC1[10],perC2[20],itemC1[15];
    FILE *fi;
    FILE *fo;

    person person[10];
    item item[20];
    if ((fi = fopen("/Users/chris/Desktop/TextData/Testing/P_I_T.txt","w,ccs=UTF-8")) == NULL){
        printf("ERROR\n");
    }else{
        fprintf(fi,"%d",-1);
    }
    fclose(fi);
    if ((fi = fopen("/Users/chris/Desktop/TextData/Testing/Personal.txt","r,ccs=UTF-8")) == NULL){
        printf("ERROR\n");
    }else{
        while(!feof(fi)){
            fscanf(fi,"%d%s%s",&perD1,perC1,perC2);
            person[perCuter].id = perD1;
            person[perCuter].name = (char *)malloc(strlen(perC1) + 1);
            strcpy(person[perCuter].name,perC1);
            person[perCuter].ads = (char *)malloc(strlen(perC2) + 1);
            strcpy(person[perCuter].ads,perC2);
            //printf("%d %s %s\n",person[perCuter].id,person[perCuter].name,person[perCuter].ads);
            perCuter += 1;
        }
    }
    fclose(fi);
    if ((fi = fopen("/Users/chris/Desktop/TextData/Testing/Item.txt","r,ccs=UTF-8")) == NULL){
        printf("ERROR\n");
    }else{
        while(!feof(fi)){
            fscanf(fi,"%d%s%d%d",&itemD1,itemC1,&itemD2,&itemD3);
            item[itemCuter].id = itemD1;
            item[itemCuter].name = (char *)malloc(strlen(perC1) + 1);
            strcpy(item[itemCuter].name,itemC1);
            item[itemCuter].cost = itemD2;
            item[itemCuter].num = itemD3;
            printf("%d %s %d %d\n",item[itemCuter].id,item[itemCuter].name,item[itemCuter].cost,item[itemCuter].num);
            itemCuter += 1;
        }
    }
    fclose(fi);
    while (1){
        printf("Mode 1:所有購買人資料\nMode 2:所有物品資料\nMode 3:建立交易資料\nMode 4:觀看所有交易紀錄\nMode 5:查詢購買人的所有交易紀錄\nMode 6:離開\n");
        printf("Choose Mode:");
        scanf("%d",&iptS);
        if (iptS == 1){
            for (int i = 0;i < perCuter;i++){
                printf("%d %s %s\n",person[i].id,person[i].name,person[i].ads);
            }
        }else if (iptS == 2){
            for (int i = 0;i < itemCuter;i++){
                printf("%d %s %d %d\n",item[i].id,item[i].name,item[i].cost,item[i].num);
            }
        }else if (iptS == 3){
            for (int i = 0;i < perCuter;i++){
                printf("%d %s %s\n",person[i].id,person[i].name,person[i].ads);
            }
            printf("輸入購買人ID");
            scanf("%d",&iptPID);
            for (int i = 0;i < itemCuter;i++){
                printf("%d %s %d %d\n",item[i].id,item[i].name,item[i].cost,item[i].num);
            }
            printf("輸入物品ID與物品數量");
            scanf("%d",&iptIID);
            scanf("%d",&iptNum);
            if (item[iptIID - 1].num != 0 && ((item[iptIID - 1].num - iptNum) > -1)){
                if ((fi = fopen("/Users/chris/Desktop/TextData/Testing/P_I_T.txt","r")) == NULL){
                    printf("No Data.\n");
                }else{
                    fscanf(fi,"%d",&tNum);
                    fclose(fi);
                    if (tNum == -1){
                        fo = fopen("/Users/chris/Desktop/TextData/Testing/P_I_T.txt","w");
                        fprintf(fo,"%d %d %d",iptPID - 1,iptIID - 1,iptNum);
                        item[iptIID - 1].num -= iptNum;
                        fclose(fo);
                    }else{
                        fo = fopen("/Users/chris/Desktop/TextData/Testing/P_I_T.txt","a");
                        fprintf(fo,"\n%d %d %d",iptPID - 1,iptIID - 1,iptNum);
                        item[iptIID - 1].num -= iptNum;
                        fclose(fo);
                    }
                }
            }else if ((item[iptIID - 1].num - iptNum) < 0){
                printf("Too Big.\n");
            }else{
                printf("This Item is Empty.\n");
            }
        }else if (iptS == 4){
            if ((fi = fopen("/Users/chris/Desktop/TextData/Testing/P_I_T.txt","r,ccs=UTF-8")) == NULL){
               printf("ERROR\n");
            }else{
                while (!feof(fi)){
                    fscanf(fi,"%d %d %d",&tPID,&tIID,&tNum);
                    //if (tNum != 0)
                    //printf("%d %d %d\n",tPID,tIID,tNum);
                    printf("%s %s %s %d %d\n",person[tPID].name,person[tPID].ads,item[tIID].name,item[tIID].cost,tNum);
                }
            }
            fclose(fi);
        }else if (iptS == 5){
            cost = 0;
            for (int i = 0;i < perCuter;i++){
                printf("%d %s %s\n",person[i].id,person[i].name,person[i].ads);
            }
            scanf("%d",&searchID);
            if ((fi = fopen("/Users/chris/Desktop/TextData/Testing/P_I_T.txt","r,ccs=UTF-8")) == NULL){
               printf("ERROR\n");
            }else{
                while (!feof(fi)){
                    fscanf(fi,"%d %d %d",&tPID,&tIID,&tNum);
                    if (searchID-1 == tPID){
                        printf("%s %s %s %d %d\n",person[tPID].name,person[tPID].ads,item[tIID].name,item[tIID].cost,tNum);
                        cost += (item[tIID].cost*tNum);
                    }
                }
                printf("Total : %d\n",cost);
            }
            fclose(fi);
        }else if (iptS == 6){
            break;
        }
    }
}