#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int rob (vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return nums[0];
        if (size == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0]+nums[2];
        for (int i = 3; i < size; ++i) {
            int preMax = dp[i-3] > dp[i-2] ? dp[i-3] : dp[i-2];
            dp[i] = preMax + nums[i];
        }
        return dp[size-1] > dp[size-2] ? dp[size-1] : dp[size-2];
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {1,2,3,1,99,0,8,7};
    cout << sol.rob (nums) << endl;

    nums = {2,7,9,3,1};
    cout << sol.rob (nums) << endl;
    
    return 0;
}