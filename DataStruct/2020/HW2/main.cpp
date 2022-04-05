#include <iostream>
#include <string.h>
#include <vector>

#define MAX 200

using namespace std;

int Solve(void);
int Resolve(int y, int x, int dir);

int rowNum, colNum, val, y, x, startY, startX, endY, endX, answer;
int maze[MAX][MAX];

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
    return 0;
}

int Solve(void) {
    while (cin >> rowNum >> colNum) {
        if (rowNum == 0 || colNum == 0) {
            break;
        } else {
            memset(maze, 0xC0, sizeof(maze));
            for (int rowIdx = 0; rowIdx < rowNum; rowIdx++) {
                for (int colIdx = 0; colIdx < colNum; colIdx++){
                    cin >> val;
                    maze[rowIdx][colIdx] = val;
                }
            }
            cin >> startY >> startX;
            cin >> endY >> endX;
            maze[startY][startX] = 2;
            Resolve(startY, startX, 0);
            cout << answer << endl;
            answer = 0;
        }
    }
    return 0;
}

int Resolve(int y, int x, int dir) {
    // Dir [ 1:From right, 2: From left, 3: From down, 4: From up ]
    if (y == endY && x == endX) {
        answer += 1;
    }
    if (maze[y-1][x] == 0 && y-1 >= 0) {
        maze[y-1][x] = -1;
        Resolve(y-1, x, 0);
        maze[y-1][x] = 0;
    }
    if (maze[y+1][x] == 0 && y+1 <= rowNum) {
        maze[y+1][x] = -1;
        Resolve(y+1, x, 0);
        maze[y+1][x] = 0;
    }
    if (maze[y][x-1] == 0 && x-1 >= 0) {
        maze[y][x-1] = -1;
        Resolve(y, x-1, 0);
        maze[y][x-1] = 0;
    }
    if (maze[y][x+1] == 0 && x+1 <= colNum) {
        maze[y][x+1] = -1;
        Resolve(y, x+1, 0);
        maze[y][x+1] = 0;
    }
    return 0;
}