#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {

    int partition (vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int index = low;

        for (int i = low; i < high; ++i)
            if (nums[i] < pivot)
                swap(nums[i], nums[index++]);

        swap(nums[high], nums[index]);
        return index;
    }

    void quickSort (vector<int>& nums, int low, int high, int k) {
        if (low < high) {
            int mid = partition (nums, low, high);
            int check = (int)nums.size()-k-mid;
            if (check == 0) return;
            else if (check > 0) quickSort (nums, mid+1, high, k);
            else if (check < 0) quickSort (nums, low,  mid-1, k);
        }
    }

public:
    int findKthLargest (vector<int>& nums, int k) {
        int size = nums.size();
        quickSort(nums, 0, size-1, k);
        return nums[size-k];
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int k;

    nums = {3,2,1,5,6,4}, k = 2;
    cout << sol.findKthLargest(nums, k) << endl;
    nums = {3,2,3,1,2,4,5,5,6}, k = 4;
    cout << sol.findKthLargest(nums, k) << endl;

    return 0;
}