#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0, count = 0;
        for (auto&n:nums) {
            if (n == 1) {
                if (++count > max)
                    max = count;
            }
            else
                count = 0;
        }
        return max;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    
    nums = {1,1,0,1,1,1};
    cout << sol.findMaxConsecutiveOnes(nums) << endl;

    return 0;
}