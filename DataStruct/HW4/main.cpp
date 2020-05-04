#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Tree{
    int key;
    int value;
};

vector<Tree> treeVec(0);

int recursionTree (int n, int key, bool *sPtr) {
    if (n == 1) {
        // cout << *sPtr << " ";
        if (*sPtr == 1) {
            Tree t;
            t.key = key;
            t.value = n - 1;
            treeVec.push_back(t);
        }
    } else {
        recursionTree(n - 1, key, sPtr - 1);
        // cout << *sPtr << " ";
        if (*sPtr == 1) {
            Tree t;
            t.key = key;
            t.value = n - 1;
            treeVec.push_back(t);
        }
    }
    return 0;
}

int tree(int *n, bool *sPtr, bool *ePtr) {
    bool *assPtr = ePtr - *n;
    for (int i = 1; i <= *n; i++) {
        if (*(assPtr + (i-1)) == 1) {
            recursionTree(*n, (i-1), sPtr + (i * *n - 1));
        }
    }
    for (int i = 0; i < treeVec.size(); i++) {
        cout << treeVec[i].key << " " << treeVec[i].value << endl;
    }
    return 0;
}

int solve(int *n) {
    int arrSize = *n * *n + *n;
    bool status; // Graph
    bool *choosePtr = (bool*) malloc(sizeof(bool) * arrSize), *nPtr = choosePtr; // Pointer
    memset(choosePtr, 0, arrSize);
    while (choosePtr + arrSize != nPtr) {
        cin >> status;
        *nPtr = status;
        // cout << *nPtr << " ";
        nPtr++;
        // if ((nPtr - choosePtr) % *n == 0) { cout << endl; }
    }
    tree(n, choosePtr, nPtr);
    return 0;
}

int main(void) {
    int n;
    while (cin >> n && n > 0) {
        solve(&n);
    }
    return 0;
}