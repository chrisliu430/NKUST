//Function 1:Translate Specific Years
//Function 2:Search Address
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    // Student
    char *num; //Number
    char *na; //Name
    char *ads;
    char *bth;
    char *phone;
}stdent;

int main(void){
    int cuter = 0,modChs,status = 0,posCnt,control;
    char iptW[100],schAds[50];
    FILE *fi;
    
    stdent std[100];

    if ((fi = fopen("/Users/chris/Desktop/Database/Testing/PersonalData.txt","r,ccs=UTF-8")) == NULL){
        printf("ERROR\n");
    }else{
        while(!feof(fi)){
            for(int i = 0;i < 5;i++){
                fscanf(fi,"%s",iptW);
                if(i == 0){
                    std[cuter].num = (char *)malloc(strlen(iptW) + 1);
                    strcpy(std[cuter].num,iptW);
                }else if (i == 1){
                    std[cuter].na = (char *)malloc(strlen(iptW) + 1);
                    strcpy(std[cuter].na,iptW);
                }else if (i == 2){
                    std[cuter].ads = (char *)malloc(strlen(iptW) + 1);
                    strcpy(std[cuter].ads,iptW);
                }else if (i == 3){
                    std[cuter].bth = (char *)malloc(strlen(iptW) + 1);
                    strcpy(std[cuter].bth,iptW);
                }else if (i == 4){
                    std[cuter].phone = (char *)malloc(strlen(iptW) + 1);
                    strcpy(std[cuter].phone,iptW);
                }
            }
            printf("%s %s %s %s %s\n",std[cuter].num,std[cuter].na,std[cuter].ads,std[cuter].bth,std[cuter].phone);
            cuter += 1;
        }
        while(1){
            printf("2 : Search Address\n1 : Translate Years\n0 : Exit\n");
            scanf("%d",&modChs);
            if (modChs == 0){
                break;
            }else if (modChs == 1){
                //Selection 1
                for (int i = 0;i < cuter;i++){
                    posCnt = 0;
                    control = 0;
                    printf("%s\t%s\t%s\t",std[i].num,std[i].na,std[i].ads);
                    while (1){
                        //printf("%d",strlen(std[i].bth));
                        for (int j = posCnt;j < strlen(std[i].bth);j++){
                            if (std[i].bth[j] < 48 || std[i].bth[j] > 57 || j > 7){
                                if (j > 7)
                                    printf("%c",std[i].bth[j]);
                                posCnt = j+1;
                                break;
                            }else if(j > 4 && j < 8){
                                printf("%c",std[i].bth[j]);
                            }else{
                                printf("%d",atoi(std[i].bth) - 1911);
                                posCnt = 5;
                                break;
                            }
                        }
                        if (posCnt == strlen(std[i].bth)){
                            break;
                        }
                    }
                    printf("\t%s\n",std[i].phone);
                }
            }else if (modChs == 2){
                //Selection 2
                scanf("%s",schAds);
                /*
                printf("%d%d%d\n",std[4].ads[9],std[4].ads[10],std[4].ads[11]);
                printf("%d%d%d\n",std[4].ads[12],std[4].ads[13],std[4].ads[14]);
                for (int i = 0;i < strlen(schAds)+1;i++){
                    printf("%d ",schAds[i]);
                }
                printf("\n");
                */
                for (int i = 0;i < cuter;i++){
                    status = 0;
                    posCnt = 0;
                    for (int j = 0;j <= strlen(std[i].ads);j++){
                        //printf("%s\n",std[i].ads);
                        //printf("%d %d\n",schAds[posCnt],std[i].ads[j]);
                        if ((int)schAds[posCnt] == 0 || (int)std[i].ads[j] == 0){
                            break;
                        }
                        if ((int)schAds[posCnt] == (int)std[i].ads[j]){
                            posCnt += 1;
                            status = 1;
                        }else{
                            if (posCnt == 0){
                                continue;
                            }else{
                                status = 0;
                                continue;
                            }
                        }
                    }
                    if (status){
                        printf("%s\t%s\t%s\t%s\t%s\n",std[i].num,std[i].na,std[i].ads,std[i].bth,std[i].phone);
                        status = 0;
                    }
                }
            }
        }
    }
    fclose(fi);
}