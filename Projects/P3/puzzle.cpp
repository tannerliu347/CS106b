#include <iostream>
#include <vector>

using namespace std;

bool solveHelper(int idx, vector<int> &squares, vector<bool> &visited) {
    if (idx == squares.size() - 1)
        return true;
    if (idx < 0 || idx >= squares.size() || visited[idx]) //cycle detection
        return false;
    visited[idx] = true;
    int step = squares[idx];
    return solveHelper(idx - step, squares, visited) || solveHelper(idx + step, squares, visited);
}

bool solvable(int start, vector<int> &squares) {
    vector<bool> visited(squares.size(), false);
    return solveHelper(start, squares, visited);
}

//int main() {
////    vector<int> squares = {3, 6, 4, 1, 3, 4, 2, 5, 3, 0};
//    vector<int> squares = {3, 1, 2, 3, 0};
//    bool res = solvable(0, squares);
//    cout << res;
//    return 0;
//}
