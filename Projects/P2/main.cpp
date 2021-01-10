/*
 * File: main.cpp
 * --------------
 * Sample QT project
 */

#include <iostream>
#include "console.h"
#include <unordered_map>
#include <vector>
#include "filelib.h"
using namespace std;

unordered_map<string, vector<char>> analyzeText(int order, string &maxFreqSeed) {
    unordered_map<string, vector<char>> res;
    unordered_map<string, int> seedFreq;
    ifstream in;
    promptUserForFile(in, "Enter filename for analysis: ", "");
    char c;
    string seed = "";
    while (true) {
        c = in.get();
        if (seed.length() <= order) {
            seed = seed + c;
        } else {
            res[seed].push_back(c);
            seedFreq[seed]++;
            seed = seed.substr(1, seed.length()-1);
            seed = seed + c;
        }
        if (in.fail()) break;
    }
    for (auto sf : seedFreq) {
        if (sf.second > seedFreq[maxFreqSeed])
            maxFreqSeed = sf.first;
    }
    return res;
}

void generateText(unordered_map<string, vector<char>> &m, string maxFreqseed) {
    ofstream out;
    out.open("output.txt");
    out << maxFreqseed;
    string seed = maxFreqseed;
    char c;
    for (int i = 0; i < 2000; i++) {
        vector<char> sampleList = m[seed];
        c = sampleList[randomInteger(0, sampleList.size())];
        out << c;
        seed = seed.substr(1, seed.length() - 1);
        seed = seed + c;
    }
    out.close();
}
/*
 * This sample main brings up testing menu.
 */
int main() {
    cout << "Order of markov model: " << endl;
    int order = 10;
    cin >> order;
    string maxFreqSeed;
    unordered_map<string, vector<char>> freq = analyzeText(order, maxFreqSeed);
    generateText(freq, maxFreqSeed);
    return 0;
}
