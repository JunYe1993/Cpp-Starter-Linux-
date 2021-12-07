#include<iostream>
#include<vector>
#include<string> 

using namespace std;

class Solution {
    int m, n;
    vector<pair<int, int>> dir = {
        { 1, 0},
        {-1, 0},
        { 0, 1},
        { 0,-1}
    };

    int DFS (vector<vector<int>>& matrix, vector<vector<int>>& dp, int x, int y) {


        if (dp[x][y] > 0) return dp[x][y];

        dp[x][y] = 1;
        for (auto&d:dir) {
            int nextx = x + d.first;
            int nexty = y + d.second;
            if (isValid(matrix, nextx, nexty, matrix[x][y]))
                dp[x][y] = max (dp[x][y], 1 + DFS(matrix, dp, nextx, nexty));
        }
        
        return dp[x][y];
    }

    bool isValid (vector<vector<int>>& matrix, int x, int y, int pre) {
        return (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > pre);
    }

public:
    int longestIncreasingPath (vector<vector<int>>& matrix) {
        
        m = matrix.size();
        n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0)
                    res = max(res, DFS (matrix, dp, i, j));
            }
        }

        return res;
    }
};

int main () {
    Solution sol;
    vector<vector<int>> matrix;

    matrix = {{9,9,4},{6,6,8},{2,1,1}};
    cout << sol.longestIncreasingPath(matrix) << endl;
    matrix = {{3,4,5},{3,2,6},{2,2,1}};
    cout << sol.longestIncreasingPath(matrix) << endl;

    return 0;
}