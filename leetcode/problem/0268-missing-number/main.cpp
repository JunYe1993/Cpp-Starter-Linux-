#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int max = nums.size();
        int sum = (max*(max+1))/2;
        for (auto&n:nums)
            sum -= n;
        return sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {3,0,1};
    cout << sol.missingNumber(nums) << endl;

    nums = {0,1};
    cout << sol.missingNumber(nums) << endl;

    nums = {9,6,4,2,3,5,7,0,1};
    cout << sol.missingNumber(nums) << endl;

    nums = {0};
    cout << sol.missingNumber(nums) << endl;

    return 0;
}