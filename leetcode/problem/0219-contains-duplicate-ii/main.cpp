#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        if (k == 0) return false;
        unordered_set<int> knums;

        for (size_t i = 0; i < nums.size(); ++i) {
            if (i < (size_t)k) {
                if (knums.find(nums[i]) == knums.end())
                    knums.insert(nums[i]);
                else
                    return true;
            } else {
                if (knums.find(nums[i]) == knums.end()) {
                    knums.insert(nums[i]);
                    knums.erase(nums[i-k]);
                } else
                    return true;
            }
        }

        return false;
    }
};


int main () {
    Solution sol;
    vector<int> nums;

    nums = {1,2,3,1};
    cout << sol.containsNearbyDuplicate(nums, 3) << endl;
    nums = {1,0,1,1};
    cout << sol.containsNearbyDuplicate(nums, 1) << endl;
    nums = {1,2,3,1,2,3};
    cout << sol.containsNearbyDuplicate(nums, 2) << endl;

    return 0;
}