#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class NumArray {
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        sums = {0};
        for (auto&n:nums) 
            sums.push_back(sums.back()+n);
    }
    
    int sumRange(int left, int right) {
        return sums[right+1]-sums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    cout << numArray.sumRange(2, 5) << endl;
    cout << numArray.sumRange(0, 5) << endl;
    return 0;
}