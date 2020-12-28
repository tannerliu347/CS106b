#include <iostream>
#include "console.h"
#include "random.h"

using namespace std;

bool isElecValid(int numVoter, double spread, double errPerc) {
    if (spread > 1 || spread < 0 || errPerc > 1 || errPerc < 0) {
        cout << "Invalid Input" << endl;
        return false;
    }
    int majority = numVoter * (0.5 + spread);
    int simResult = 0;
    for (int i = 0; i < majority; i++) {
        double sample = randomReal(0, 1);
        int cur = (sample < (1 - errPerc)) ? 1 : 0;
        simResult += cur;
    }
    return simResult >= numVoter * 0.5;
}

int main() {
    cout << "Enter number of voters:" << endl;
    int numVoter = 0;
    cin >> numVoter;
    cout << "Enter percentage spread between candidates:" << endl;
    double spread = 0;
    cin >> spread;
    cout << "Enter voting error percentage: " << endl;
    double errPerc = 0;
    cin >> errPerc;
    int numInvalid = 0;
    for (int i = 0; i < 500; i++) {
        if (!isElecValid(numVoter, spread, errPerc))
            numInvalid++;
    }
    double result = (double) numInvalid / numVoter;
    cout << "Chance of an invalid election result after 500 trials = " << result << endl;
    return 0;
}
