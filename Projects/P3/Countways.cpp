#include <iostream>

using namespace std;

int countHelper(int curStep, int goal) {
    if (curStep > goal)
        return 0;
    if (curStep == goal)
        return 1;
    return countHelper(curStep + 1, goal) + countHelper(curStep + 2, goal);
}

int countWays(int numStairs) {
    return countHelper(0, numStairs);
}

//int main() {
//    cout << countWays(30);
//    return 0;
//}
