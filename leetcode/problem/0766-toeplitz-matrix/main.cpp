#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    int rows, cols;
    bool isValid(int i, int j) {
        return (i >= 0 && j >= 0 && i < rows && j < cols);
    }

public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {

        rows = matrix.size();
        cols = matrix[0].size();

        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (isValid(i-1, j-1))
                    if (matrix[i][j] != matrix[i-1][j-1])
                        return false;
            }
        }
        return true;
    }
};


int main () {
    Solution sol;
    vector<vector<int>> m;

    m = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    cout << sol.isToeplitzMatrix(m) << endl;
    return 0;
}