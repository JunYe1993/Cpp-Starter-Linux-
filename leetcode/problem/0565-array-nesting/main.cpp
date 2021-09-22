#include <iostream>
#include <vector>
#include <string> 
#include <cctype>
#include <unordered_map>

using namespace std;

class Solution {
    
    int find (vector<int>& nums, int index, int start) {
        if (nums[index] == index) return index;
        else if (nums[index] == start) return start;
        else {
            nums[index] = find(nums, nums[index], start);
            return nums[index];
        }
    }

public:
    int arrayNesting(vector<int>& nums) {
        
        int size = nums.size();
        for (int i = 0; i < size; ++i)
            find (nums, i, i);
        
        int maxSize = 0;
        unordered_map<int, int> map;
        for (auto&n:nums) 
            maxSize = max(maxSize, ++map[n]);

        return maxSize;
    }
};

int main () {
    Solution sol;
    vector<int> nums;
    
    nums = {5,4,0,3,1,6,2};
    cout << sol.arrayNesting(nums) << endl;
    nums = {0,1,2};
    cout << sol.arrayNesting(nums) << endl;

    return 0;
}