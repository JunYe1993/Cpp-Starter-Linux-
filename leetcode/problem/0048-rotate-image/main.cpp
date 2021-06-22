#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        size_t rotateTimes = matrix.size()/2;
        for (size_t i = 0; i < rotateTimes; ++i) {
            vector<int> temp{matrix[i].begin()+i, matrix[i].begin()+matrix.size()-i};
            size_t edgeLength = temp.size();
            for(size_t k = 0; k < edgeLength-1; ++k) { 
                matrix[i][k+i] = matrix[edgeLength-k-1+i][i]; // top
                matrix[edgeLength-k-1+i][i] = matrix[edgeLength-1+i][edgeLength-k-1+i]; // left
                matrix[edgeLength-1+i][edgeLength-k-1+i] = matrix[k+i][edgeLength-1+i]; // button
                matrix[k+i][edgeLength-1+i] = temp[k];
            }
        }
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> matrix;

    matrix = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    sol.rotate(matrix);
    for (auto&row:matrix) {
        for(auto&n:row)
            cout << n << " ";
        cout << endl;
    }

    matrix = {
        {5,1,9,11},
        {2,4,8,10},
        {13,3,6,7},
        {15,14,12,16}
    };
    sol.rotate(matrix);
    for (auto&row:matrix) {
        for(auto&n:row)
            cout << n << " ";
        cout << endl;
    }

    matrix = {{1}};
    sol.rotate(matrix);
    for (auto&row:matrix) {
        for(auto&n:row)
            cout << n << " ";
        cout << endl;
    }

    matrix = {
        {1,2},
        {3,4}
    };
    sol.rotate(matrix);
    for (auto&row:matrix) {
        for(auto&n:row)
            cout << n << " ";
        cout << endl;
    }

    return 0;
}