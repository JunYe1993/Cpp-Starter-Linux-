#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {

    int numTrees (vector<int>& dp, int nums) {
        
        // cout << "nums = " << nums << endl;
        if (dp[nums] > 0) return dp[nums];
        
        for (int i = 0; i < nums; ++i) {
            dp[nums] += numTrees(dp, nums-i-1) * numTrees(dp, i);
        }
        
        return dp[nums];
    }

public:
    int numTrees (int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        return numTrees(dp, n);
    }
};

int main() {
    Solution sol;
    cout << sol.numTrees(3) << endl;
    cout << sol.numTrees(1) << endl;
    return 0;
}