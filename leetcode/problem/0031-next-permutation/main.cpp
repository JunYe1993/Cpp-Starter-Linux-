#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int size = nums.size();
        int left = size;
        for (int i = size-1; i > 0; --i) 
            if (nums[i] > nums[i-1]) {
                left = i - 1;
                break;
            }

        if (left == size) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = size-1; i > 0; --i)
            if (nums[i] > nums[left]) {
                int temp = nums[i];
                nums[i] = nums[left];
                nums[left] = temp;
                sort(nums.begin()+left+1, nums.end());
                return;
            }
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums;
    
    nums = {1,2,3};
    sol.nextPermutation(nums);
    for (auto&n:nums) 
        cout << n << " ";
    cout << endl;
    nums = {3,2,1};
    sol.nextPermutation(nums);
    for (auto&n:nums) 
        cout << n << " ";
    cout << endl;
    nums = {1,1,5};
    sol.nextPermutation(nums);
    for (auto&n:nums) 
        cout << n << " ";
    cout << endl;
    nums = {1};
    sol.nextPermutation(nums);
    for (auto&n:nums) 
        cout << n << " ";
    cout << endl;
    nums = {1, 3, 2};
    sol.nextPermutation(nums);
    for (auto&n:nums) 
        cout << n << " ";
    cout << endl;

    return 0;
}