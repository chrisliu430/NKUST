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
vector<string> cus_adrs(0); // Record Customer Birthday
vector<int> cus_date_y(0); // Record Customer Birthday Year
/* BOOKS DATA */
vector<int> bok_id(0); // Record Customer ID
vector<string> bok_name(0); // Record Customer Name
vector<string> bok_puber(0); // Record Customer Birthday
vector<string> bok_date(0); // Record Customer Birthday
/* BORROWS DATA */
vector<int> brw_cus_id(0); // Record Customer ID
vector<int> brw_bok_id(0); // Record Customer ID
vector<string> brw_date(0); // Record Customer Birthday
/* SORT DATA LIST */
vector<int> sort_date(0); // Record Customer Birthday Year

/* Establish Object */
class data_list{
    public:
        int id,money,b_id;
        char name[10],puber_name[10],date[10],adrs[10];
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
    int cmd = 0,cus_counter = 0,book_counter = 0,brw_counter = 0,cus_regi,bok_regi;
    data_list pull_data;
    ifstream customer("customer_1008.txt");
    ifstream books_list("books.txt");
    ifstream borrow_list("borrows.txt");
    while(!customer.eof()){
        customer >> pull_data.id;
        customer >> pull_data.name;
        customer >> pull_data.adrs;
        customer >> pull_data.date;
        cus_id.push_back(pull_data.id);
        cus_name.push_back(pull_data.name);
        cus_adrs.push_back(pull_data.adrs);
        cus_date.push_back(pull_data.date);
        cus_date_y.push_back(atoi(pull_data.date));
        cus_counter += 1;
    }
    while(!books_list.eof()){
        books_list >> pull_data.id;
        books_list >> pull_data.name;
        books_list >> pull_data.puber_name;
        books_list >> pull_data.date;
        bok_id.push_back(pull_data.id);
        bok_name.push_back(pull_data.name);
        bok_puber.push_back(pull_data.puber_name);
        bok_date.push_back(pull_data.date);
        book_counter += 1;
    }
    while(!borrow_list.eof()){
        borrow_list >> pull_data.id;
        borrow_list >> pull_data.b_id;
        borrow_list >> pull_data.date;
        brw_cus_id.push_back(pull_data.id);
        brw_bok_id.push_back(pull_data.b_id);
        brw_date.push_back(pull_data.date);
        brw_counter += 1;
    }
    while(cin >> cmd){
        if (cmd == 1){
            sort_date.clear();
            for (int i = 0;i < cus_counter;i++)
                sort_date.push_back(cus_date_y[i]);
            for (int i = 0;i < cus_counter-1;i++)
                for (int j = i+1;j < cus_counter;j++)
                    pull_data.compare(&sort_date[i],&sort_date[j]) ? pull_data.swap(&sort_date[i],&sort_date[j]) : 1;
            for (int i = 0;i < cus_counter;i++)
                for (int j = 0;j < cus_counter;j++)
                    if (sort_date[i] == cus_date_y[j])
                        cout << cus_id[j] << "\t" << cus_name[j] << "\t" << cus_adrs[j] << "\t" << cus_date[j] << "\t" << endl;
        }else if (cmd == 2){
            for (int i = 0;i < brw_counter;i++){
                for (int j = 0; j < cus_counter;j++)
                    if (brw_cus_id[i] == cus_id[j]){
                        cus_regi = j;
                        break;
                    }
                for (int j = 0; j < book_counter;j++)
                    if (brw_bok_id[i] == bok_id[j]){
                        bok_regi = j;
                        break;
                    }
                cout << cus_name[cus_regi] << "\t" << bok_name[bok_regi] << "\t" << cus_adrs[cus_regi] << "\t" << bok_puber[bok_regi] << "\t" << brw_date[i] << "\n";
            }
        }else if (cmd == 3){
            break;
        }
    }
    return 0;
}
