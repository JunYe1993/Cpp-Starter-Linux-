#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {


public:
    vector<int> findBall(vector<vector<int>>& grid) {

        vector<int> ret;
        int high = (int)grid[0].size();
        int size = (int)grid.size();

        for (int i = 0; i < size; ++i) {
            int curHigh = 0;
            int curPosi = i;
            while (curHigh < high) {

            }
        }




        return ret;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid;

    grid = {{1,1,1,-1,-1},{1,1,1,-1,-1},{-1,-1,-1,1,1},{1,1,1,1,-1},{-1,-1,-1,-1,-1}};
    for (auto&n:sol.findBall(grid))
        cout << n << " ";
    cout << endl;

    grid = {{-1}};
    for (auto&n:sol.findBall(grid))
        cout << n << " ";
    cout << endl;

    grid = {{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1},{1,1,1,1,1,1},{-1,-1,-1,-1,-1,-1}};
    for (auto&n:sol.findBall(grid))
        cout << n << " ";
    cout << endl;

    return 0;
}