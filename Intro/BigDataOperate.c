/*********************************************/
/*Big-Data Operate ***************************/
/*********************************************/
/*Asking Condition ***************************/
/*FILE OPEN READ & WRITE # CHOOSE MODE *******/
/*DATA TYPE CAN'T USE BUILT-IN NUMBER TYPE ***/
/*OPERATE POSITIVE VALUE & NEGATIVE VALUE ****/
/*********************************************/
/*Note:This Code isnt IDEAL-CODE & Unfinished*/
/*********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(com1,com2) com1 > com2 ? com1 : com2

FILE *fi;
FILE *fo;

char n1[400] = {0},n2[400] = {0},sn[400] = {0};
short opn1[400] = {0},opn2[400] = {0};
short ans[401] = {0};
int nar[10] = {48,49,50,51,52,53,54,55,56,57}; // ASCII Code about Number that from 1 to 10 & NULL
int psn1 = 399,psn2 = 399,psna = 0,reps = 0; // psn1 & psn2 is record number array null position
int carn = 0,sta1,sta2,ctl = 0,sct = 0;// carn is record carry-number & ren is record remainder-number
int mps = 0,count = 0,resta = 0;// mps is record that psn1 & psn2 compare max bit & ans is record calculate answer

char stn1[400] = {0},stn2[400] = {0};
short pos1[400] = {0},pos2[400] = {0};
short posans[401] = {0};
int posnar[10] = {48,49,50,51,52,53,54,55,56,57}; // ASCII Code about Number that from 1 to 10 & NULL
int pospsn1 = 399,pospsn2 = 399,pospsna = 0; // pospsn1 & pospsn2 is record number array null position
int poscarn = 0;// poscarn is record carry-number & ren is record remainder-number
int posmps = 0;// posmps is record that pospsn1 & pospsn2 compare max bit & posans is record calculate answer

int stateset(){
  if (n1[0] == 45 && n2[0] != 45){
    for (int i = 399;i > 0;i--)
      if (n1[i] != 0 && n1[i] != '\0')
        for (int j = 0;j < 10;j++)
          if (n1[i] == nar[j]){
            opn1[psn1] = -j;
            psn1 -= 1;
          }
    for (int i = 399;i >= 0;i--)
      if (n2[i] != 0 && n2[i] != '\0')
        for (int j = 0;j < 10;j++)
          if (n2[i] == nar[j]){
            opn2[psn2] = j;
            psn2 -= 1;
          }
  }else if (n1[0] != 45 && n2[0] == 45){
    //negdata1();
    for (int i = 399;i >= 0;i--)
      if (n1[i] != 0 && n1[i] != '\0')
        for (int j = 0;j < 10;j++)
          if (n1[i] == nar[j]){
            opn1[psn1] = j;
            psn1 -= 1;
          }
    for (int i = 399;i > 0;i--)
      if (n2[i] != 0 && n2[i] != '\0')
        for (int j = 0;j < 10;j++)
          if (n2[i] == nar[j]){
            opn2[psn2] = -j;
            psn2 -= 1;
          }
  }else if (n1[0] == 45 && n2[0] == 45){
    //negdata1();
    for (int i = 399;i > 0;i--)
      if (n1[i] != 0 && n1[i] != '\0')
        for (int j = 0;j < 10;j++)
          if (n1[i] == nar[j]){
            opn1[psn1] = -j;
            psn1 -= 1;
          }
    for (int i = 399;i > 0;i--)
      if (n2[i] != 0 && n2[i] != '\0')
        for (int j = 0;j < 10;j++)
          if (n2[i] == nar[j]){
            opn2[psn2] = -j;
            psn2 -= 1;
          }
  }
}

int autocomp(){
  if (mps == 399-psn1){
    for (int i = psn2;i > psn1;i--)
      opn2[i] = 0;
  }else
    for (int i = psn1;i > psn2;i--)
      opn1[i] = 0;
}

int negplus(){
  //printf("OPN1-399:%d\nOPN2-399:%d\n",opn1[399-mps+1],opn2[399-mps+1]);
  if (opn1[399-mps+1] < 0 && opn2[399-mps+1] < 0){
    //printf("IF1\n");
    for (int i = 399;i > 399-mps+1;i--){
      //printf("FOR1\n");
      opn1[i] *= -1;
      opn2[i] *= -1;
    }
    for (int i = 399;i > 399-mps+1;i--){
      //printf("FOR2\n");
      if ((opn1[i] + opn2[i] + carn) > 9){
        ans[psna] = (opn1[i] + opn2[i] + carn) % 10;
        carn = (opn1[i] + opn2[i] + carn) / 10;
      }else{
        ans[psna] = opn1[i] + opn2[i] + carn;
        carn = 0;
      }
      psna += 1;
    }
    carn *= -1;
    ans[psna] = opn1[399-mps+1] + opn2[399-mps+1] + carn;
  }else if (psn1 > psn2){ //N1 Bit less than N2 Bit and N1 is positive
    if (opn1[psn1+1] < opn2[psn2+1]){
      opn2[psn2+1] += 1;
      ans[psna] = opn2[psn2+1];
      for (int i = psn2+2;i < 400;i++){
        if ((opn1[i]+opn2[i]+carn) > 9){
          ans[psna] = (opn1[i]+opn2[i]+carn) % 10;
          carn = (opn1[i]+opn2[i]+carn) / 10;
          ans[psna-1] += 1;
          psna += 1;
        }else{
          ans[psna] = opn1[i]+opn2[i]+carn;
          carn = 0;
          psna += 1;
        }
      }
    }else{
      for (int i = 399;i > 399-mps;i--){
        if ((opn1[i]+opn2[i]+carn) > 9){
          ans[psna] = (opn1[i]+opn2[i]+carn) % 10;
          carn = (opn1[i]+opn2[i]+carn) / 10;
          ans[psna-1] += 1;
          psna += 1;
        }else{
          ans[psna] = opn1[i]+opn2[i]+carn;
          carn = 0;
          psna += 1;
        }
      }
    }
  }else if (psn1 < psn2){
    //printf("N1:%s\n",n1);
    //printf("%d\n",count);
    //printf("ENTER\n");
    if ((opn1[399-mps+1] + opn2[399-mps+1]) < 0){
      //printf("ENTER1\n");
      for (int i = 399;i > 399-mps;i--){
        ans[psna] = opn1[i] + opn2[i];
        psna += 1;
      }
    }else{
      //printf("ENTER2\n");
      for (int i = 399;i > 399-mps;i--){
        if ((opn1[i]+opn2[i]+carn) < 0){
          //printf("OPN1-%d:%d OPN2-%d:%d\n",i,opn1[i],i,opn2[i]);
          ans[psna] = 10+opn1[i]+opn2[i]+carn;
          carn = -1;
          psna += 1;
        }else{
          //printf("OPN1-%d:%d OPN2-%d:%d\n",i,opn1[i],i,opn2[i]);
          ans[psna] = opn1[i]+opn2[i]+carn;
          carn = 0;
          psna += 1;
        }
      }
    }
  }else if (psn1 == psn2){
    for (int i = 399-mps+1;i < 400;i++){
      if (opn1[i] < ((opn2[i])*(-1))){
        ctl = 0;
        break;
      }else if (opn1[i] > ((opn2[i])*(-1))){
        ctl = 1;
        break;
      }
    }
    if (ctl){
      for (int i = 399;i >= 399-mps;i--){
        if ((opn1[i] + opn2[i] + carn) < 0){
          ans[psna] = (10 + opn1[i] + opn2[i] + carn) % 10;
          carn = -1;
        }else{
          ans[psna] = opn1[i] + opn2[i] + carn;
          carn = 0;
        }
        psna += 1;
      }
    }else{
      for (int i = 399;i > 399-mps;i--){
        if ((opn2[i] * (-1)) > opn1[i]){
          ans[psna] = opn1[i] + opn2[i];
        }else if ((opn2[i] * (-1)) < opn1[i]){
          ans[psna] = opn1[i] + opn2[i];
          ans[psna] -= 10;
          opn2[i-1] += 1;
        }
        //printf("N1:%d N2:%d ANS:%d\n",opn1[i],opn2[i],ans[psna]);
        psna += 1;
      }
    }
  }
  /*
  for (int i = psna;i >= 0;i--){
    printf("%d",ans[i]);
  }
  printf("\n");
  */
  for (int i = psna;i >= 0;i--){
    if (ans[i] != 0){
      reps = i;
      break;
    }
  }
  psna = reps;
  if (ans[psna] < 0 && ans[psna-1] < 0){
    for (int i = psna-1;i >= 0;i--){
      ans[i] *= -1;
    }
  }
  for (int i = psna-1;i >= 0;i--){
    if (ans[i] < 0){
      ans[i] += 10;
      ans[i+1] -= 1;
    }
  }
  for (int i = psna;i >= 0;i--){
    fprintf(fo,"%d",ans[i]);
  }
  fprintf(fo,"\n");
}

int clean(){
  for (int i = 399;i > 399-mps;i--){
    opn1[i] = 0;
    opn2[i] = 0;
  }
  for (int i = 0;i <= 400;i++){
    n1[i] = 0;
    n2[i] = 0;
  }
  for (int i = 0;i <= psna;i++)
    ans[i] = 0;
  psn1 = psn2 = 399;
  psna = carn = mps = ctl = 0;
}

int datainput(){
  for (int i = 399;i >= 0;i--)
    if (stn1[i] != 0 && stn1[i] != "\0")
      for (int j = 0;j < 10;j++)
        if ((int)stn1[i] == posnar[j]){
          pos1[pospsn1] = j;
          pospsn1 -= 1;
        }
  for (int i = 399;i >= 0;i--)
    if (stn2[i] != 0 && stn2[i] != "\0")
      for (int j = 0;j < 10;j++)
        if ((int)stn2[i] == posnar[j]){
          pos2[pospsn2] = j;
          pospsn2 -= 1;
        }
}

int posautocomp(){
  if (posmps == 399-pospsn1){
    for (int i = pospsn2;i > pospsn1;i--)
      pos2[i] = 0;
  }else
    for (int i = pospsn1;i > pospsn2;i--)
      pos1[i] = 0;
}

int posplus(){
  for (int i = 399;i > 399-posmps-1;i--){
    if ((pos1[i] + pos2[i] + poscarn) > 9){
      posans[pospsna] = (pos1[i]+pos2[i]+poscarn)%10;
      poscarn = (pos1[i]+pos2[i]+poscarn)/10;
      pospsna += 1;
    }else{
      if (pospsna != 399-posmps+1){
        posans[pospsna] = pos1[i]+pos2[i]+poscarn;
        pospsna += 1;
        poscarn = 0;
      }else{
        posans[pospsna] = (pos1[i]+pos2[i]+poscarn)%10;
        pospsna += 1;
      }
    }
  }
  if (posans[pospsna-1] == 0)
    pospsna -= 2;
  if (posans[pospsna] != 0){
    for (int i = pospsna;i >= 0;i--)
      fprintf(fo,"%d",posans[i]);
  }else{
    for (int i = pospsna-1;i >= 0;i--)
      fprintf(fo,"%d",posans[i]);
  }
  /*
  for (int i = pospsna-1;i >= 0;i--){
    if (posans[pospsna] != 0){
      pospsna = i;
      break;
    }
  }
  for (int i = pospsna;i >= 0;i--)
      fprintf(fo,"%d",posans[i]);
  */
  fprintf(fo,"\n");
}

int cleanpos(){
  for (int i = 399;i > pospsn1;i--)
    pos1[i] = 0;
  for (int i = 399;i > pospsn2;i--)
    pos2[i] = 0;
  for (int i = 0;i <= 399-pospsn1;i++)
    stn1[i] = 0;
  for (int i = 0;i <= 399-pospsn2;i++)
    stn2[i] = 0;
  for (int i = 0;i <= pospsna;i++)
    posans[i] = 0;
  pospsn1 = 399;
  pospsn2 = 399;
  pospsna = 0;
  poscarn = 0;
}

int main(void){
  if ((fi = fopen("Input.txt","r")) == NULL || (fo = fopen("Output.txt","w")) == NULL)
    printf("Error\n");
  else{
    while(!feof(fi)){
      /* Open Read File */
      fscanf(fi,"%s%s",stn1,stn2);
      datainput();
      if (stn1[0] != 45 && stn2[0] != 45){
        posmps = max(399-pospsn1,399-pospsn2);
        posautocomp();
        posplus();
        //checkdata();
        cleanpos();
      }else{
        for (int i = 0;i < 400;i++){
          sn[i] = stn1[i];
          n1[i] = sn[i];
        }
        for (int i = 0;i < 400;i++){
          sn[i] = stn2[i];
          n2[i] = sn[i];
        }
        if (n1[1] < n2[1] && n1[0] == 45){
          for (int i = 0;i < 400;i++){
            sn[i] = n1[i];
            n1[i] = n2[i];
            n2[i] = sn[i];
          }
        }
        //printf("%s\n%s\n",n1,n2);
        stateset();
        mps = max(399-psn1,399-psn2);
        autocomp();
        negplus();
        cleanpos();
        clean();
      }
    }
  }
  fclose(fi);
  fclose(fo);
  return 0;
}
