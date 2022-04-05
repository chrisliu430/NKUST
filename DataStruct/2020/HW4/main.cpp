#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void InputProcess(int n) {
    bool inStatus;
    vector<bool> node(0);
    vector<vector<bool>> graph(0);
    while (graph.size() != n) {
        while (node.size() != n) {
            cin >> inStatus;
            node.push_back(inStatus);
        }
        graph.push_back(node);
        node.clear();
    }
    while (node.size() != n) {
        cin >> inStatus;
        node.push_back(inStatus);
    }
    // ---
}

int main(void) {
    int n;
    while (cin >> n && n > 0) InputProcess(n);
    return 0;
}