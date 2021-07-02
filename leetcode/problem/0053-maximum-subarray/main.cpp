#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxSubArray (vector<int>& nums) {
        int sum = 0, max = -1000000;
        size_t i;
        for (i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            max = max > sum ? max : sum;
            if (sum < 0) sum = 0;
        }   
        return max;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << sol.maxSubArray(nums) << endl;

    nums = {1};
    cout << sol.maxSubArray(nums) << endl;

    nums = {5,4,-1,7,8};
    cout << sol.maxSubArray(nums) << endl;

    nums = {-1};
    cout << sol.maxSubArray(nums) << endl;
    
    return 0;
}