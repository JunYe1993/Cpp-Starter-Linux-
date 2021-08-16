#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int mSize = matrix.size();
        int nSize = matrix[0].size();
        vector<bool> rowZero(mSize, false);
        for (int i = 0; i < mSize; ++i) {
            bool colZero = false;
            for (int j = 0; j < nSize; ++j) {
                if (matrix[i][j] == 0) {
                    colZero = true;
                    if (!rowZero[j]) {
                        int index = i;
                        while (index >= 0) 
                            matrix[index--][j] = 0;
                    }
                    rowZero[j] = true;
                } else {
                    if (rowZero[j])
                        matrix[i][j] = 0;
                }
            }
            if (colZero)
                matrix[i] = vector<int>(nSize, 0);
        }
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> matrix;

    matrix = {{1,1,1},{1,0,1},{1,1,1}};
    sol.setZeroes(matrix);
    for (auto&v:matrix) {
        for (auto&n:v)
            cout << n << " ";
        cout << endl;
    }
    matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    sol.setZeroes(matrix);
    for (auto&v:matrix) {
        for (auto&n:v)
            cout << n << " ";
        cout << endl;
    }

    return 0;
}