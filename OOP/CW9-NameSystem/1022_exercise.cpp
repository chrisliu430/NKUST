#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class nameData{
    public:
        int rand_n;
        nameData(string f_name,string f_nick){
            ifstream fi_name(f_name);
            ifstream fi_nick(f_nick);
            string ipt;
            while (!fi_name.eof()){
                fi_name >> ipt;
                name.push_back(ipt);
            }
            while (!fi_nick.eof()){
                fi_nick >> ipt;
                nick.push_back(ipt);
            }
            record_2char_pos = 0;
            record_3char_pos = 0;
            setTotalName();
        };
        void print2Char(){
            while(1){
                register_of_2char[0] = rand()%name.size();
                register_of_2char[1] = rand()%nick.size();
                call_status = checkRepeat(2);
                if(number_2char == 0){
                    break;
                }
                if(call_status){
                    number_2char -= 1;
                    record_2char_name.push_back(register_of_2char[0]);
                    record_2char_name.push_back(register_of_2char[1]);
                    cout << name[register_of_2char[0]] << nick[register_of_2char[1]] << endl;
                    record_2char_pos += 2;
                    break;
                }
            }
        }
        void print3Char(){
            while(1){
                register_of_3char[0] = rand()%name.size();
                register_of_3char[1] = rand()%nick.size();
                register_of_3char[2] = rand()%nick.size();
                call_status = check3CharRepeat(3);
                if(number_3char == 0){
                    break;
                }
                if(call_status){
                    number_3char -= 1;
                    record_3char_name.push_back(register_of_3char[0]);
                    record_3char_name.push_back(register_of_3char[1]);
                    record_3char_name.push_back(register_of_3char[2]);
                    cout << name[register_of_3char[0]] << nick[register_of_3char[1]] << nick[register_of_3char[2]] << endl;
                    record_3char_pos += 3;
                    break;
                }
            }
        }
        void setTotalName(){
            number_2char = name.size()*nick.size();
            number_3char = name.size()*nick.size()*nick.size();
            total_nubmer = number_2char + number_3char;
            //outputTotalNumber();
        }
        int changeTotalNumber(){
            total_nubmer = number_2char + number_3char;
            if (total_nubmer <= 0){
                cout << "Out of Range" << endl;
                return -1;
            }else{
                cout << "After Random Combine Name Number is " << total_nubmer << endl;
                return 1;
                outputTotalNumber();
            }
        };
        int checkRepeat(int arg_num){
            status = 0;
            if (arg_num == 2 && record_2char_name.size() == 0){
                return 1;
            }else{
                for (int i = 0;i < record_2char_name.size();i+=2){
                    if (record_2char_name[i] == register_of_2char[0] && record_2char_name[i+1] == register_of_2char[1]){
                        status = 0;
                        break;
                    }else{
                        status = 1;
                    }
                }
                return status;
            }
        };
        int check3CharRepeat(int arg_num){
            status = 0;
            if (arg_num == 3 && record_3char_name.size() == 0){
                return 1;
            }else{
                for (int i = 0;i < record_3char_name.size();i+=3){
                    if (record_3char_name[i] == register_of_3char[0] && record_3char_name[i+1] == register_of_3char[1] && record_3char_name[i+2] == register_of_3char[2]){
                        status = 0;
                        break;
                    }else{
                        status = 1;
                    }
                }
                return status;
            }
        }
        void outputTotalNumber(){
            cout << total_nubmer << endl;
            total_nubmer = 0;
        };
        int check2CharLimit(){
            if (number_2char == 0){
                return 0;
            }else{
                return 1;
            }
        }
        int check3CharLimit(){
            if (number_3char == 0){
                return 0;
            }else{
                return 1;
            }
        }
    private:
        vector<string> name;
        vector<string> nick;
        vector<int> record_2char_name;
        vector<int> record_3char_name;
        int total_nubmer,register_of_2char[2],register_of_3char[3];
        int record_2char_pos,record_3char_pos,status,call_status,number_2char,number_3char;
};

vector<nameData *> db_ptr(0);

int main(int argc,char* argv[]){
    int number = 0,rand_cache;
    if (argc == 3){
        nameData combine_name(argv[1],argv[2]);
        combine_name.outputTotalNumber();
        while(1){
            cin >> number;
            if (number == 0)
                break;
            while(number != 0){
                rand_cache = rand() % 2;
                if (rand_cache == 0 && combine_name.check2CharLimit()){
                    combine_name.print2Char();
                    number -= 1;
                }else if (rand_cache == 0 && combine_name.check3CharLimit()){
                    combine_name.print3Char();
                    number -= 1;
                }
            }
            if(combine_name.changeTotalNumber() == -1){
                break;
            }
            combine_name.outputTotalNumber();
        }
    }else{
        cout << "Some Argument is Error.\n";
    }
    return 0;
}