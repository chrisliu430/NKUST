#include <iostream>
#include <vector>

using namespace std;

class LINE {
    public:
        // Initial Set
        LINE(){
            row_value.clear();
            max_router = 0;
            verify_num = 0;
        }
        // Add Row Data
        void addRowData(int _data){
            row_value.push_back(_data);
        }
        // Change Value of Assign Position
        void changeSingleData(int _assign_pos, int _assign_val){
            row_value[_assign_pos] = _assign_val;
        }
        // Verify Row Data
        void verifyData(){
            for (int _idx = 0; _idx < row_value.size(); _idx++){
                cout << row_value[_idx] << " ";
            }
            cout << endl;
        }
        // Counter Link
        void counterLink(){
            for (int _idx = 0; _idx < row_value.size(); _idx++){
                if (row_value[_idx] == 0){
                    max_router++;
                }
            }
        }
        // Using Position is 0 in Operate Array To Verify Data is Correct
        void addVerifyNumber(){
            verify_num += 1;
        }
        // Get Row Size
        int getSize(){
            return row_value.size();
        }
        // Get Data of Assign Position on Row
        int getSingleData(int _assign_pos){
            return row_value[_assign_pos];
        }
        // Get Max Router of Less Link
        int getMaxRouter(){
            if (verify_num+1 == max_router){ // Becasue of self not run OR-Operate, +1 is provide verify is correct
                return max_router;
            } else {
                return 1;
            }
        }
        // Get Verify Number To Verify Number is Reliable
        int getVerifyNumber(){
            return verify_num;
        }
    private:
        vector<bool> row_value;
        int max_router,verify_num;
};

class MATRIX : public LINE {
    public:
        // Initial Set
        MATRIX(){
            line_array.clear();
            operate_array.clear();
            solution_array.clear();
            max_number = 0;
            ptr_addrs = 0;
        }
        // Add New Column
        void addCol(){
            line_array_ptr = new LINE();
            line_array.push_back(line_array_ptr);
        }
        // Give Data To Assign Row
        void giveRowData(int _data){
            call_line_ptr = line_array.end() - 1;
            (*call_line_ptr)->addRowData(_data);
        }
        // Verify Matrix Data
        void verifyMatrix(){
            for (call_line_ptr = line_array.begin(); call_line_ptr < line_array.end(); call_line_ptr++){
                (*call_line_ptr)->verifyData();
            }
            for (call_line_ptr = operate_array.begin(); call_line_ptr < operate_array.end(); call_line_ptr++){
                (*call_line_ptr)->verifyData();
            }
        }
        // Call Link Counter
        void callCounter(){
            for (call_line_ptr = solution_array.begin(); call_line_ptr < solution_array.end(); call_line_ptr++){
                (*call_line_ptr)->counterLink();
            }
        }
        // Create Array for OR-Operate
        void createOperateLine(){
            for (int _idx = 0; _idx < line_array.size(); _idx++){
                line_array_ptr = new LINE();
                for (int y_idx = 0; y_idx < (line_array[_idx])->getSize(); y_idx++){
                    if (_idx == y_idx){
                        line_array_ptr->addRowData(0);
                    } else {
                        line_array_ptr->addRowData((line_array[_idx])->getSingleData(y_idx));
                    }
                }
                operate_array.push_back(line_array_ptr);
            }
        }
        // Search Max Number of Router
        int searchMax(){
            for (call_line_ptr = solution_array.begin(); call_line_ptr < solution_array.end(); call_line_ptr++){
                if ((*call_line_ptr)->getMaxRouter() > max_number){
                    max_number = (*call_line_ptr)->getMaxRouter();
                }
            }
            return max_number;
        }
        // OR-Operate Function
        void operateForOR(){
            for (int operate_idx = 0; operate_idx < operate_array.size(); operate_idx++){
                for (int solution_idx = operate_idx; solution_idx < (operate_array[operate_idx])->getSize(); solution_idx++){
                    line_array_ptr = new LINE();
                    for (int _idx = 0; _idx < (operate_array[operate_idx])->getSize(); _idx++){
                        line_array_ptr->addRowData((operate_array[operate_idx])->getSingleData(_idx));
                    }
                    for (int _idx = solution_idx; _idx < (operate_array[operate_idx])->getSize(); _idx++){
                        if (line_array_ptr->getSingleData(_idx) == 0 && _idx != operate_idx){
                            for (int change_idx = 0; change_idx < line_array_ptr->getSize(); change_idx++){
                                line_array_ptr->changeSingleData(change_idx,line_array_ptr->getSingleData(change_idx) | operate_array[_idx]->getSingleData(change_idx));
                            }
                            line_array_ptr->addVerifyNumber();
                        }
                    }
                    solution_array.push_back(line_array_ptr);
                }
            }
        }
        // Verify Solution Data
        void verifySolution(){
            cout << "Solution" << endl;
            for (call_line_ptr = solution_array.begin(); call_line_ptr < solution_array.end(); call_line_ptr++){
                (*call_line_ptr)->verifyData();
                // cout << " Verify Number: " << (*call_line_ptr)->getVerifyNumber() << endl;
            }
        }
    private:
        vector<LINE *> line_array;
        vector<LINE *> operate_array;
        vector<LINE *> solution_array;
        LINE *line_array_ptr;
        // Pointer of Line Class
        vector<LINE *>::iterator call_line_ptr;
        // ---
        int max_number,ptr_addrs;
};

int main(void) {
    int row_n_col;
    bool link_;
    vector<MATRIX *> matrix_array;
    MATRIX *matrix_array_ptr;
    // ---
    vector<MATRIX *>::iterator call_matrix_ptr;
    while (cin >> row_n_col) {
        if (row_n_col == -1) {
            break;
        } else {
            matrix_array_ptr = new MATRIX();
            for (int idx_x = 0; idx_x < row_n_col; idx_x++){
                matrix_array_ptr->addCol();
                for (int idx_y = 0; idx_y < row_n_col; idx_y++){
                    cin >> link_;
                    matrix_array_ptr->giveRowData(link_);
                }
            }
            matrix_array_ptr->createOperateLine();
            matrix_array_ptr->operateForOR();
            // matrix_array_ptr->verifySolution();
            matrix_array_ptr->callCounter();
            matrix_array.push_back(matrix_array_ptr);
        }
    }
    for (call_matrix_ptr = matrix_array.begin(); call_matrix_ptr < matrix_array.end(); call_matrix_ptr++){
        cout << (*call_matrix_ptr)->searchMax() << endl;
    }
    return 0;
}