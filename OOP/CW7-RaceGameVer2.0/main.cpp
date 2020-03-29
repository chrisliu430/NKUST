#include <iostream>
#include <unistd.h>
#include <random>

#define turtleVal 50
#define rabbitVal 100
#define MAX 1000

using namespace std;

class TurtleSet{
    public:
        TurtleSet(string name,int id,int value,int total){
            per_name = name;
            per_id = id;
            per_val = value;
            per_total = total;
            per_chance = 5;
        }
        void getPerson(vector<TurtleSet *>::iterator position){
            cout << "PlayerInfo\t" << (*position)->per_name << (*position)->per_id+1 << "," << (*position)->per_val << endl;
            cout << (*position)->per_total << "\t";
            for (int idx = 0;idx < ((*position)->per_total)/50;idx++){
                cout << "#";
            }
            cout << endl;
        }
        void decTotal(vector<TurtleSet *>::iterator position){
            if (random()%per_chance <= 1){
                dec_val = rand()%(*position)->per_val*0;
                cout << "遊戲該結束了吧！！！" << endl;
            }else{
                dec_val = rand()%(*position)->per_val;
            }
            if( (*position)->per_total > dec_val){
                (*position)->per_total -= dec_val;
            }else{
                (*position)->per_total -= (*position)->per_total;
            }
        } // Decrease Total Food of Player
        int checkRace(vector<TurtleSet *>::iterator position){
            if((*position)->per_total == 0){
                return 1;
            }else{
                return 0;
            }
        } //Check Race Status in Now
        void announceWinner(vector<TurtleSet *>::iterator position){
            if((*position)->per_total == 0){
                cout << "Winner is " << (*position)->per_name << (*position)->per_id+1 << endl;
            }
        } //Announce Who is Winner
    private:
        string per_name;
        int per_id,per_val,per_total,per_chance,dec_val;
        bool skill_open;
};

class RabbitSet{
    public:
        RabbitSet(string name,int id,int value,int total){
            per_name = name;
            per_id = id;
            per_val = value;
            per_total = total;
            per_chance = 5;
        }
        void getPerson(vector<RabbitSet *>::iterator position){
            cout << "PlayerInfo\t" << (*position)->per_name << (*position)->per_id+1 << "," << (*position)->per_val << endl;
            cout << (*position)->per_total << "\t";
            for (int idx = 0;idx < ((*position)->per_total)/50;idx++){
                cout << "#";
            }
            cout << endl;
        }
        void decTotal(vector<RabbitSet *>::iterator position){
            if (random()%per_chance <= 1){
                dec_val = rand()%(*position)->per_val*2;
                cout << "遊戲該結束了吧！！！" << endl;
            }else{
                dec_val = rand()%(*position)->per_val;
            }
            if( (*position)->per_total > dec_val){
                (*position)->per_total -= dec_val;
            }else{
                (*position)->per_total -= (*position)->per_total;
            }
        } // Decrease Total Food of Player
        int checkRace(vector<RabbitSet *>::iterator position){
            if((*position)->per_total == 0){
                return 1;
            }else{
                return 0;
            }
        } //Check Race Status in Now
        void announceWinner(vector<RabbitSet *>::iterator position){
            if((*position)->per_total == 0){
                cout << "Winner is " << (*position)->per_name << (*position)->per_id+1 << endl;
            }
        } //Announce Who is Winner
    private:
        string per_name;
        int per_id,per_val,per_total,per_chance,dec_val;
        bool skill_open;
};

int main(void){
    bool status = false;
    int num[2],value = 0;
    TurtleSet *forTurtle;
    vector<TurtleSet *> tur_ptr(0);
    RabbitSet *forRabbit;
    vector<RabbitSet *> rab_ptr(0);
    while(1){
        cin >> num[0] >> num[1];
        if (num[0] == 0 || num[1] == 0)
            break;
        for (int id = 0;id < num[0];id++){
            forTurtle = new TurtleSet("烏龜",id,rand()%turtleVal+10,MAX);
            tur_ptr.push_back(forTurtle);
        }
        for (int id = 0;id < num[1];id++){
            forRabbit = new RabbitSet("兔子",id,rand()%rabbitVal+10,MAX);
            rab_ptr.push_back(forRabbit);
        }
        while(1){
            for (vector<TurtleSet *>::iterator it = tur_ptr.begin();it != tur_ptr.end();it++){
                if (!value){
                    value = (forTurtle)->checkRace(it);
                }
                if (value && it == tur_ptr.end()){
                    break;
                }
                (forTurtle)->getPerson(it);
                (forTurtle)->decTotal(it);
            }
            for (vector<RabbitSet *>::iterator it = rab_ptr.begin();it != rab_ptr.end();it++){
                if (!value){
                    value = (forRabbit)->checkRace(it);
                }
                if (value && it == rab_ptr.end()){
                    break;
                }
                (forRabbit)->getPerson(it);
                (forRabbit)->decTotal(it);
            }
            for (vector<TurtleSet *>::iterator winner_it = tur_ptr.begin();winner_it != tur_ptr.end();winner_it++){
                if ((forTurtle)->checkRace(winner_it))
                    (forTurtle)->announceWinner(winner_it);
            }
            for (vector<RabbitSet *>::iterator winner_it = rab_ptr.begin();winner_it != rab_ptr.end();winner_it++){
                if ((forRabbit)->checkRace(winner_it))
                    (forRabbit)->announceWinner(winner_it);
            }
            if (value){
                value = 0;
                break;
            }
            usleep(1500000);
            system("clear");
        }
        tur_ptr.clear();
        rab_ptr.clear();
    }
}
