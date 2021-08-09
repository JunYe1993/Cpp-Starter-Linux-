#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        return matrix;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix;

    matrix = {{1,2},{3,4}};
    for (auto&v:sol.matrixRankTransform(matrix)) {
        for (auto&n:v)
            cout << n << " ";
        cout << endl;
    }
    
    return 0;
}