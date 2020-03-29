#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <typeinfo>

#define MAX 1000

using namespace std;

class playerData{
    public:
        playerData(string name,int id,int value,int total){
            per_name = name;
            per_id = id;
            per_val = value;
            per_total = total;
        }
        void getPerson(vector<playerData *>::iterator position){
            cout << "PlayerInfo\t" << (*position)->per_name << (*position)->per_id+1 << "," << (*position)->per_val << endl;
            cout << (*position)->per_total << "\t";
            for (int idx = 0;idx < ((*position)->per_total)/50;idx++){
                cout << "#";
            }
            cout << endl;
        }
        void decTotal(vector<playerData *>::iterator position){
            dec_val = rand()%(*position)->per_val;
            if( (*position)->per_total > dec_val){
                (*position)->per_total -= dec_val;
            }else{
                (*position)->per_total -= (*position)->per_total;
            }
        } // Decrease Total Food of Player
        int checkRace(vector<playerData *>::iterator position){
            if((*position)->per_total == 0){
                return 1;
            }else{
                return 0;
            }
        } //Check Race Status in Now
        void announceWinner(vector<playerData *>::iterator position){
            if((*position)->per_total == 0){
                cout << "Winner is " << (*position)->per_name << (*position)->per_id+1 << endl;
            }
        } //Announce Who is Winner
    private:
        string per_name;
        int per_id,per_val,per_total,dec_val,status;
};


int main(int argc,char* argv[]){
    int number = 0,value = 0;
    string name = "Rabbit";
    playerData *race_set;
    vector<playerData *> pd_ptr(0);
    srand(time(NULL));
    while(1){
        cin >> number;
        if (number == 0)
            break;
        else {
            for (int id = 0;id < number;id++){
                race_set = new playerData(name,id,rand()%91+10,MAX);
                pd_ptr.push_back(race_set);
            }
            while(1){
                for (vector<playerData *>::iterator it = pd_ptr.begin();it != pd_ptr.end();it++){
                    if (!value){
                        value = (race_set)->checkRace(it);
                    }
                    if (value && it == pd_ptr.end()){
                        break;
                    }
                    (race_set)->getPerson(it);
                    (race_set)->decTotal(it);
                }
                for (vector<playerData *>::iterator winner_it = pd_ptr.begin();winner_it != pd_ptr.end();winner_it++){
                    (race_set)->announceWinner(winner_it);
                }
                if (value){
                    value = 0;
                    break;
                }
                usleep(500000);
                system("clear");
            }
            pd_ptr.clear();
        }
    }
    return 0;
}