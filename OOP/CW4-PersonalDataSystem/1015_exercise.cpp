#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class database{
    public:
        int setArgs(int person_id,string person_name,string person_adrs,string person_birth){
            id = person_id;
            name = person_name;
            adrs = person_adrs;
            birth = person_birth;
        }
        int printData(vector<database *>::iterator position){
            cout << (*position)->id << '\t' << (*position)->name << "\t" << (*position)->adrs << "\t" << (*position)->birth << "\n";
        }
        int modifyData(vector<database *>::iterator position,int person_id,string person_name,string person_adrs,string person_birth){
            (*position)->id = person_id;
            (*position)->name = person_name;
            (*position)->adrs = person_adrs;
            (*position)->birth = person_birth;
        }
        int returnId(vector<database *>::iterator position){
            return (*position)->id;
        }
        string returnName(vector<database *>::iterator position){
            return (*position)->name;
        }
        string returnAdrs(vector<database *>::iterator position){
            return (*position)->adrs;
        }
        string returnBirth(vector<database *>::iterator position){
            return (*position)->birth;
        }
        void writeData(bool status,vector<database *>::iterator position){
            if (status){
                ofstream writeAdrs("customer_1008.txt",ios::app);
                //writeAdrs.open("customer_1008.txt",ios::app);
                writeAdrs << "\n" << (*position)->id << " " << (*position)->name << " " << (*position)->adrs << " " << (*position)->birth;
            }else{
                ofstream writeAdrs("customer_1008.txt",ios::out);
                //writeAdrs.open("customer_1008.txt",ios::out);
                writeAdrs << (*position)->id << " " << (*position)->name << " " << (*position)->adrs << " " << (*position)->birth;
            }
        }
    private:
        int id;
        string name,adrs,birth;
};

int main(){
    int cmd,person_id,ch_mod;
    string person_name,person_adrs,person_birth;
    database *db;
    vector<database *> db_ptr(0);
    ifstream customer("customer_1008.txt");
    while (!customer.eof()){
        db = new database();
        customer >> person_id >> person_name >> person_adrs >> person_birth;
        (db)->setArgs(person_id,person_name,person_adrs,person_birth);
        db_ptr.push_back(db);
    }
    while(cin >> cmd){
        if (cmd == 1){
            cin >> person_name >> person_adrs >> person_birth;
            db = new database();
            person_id = ((db)->returnId(--db_ptr.end()))+1;
            (db)->setArgs(person_id,person_name,person_adrs,person_birth);
            db_ptr.push_back(db);
        }else if (cmd == 2){
            cin >> person_id;
            for (vector<database *>::iterator it = db_ptr.begin();it != db_ptr.end();it++){
                if ((db)->returnId(it) == person_id){
                    db_ptr.erase(it);
                    break;
                }
            }
        }else if (cmd == 3){
            for (vector<database *>::iterator it = db_ptr.begin();it != db_ptr.end();it++){
                (db)->printData(it);
            }
        }else if (cmd == 4){
            cin >> person_id;
            cin >> ch_mod;
            switch(ch_mod){
                case 1:
                    cin >> person_name;
                    for (vector<database *>::iterator it = db_ptr.begin();it != db_ptr.end();it++)
                        if ((db)->returnId(it) == person_id){
                            (db)->modifyData(it,person_id,person_name,(db)->returnAdrs(it),(db)->returnBirth(it));
                            break;
                        }
                    break;
                case 2:
                    cin >> person_adrs;
                    for (vector<database *>::iterator it = db_ptr.begin();it != db_ptr.end();it++)
                        if ((db)->returnId(it) == person_id){
                            (db)->modifyData(it,person_id,(db)->returnName(it),person_adrs,(db)->returnBirth(it));
                            break;
                        }
                    break;
                case 3:
                    cin >> person_birth;
                    for (vector<database *>::iterator it = db_ptr.begin();it != db_ptr.end();it++)
                        if ((db)->returnId(it) == person_id){
                            (db)->modifyData(it,person_id,(db)->returnName(it),(db)->returnAdrs(it),person_birth);
                            break;
                        }
                    break;
            }
        }else if (cmd == 5){
            break;
        }
        vector<database *>::iterator it;
        // ofstream writeAdrs("customer_1008.txt");
        for (it = db_ptr.begin();it != db_ptr.end();it++){
            if (it == db_ptr.begin())
                (db)->writeData(false,it);
            else
                (db)->writeData(true,it);
        }
    }
    return 0;
}