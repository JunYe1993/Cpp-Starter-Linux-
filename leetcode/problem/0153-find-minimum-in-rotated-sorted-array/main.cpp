#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int maxIndex = nums.size()-1;
        int minIndex = 0;
        while (minIndex+1 < maxIndex) {
            // int midIndex = (maxIndex+minIndex)/2;
            // printf("max = %2d, min = %2d, mid = %2d\n", maxIndex, minIndex, midIndex);
            if (nums[maxIndex] > nums[minIndex]) return nums[minIndex];
            else {
                int midIndex = (maxIndex+minIndex)/2;
                if (nums[midIndex] < nums[maxIndex]) maxIndex = midIndex;
                else minIndex = midIndex;
            }
        }
        return min(nums[maxIndex], nums[minIndex]);
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    nums = {3,4,5,1,2};
    cout << sol.findMin(nums) << endl;
    nums = {4,5,6,7,0,1,2};
    cout << sol.findMin(nums) << endl;
    nums = {11,13,15,17};
    cout << sol.findMin(nums) << endl;

    return 0;
}