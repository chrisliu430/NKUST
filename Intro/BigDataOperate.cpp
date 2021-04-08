/*********************************************/
/*Big-Data Operate ***************************/
/*********************************************/
/*Asking Condition ***************************/
/*OPEN FILE FOR READ *************************/
/*DATA TYPE CAN'T USE BUILT-IN NUMBER TYPE ***/
/*OPERATE POSITIVE VALUE & NEGATIVE VALUE ****/
/*********************************************/
/* Modify Date: 110/04/08 ********************/
/*********************************************/
#include <iostream>
#include <string>
#include <string.h>

#define MAXSIZE 2
#define MAXSTRINGSIZE 50
#define MAXINTSIZE MAXSTRINGSIZE*2

using namespace std;

int strCount;
int length;
bool negSym[MAXSIZE]; // True is - / False is +
char num[MAXSIZE][MAXSTRINGSIZE];
int numInt[MAXSIZE][MAXSTRINGSIZE];
int intStart[MAXSIZE];
int result[MAXINTSIZE];

int String2Int();
// Above -> "" meaning is [Operation Symbol]
int Addition(); // Process + "+" + / - "+" - / + "-" - / - "-" +
int AdditionPos(); // Process - "+" + / - "-" -
int AdditionNeg(); // Process + "+" - / + "-" +
void ShowResult(int);
void ResultOutput(char);

int main() {
    FILE *fin = fopen("Input.txt", "r");
    strCount = 0;
    if (fin == NULL) {
        cout << "Error!" << endl;
    } else {
        while (!feof(fin)) {
            fscanf(fin, "%s", num[strCount]);
            if (num[strCount][0] == '-') negSym[strCount] = true;
            else negSym[strCount] = false;
            strCount += 1;
        }
        String2Int();
        length = (MAXSTRINGSIZE - 1 - intStart[0]) > (MAXSTRINGSIZE - 1 - intStart[1]) ? (MAXSTRINGSIZE - 1 - intStart[0]) : (MAXSTRINGSIZE - 1 - intStart[1]);
        cout << "Addition\n";
        ResultOutput('+');
        if (negSym[0] && negSym[1]) cout << "-";
        if (negSym[0] == negSym[1]) Addition();
        if (negSym[0] == true && negSym[1] == false) AdditionPos();
        if (negSym[0] == false && negSym[1] == true) AdditionNeg();
        String2Int();
        cout << "Subtraction\n";
        ResultOutput('-');
        if (negSym[0] && !negSym[1]) cout << "-";
        if (negSym[0] != negSym[1]) Addition();
        if (negSym[0] == true && negSym[1] == true) AdditionPos();
        if (negSym[0] == false && negSym[1] == false) AdditionNeg();
    }
    fclose(fin);
    cout << endl;
    return 0;
}

int String2Int() {
    for (int i = 0; i < MAXSIZE; i++) {
        int intPos = MAXSTRINGSIZE - 1, endPos;
        if (negSym[i] == true) endPos = 1;
        else endPos = 0;
        for (int j = strlen(num[i]) - 1; j >= endPos; j--) {
            numInt[i][intPos] = num[i][j] - 48;
            intPos -= 1;
        }
        intStart[i] = intPos;
        for (int j = intPos; j >= 0; j--) numInt[i][intPos] = 0;
    }
    return 0;
}

int Addition() {
    int operPos = MAXSTRINGSIZE - 1, carry = 0, value, resPos = MAXINTSIZE - 1;
    for (int i = operPos; i > operPos - length; i--) {
        value = numInt[0][i] + numInt[1][i] + carry;
        carry = value / 10;
        result[resPos] = value % 10;
        resPos -= 1;
    }
    if (carry) {
        result[resPos] = carry;
        resPos -= 1;
    }
    for (int j = resPos + 1; j < MAXINTSIZE; j++) cout << result[j];
    cout << endl;
    return 0;
}

int AdditionPos() {
    bool resultNeg, show = false;
    int operPos = MAXSTRINGSIZE - 1, carry = 0, value, resPos, startPos;
    if ((operPos - intStart[0]) > (operPos - intStart[1])) { resultNeg = true; }
    else if ((operPos - intStart[0]) < (operPos - intStart[1])) { resultNeg = false; }
    else {
        for (int i = MAXSTRINGSIZE - length; i < MAXSTRINGSIZE; i++) {
            if (numInt[0][i] > numInt[1][i]) {
                resultNeg = true;
                break;
            } else if (numInt[0][i] < numInt[1][i]) {
                resultNeg = false;
                break;
            }
        }
    }
    if (resultNeg) {
        resPos = MAXINTSIZE - 1;
        for (int i = MAXSTRINGSIZE - 1; i > MAXSTRINGSIZE - 1 - length; i--) {
            if (numInt[0][i] < numInt[1][i]) {
                numInt[0][i - 1] -= 1;
                numInt[0][i] += 10;
                value = numInt[0][i] - numInt[1][i];
            } else {
                value = numInt[0][i] - numInt[1][i];
            }
            result[resPos] = value;
            resPos -= 1;
        }
        startPos = resPos + 1;
    }
    else {
        resPos = MAXINTSIZE - 1;
        for (int i = MAXSTRINGSIZE - 1; i > MAXSTRINGSIZE - 1 - length; i--) {
            if (numInt[0][i] > numInt[1][i]) {
                numInt[1][i - 1] -= 1;
                numInt[1][i] += 10;
                value = numInt[1][i] - numInt[0][i];
            } else {
                value = numInt[1][i] - numInt[0][i];
            }
            result[resPos] = value;
            resPos -= 1;
        }
        startPos = MAXINTSIZE - length;
    }
    if (resultNeg) { cout << "-"; }
    ShowResult(startPos);
    return 0;
}

int AdditionNeg() {
    bool resultNeg, show = false;
    int operPos = MAXSTRINGSIZE - 1, carry = 0, value, resPos, startPos;
    if ((operPos - intStart[0]) > (operPos - intStart[1])) { resultNeg = false; }
    else if ((operPos - intStart[0]) < (operPos - intStart[1])) { resultNeg = true; }
    else {
        for (int i = MAXSTRINGSIZE - length; i < MAXSTRINGSIZE; i++) {
            if (numInt[0][i] > numInt[1][i]) {
                resultNeg = false;
                break;
            } else if (numInt[0][i] < numInt[1][i]) {
                resultNeg = true;
                break;
            }
        }
    }
    if (resultNeg) {
        resPos = MAXINTSIZE - 1;
        for (int i = MAXSTRINGSIZE - 1; i > MAXSTRINGSIZE - 1 - length; i--) {
            if (numInt[0][i] > numInt[1][i]) {
                numInt[1][i - 1] -= 1;
                numInt[1][i] += 10;
                value = numInt[1][i] - numInt[0][i];
            } else {
                value = numInt[1][i] - numInt[0][i];
            }
            result[resPos] = value;
            resPos -= 1;
        }
        startPos = resPos + 1;
    }
    else {
        resPos = MAXINTSIZE - 1;
        for (int i = MAXSTRINGSIZE - 1; i > MAXSTRINGSIZE - 1 - length; i--) {
            if (numInt[0][i] < numInt[1][i]) {
                numInt[0][i - 1] -= 1;
                numInt[0][i] += 10;
                value = numInt[0][i] - numInt[1][i];
            } else {
                value = numInt[0][i] - numInt[1][i];
            }
            result[resPos] = value;
            resPos -= 1;
        }
        startPos = MAXINTSIZE - length;
    }
    if (resultNeg) { cout << "-"; }
    ShowResult(startPos);
    return 0;
}

void ShowResult(int startPos) {
    bool show = false;
    for (int j = startPos; j < MAXINTSIZE; j++) {
        if (result[j] == 0 && show) { cout << result[j]; }
        if (result[j] < 0) {
            cout << result[j] * -1;
            show = true;
        } else if ((result[j] > 0)) {
            cout << result[j];
            show = true;
        }
    }
    cout << endl;
}

void ResultOutput(char symbol) {
    if (negSym[0]) { cout << "-"; }
    for (int i = intStart[0] + 1; i < MAXSTRINGSIZE; i++) { cout << numInt[0][i]; }
    cout << " " << symbol << " ";
    if (negSym[1]) { cout << "-"; }
    for (int i = intStart[1] + 1; i < MAXSTRINGSIZE; i++) { cout << numInt[1][i]; }
    cout << " = ";
}