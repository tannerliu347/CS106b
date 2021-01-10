#include <iostream>
#include <vector>

using namespace std;

bool recSum(vector<int> &nums, int index, int AccSum, int target) {
    if (AccSum == target)
        return true;
    if (index == nums.size())
        return false;
    return recSum(nums, index + 1, AccSum, target) || recSum(nums, index + 1, AccSum + nums[index], target);
}

bool recSumv2(vector<int> &nums, int index, int AccSum, int target) {
    if (index == nums.size())
        return false;
    for (int i = index; i < nums.size(); i++) {
        if (recSumv2(nums, i+1, AccSum + nums[i], target))
            return true;
    }
    return false;
}

bool canMakeSum(vector<int> &nums, int targetSum) {
    return recSumv2(nums, 0, 0, targetSum);
}

//int main() {
//    vector<int> nums = {3, 7, 1, 8, -3};
//    bool res = canMakeSum(nums, 2);
//    cout << res;
//    return 0;
//}
