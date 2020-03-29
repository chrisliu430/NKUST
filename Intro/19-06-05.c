#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *word;
    int counter;
}Article;

typedef struct{
    char *word;
    int counter;
}ProcessArticle;

typedef struct{
    char *word;
    int counter;
}changeBlock;

typedef struct{
    char *word;
}regiStr;

int main(void){
    int start = 1,cnter = 0,writeSta = 0,cnterArt = 0,pscCnter = 0,control = 0,status = 0,regilen,statusCon,regiPos = 0;
    char iptS[30] = {};
    Article atcle[100];
    ProcessArticle pcsatcle[100];
    changeBlock cB[1];
    regiStr regS[1];

    FILE *fi;
    FILE *fw;

    if ((fi = fopen("/Users/chris/Desktop/Database/Testing/Article.txt","r,ccs=UTF-8")) == NULL){
        printf("ERROR\n");
    }else{
        while(!feof(fi)){
            if (start){
                start = 0;
                fscanf(fi,"%s",iptS);
                atcle[cnter].word = (char *)malloc(strlen(iptS) + 1);
                pcsatcle[pscCnter].word = (char *)malloc(strlen(iptS) + 1);
                strcpy(pcsatcle[pscCnter].word,iptS);
                for (int i = 0;i < strlen(iptS);i++){
                    if ((iptS[i] > 64 && iptS[i] < 91) || (iptS[i] > 96 && iptS[i] < 123) || (iptS[i] > 47 && iptS[i] < 58)){
                        atcle[cnter].word[i] = iptS[i];
                    }
                }
                atcle[cnter].counter = 1;
                cnter += 1;
                pscCnter += 1;
            }else{
                fscanf(fi,"%s",iptS);
                pcsatcle[pscCnter].word = (char *)malloc(strlen(iptS) + 1);
                //printf("%s\n",iptS);
                strcpy(pcsatcle[pscCnter].word,iptS);
                pscCnter += 1;
                regS[0].word = (char *)malloc(strlen(iptS) + 1);
                for (int i = 0;i < strlen(iptS);i++){
                    if ((iptS[i] > 64 && iptS[i] < 91) || (iptS[i] > 96 && iptS[i] < 123) || (iptS[i] > 47 && iptS[i] < 58)){
                        regS[0].word[cnterArt] = iptS[i];
                        cnterArt += 1;
                    }else if (cnterArt != 0){
                        break;
                    }
                }
                cnterArt = 0;
                for (int i = 0;i < cnter;i++){
                    if (strlen(atcle[i].word) != strlen(regS[0].word)){
                        continue;
                    }else{
                        for (int j = 0;j < strlen(iptS);j++){
                            if (regS[0].word[j] != atcle[i].word[j]){
                                writeSta = 1;
                                break;
                            }else{
                                writeSta = 0;
                                regiPos = i;
                            }
                        }
                    }
                }
                if (writeSta){
                    atcle[cnter].word = (char *)malloc(strlen(iptS) + 1);
                    for (int i = 0;i < strlen(iptS);i++){
                        if ((iptS[i] > 64 && iptS[i] < 91) || (iptS[i] > 96 && iptS[i] < 123) || (iptS[i] > 47 && iptS[i] < 58)){
                            atcle[cnter].word[cnterArt] = iptS[i];
                            cnterArt += 1;
                        }else if (cnterArt != 0){
                            break;
                        }
                    }
                    cnterArt = 0;
                    //printf("%s\n",atcle[cnter].word);
                    atcle[cnter].counter = 1;
                    cnter += 1;
                    writeSta = 0;
                }else{
                    atcle[regiPos].counter += 1;
                    writeSta = 0;
                }
            }
        }
        for (int i = 0;i < cnter;i++){
            for (int j = 0;j < cnter;j++){
                if (atcle[i].counter > atcle[j].counter){
                    cB[0].counter = atcle[i].counter;
                    atcle[i].counter = atcle[j].counter;
                    atcle[j].counter = cB[0].counter;
                    cB[0].word = (char *)malloc(strlen(atcle[i].word) + 1);
                    strcpy(cB[0].word,atcle[i].word);
                    atcle[i].word = (char *)malloc(strlen(atcle[j].word) + 1);
                    strcpy(atcle[i].word,atcle[j].word);
                    atcle[j].word = (char *)malloc(strlen(cB[0].word) + 1);
                    strcpy(atcle[j].word,cB[0].word);
                }
            }
        }
        for (int i = 0;i < cnter;i++){
            printf("%s : %d\n",atcle[i].word,atcle[i].counter);
        }
        fw = fopen("/Users/chris/Desktop/Database/Testing/NewArticle.txt","w");
        if (fw == NULL){
            printf("ERROR\n");
        }else{
            for (int j = 0;j < pscCnter;j++){
                //printf("%s\n",pcsatcle[j].word);
                if (j != 0){
                    fprintf(fw," ");
                }
                regilen = strlen(pcsatcle[j].word)-1;
                if (pcsatcle[j].word[regilen] == 46){
                    status = 1;
                }
                for (int i = 0;i < 6;i++){
                    if (strlen(atcle[i].word) != strlen(pcsatcle[j].word)){
                        control = 1;
                        continue;
                    }else{
                        for (int m = 0;m < strlen(atcle[i].word);m++){
                            //printf("%c : %c",atcle[i].word[m],pcsatcle[j].word[m]);
                            //printf("%d : %d\n",(int)atcle[i].word[m],(int)pcsatcle[j].word[m]);
                            if ((int)atcle[i].word[m] == (int)pcsatcle[j].word[m]){
                                statusCon = 1;
                            }else{
                                statusCon = 0;
                                break;
                            }
                        }
                        if (statusCon){
                            if (i == 0){
                                fprintf(fw,"!");
                            }else if (i == 1){
                                fprintf(fw,"~");
                            }else if (i == 2){
                                fprintf(fw,"*");
                            }else if (i == 3){
                                fprintf(fw,"#");
                            }else if (i == 4){
                                fprintf(fw,"@");
                            }else if (i == 5){
                                fprintf(fw,"&");
                            }
                            statusCon = 0;
                            control = 0;
                            break;
                        }else{
                            control = 1;
                        }
                    }
                }
                if (control){
                    fprintf(fw,"%s",pcsatcle[j].word);
                    control = 0;
                }
                if (status){
                    fprintf(fw,"\n");
                    status = 0;
                }
            }
        }
    }
}