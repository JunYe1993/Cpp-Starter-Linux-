#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int num = (int)nums.size() - (k%(int)nums.size());
        // cout << "k = " << num << endl;
        vector<int> temp(nums.begin()+num, nums.end());
        // for (auto&n:temp)
        //     cout << n << " ";
        // cout << endl;
        nums.resize(num);
        // for (auto&n:nums)
        //     cout << n << " ";
        // cout << endl;
        nums.insert(nums.begin(),temp.begin(),temp.end());
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {-1,-100,3,99};
    sol.rotate(nums, 2);
    for (auto&n:nums)
        cout << n << " ";
    cout << endl;
    
    nums = {1,2,3,4,5,6,7};
    sol.rotate(nums, 3);
    for (auto&n:nums)
        cout << n << " ";
    cout << endl;
    return 0;
}