#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge (vector<vector<int>>& intervals) {
        
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[0]<b[0];});
        
        int bound = -1;
        for (auto&v:intervals) {
            if (v[0] > bound) {
                res.push_back(v);
                bound = v[1];
            } else {
                res.back()[1] = max(res.back()[1], v[1]);
                bound = res.back()[1];
            }
        }
        
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals;

    intervals = {{1,3},{2,6},{8,10},{15,18}};
    for (auto&v:sol.merge(intervals))
        cout << v[0] << " " << v[1] << " ";
    cout << endl;

    intervals = {{1,4},{4,5}};
    for (auto&v:sol.merge(intervals))
        cout << v[0] << " " << v[1] << " ";
    cout << endl;
    
    return 0;
}