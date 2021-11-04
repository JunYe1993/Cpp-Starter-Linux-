#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<string> findMissingRanges (vector<int>& nums, int lower, int upper) {
        
        vector<string> missingRanges;
        int size = nums.size();
        
        int cur = lower;
        for (int i = 0; i < size && nums[i] <= upper; ++i) {
            if (nums[i] > cur) {
                if (cur == nums[i]-1) missingRanges.push_back(to_string(cur));
                else missingRanges.push_back(to_string(cur) + "->" + to_string(nums[i] - 1));
                cur = nums[i] + 1;
            } else if (nums[i] == cur) {
                ++cur;
            } 
        }

        if (cur <= upper) {
            if (cur == upper) missingRanges.push_back(to_string(cur));
            else missingRanges.push_back(to_string(cur) + "->" + to_string(upper));
        }

        return missingRanges;
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int lower, upper;

    nums = {0,1,3,50,75};
    lower = 0, upper = 99;
    for (auto&s:sol.findMissingRanges(nums, lower, upper))
        cout << s << endl;
    cout << "---" << endl;
    nums = {};
    lower = 1, upper = 1;
    for (auto&s:sol.findMissingRanges(nums, lower, upper))
        cout << s << endl;
    cout << "---" << endl;
    nums = {};
    lower = -3, upper = -1;
    for (auto&s:sol.findMissingRanges(nums, lower, upper))
        cout << s << endl;
    cout << "---" << endl;
    nums = {-1};
    lower = -1, upper = -1;
    for (auto&s:sol.findMissingRanges(nums, lower, upper))
        cout << s << endl;
    cout << "---" << endl;
    nums = {-1};
    lower = -2, upper = -1;
    for (auto&s:sol.findMissingRanges(nums, lower, upper))
        cout << s << endl;
    cout << "---" << endl;


    return 0;
}