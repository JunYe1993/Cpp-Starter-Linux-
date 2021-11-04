#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    int m, n;
    vector<pair<int, int>> dir = {
        { 1, 0},
        {-1, 0},
        { 0, 1},
        { 0,-1}
    };

    void init (vector<vector<int>>& grid, int& x, int& y, int& count) {
        count = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                } else if (grid[i][j] == 0)
                    ++count;
    }

    int DFS (vector<vector<int>>& grid, int x, int y, int count) {
        
        if (grid[x][y] == 2) return ((count == 0) ? 1 : 0);
        if (count == 0) return 0;
            
        grid[x][y] = 1;
        int res = 0;
        for (auto&d:dir)
            if (isValid(grid, x+d.first, y+d.second))
                res += DFS (grid, x+d.first, y+d.second, count-1);
        
        grid[x][y] = 0;
        return res;
    }

    bool isValid (vector<vector<int>>& grid, int x, int y) {
        return (x >= 0 && x < m && y >= 0 && y < n && (grid[x][y]==0||grid[x][y]==2));
    }

public:
    int uniquePathsIII (vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid[0].size();
        
        int x, y, count;
        init(grid, x, y, count);
        return DFS (grid, x, y, count+1);
    }
};

int main () {

    Solution sol;
    vector<vector<int>> grid;

    grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
    cout << sol.uniquePathsIII(grid) << endl;
    grid = {{1,0,0,0},{0,0,0,0},{0,0,0, 2}};
    cout << sol.uniquePathsIII(grid) << endl;
    grid = {{0,1},{2,0}};
    cout << sol.uniquePathsIII(grid) << endl;

    return 0;
}