#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    void swap(vector<int>::iterator a, vector<int>::iterator b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void moveZeroes(vector<int>& nums) {
        size_t zeroNum = 0;
        for (size_t i = 0; i < nums.size()-zeroNum; ++i) {
            cout << "i = " << i << endl;
            cout << "zeroNum = " << zeroNum << endl;
            if (zeroNum == 0 && nums[i] == 0) ++zeroNum;
            cout << "zeroNum = " << zeroNum << endl;
            if (zeroNum > 0) {
                while (i+zeroNum < nums.size() && nums[i+zeroNum] == 0) {
                    ++zeroNum;
                }
                cout << "zeroNum = " << zeroNum << endl;
                if (i+zeroNum != nums.size()) 
                    swap (nums.begin()+i, nums.begin()+i+zeroNum);
            }
            cout << "zeroNum = " << zeroNum << endl;
            for(auto&n:nums)
                cout << n << " ";
            cout << endl;
            cout << "==============================" << endl;
        }
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums;

    nums = {0};
    sol.moveZeroes(nums);
    for(auto&n:nums)
        cout << n << " ";
    cout << endl;

    return 0;
}