#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *word;
    int count;
}strCount;

int checkChar(char iptS[],char chkS[]){
    int status = 0;
    for (int i = 0;i < strlen(iptS);i++){
        if (iptS[i] == '\0'){
            break;
        }
        if (iptS[i] == chkS[i]){
            status = 1;
        }else{
            status = 0;
            break;
        }
    }
    //printf("\n");
    if (status){
        return 1;
    }else{
        return 0;
    }
}

int main(void){
    char iptW[50],regS[50];
    int cuter = 0,resta = 0,status,regN;

    FILE *fi;
    strCount sCnt[300];
    for (int i = 0;i < 300;i++){
        sCnt[i].count = 0;
    }

    if ((fi = fopen("/Users/chris/Desktop/Database/Testing/Article.txt","r,ccs=UTF-8")) == NULL){
        printf("ERROR\n");
    }else{
        while(!feof(fi)){
            fscanf(fi,"%s",iptW);
            //printf("%s\n",iptW);
            if (cuter == 0){
                sCnt[cuter].word = (char *)malloc(strlen(iptW) + 1);
                strcpy(sCnt[cuter].word,iptW);
                sCnt[cuter].count = 1;
                //printf("%s %d %s %d\n",iptW,cuter,sCnt[cuter].word,sCnt[cuter].count);
                cuter += 1;
            }else{
                status = 1;
                //printf("%s : %d\n",sCnt[cuter].word,sCnt[cuter].count);
                for (int i = 0;i < cuter;i++){
                    /*
                    if (strlen(sCnt[i].word) != strlen(iptW)){
                        continue;
                    }
                    */
                    resta = checkChar(iptW,sCnt[i].word);
                    if (resta){
                        sCnt[i].count += 1;
                        status = 0;
                        break;
                    }
                }
                if (status){
                    sCnt[cuter].word = (char *)malloc(strlen(iptW) + 1);
                    strcpy(sCnt[cuter].word,iptW);
                    sCnt[cuter].count = 1;
                    cuter += 1;
                }
                //printf("%s %d %s %d\n",iptW,cuter-1,sCnt[cuter-1].word,sCnt[cuter-1].count);
            }
        }
        //printf("\n");
        for (int i = 0;i < cuter-1;i++){
            for (int j = i + 1;j < cuter;j++){
                if (sCnt[i].count < sCnt[j].count){
                    strcpy(regS,sCnt[i].word);
                    strcpy(sCnt[i].word,sCnt[j].word);
                    strcpy(sCnt[j].word,regS);
                    regN = sCnt[i].count;
                    sCnt[i].count = sCnt[j].count;
                    sCnt[j].count = regN;
                }
            }
        }
        for (int i = 0;i < cuter-1;i++){
            for (int j = i+1;j < cuter;j++){
                if (strlen(sCnt[i].word) < strlen(sCnt[j].word) && sCnt[i].count == sCnt[j].count){
                    strcpy(regS,sCnt[i].word);
                    strcpy(sCnt[i].word,sCnt[j].word);
                    strcpy(sCnt[j].word,regS);
                    regN = sCnt[i].count;
                    sCnt[i].count = sCnt[j].count;
                    sCnt[j].count = regN;
                }
            }
        }
        for (int i = 0;i < cuter;i++){
            printf("%s : %d\n",sCnt[i].word,sCnt[i].count);
        }
    }
}