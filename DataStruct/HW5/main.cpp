#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool Check(int checkN, vector<int> &run) {
    bool status = true;
    for (int i = 0; i < run.size(); i++) {
        if (run[i] <= 0) status = false;
        else if (run[checkN] == 0) continue;
    }
    return status;
}

void ChangeValue(int pos, int freq, vector<int> &run, vector<bool> &node) {
    for (int i = 0; i < node.size(); i++) if (node[i] && i != pos && run[i] == 0) run[i] = freq;
}

void Run(int pos, int freq, vector<int> &run, vector<vector<bool>> &graph) {
    for (int i = 0; i < run.size(); i++) if (run[i] == freq) ChangeValue(pos, freq + 1, run, graph[i]);
}

int Solve(vector<vector<bool>> &graph, int n) {
    // FINISH
    int verifyN = INT_MAX, reg = 0;
    vector<int> answer(0), record(0), run(0);
    for (int i = 0; i < n; i++) {
        answer.push_back(0);
        run.push_back(0);
    }
    for (int i = 0; i < n; i++) {
        run[i] = 0;
        for (int j = 0; j < n; j++) if (graph[i][j]) run[j] = 1;
        for (int j = 1; j < n; j++) {
            Run(i, j, run, graph);
            if (Check(i, run)) break;
        }
        sort(run.begin(), run.end());
        reg = (run[1] == 0) ? 0 : run[run.size() - 1];
        for (int j = 0; j < n; j++) run[j] = 0;
        answer[i] = reg;
    }
    for (int i = 0; i < answer.size(); i++) verifyN = verifyN > answer[i] ? answer[i] : verifyN;
    if (verifyN == 0) {
        cout << "disconnected";
    } else {
        for (int i = 0; i < answer.size(); i++) {
            if (answer[i] == verifyN) {
                cout << i << " ";
            }
        }
    }
    cout << endl;
    // ---
    return 0;
}

// FINISH
int InputProcess(int n) {
    bool inStatus;
    vector<vector<bool>> graph(0);
    vector<bool> status(0);
    // ---
    while (graph.size() != n) {
        while (status.size() != n) {
            cin >> inStatus;
            status.push_back(inStatus);
        }
        graph.push_back(status);
        status.clear();
    }
    Solve(graph, n);
    return 0;
}
// ---

int main(void) {
    int n;
    while (cin >> n && n > 0) InputProcess(n);
    return 0;
} 