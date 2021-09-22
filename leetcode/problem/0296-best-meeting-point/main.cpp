#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

class Solution {

    int getDistance (vector<int>& arr, int target) {
        int ret = 0;
        for (auto&n:arr) 
            ret += abs(target-n);
        return ret;
    }

public:
    int minTotalDistance (vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid.back().size();
        vector<int> x;
        vector<int> y;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1) {
                    x.push_back(i);
                    y.push_back(j);
                }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        int total = 0;
        int xMedian = x.size()/2;
        int yMedian = y.size()/2;
        total += (x.size() % 2) ? getDistance(x, x[xMedian]):min(getDistance(x, x[xMedian]), getDistance(x, x[xMedian-1]));
        total += (y.size() % 2) ? getDistance(y, y[yMedian]):min(getDistance(y, y[yMedian]), getDistance(y, y[yMedian-1]));

        return total;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    grid = {{1,0,0,0,1},{0,0,0,0,0},{0,0,1,0,0}};
    cout << sol.minTotalDistance(grid) << endl;
    grid = {{1,1}};
    cout << sol.minTotalDistance(grid) << endl;

    return 0;
}