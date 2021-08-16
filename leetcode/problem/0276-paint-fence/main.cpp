#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution {
public:
    int numWays(int n, int k) {
        
        int num = (n >= 2) ? n : 2;
        vector<int> dp(num, 0);
        dp[0] = k;
        dp[1] = k*k;
        
        for (int i = 2; i < n; ++i)
            dp[i] = dp[i-1]*(k-1) + dp[i-2]*(k-1);

        return dp[n-1];
    }
};

int main() {
    Solution sol;
    int n, k;

    n = 3;
    k = 2;
    cout << sol.numWays(n, k) << endl;
    n = 1;
    k = 1;
    cout << sol.numWays(n, k) << endl;
    n = 7;
    k = 2;
    cout << sol.numWays(n, k) << endl;

    return 0;
}