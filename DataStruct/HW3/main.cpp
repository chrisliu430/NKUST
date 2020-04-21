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
vector<string> AnswerJudge(0);
vector<int> Answer(0);

int RecursionAnswer(string _target, vector<int>& _answer) {
    for (int i = 0; i < TreePosition.size(); i++) {
        if (TreePosition[i] == _target) {
            AnswerJudge.push_back(_target);
            RecursionAnswer(_target + "L", _answer);
            _answer.push_back(TreeValue[i]);
            RecursionAnswer(_target + "R", _answer);
        }
    }
    return 0;
}

int Resolve (string *str) {
    int value;
    bool analysis;
    char sArr[(*str).size() + 1], *ptrStr = sArr;
    string pArr = "";
    bool judgeFinal = true;
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
            case ' ':
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
    RecursionAnswer("", Answer);
    if (Answer.size() != TreeValue.size()) {
        judgeFinal = false;
    } else {
        for (int i = 0; i < AnswerJudge.size(); i++) {
            for (int j = i+1; j < AnswerJudge.size(); j++) {
                if (AnswerJudge[i] == AnswerJudge[j]) {
                    judgeFinal = false;
                    break;
                }
            }
            if (judgeFinal == false) { break; }
        }
    }
    if (judgeFinal) {
        for (int i = 0; i < Answer.size(); i++)
            cout << Answer[i] << " ";
        cout << endl;
    } else {
        cout << "wrong data\n";
    }
    AnswerJudge.clear();
    Answer.clear();
    return 0;
}

int main(void) {
    cin.tie(0);
    string str;
    while (getline(cin, str) && str != "()") {
        Resolve(&str);
    }
    return 0;
}