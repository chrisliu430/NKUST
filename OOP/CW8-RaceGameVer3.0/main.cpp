#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <unistd.h>
#include "animal.h"

using namespace std;

int main(void){
    bool status,_judge;
    int tal_num[4],total,regi_num; // 0:Rab 1:Tur 2:Mou 3:Peo
    int steal_pos,wanna_pos;
    animalList *db;
    vector<animalList *> db_ptr(0);
    while(cin >> tal_num[0] >> tal_num[1] >> tal_num[2] >> tal_num[3]){
        total = 0;
        for (int i = 0;i < 4;i++){
            total += tal_num[i];
            if (tal_num[i] == 0)
                status = true;
        }
        total -= tal_num[3];
        if (status)
            break;
        else{
            for (int i = 0;i < 4;i++){
                if(i == 0)
                    for (int j = 0;j < tal_num[i];j++){
                        db = new animalList("Rabbit");
                        db_ptr.push_back(db);
                    }
                if(i == 1)
                    for (int j = 0;j < tal_num[i];j++){
                        db = new animalList("Turtle");
                        db_ptr.push_back(db);
                    }
                if(i == 2)
                    for (int j = 0;j < tal_num[i];j++){
                        db = new animalList("Mouse");
                        db_ptr.push_back(db);
                    }
                if(i == 3)
                    for (int j = 0;j < tal_num[i];j++){
                        db = new animalList("People",2,0);
                        db_ptr.push_back(db);
                    }
            }
            _judge = false;
            while(1){
                for (vector<animalList *>::iterator it = db_ptr.begin();it != db_ptr.end();it++){
                    if((*it)->getName() == "People"){
                        cout << (*it)->getName() << " | ";
                        if(random()%(*it)->getVal() == 0){
                            cout << "偷食物囉！！！嘻嘻嘻\n";
                            steal_pos = random()%total;
                            wanna_pos = random()%total;
                            regi_num = random()%(db_ptr[steal_pos])->getVal()+1;
                            (db_ptr[steal_pos])->decTotal(regi_num);
                            (db_ptr[wanna_pos])->incTotal(regi_num);
                        }else{
                            wanna_pos = random()%total;
                            (db_ptr[wanna_pos])->decTotal(200);
                            cout << "給我吃下去吧！！！哈哈哈\n";
                        }
                    }
                    if((*it)->getName() == "Mouse"){
                        cout << (*it)->getName() << " | ";
                        if(random()%(*it)->getVal() == 0){
                            cout << "偷食物囉！！！吱吱吱\n";
                            steal_pos = random()%total;
                            wanna_pos = random()%total;
                            regi_num = random()%(db_ptr[steal_pos])->getVal()+1;
                            (db_ptr[steal_pos])->decTotal(regi_num);
                            (db_ptr[wanna_pos])->incTotal(regi_num);
                        }else{
                            cout << "吃吃吃！！！\n";
                            regi_num = random()%(*it)->getVal()+1;
                            (*it)->decTotal(regi_num);
                            if ((*it)->getTotal() <= 0){
                                (*it)->setTotal();
                                _judge = true;
                            }
                        }
                        cout << (*it)->getTotal() << " | ";
                        for (int i = 0;i < (*it)->getTotal()/50;i++)
                            cout << "#";
                        cout << endl;
                    }
                    if((*it)->getName() == "Rabbit"){
                        cout << (*it)->getName() << " | ";
                        if(random()%(*it)->getVal() == 0){
                            cout << "睡一波！！！\n";
                        }else{
                            cout << "吃吃吃！！！\n";
                            regi_num = random()%(*it)->getVal()+1;
                            (*it)->decTotal(regi_num);
                            if ((*it)->getTotal() <= 0){
                                (*it)->setTotal();
                                _judge = true;
                            }
                        }
                        cout << (*it)->getTotal() << " | ";
                        for (int i = 0;i < (*it)->getTotal()/50;i++)
                            cout << "#";
                        cout << endl;
                    }
                    if((*it)->getName() == "Turtle"){
                        cout << (*it)->getName() << " | ";
                        if(random()%(*it)->getVal() == 0){
                            cout << "大吃特吃！！！\n";
                            (*it)->decTotal(200);
                        }else{
                            cout << "吃吃吃！！！\n";
                            regi_num = random()%(*it)->getVal()+1;
                            (*it)->decTotal(regi_num);
                            if ((*it)->getTotal() <= 0){
                                (*it)->setTotal();
                                _judge = true;
                            }
                        }
                        cout << (*it)->getTotal() << " | ";
                        for (int i = 0;i < (*it)->getTotal()/50;i++)
                            cout << "#";
                        cout << endl;
                    }
                }
                sleep(3);
                system("clear");
                if(_judge)
                    break;
            }
        }
    }
}