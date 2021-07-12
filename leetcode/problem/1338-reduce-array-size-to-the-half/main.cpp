#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {

        map<int, int> nums;
        vector<int> sums;
        int size = arr.size();

        for (auto&n:arr) {
            if (nums.find(n)==nums.end()) nums[n] = 1;
            else ++nums[n];
        }
        for (auto&m:nums)
            sums.push_back(m.second);
        sort(sums.begin(), sums.end());

        int count = size;
        for (int i = (int)sums.size()-1; i >= 0; --i) {
            count -= sums[i];
            if (count <= size/2) return (int)sums.size()-i;
        }

        return 0;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    arr = {3,3,3,3,5,5,5,2,2,7};
    cout << sol.minSetSize(arr) << endl;

    arr = {7,7,7,7,7,7};
    cout << sol.minSetSize(arr) << endl;

    arr = {1,9};
    cout << sol.minSetSize(arr) << endl;

    arr = {1000,1000,3,7};
    cout << sol.minSetSize(arr) << endl;

    arr = {1,2,3,4,5,6,7,8,9,10};
    cout << sol.minSetSize(arr) << endl;

    return 0;
}