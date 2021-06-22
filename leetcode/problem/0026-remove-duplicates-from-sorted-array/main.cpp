#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int count = 1, cur = nums[0];
        for (int& n : nums)
            if (n > cur) {
                cur = n;
                nums[count++] = n;
            }
        return count;
    }
};

int main() {
    Solution sol = Solution();
    
    // Test1
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int answer = sol.removeDuplicates(nums);
    cout << answer << endl;
    for (int i = 0; i < answer; ++i)
        cout << nums[i] << " ";
    cout << endl;
    for (int& n : nums)
        cout << n << " ";
    cout << endl;

    return 0;
}