#include <iostream>
#include <vector>
#include <string> 

using namespace std;

class Solution {
public:
    int findLength (vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
        int max = 0;
        for (size_t i = 0; i < nums1.size(); ++i) {
            for (size_t j = 0; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    ++dp[i][j];
                    if (i != 0 && j != 0) 
                        dp[i][j] += dp[i-1][j-1];
                }
                if (dp[i][j] > max) max = dp[i][j];
            }
        }
        for (auto&v:dp) {
            for (auto&n:v)
                cout << n << " ";
            cout << endl;
        }
        return max;
    }
};

int main () {
    Solution sol;
    vector<int> nums1, nums2;

    nums1 = {1, 2, 3, 2, 1};
    nums2 = {3, 2, 1, 4, 7};
    cout << sol.findLength(nums1, nums2) << endl;

    nums1 = {0, 1, 1, 1, 1};
    nums2 = {1, 0, 1, 0, 1};
    cout << sol.findLength(nums1, nums2) << endl;

    return 0;
}