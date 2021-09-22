#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
    vector<pair<int, int>> moving = {
        { 0,  1},
        { 1,  0},
        { 0, -1},
        {-1,  0}
    };
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int size = m * n;
        vector<int> ans;
        
        vector<int> dirCount = {n, m, n, m};
        int move = 0;
        int dir = 0;
        int row = 0;
        int col = -1;
        while (move < size) {
            for (int i = 0; i < dirCount[dir]; ++i) {
                row += moving[dir].first;
                col += moving[dir].second;
                ans.push_back(matrix[row][col]);
                ++move;
            }
            int nextdir = (dir+1) % 4;
            int predir  = (dir+3) % 4;
            --dirCount[predir];
            --dirCount[nextdir];
            dir = nextdir;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix;

    matrix = {{1,2,3},{4,5,6},{7,8,9}};
    for (auto&n:sol.spiralOrder(matrix))
        cout << n << " ";
    cout << endl;
    matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    for (auto&n:sol.spiralOrder(matrix))
        cout << n << " ";
    cout << endl;
    matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    for (auto&n:sol.spiralOrder(matrix))
        cout << n << " ";
    cout << endl;
    
    return 0;
}