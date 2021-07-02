#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> dp(n, 0);
        dp[1] = 1; 
        dp[2] = 2;
        for(int i = 3; i < n; ++i)
            dp[i] = dp[i-1] + dp[i-2];
        return dp[n-1]+dp[n-2];
    }
};

int main() {
    Solution sol;
    int n;

    n = 3;
    cout << sol.climbStairs(n) << endl;

    n = 4;
    cout << sol.climbStairs(n) << endl;
    
    return 0;
}