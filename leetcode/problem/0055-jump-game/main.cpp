#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Solution {

    bool trace (vector<int>& nums, int target) {
        
        for (int i = 0; i < target; ++i) {
            if (nums[i]>= target) {
                if (i == 0) return true;
                else return trace(nums, i);
            }
        }
        return false;
    }

public:
    bool canJump (vector<int>& nums) {
        
        int size = nums.size();
        if (size == 1) return true;
        for (int i = 0; i < size; ++i) {
            nums[i] += i; 
            if (nums[i] >= size-1) {
                if (i == 0) return true;
                else return trace(nums, i);
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {2,3,1,1,4};
    cout << sol.canJump (nums) << endl;
    nums = {3,2,1,0,4};
    cout << sol.canJump (nums) << endl;
    nums = {0};
    cout << sol.canJump (nums) << endl;
    
    return 0;
}