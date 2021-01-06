#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void mnemonicsHelper(string &str, string &cur, unordered_map<char, vector<char>> &m) {
    if (cur.length() == str.length())
        cout << cur << endl;
    for (char c : m[str[cur.length()]]){
        cur = cur + c;
        mnemonicsHelper(str, cur, m);
        cur.pop_back();
    }
}

int main() {
    unordered_map<char, vector<char>> m = {{'2', {'A', 'B', 'C'}}, {'3', {'D', 'E', 'F'}}, {'4', {'G', 'H', 'I'}}, {'5', {'J', 'K', 'L'}},
                                           {'6', {'M', 'N', 'O'}}, {'7', {'P', 'R', 'S'}}, {'8', {'T', 'U','V'}}, {'9', {'W', 'X', 'Y', 'Z'}}};
    string str = "723";
    string res = "";
    mnemonicsHelper(str, res, m);
    return 0;
}
