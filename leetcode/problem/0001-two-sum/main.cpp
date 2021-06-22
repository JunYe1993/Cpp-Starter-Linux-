#include<iostream>
#include<map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> dict;
        for(size_t i = 0; i < nums.size(); ++i) {
            if (dict.find(nums[i])==dict.end())
                dict[target-nums[i]] = i;
            else
                return {dict[nums[i]], (int)i};
        }
        return {0, 0};
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums;
    
    nums = {2,7,11,15};
    for (auto&n:sol.twoSum(nums, 9))
        cout << n << " ";
    cout << endl;
    
    return 0;
}