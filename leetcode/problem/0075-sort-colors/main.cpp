#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
    void show (vector<int>& nums) {
        for (auto&n:nums)
            cout << n << " ";
        cout << endl;
    }

public:
    void sortColors (vector<int>& nums) {
        
        int size = nums.size();
        int zero = 0;
        for (int i = 0; i < size; ++i) {
            while (nums[i] != 1) {
                if (nums[i] == 0) {
                    if (i > zero) swap(nums[i], nums[zero++]);
                    else break;
                } 
                else if (nums[i] == 2) {
                    if (i < size) swap(nums[i], nums[--size]);
                    else break;
                }
            }         
        }
        show (nums);
    }
};

int main () {

    Solution sol = Solution();
    vector<int> nums;

    nums = {2,0,2,1,1,0};
    sol.sortColors (nums);
    nums = {2,0,1};
    sol.sortColors (nums);
    nums = {0};
    sol.sortColors (nums);
    nums = {1,2,0};
    sol.sortColors (nums);

    return 0;
}