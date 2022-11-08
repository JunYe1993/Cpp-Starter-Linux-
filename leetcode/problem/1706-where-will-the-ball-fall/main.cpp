#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    int size, high;
    int next (vector<vector<int>>& grid, int i, int j) {
        if (grid[i][j] == 1) {
            ++j;
            // cout << "j         : " << j << endl;
            // cout << "next grid : " << grid[i][j] << endl;
            // cout << "size      : " << size << endl;
            if (j < size && grid[i][j] == 1)
                return j;
            else
                return -1;
        } else {
            --j;
            if (j >= 0 && grid[i][j] == -1)
                return j;
            else
                return -1;
        }
    }

public:
    vector<int> findBall(vector<vector<int>>& grid) {

        size = (int)grid[0].size();
        high = (int)grid.size();

        int maxPosi = 0;
        vector<int> ret(size, -1);

        for (int i = 0; i < size; ++i) {
            if (maxPosi == size-1)
                break;
            int curHigh = 0;
            int curPosi = i;
            //cout << "Ball " << i << endl;
            while (curHigh < high) {
                //cout << "cur Posi : " << curPosi << endl;
                //cout << "cur High : " << curHigh << endl << endl;
                curPosi = next(grid, curHigh, curPosi);
                ++curHigh;
                if (curPosi >= 0) {
                    maxPosi = max(maxPosi, curPosi);
                    if (curHigh == high) {
                        ret[i] = curPosi;
                        break;
                    }
                } else
                  break;
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