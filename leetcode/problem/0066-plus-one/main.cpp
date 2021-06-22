#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        reverse(digits.begin(), digits.end());
        for (auto&n:digits) {
            if (carry) 
                ++n;
            if (n == 10) {
                n = 0;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        if (carry) digits.push_back(1);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums;

    // Test
    nums = {1, 2, 3};
    for (int& n : sol.plusOne(nums))
        cout << n << " ";
    cout << endl;

    nums = {9};
    for (int& n : sol.plusOne(nums))
        cout << n << " ";
    cout << endl;

    nums = {0};
    for (int& n : sol.plusOne(nums))
        cout << n << " ";
    cout << endl;

    return 0;
}