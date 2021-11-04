#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {

    int m, n;
    vector<pair<int, int>> dir = {
        { 0, 1},
        { 0,-1},
        { 1, 0},
        {-1, 0}
    };

    bool isValid (vector<vector<int>>& grid, int x, int y) {
        return (
            x >= 0 &&
            y >= 0 &&
            x < m &&
            y < n
        );
    }

    int encodeSetFunc (int i, int j) {
        return i*100 + j;
    }
    pair<int, int> decodeSetFunc (int x) {
        return {x/100, x%100};
    }

    void BFS (vector<vector<int>>& grid, int x, int y, 
            unordered_set<int>& buildings, vector<pair<int, int>>& locations) {
        
        grid[x][y] = 2;
        locations.push_back({x, y});
        for (auto&d:dir) {
            int next_x = x + d.first;
            int next_y = y + d.second;
            if (isValid(grid, next_x, next_y)) {
                if (grid[next_x][next_y] == 0) BFS(grid, next_x, next_y, buildings, locations);
                else if (grid[next_x][next_y] == 1) buildings.erase(encodeSetFunc(next_x, next_y));
                else if (grid[next_x][next_y] == 2) continue;
            }
        }
    }

public:

    int shortestDistance (vector<vector<int>>& grid) {
        
        m = grid.size();
        n = grid.back().size();

        unordered_set<int> buildings;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1)
                    buildings.insert(encodeSetFunc(i, j));

        vector<pair<int, int>> locations;
        for (auto&d:dir) {
            pair<int, int> build = decodeSetFunc(*(buildings.begin()));
            int x = build.first  + d.first;
            int y = build.second + d.second;
            if (isValid(grid, x, y) && grid[x][y] == 0) {
                vector<vector<int>> temp_g = grid;
                unordered_set<int>  temp_b = buildings;
                vector<pair<int, int>> temp_l;
                BFS (temp_g, x, y, temp_b, temp_l);
                if (temp_b.empty()) {
                    locations = temp_l;
                    break;
                }
            }
        }

        if (locations.empty()) return -1;
        
        int res = INT_MAX;
        for (auto&l:locations) {
            int cur = 0;
            for (auto&build:buildings) {
                pair<int, int> b = decodeSetFunc(build);
                cur += abs (l.first - b.first);
                cur += abs (l.second - b.second);
            }
            res = min (res, cur);
            printf("(%2d,%2d) : %3d\n", l.first, l.second, cur);
        }
        cout << buildings.size() << endl;
        return res;
    }
};

int main() {

    Solution sol = Solution();
    vector<vector<int>> grid;
    
    // grid = {{1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0}};
    // cout << sol.shortestDistance(grid) << endl;
    // grid = {{1,0}};
    // cout << sol.shortestDistance(grid) << endl;
    // grid = {{1}};
    // cout << sol.shortestDistance(grid) << endl;
    grid = {
        {1,1,1,1,1,0},
        {0,0,0,0,0,1},
        {0,1,1,0,0,1},
        {1,0,0,1,0,1},
        {1,0,1,0,0,1},
        {1,0,0,0,0,1},
        {0,1,1,1,1,0}
    };
    cout << sol.shortestDistance(grid) << endl;

    return 0;
}