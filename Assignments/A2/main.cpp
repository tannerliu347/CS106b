/*
 * File: main.cpp
 * --------------
 * Sample QT project
 */

#include <iostream>
#include <vector>
#include "console.h"
using namespace std;


vector<vector<int>> makeGridOfCounts(vector<vector<bool>> &bombLocations) {
    vector<vector<int>> res(bombLocations.size(), vector<int>(bombLocations[0].size(), 0));
    vector<vector<int>> dirs = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {0, 0}};
    for (int i = 0; i < bombLocations.size(); i++) {
        for (int j = 0; j < bombLocations[0].size(); j++) {
            int bombCount = 0;
            for (vector<int> d:dirs) {
                int nbrR = d[0] + i, nbrC = d[1] + j;
                if (nbrR >= 0 && nbrR < bombLocations.size() && nbrC >= 0 && nbrC < bombLocations[0].size() && bombLocations[nbrR][nbrC])
                    bombCount++;
            }
            res[i][j] = bombCount;
        }
    }
    return res;
}

void printGrid(vector<vector<int>> grid) {
    for (auto row : grid) {
        for (auto ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }
}
/*
 * This sample main brings up testing menu.
 */
int main() {
    vector<vector<bool>> bombLocations = {{true, false, false, false, false, true}, {false, false, false, false, false, true, true},
                                          {true, true, false, true, false, true}, {true, false, false, false, false, false},
                                          {false, false, true, false, false, false}, {false, false, false, false, false}};
    vector<vector<int>> res = makeGridOfCounts(bombLocations);
    printGrid(res);
    return 0;
}
