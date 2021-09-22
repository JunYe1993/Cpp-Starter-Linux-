#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution {

public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        
        // init map
        vector<vector<int>> map(n, vector<int>(n, 1));
        for (auto&v:mines) map[v[0]][v[1]] = 0;

        vector<vector<int>> top, lef, bot, rig;
        top = lef = bot = rig = map;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int r_i = n-i-1;
                int r_j = n-j-1;
                if (i > 0 && map[i][j] == 1) top[i][j] += top[i-1][j];
                if (j > 0 && map[i][j] == 1) lef[i][j] += lef[i][j-1];
                if (r_i < n-1 && map[r_i][r_j] == 1) bot[r_i][r_j] += bot[r_i+1][r_j];
                if (r_j < n-1 && map[r_i][r_j] == 1) rig[r_i][r_j] += rig[r_i][r_j+1];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < n; ++j) {
                ans = max(ans, min(min(lef[i][j], rig[i][j]), min(top[i][j], bot[i][j])));
            }
                
        return ans;
    }
};

int main () {
    Solution sol;
    int n;
    vector<vector<int>> mines;
    
    n = 5, mines = {{4, 2}};
    cout << sol.orderOfLargestPlusSign(n, mines) << endl;
    n = 1, mines = {{0, 0}};
    cout << sol.orderOfLargestPlusSign(n, mines) << endl;
    n = 10, mines = {{0,1},{0,2},{0,6},{0,7},{0,8},{0,9},{1,1},{1,2},{1,5},{2,0},{2,1},{2,2},{2,3},{2,4},{2,7},{3,0},{3,3},{3,4},{3,8},{4,0},{4,2},{4,4},{4,5},{4,8},{4,9},{5,0},{5,3},{5,4},{5,5},{5,6},{5,8},{6,0},{6,4},{6,6},{6,7},{6,8},{6,9},{7,1},{7,3},{7,6},{8,1},{8,2},{8,5},{8,6},{8,8},{9,0},{9,1},{9,6},{9,7},{9,8},{9,9}};
    cout << sol.orderOfLargestPlusSign(n, mines) << endl;
    n = 5, mines = {{0,0},{0,3},{1,1},{1,4},{2,3},{3,0},{4,2}};
    cout << sol.orderOfLargestPlusSign(n, mines) << endl;


    return 0;
}