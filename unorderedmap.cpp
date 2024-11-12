#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSumBruteForce(const vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) return {i, j};
        }
    }
    return {};
}

vector<int> twoSumOptimal(const vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numMap.count(complement)) return {numMap[complement], i};
        numMap[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    auto resultBrute = twoSumBruteForce(nums, target);
    cout << "Brute Force Solution: [" << resultBrute[0] << ", " << resultBrute[1] << "]" << endl;

    auto resultOptimal = twoSumOptimal(nums, target);
    cout << "Optimal Solution: [" << resultOptimal[0] << ", " << resultOptimal[1] << "]" << endl;

    return 0;
}
