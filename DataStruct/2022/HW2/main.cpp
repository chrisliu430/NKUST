#include <iostream>
#include <string.h>
#include <vector>

#define MAX 200

using namespace std;

int Solve(void);
int Resolve(int z, int y, int x, int dir);

int lyrNum, rowNum, colNum, val, z, y, x, startZ, startY, startX, endZ, endY, endX, answer;
int maze[MAX][MAX][MAX];

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
    return 0;
}

int Solve(void) {
    while (cin >> lyrNum >> rowNum >> colNum) {
        if (lyrNum == 0 || rowNum == 0 || colNum == 0) {
            break;
        } else {
            memset(maze, 0xC0, sizeof(maze));
	    for (int lyrIdx = 0; lyrIdx < 1; lyrIdx++) {
                for (int rowIdx = 0; rowIdx < rowNum; rowIdx++) {
	            for (int colIdx = 0; colIdx < colNum; colIdx++){
		        maze[lyrIdx][rowIdx][colIdx] = 1;
		    }
		}
	    }
	    for (int lyrIdx = 1; lyrIdx <= lyrNum; lyrIdx++) {
                for (int rowIdx = 0; rowIdx < rowNum; rowIdx++) {
	            for (int colIdx = 0; colIdx < colNum; colIdx++){
	                cin >> val;
		        maze[lyrIdx][rowIdx][colIdx] = val;
		    }
		}
	    }
            cin >> startZ >> startY >> startX;
            cin >> endZ >> endY >> endX;
            maze[startZ][startY][startX] = 2;
            Resolve(startZ, startY, startX, 0);
            cout << answer << endl;
            answer = 0;
        }
    }
    return 0;
}

int Resolve(int z, int y, int x, int dir) {
    // Dir [ 1:From right, 2: From left, 3: From down, 4: From up ]
    if (z == endZ && y == endY && x == endX) {
        answer += 1;
    }
    if (maze[z-1][y][x] == 0 && z-1 >= 1) {
	maze[z-1][y][x] = -1;
	Resolve(z-1, y, x, 0);
	maze[z-1][y][x] = 0;
    }
    if (maze[z+1][y][x] == 0 && z+1 <= lyrNum) {
	maze[z+1][y][x] = -1;
	Resolve(z+1, y, x, 0);
	maze[z+1][y][x] = 0;
    }
    if (maze[z][y-1][x] == 0 && y-1 >= 0) {
        maze[z][y-1][x] = -1;
        Resolve(z, y-1, x, 0);
        maze[z][y-1][x] = 0;
    }
    if (maze[z][y+1][x] == 0 && y+1 <= rowNum) {
        maze[z][y+1][x] = -1;
        Resolve(z, y+1, x, 0);
        maze[z][y+1][x] = 0;
    }
    if (maze[z][y][x-1] == 0 && x-1 >= 0) {
        maze[z][y][x-1] = -1;
        Resolve(z, y, x-1, 0);
        maze[z][y][x-1] = 0;
    }
    if (maze[z][y][x+1] == 0 && x+1 <= colNum) {
        maze[z][y][x+1] = -1;
        Resolve(z, y, x+1, 0);
        maze[z][y][x+1] = 0;
    }
    return 0;
}
