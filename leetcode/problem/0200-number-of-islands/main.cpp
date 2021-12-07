#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Solution {

    int m, n;
    vector<pair<int, int>> dir = {
        { 1, 0},
        {-1, 0},
        { 0, 1},
        { 0,-1}
    };

    void DFS (vector<vector<char>>& grid, int x, int y) {
        
        grid[x][y] = 'X';
        for (auto & d : dir) {
            int xx = x + d.first;
            int yy = y + d.second;
            if (isValid(grid, xx, yy)) DFS (grid, xx, yy);
        }

    }

    bool isValid (vector<vector<char>>& grid, int x, int y) {
        // printf("x = %2d, y = %2d\n", x, y);
        return (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1');
    }

    void show (vector<vector<char>>& grid) {
        for (auto&v:grid) {
            for (auto&c:v)
                cout << c << " ";
            cout << endl;
        }
        cout << endl;
    }

public:
    int numIslands (vector<vector<char>>& grid) {
        
        m = (int)grid.size();
        n = (int)grid[0].size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ++res;
                    DFS (grid, i, j);
                }
            }
        }

        return res;
    }
};

int main() { 
    Solution sol;
    vector<vector<char>> grid;

    grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout << sol.numIslands(grid) << endl;
    grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << sol.numIslands(grid) << endl;
    
    return 0; 
}