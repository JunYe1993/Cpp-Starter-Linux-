#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // Intuition
        // Translation:
        // Find the longest subarray with at most K zeros.
        // 
        // Explanation
        // For each A[j], try to find the longest subarray.
        // If A[i] ~ A[j] has zeros <= K, we continue to increment j.
        // If A[i] ~ A[j] has zeros > K, we increment i (as well as j).

        size_t i = 0, j;
        for (j = 0; j < nums.size(); ++j) {
            if (nums[j] == 0) --k;
            if (k < 0) {
                if (nums[i] == 0) ++k;
                ++i;
            }
        }
        return j - i;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int k;
    
    nums = {1,1,1,0,0,0,1,1,1,1,0}; k = 2;
    cout << sol.longestOnes(nums, k) << endl;

    nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}; k = 3;
    cout << sol.longestOnes(nums, k) << endl;

    nums = {0,0,0,1}; k = 4;
    cout << sol.longestOnes(nums, k) << endl;

    return 0;
}