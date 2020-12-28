#include <unordered_map>
#include "simpio.h"

using namespace std;

string soundexConv (string surname) {
    unordered_map<char, char> m = {
        {'a', '0'}, {'e', '0'}, {'i', '0'}, {'o', '0'}, {'u', '0'}, {'h', '0'}, {'w', '0'}, {'y', '0'}, {'b', '1'}, {'f', '1'},
        {'p', '1'}, {'v', '1'}, {'c', '2'}, {'g', '2'}, {'k', '2'}, {'k', '2'},{'q', '2'}, {'s', '2'}, {'x', '2'}, {'z', '2'},
        {'d', '3'}, {'t', '3'}, {'m', '4'}, {'n', '4'}, {'l', '5'}, {'r', '6'}
    };
    string res;
    res = res + surname[0];
    for (int i = 1; i < surname.length(); i++) {
        char cur = m[surname[i]];
        if (cur != '0' && cur != res.back())
            res = res + cur;
    }
    if (res.length() > 4)
        res = res.substr(0, 4);
    if (res.length() < 4) {
        size_t size = 4 - res.length();
        for (int i = 0; i < size; i++)
            res = res + '0';
    }
    return res;
}

int main() {
    string surname = getLine("Enter your surname");
    cout << "Corresponding soundex token: " << soundexConv(surname);
    return 0;
}
