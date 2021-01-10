#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void cutHelper(vector<int> &requests, int idx, vector<int> &used, int stockLength, int &bestRes) {
    if (idx == requests.size()) {
        bestRes = min(bestRes, (int) used.size());
        return;
    }
    for (int i = 0; i < used.size(); i++) {
        int u = used[i];
        if (requests[idx] <= u) {
            // can use scrap
            used[i] = used[i] - requests[idx];
            cutHelper(requests, idx + 1, used, stockLength, bestRes);
            used[i] = used[i] + requests[idx];
        }
    }
    // or not use scrap, start a new piece
    used.push_back(stockLength - requests[idx]);
    cutHelper(requests, idx + 1, used, stockLength, bestRes);
    used.pop_back();
}

int cutStock(vector<int> &requests, int stockLength) {
    int res = INT_MAX;
    vector<int> used;
    cutHelper(requests, 0, used, stockLength, res);
    return res;
}

int main() {
    vector<int> requests = {4,3,4,1,7,8,1,9,9,2,2};
    int stockLength = 10;
    int res = cutStock(requests, stockLength);
    cout << res;
    return 0;
}
