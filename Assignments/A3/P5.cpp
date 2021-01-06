#include <iostream>

using namespace std;

string reverseString(string str) {
    if (str.length() == 0 || str.length() == 1)
        return str;
    return str[str.length() - 1] + reverseString(str.substr(1, str.length() - 2)) + str[0];
}

//int main() {
//    string str = "reverse";
//    cout << "Original string: " << str << endl;
//    cout << "Reversed string: " << reverseString(str) << endl;
//    return 0;
//}
