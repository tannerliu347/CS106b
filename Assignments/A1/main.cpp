/*
 * File: main.cpp
 * --------------
 * Sample QT project
 */

#include <iostream>
#include <fstream>
#include <vector>
#include "console.h"
using namespace std;

/*
 * This sample main brings up testing menu.
 */

// P1
string CensorString1(string text, string remove) {
    string res = "";
    for (char c : text) {
        if (remove.find(c) == string::npos)
            res += c;
    }
    return res;
}
void CensorString2(string &text, string remove) {
    for (int i = 0; i < remove.length(); i++) {
        int pos = 0;
        while ((pos = text.find(remove[i], pos)) != string::npos) {
            text.replace(pos, 1, "");
        }
    }

}

//P2
struct statsT {
    int min;
    int max;
    double average;
};
statsT CalculateStatistics(string filename) {
    statsT stats;
    stats.min = 101;
    stats.max = -1;
    int total = 0;
    int count = 0;
    ifstream in;
    in.open(filename);
    if (in.fail()) cout << "GG" << endl;
    while(true) {
        int num;
        in >> num;
        if (in.fail()) break;
        stats.min = min(stats.min, num);
        stats.max = max(stats.max, num);
        total += num;
        count++;
    }
    stats.average = (double) total / count;
    in.close();
    return stats;
}

// P3
void CountLetters(string filename) {
    ifstream in;
    in.open(filename);
    if (in.fail()) cout << "GG" << endl;
    vector<int> counts(26);
    string line;
    while (true) {
        getline(in, line);
        if (in.fail()) break;
        // iterate through every char
        for (char c : line) {
            int idx = tolower(c) - 'a';
            if (idx >= 0 && idx < 26)
                counts[idx]++;
        }
    }
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        cout << c << ": " << counts[i] << endl;
    }
}

int main() {
    string res = CensorString1("Stanford University", "nt");
    cout << res << endl;
    cout << CensorString1("Llamas like to laugh", "la") << endl;
    cout << "Inplace:" << endl;
    string a = "Stanford University";
    CensorString2(a, "nt");
    cout << a << endl;
    statsT score = CalculateStatistics("Scores.txt");
    cout << score.max << " " << score.min << " " << score.average << endl;
    CountLetters("P3.txt");
    return 0;
}
