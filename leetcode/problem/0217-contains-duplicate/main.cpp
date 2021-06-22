#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> dict;
        for (auto&n:nums) {
            if (dict.find(n) == dict.end())
                dict[n] = true;
            else
                return dict[n];
        }
        return false;
    }
    // sort 比較快
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-1; i++)
            if(nums[i] == nums[i+1])
                return true;
        return false;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {1,2,3};
    sol.containsDuplicate(nums);
    return 0;
}