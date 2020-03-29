#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *name;
    int age;
    char *adres;
    int pn;
    int id;
}person;

typedef struct{
    char *name;
    char *adres;
}registerBlock;

int swap(int *s1,int *s2){
    int regi;
    regi = *s1;
    *s1 = *s2;
    *s2 = regi;
    return 0;
}

int main(void){
    char fname[15],fadres[15];
    int fage,fpn,fid,cnt = 0,storage[100] = {};
    FILE *fi;

    person ps[100];
    registerBlock regi[100];

    if ((fi = fopen("Input.txt","r")) == NULL)
        printf("Error\n");
    else{
        while(!feof(fi)){
            fscanf(fi,"%s%d%s%d%d",fname,&fage,fadres,&fpn,&fid);
            ps[cnt].name = (char *)malloc(strlen(fname) + 1);
            strcpy(ps[cnt].name,fname);
            ps[cnt].age = fage;
            ps[cnt].adres = (char *)malloc(strlen(fadres) + 1);
            strcpy(ps[cnt].adres,fadres);
            ps[cnt].pn = fpn;
            ps[cnt].id = fid;
            cnt += 1;
        }
        for (int i = 0;i < cnt-1;i++){
            for (int j = i + 1;j < cnt;j++){
                if (ps[i].age > ps[j].age){
                    regi[i].name = (char *)malloc(strlen(ps[i].name) + 1);
                    strcpy(regi[i].name,ps[i].name);
                    strcpy(ps[i].name,ps[j].name);
                    strcpy(ps[j].name,regi[i].name);
                    regi[i].adres = (char *)malloc(strlen(ps[i].adres) + 1);
                    strcpy(regi[i].adres,ps[i].adres);
                    strcpy(ps[i].adres,ps[j].adres);
                    strcpy(ps[j].adres,regi[i].adres);
                    swap(&ps[i].age,&ps[j].age);
                    swap(&ps[i].pn,&ps[j].pn);
                    swap(&ps[i].id,&ps[j].id);
                }
            }
        }
        for (int i = 0;i < cnt;i++){
            printf("%s\t%d\t%s\t%d\t%d\n",ps[i].name,ps[i].age,ps[i].adres,ps[i].pn,ps[i].id);
        }
    }
}