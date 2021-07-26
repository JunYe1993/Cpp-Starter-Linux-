#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return 0;
        int max = size - 1;
        int min = 0;
        
        if (nums[min] > nums[min+1]) return min;
        if (nums[max] > nums[max-1]) return max;
        while (min < max) {
            int mid = (max+min) / 2;
            if (mid == min) break;
            if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) return mid;
            else if (nums[mid-1] < nums[mid] && nums[mid] < nums[mid+1]) min = mid;
            else if (nums[mid-1] > nums[mid] && nums[mid] > nums[mid+1]) max = mid;
            else min = mid;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> num;

    num = {1, 2, 3, 1};
    cout << sol.findPeakElement(num) << endl;

    num = {1, 2, 1, 3, 5, 6, 4};
    cout << sol.findPeakElement(num) << endl;

    return 0;
}