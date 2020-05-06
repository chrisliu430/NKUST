#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool>> graph(0);
vector<bool> status(0);
vector<int> router(0);
vector<int> number(0);
vector<int> stack(0);
vector<int> frequency(0);

int check() {
    bool breakJudge = false;
    for (int i = 0; i < status.size(); i++) {
        if (status[i] == 1 && router[i] >= 1) {
            breakJudge = true;
        } else {
            breakJudge = false;
            break;
        }
    }
    return breakJudge;
}

int solve(int n) {
    int min = INT_MAX, reg, runSize;
    bool inStatus, writeMin = true, pushJudge;
    // ---
    while (graph.size() != n) {
        reg = 0;
        while (status.size() != n) {
            cin >> inStatus;
            status.push_back(inStatus);
        }
        for (int i = 0; i < n; i++) {
            if (status[i] == 1) {
                reg++;
            }
        }
        frequency.push_back(reg);
        graph.push_back(status);
        status.clear();
    }
    while (status.size() != n) {
        cin >> inStatus;
        status.push_back(inStatus);
        router.push_back(0);
    }
    for (int i = 0; i < n; i++) {
    }
    graph.clear();
    status.clear();
    router.clear();
    frequency.clear();
    cout << min << endl;
    return 0;
}
 
int main(void) {
    int n;
    while (cin >> n && n > 0) { solve(n); }
    return 0;
} 