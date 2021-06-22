#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle = {{1}};
        for (int i = 0; i < numRows-1; ++i) {
            int size = triangle[i].size();
            vector<int> temp;
            temp.push_back(1);
            for(int j = 1; j < size; ++j)
                temp.push_back(triangle[i][j]+triangle[i][j-1]);
            temp.push_back(1);
            triangle.push_back(temp);
        }
        return triangle;
    }
};

int main() {
    Solution sol = Solution();
    int nums;

    nums = 1;
    for (auto& v : sol.generate(nums)) {
        for (auto& n : v)
            cout << n << " ";
        cout << endl;
    }

    nums = 5;
    for (auto& v : sol.generate(nums)) {
        for (auto& n : v)
            cout << n << " ";
        cout << endl;
    }

    return 0;
}