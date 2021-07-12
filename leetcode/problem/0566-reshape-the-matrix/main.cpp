#include<iostream>
#include<vector>
#include<string> 

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (mat.size() > 0) {
            if ((int)(mat.size()*mat[0].size()) != r*c)
                return mat;
        }
        vector<vector<int>> reShape = {{}};
        int rowIndex = 0;
        int colIndex = 0;
        
        for (auto&v:mat) {
            for (auto&n:v) {
                if (colIndex < c) {
                    reShape[rowIndex].push_back(n);
                    ++colIndex;
                } else {
                    reShape.push_back(vector<int>({n}));
                    colIndex = 1;
                    ++rowIndex;
                }
            }
        }
        return reShape;
    }
};

int main () {
    Solution sol;
    vector<vector<int>> mat;
    int r, c;

    mat = {{1,2},{3,4}};
    r = 1; c = 4;
    for (auto&v:sol.matrixReshape(mat, r, c)) {
        for (auto&n:v)
            cout << n << " ";
        cout << endl;
    }

    mat = {{1,2},{3,4}};
    r = 4; c = 1;
    for (auto&v:sol.matrixReshape(mat, r, c)) {
        for (auto&n:v)
            cout << n << " ";
        cout << endl;
    }

    return 0;
}