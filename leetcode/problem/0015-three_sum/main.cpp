#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

class SortClass {
protected:
    void swap (vector<int>::iterator a, vector<int>::iterator b) {
        int temp = *a;
        // cout << "a: " << *a << ", b: " << *b << endl;
        *a = *b;
        *b = temp;
    }
    size_t partition (vector<int>& nums, size_t low, size_t high) {
        int pivot = *(nums.begin()+high);
        size_t partitionIndex = low;

        for (size_t i = low; i <= high; ++i) {
            if (*(nums.begin()+i) < pivot) {
                swap(nums.begin()+partitionIndex, nums.begin()+i);
                ++partitionIndex;
            }
        }
        swap(nums.begin()+high, nums.begin()+partitionIndex);
        return partitionIndex;
    }
    void quickSort (vector<int>& nums, size_t low, size_t high) {
        if (low < high && high ) {
            size_t mid = partition (nums, low, high);
            if (mid > 0) quickSort (nums, low, mid-1);
            quickSort (nums, mid+1, high);
        }
    }
public:
    void sort(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        if (nums.size() < 3) return answer;
        std::sort(nums.begin(), nums.end());

        for (size_t i = 0; i < nums.size()-2; ++i) 
        {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int target = nums[i]*(-1);
            size_t j = i + 1;
            size_t k = nums.size() - 1;
            while (j < k)
            {
                int subSum = nums[j]+nums[k];
                if (subSum == target) {
                    answer.push_back({nums[i], nums[j], nums[k]});
                    do ++j; while (j < nums.size() && nums[j] == nums[j-1]);
                } else if (subSum > target) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return answer;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums;
    
    // Test1
    cout << "Test1" << endl;
    nums = {-1, 0, 1, 2, -1, -4};
    sol.threeSum(nums);

    // Test1
    cout << "Test2" << endl;
    nums = {};
    sol.threeSum(nums);

    // Test1
    cout << "Test3" << endl;
    nums = {0, 0, 0, 0};
    sol.threeSum(nums);

    return 0;
}