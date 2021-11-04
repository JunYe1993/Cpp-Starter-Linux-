#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
    int DFS (vector<vector<int>>& dp, int m, int n) {
        if (m == 0 || n == 0) return 1;
        if (dp[m][n] > 0) return dp[m][n];
        dp[m][n] = DFS(dp, m-1, n) + DFS(dp, m, n-1);
        return dp[m][n];
    }

public:
    int uniquePaths (int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return DFS(dp, m-1, n-1);
    }
};  

int main() {
    Solution sol;
    int m, n;

    m = 3;
    n = 7;
    cout << sol.uniquePaths(m, n) << endl;
    m = 3;
    n = 2;
    cout << sol.uniquePaths(m, n) << endl;
    m = 7;
    n = 3;
    cout << sol.uniquePaths(m, n) << endl;
    m = 3;
    n = 3;
    cout << sol.uniquePaths(m, n) << endl;
    m = 19;
    n = 13;
    cout << sol.uniquePaths(m, n) << endl;
    
    
    return 0;
}