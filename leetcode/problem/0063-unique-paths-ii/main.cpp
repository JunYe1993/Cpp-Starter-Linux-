#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
    int DFS (vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid, int x, int y) {
        // printf ("x = %d, y = %d\n", x, y);
        if (obstacleGrid[x][y] == 1) return 0;
        if (dp[x][y] >= 0) return dp[x][y];
        dp[x][y] = 0;
        if (x > 0) dp[x][y] += DFS (dp, obstacleGrid, x-1, y);
        if (y > 0) dp[x][y] += DFS (dp, obstacleGrid, x, y-1);
        return dp[x][y];
    }

public:
    int uniquePathsWithObstacles (vector<vector<int>>& obstacleGrid) {
        int x = obstacleGrid.size();
        int y = obstacleGrid[0].size();
        vector<vector<int>> dp(x, vector<int>(y, -1));
        dp[0][0] = 1;
        return DFS (dp, obstacleGrid, x-1, y-1);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> obstacleGrid;

    obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl;
    obstacleGrid = {{0,1},{0,0}};
    cout << sol.uniquePathsWithObstacles(obstacleGrid) << endl;
    
    return 0;
}