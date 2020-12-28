#include <vector>
#include <string>
#include "simpio.h"
#include "filelib.h"

using namespace std;
int main() {
    vector<int> hist(10, 0);
    ifstream in;
    promptUserForFile(in, "Enter filename for score: ", "");
    string line;
    while (true) {
        getline(in, line);
        if (in.fail()) break;
        int score = stoi(line);
        hist[score / 10]++;
    }
    for (int i = 0; i < hist.size(); i++) {
        cout << hist[i] << endl;
    }
    return 0;
}
