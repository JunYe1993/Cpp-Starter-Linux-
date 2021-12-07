#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int searchInsert (vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;

        if (target > nums[r]) return r+1;

        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums;
    int target;
    
    nums = {1,3,5,6};
    target = 5;
    cout << sol.searchInsert(nums, target) << endl;
    nums = {1,3,5,6};
    target = 2;
    cout << sol.searchInsert(nums, target) << endl;
    nums = {1,3,5,6};
    target = 7;
    cout << sol.searchInsert(nums, target) << endl;
    nums = {1,3,5,6};
    target = 0;
    cout << sol.searchInsert(nums, target) << endl;
    nums = {1};
    target = 0;
    cout << sol.searchInsert(nums, target) << endl;

    return 0;
}