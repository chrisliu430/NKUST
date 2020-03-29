/* Version:0.0.1 */
/* Export Path */
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

/* Establish Vector */
/* CUSTOMER VECTOR */
vector<int> cus_id(0); // Record Customer ID
vector<string> cus_name(0); // Record Customer Name
vector<string> cus_date(0); // Record Customer Birthday
vector<int> cus_date_y(0); // Record Customer Birthday Year
vector<int> cus_date_m(0); // Record Customer Birthday Year
vector<int> cus_date_d(0); // Record Customer Birthday Year
/* TRANSACTION VECTOR */
vector<int> trans_id(0); // Record Transaction ID
vector<string> trans_date(0); // Record Transaction Date
vector<int> trans_money(0); // Record Transaction Money
vector<int> date_y(0); // Record Transaction Year
vector<int> date_m(0); // Record Transaction Month
/* TOTAL DATA */
vector<int> sort_data(0);
vector<int> sort_date_y(0);
vector<int> sort_date_m(0);
vector<int> sort_date_d(0);
vector<int> total_money(0);

/* Establish Object */
class data_list{
    public:
        int id,money;
        char name[10],date[10];
        int compare(int *compare_int_1,int *compare_int_2){
            return (*compare_int_1 < *compare_int_2) ? 1 : 0;
        }
        int swap(int *swap_id_1,int *swap_id_2){
            int regi_int;
            regi_int = *swap_id_1;
            *swap_id_1 = *swap_id_2;
            *swap_id_2 = regi_int;
        }
};

int main(int argc,char* argv[]){
    int cmd = 0,cus_counter = 0,trans_counter = 0,sort_cmd = 0;
    char search_date[8] = "\0";
    data_list pull_data;
    if (argc == 3){
        ifstream customer(argv[1]);
        ifstream transaction(argv[2]);
        while(!customer.eof()){
            customer >> pull_data.id;
            customer >> pull_data.name;
            customer >> pull_data.date;
            cus_id.push_back(pull_data.id);
            cus_name.push_back(pull_data.name);
            cus_date.push_back(pull_data.date);
            cus_date_y.push_back(atoi(pull_data.date));
            cus_date_m.push_back(atoi(pull_data.date+5));
            cus_date_d.push_back(atoi(pull_data.date+8));
            cus_counter += 1;
        }
        while(!transaction.eof()){
            transaction >> pull_data.id;
            transaction >> pull_data.date;
            transaction >> pull_data.money;
            trans_id.push_back(pull_data.id);
            trans_date.push_back(pull_data.date);
            date_y.push_back(atoi(pull_data.date));
            date_m.push_back(atoi(pull_data.date+5));
            trans_money.push_back(pull_data.money);
            trans_counter += 1;
        }
        while(cin >> cmd){
            if (cmd == 1){
                sort_data.clear();
                total_money.clear();
                for (int i = 0;i < cus_counter;i++){
                    sort_data.push_back(cus_id[i]);
                    total_money.push_back(0);
                }
                cin >> search_date;
                for (int i = 0;i < trans_counter;i++)
                    if (atoi(search_date) == date_y[i] && atoi(search_date+5) == date_m[i])
                        for (int j = 0;j < cus_counter;j++)
                            if (cus_id[j] == trans_id[i]){
                                total_money[j] += trans_money[i];
                                break;
                            }
                for (int i = 0;i < cus_counter-1;i++)
                    for (int j = i+1;j < cus_counter;j++){
                        pull_data.compare(&total_money[i],&total_money[j]) ? pull_data.swap(&sort_data[i],&sort_data[j]) : 1;
                        pull_data.compare(&total_money[i],&total_money[j]) ? pull_data.swap(&total_money[i],&total_money[j]) : 1;
                    }
                for (int i = 0;i < cus_counter;i++)
                    for (int j = 0;j < cus_counter;j++)
                        if (sort_data[i] == cus_id[j] && total_money[i] != 0)
                            cout << sort_data[i] << "\t" << cus_name[j] << "\t" << cus_date[j] << "\t" << atoi(search_date) - cus_date_y[j] << "\t" << total_money[i] << endl;
            }else if (cmd == 2){
                sort_data.clear();
                for (int i = 0;i < trans_counter;i++)
                    sort_data.push_back(trans_money[i]);
                for (int i = 0;i < trans_counter-1;i++)
                    for (int j = i+1;j < trans_counter;j++)
                        pull_data.compare(&sort_data[i],&sort_data[j]) ? pull_data.swap(&sort_data[i],&sort_data[j]) : 1;
                for (int i = 0;i < trans_counter;i++)
                    if (trans_money[i] == sort_data[trans_counter/2])
                        for (int j = 0;j < cus_counter;j++)
                            if (trans_id[i] == cus_id[j])
                                cout << trans_id[i] << "\t" << cus_name[j] << "\t" << trans_date[i] << "\t" << trans_money[i] << endl;
            }else if (cmd == 3){
                sort_data.clear();
                sort_date_y.clear();
                sort_date_m.clear();
                sort_date_d.clear();
                for (int i = 0;i < cus_counter;i++){
                    sort_data.push_back(cus_id[i]);
                    sort_date_y.push_back(cus_date_y[i]);
                    sort_date_m.push_back(cus_date_m[i]);
                    sort_date_d.push_back(cus_date_d[i]);
                }
                cin >> sort_cmd;
                if (sort_cmd == 0){
                    for (int i = 0;i < cus_counter-1;i++)
                        for (int j = i+1;j < cus_counter;j++)
                            pull_data.compare(&sort_date_y[i],&sort_date_y[j]) ? pull_data.swap(&sort_date_y[i],&sort_date_y[j]) : 1;
                }else if(sort_cmd == 1){
                    for (int i = 0;i < cus_counter-1;i++)
                        for (int j = i+1;j < cus_counter;j++)
                            pull_data.compare(&sort_date_y[i],&sort_date_y[j]) ? 1 : pull_data.swap(&sort_date_y[i],&sort_date_y[j]);
                }
                for (int i = 0;i < cus_counter;i++)
                    for (int j = 0;j < cus_counter;j++)
                        if (sort_date_y[i] == cus_date_y[j])
                            cout << sort_data[j] << "\t" << cus_name[j] << "\t" << cus_date[j] << "\t" << "\t" << endl;
            }else if (cmd == 4){
                break;
            }else{
                cout << "Not Exist Command\n";
            }
        }
    }else{
        cout << "ERROR\n";
    }
    return 0;
}
