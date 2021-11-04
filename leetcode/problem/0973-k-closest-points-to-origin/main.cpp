#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest (vector<vector<int>>& points, int k) {
        
        vector<vector<int>> res, ref = points;
        
        int index = 0;
        for (auto&p:ref) {
            p[0] = p[0]*p[0] + p[1]*p[1];
            p[1] = index++;
        }

        sort (ref.begin(), ref.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });

        for (int i = 0; i < k; ++i)
            res.push_back(points[ref[i][1]]);

        return res;
    }
};

int main() {
    Solution sol;
    int k;
    vector<vector<int>> points;

    k = 1;
    points = {{1,3},{-2,2}};
    for (auto&v:sol.kClosest(points, k))
        cout << "{" << v[0] << ", " << v[1] << "} ";
    cout << endl;
    k = 2;
    points = {{3,3},{5,-1},{-2,4}};
    for (auto&v:sol.kClosest(points, k))
        cout << "{" << v[0] << ", " << v[1] << "} ";
    cout << endl;

    return 0;
}