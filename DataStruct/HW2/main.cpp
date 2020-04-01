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
            if (startX >= endX){
                judgeY = endY;
                judgeX = endX;
                pointY = startY;
                pointX = startX;
                MultipleRouter(startY, startX, -1, -1, 0);
            } else {
                judgeY = startY;
                judgeX = startX;
                pointY = endY;
                pointX = endX;
                MultipleRouter(endY, endX, -1, -1, 0);
            }
        }
        void MultipleRouter(int y, int x, int prey, int prex, int weight) {
            // Detail of weight
            // 1: From left 2: From right
            // 3: From up 4: From down
            previousY = prey;
            previousX = prex;
            cout << "Y " << y << " X " << x << endl;
            if (y == judgeY && x == judgeX) {
                answerRouter += 1;
                previousY = -1;
                previousX = -1;
            } else {
                for (int dir = 0; dir < 4; dir++){
                    if (dir == 0 && x-1 >= 0 && x-1 != previousX && weight != 1 && mazeValue[y][x-1] == 0) {
                        MultipleRouter(y, x-1, y, x, 2);
                    }
                    if (dir == 1 && y-1 >= 0 && y-1 != previousY && weight != 3 && mazeValue[y-1][x] == 0) {
                        MultipleRouter(y-1, x, y, x, 4);
                    }
                    if (dir == 2 && y+1 <= mazeValue.size()-1 && y+1 != previousY && weight != 4 && mazeValue[y+1][x] == 0) {
                        MultipleRouter(y+1, x, y, x, 3);
                    }
                    if (dir == 3 && x+1 <= mazeValue[y].size()-1 && x+1 != previousX && weight != 2
                        && ((y-1 == previousY && weight == 3) || (y+1 == previousY && weight == 4) || (x-1 == previousX && weight == 1))
                        && (mazeValue[y-1][x] != 0 || mazeValue[y][x+1] != 0 || mazeValue[y-1][x+1] != 0 || (y == judgeY && x < judgeX))
                        && (mazeValue[y+1][x] != 0 || mazeValue[y][x+1] != 0 || mazeValue[y+1][x+1] != 0 || (y == judgeY && x < judgeX))
                        && mazeValue[y][x+1] == 0) {
                        MultipleRouter(y, x+1, y, x, 1);
                    }
                }
            }
        }
        int GetRouter() {
            return answerRouter;
        }
    private:
        int answerRouter, startY, startX, endY, endX, judgeY, judgeX, previousY, previousX, pointY, pointX;
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
