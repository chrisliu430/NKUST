#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void RecursionTree(int dir, map<string, string>& cprDat, string dat, string cpr, vector<vector<string>>& tree);
void SortNode(vector<int>& cFreq, vector<string>& cDict);
template <typename ST> void Swap(ST chgThing1, ST chgThing2);

int main(void) {
    int layerCnt = 0;
    string s = "";
    vector<int> cFreq(0);
    vector<string> cDict(0);
    vector<vector<string>> tree(0);
    map<string, string> compressDat(0);
    cin >> s;
    for (int l = 0; l < s.length(); l++) {
        string c;
        stringstream cs;
        cs << s[l];
        cs >> c;
        vector<string>::iterator cIter = find(cDict.begin(), cDict.end(), c);
        if (cIter == cDict.end()) {
            cDict.push_back(c);
            cFreq.push_back(1);
        } else {
            int dtc = distance(cDict.begin(), cIter);
            cFreq[dtc]++;
        }
    }
    SortNode(cFreq, cDict);
    cout << "Total of char frequence:\n";
    for (int i = 0; i < cFreq.size(); i++) {
        cout << cDict[i] << " " << cFreq[i] << endl;
    }
    while(cDict.size() > 2) {
        int mergeFreq = 0;
        vector<string> subNode(2);
        subNode[0] = cDict[0];
        subNode[1] = cDict[1];
        mergeFreq = cFreq[0] + cFreq[1];
        reverse(cDict.begin(),cDict.end());
        reverse(cFreq.begin(),cFreq.end());
        cDict.pop_back();
        cDict.pop_back();
        cFreq.pop_back();
        cFreq.pop_back();
        reverse(cDict.begin(),cDict.end());
        reverse(cFreq.begin(),cFreq.end());
        cDict.push_back(to_string(layerCnt) + "Layer");
        cFreq.push_back(mergeFreq);
        tree.push_back(subNode);
        SortNode(cFreq, cDict);
        layerCnt++;
    }
    vector<string> subNode(2);
    subNode[0] = cDict[0];
    subNode[1] = cDict[1];
    tree.push_back(subNode);
    RecursionTree(0, compressDat, tree[tree.size() - 1][0], "0", tree);
    RecursionTree(1, compressDat, tree[tree.size() - 1][1], "1", tree);
    cout << "Compress result:\n";
    for (map<string, string>::iterator mIter = compressDat.begin(); mIter != compressDat.end(); mIter++) {
        cout << mIter->first << " " << mIter->second << endl;
    }
    return 0;
}

void SortNode(vector<int>& cFreq, vector<string>& cDict) {
    for (int i = 0; i < cFreq.size() - 1; i++) {
        for (int j = i + 1; j < cFreq.size(); j++) {
            if (cFreq[i] > cFreq[j]) {
                // int temp = cFreq[i];
                // cFreq[i] = cFreq[j];
                // cFreq[j] = temp;
                // string cTemp = cDict[i];
                // cDict[i] = cDict[j];
                // cDict[j] = cTemp;
                Swap(cFreq[i], cFreq[j]);
                Swap(cDict[i], cDict[j]);
            }
        }
    }
    return;
}

void RecursionTree(int dir, map<string, string>& cprDat, string dat, string cpr, vector<vector<string>>& tree) {
    size_t dIndex = dat.find("Layer", 0);
    if (dIndex != string::npos) {
        int l = stoi(dat.substr(0, dIndex));
        RecursionTree(0, cprDat, tree[l][0], cpr + "0", tree);
        RecursionTree(1, cprDat, tree[l][1], cpr + "1", tree);
    } else {
        cprDat.insert(pair<string, string>(dat, cpr));
        return;
    }
}

template <typename ST> // Swap Type
void Swap(ST chgThing1, ST chgThing2) {
    ST temp = chgThing1;
    chgThing1 = chgThing2;
    chgThing2 = temp;
    return;
}