#include<iostream>
#include<vector>
#include<string> 

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int min, row;
        int size = matrix.size();
        vector<int> indexs(size, 0);
        queue<int>
        
        for (int i = 0; i < k; ++i) {
            min = 1000000000;
            for (int j = 0; j < size; ++j) {
                // cout << "j = " << j << ", indexs[j] = " << indexs[j] << endl;
                if (indexs[j] == size) continue;
                if (min > matrix[j][indexs[j]]) {
                    min = matrix[j][indexs[j]];
                    row = j;
                }
            }
            // cout << matrix[row][indexs[row]] << endl;
            ++indexs[row];
        }
        return min;
    }
};

int main () {
    Solution sol;
    vector<vector<int>> arr;
    int k;

    arr = {{1,5,9},{10,11,13},{12,13,15}};
    k = 8;
    cout << sol.kthSmallest(arr, k) << endl;

    arr = {{-100}};
    k = 1;
    cout << sol.kthSmallest(arr, k) << endl;

    return 0;
}