#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int closest = nums[0]+nums[1]+nums[2];
        
        for (int i = 0; i < size-2; ++i) {
            int subTarget = target-nums[i];
            int j = i + 1;
            int k = size - 1;
            while (j < k) {
                int diff = subTarget-nums[j]-nums[k];
                int gap = abs(diff);
                if (diff > 0) ++j;
                else if (diff < 0) --k;
                else return target;
                closest = (abs(closest-target) > gap) ? target-diff:closest;
            }
        }

        return closest;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int target;

    nums = {-1,2,1,-4};
    target = 1;
    cout << sol.threeSumClosest(nums, target) << endl;

    return 0;
}