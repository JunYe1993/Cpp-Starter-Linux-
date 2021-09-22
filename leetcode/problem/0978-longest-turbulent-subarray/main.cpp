#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <map>

using namespace std;

class Solution {

    int getComparisonSign (int a, int b) {
        if (a == b) return -1;
        else if (a > b) return 0;
        else if (a < b) return 1;
        return -1;
    }

public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        if (arr.size()==1) return 1;
        
        int maxSize = 0, curSize = 0;
        int preSign = -1;
        
        for (size_t i = 1; i < arr.size(); ++i) {
            // printf("Number : %2d\nBefore : %2d\n", arr[i], curSize);
            int curSign = getComparisonSign(arr[i-1], arr[i]);
            
            // 遇到等號 = 結算
            if (curSign < 0 || preSign < 0) {
                maxSize = max(maxSize, curSize);
                curSize = (curSign >= 0) ? 1:0;
            
            // 反方向 ++
            } else if (curSign ^ preSign) {
                ++curSize;

            // 同方向 = 結算
            } else {
                maxSize = max(maxSize, curSize);
                curSize = 1;
            }
            // printf("After  : %2d\n\n",curSize);
            preSign = curSign;
        }

        maxSize = max(maxSize, curSize);
        return maxSize+1;
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    arr = {9,4,2,10,7,8,8,1,9};
    cout << sol.maxTurbulenceSize(arr) << endl;
    arr = {4,8,12,16};
    cout << sol.maxTurbulenceSize(arr) << endl;
    arr = {100};
    cout << sol.maxTurbulenceSize(arr) << endl;
    arr = {9,9};
    cout << sol.maxTurbulenceSize(arr) << endl;
    arr = {0,1,1,0,1,0,1,1,0,0};
    cout << sol.maxTurbulenceSize(arr) << endl;


    return 0;
}