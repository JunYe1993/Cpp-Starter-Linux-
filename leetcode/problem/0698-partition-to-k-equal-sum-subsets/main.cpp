#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {

    void showVector (vector<int>& nums) {
        for (auto&n:nums)
            cout << n << " ";
        cout << endl;
    }

    bool canPartition (vector<int>& nums, vector<int>& stack) {
        
        if (stack.empty()) return true;
        // showVector (nums);
        // showVector (stack);
        for (int i = nums.size()-1; i >= 0; --i) {
            if (stack.back() == nums[i]) {
                nums.erase(nums.begin()+i);
                stack.pop_back();
                return canPartition(nums, stack);
            } else if (stack.back() > nums[i]){
                vector<int> next_nums  = nums; 
                vector<int> next_stack = stack;
                next_nums.erase(next_nums.begin()+i);
                next_stack.back() -= nums[i];
                if (canPartition(next_nums, next_stack)) return true;
            }
        }
        return false;
    }

public:
    bool canPartitionKSubsets (vector<int>& nums, int k) {
        
        // 總和不能整除 = false.
        int sum = 0;
        for (auto&n:nums) sum += n;
        if (sum % k > 0) return false;

        // 題目有寫都是正整數, 所以最大的數大於 target, 會合不出 sub set.
        int target = sum / k;
        sort (nums.begin(), nums.end());
        if (nums.back() > target) return false;

        vector<int> stack(k, target);
        return canPartition(nums, stack);
    }
};

int main() {
    Solution sol;
    int k;
    vector<int> nums;

    k = 4, nums = {4,3,2,3,5,2,1};
    cout << ((sol.canPartitionKSubsets(nums, k)) ? "True":"False") << endl;
    k = 3, nums = {1,2,3,4};
    cout << ((sol.canPartitionKSubsets(nums, k)) ? "True":"False") << endl;
    k = 3, nums = {1,2,2,2,2};
    cout << ((sol.canPartitionKSubsets(nums, k)) ? "True":"False") << endl;
    k = 5, nums = {3522,181,521,515,304,123,2512,312,922,407,146,1932,4037,2646,3871,269};
    cout << ((sol.canPartitionKSubsets(nums, k)) ? "True":"False") << endl;

    return 0;
}