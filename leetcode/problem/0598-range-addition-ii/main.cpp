#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minX = m;
        int minY = n;
        for (auto&v:ops) {
            minX = min (minX, v[0]);
            minY = min (minY, v[1]);
        }
        return minX*minY;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> ops;
    int m, n;

    m = 3, n = 3;
    ops = {{2,2},{3,3}};
    cout << sol.maxCount(m, n, ops) << endl;
    m = 3, n = 3;
    ops = {{2,2},{3,3},{3,3},{3,3},{2,2},{3,3},{3,3},{3,3},{2,2},{3,3},{3,3},{3,3}};
    cout << sol.maxCount(m, n, ops) << endl;
    m = 3, n = 3;
    ops = {};
    cout << sol.maxCount(m, n, ops) << endl;

    return 0;
}