#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets = {{}, {nums[0]}};
        
        int preSize = 1;
        for (int i = 1; i < (int)nums.size(); ++i) {
            int startIndex = nums[i] == nums[i-1] ? preSize : 0;
            preSize = subsets.size();
            for (int j = startIndex; j < preSize; ++j) {
                vector<int> temp = subsets[j];
                temp.push_back(nums[i]);
                subsets.push_back(temp);
            }
        }
        return subsets;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {1, 1};
    for (auto&v:sol.subsetsWithDup(nums)) {
        cout << "{ ";
        for (auto&n:v) {
            cout << n << " ";
        }
        cout << "}, ";
    }
    cout << endl;

    nums = {1, 2, 2};
    for (auto&v:sol.subsetsWithDup(nums)) {
        cout << "{ ";
        for (auto&n:v) {
            cout << n << " ";
        }
        cout << "}, ";
    }
    cout << endl;

    return 0;
}