#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // int theNum = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (i == nums.size()-1 && nums[i-1] != nums[i]) 
                return nums[i];
            else if ( nums[i-1] != nums[i] && nums[i+1] != nums[i] )
                return nums[i];
        }
        return nums[0];
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {2,2,1};
    cout << sol.singleNumber(nums) << endl;
    return 0;
}

