#include <iostream>
#include <cstring>
#include <string>
#include <vector>

#define LS '('
#define RS ')'
#define NTS ',' // NAP = Number and Tree Position

using namespace std;

vector<string> TreePosition(0);
vector<int> TreeValue(0);

int VerifyNumber (int n, int c) {
    if (n == 2) {
        return ++c;
    } else if (n == 1) {
        return 0*c;
    } else {
        return VerifyNumber(n/2, ++c);
    }
}

int Answer() {
    bool judge = true;
    int nArr[TreeValue.size()], initPos = TreeValue.size()-1, arrPos, arrSize, judgeN, counterN;
    // ---
    judgeN = VerifyNumber(TreeValue.size()+1, 0);
    if (judgeN == 0) {
        judge = false;
    } else {
        for (int i = 0; i < TreePosition.size(); i++)
            nArr[i] = INT_MAX;
        while (TreeValue.size() != 0) {
            arrSize = arrPos = TreePosition.size()/2;
            arrSize += 1;
            counterN = 1;
            for (string::iterator sPtr = TreePosition[initPos].begin(); sPtr < TreePosition[initPos].end(); sPtr++) {
                arrSize > 2 ? (*sPtr == 'L' ? arrPos -= arrSize/2 : arrPos += arrSize/2) : (*sPtr == 'L' ? arrPos -= 1 : arrPos += 1);
                arrSize = arrSize / 2 + 1;
                counterN += 1;
            }
            arrPos < TreePosition.size() && counterN <= judgeN ? nArr[arrPos] = TreeValue[initPos] : nArr[arrPos] = INT_MAX;
            TreeValue.pop_back();
            initPos -= 1;
        }
        for (int i = 0; i < TreePosition.size(); i++) {
            if (nArr[i] == INT_MAX) {
                judge = false;
                break;
            }
        }
    }
    if (judge) {
        for (int i = 0; i < TreePosition.size(); i++)
            cout << nArr[i] << " ";
        cout << endl;
    } else {
        cout << "wrong data\n";
    }
    return 0;
}

int Resolve (string *str) {
    int value;
    bool analysis;
    char sArr[(*str).size() + 1], *ptrStr = sArr;
    string pArr = "";
    // ---
    strcpy(sArr, (*str).c_str());
    TreePosition.clear();
    TreeValue.clear();
    while (1) {
        if (*ptrStr == '(' && *(ptrStr+1) == ')') { break; }
        switch(*ptrStr) {
            case LS:
                analysis = false;
                value = 0;
                pArr = "";
                break;
            case RS:
                TreePosition.push_back(pArr);
                break;
            case NTS:
                analysis = true;
                TreeValue.push_back(value);
                break;
            default:
                if (analysis) {
                    pArr += *ptrStr;
                } else {
                    value *= 10;
                    value += *ptrStr - 48;
                }
                break;
        }
        ptrStr += 1;
    }
    Answer();
    return 0;
}

int main(void) {
    cin.tie(0);
    string str;
    while (cin >> str && str != "()") {
        Resolve(&str);
    }
    return 0;
}