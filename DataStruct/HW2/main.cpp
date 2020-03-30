#include <iostream>
#include <vector>

using namespace std;

class MAZE {
    public:
        MAZE () {
            answerRouter = 0;
            previousY = 0;
            previousX = 0;
            mazeValue.clear();
            valueVector.clear();
        }
        void SetValue(int val) {
            valueVector.push_back(val);
        }
        void Push2DVector() {
            mazeValue.push_back(valueVector);
            valueVector.clear();
        }
        void SetStartPoint(int y, int x) {
            startY = y;
            startX = x;
        }
        void SetEndPoint(int y, int x) {
            endY = y;
            endX = x;
        }
        void StartCalculate() {
            // Router is from right to left
            if (startY >= endY){
                judgeY = endY;
                judgeX = endX;
            } else {
                judgeY = startY;
                judgeX = startX;
                startY = endY;
                startX = endX;
            }
            MultipleCheck(startY, startX, 0, -1, -1);
        }
        void MultipleCheck (int y, int x, int weight, int prey, int prex) {
            // Detail of weight
            // 1: From left 2: From right
            previousY = prey;
            previousX = prex;
            if (y == judgeY && x == judgeX) {
                answerRouter += 1;
            } else if (mazeValue[y-1][x] == 0 && mazeValue[y][x-1] == 0 && weight != 3 && weight != 1) {
                MultipleCheck(y-1,x,4,y,x);
                MultipleCheck(y,x-1,2,y,x);
            } else if (mazeValue[y+1][x] == 0 && mazeValue[y][x-1] == 0 && weight != 4 && weight != 1) {
                MultipleCheck(y+1,x,3,y,x);
                MultipleCheck(y,x-1,2,y,x);
            } else if (mazeValue[y-1][x] == 0 && mazeValue[y+1][x] == 0 && weight != 3 && weight != 4) {
                MultipleCheck(y-1,x,4,y,x);
                MultipleCheck(y+1,x,3,y,x);
            } else if (mazeValue[y][x+1] == 0 && mazeValue[y][x-1] == 0 && weight != 2 && weight != 1) {
                MultipleCheck(y,x+1,1,y,x);
                MultipleCheck(y,x-1,2,y,x);
            } else if (mazeValue[y-1][x] == 0 && mazeValue[y][x+1] == 0 && weight != 3 && weight != 2 && x < judgeX) {
                MultipleCheck(y-1,x,4,y,x);
                MultipleCheck(y,x+1,1,y,x);
            } else if (mazeValue[y+1][x] == 0 && mazeValue[y][x+1] == 0 && weight != 4 && weight != 2 && x < judgeX) {
                MultipleCheck(y+1,x,3,y,x);
                MultipleCheck(y,x+1,1,y,x);
            } else if (mazeValue[y][x-1] == 0 && weight != 1 && x >= judgeX && previousX != x-1) { //  && x >= judgeX
                MultipleCheck(y,x-1,2,y,x);
            } else if (mazeValue[y+1][x] == 0 && (weight != 4 || y <= judgeY) && previousY != y+1) { // && y < judgeY
                MultipleCheck(y+1,x,3,y,x);
            } else if (mazeValue[y-1][x] == 0 && weight != 3 && previousY != y-1) { // && y >= judgeY
                MultipleCheck(y-1,x,4,y,x);
            } else if (mazeValue[y][x+1] == 0 && weight != 2 && previousX != x+1) { // && x < judgeX
                MultipleCheck(y,x+1,1,y,x);
            }
        }
        int GetRouter() {
            return answerRouter;
        }
    private:
        int answerRouter, startY, startX, endY, endX, judgeY, judgeX, previousY, previousX;
        vector<vector<int>> mazeValue;
        vector<int> valueVector;
};

int main(void){
    int row, col, val, x, y;
    vector<int> answer(0);
    // ---
    answer.clear();
    while (cin >> row >> col) {
        if (row == 0 || col == 0) {
            break;
        } else {
            MAZE *maze_ptr = new MAZE();
            for (int rowIdx = 0; rowIdx < row; rowIdx++) {
                for (int colIdx = 0; colIdx < col; colIdx++) {
                    cin >> val;
                    maze_ptr->SetValue(val);
                }
                maze_ptr->Push2DVector();
            }
            cin >> y >> x;
            maze_ptr->SetStartPoint(y, x);
            cin >> y >> x;
            maze_ptr->SetEndPoint(y, x);
            maze_ptr->StartCalculate();
            answer.push_back(maze_ptr->GetRouter());
            maze_ptr = 0;
        }
    }
    // ---
    for (int ansIdx = 0; ansIdx < answer.size(); ansIdx++) {
        cout << answer[ansIdx] << endl;
    }
    return 0;
}
