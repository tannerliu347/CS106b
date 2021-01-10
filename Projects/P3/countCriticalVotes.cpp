#include <iostream>
#include <vector>
#include <math.h>


using namespace std;

void helper(vector<int> &blocks, int majority, int Avotes, int Bvotes, int blockVotes, int idx, int &count) {
    if (idx == blocks.size()) {
        if ((Avotes < majority && Avotes + blockVotes >= majority) || (Bvotes < majority && Bvotes + blockVotes >= majority))
            count++;
        return;
    }
    helper(blocks, majority, Avotes + blocks[idx], Bvotes, blockVotes, idx + 1, count);
    helper(blocks, majority, Avotes, Bvotes + blocks[idx], blockVotes, idx + 1, count);
}

int countCriticalVotes(vector<int> &blocks, int blockIndex) {
    int sum = 0;
    for (int b : blocks)
        sum += b;
    int majority = (int) ceil(sum / 2.0);
    int blockVotes = blocks[blockIndex];
    blocks.erase(blocks.begin() + blockIndex);
    int res = 0;
    helper(blocks, majority, 0, 0, blockVotes, 0, res);
    return res;
}

//int main() {
//    vector<int> blocks = {4, 2, 7, 4};
//    int res = countCriticalVotes(blocks, 1);
//    cout << res;
//    return 0;
//}

