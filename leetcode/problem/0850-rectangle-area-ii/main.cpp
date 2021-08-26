#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;

class Solution {
    struct rectangle {
        int x1, y1, x2, y2;
        rectangle(vector<int>& data): x1(data[0]), y1(data[1]), x2(data[2]), y2(data[3]) {}
    };
    struct area {
        int x;
        int length;
    };
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int mod = 1000000007;
        long long ans = 0;
        
        map<int, int> areas = {{0, 0}};
        for (auto&v:rectangles) {
            struct rectangle r(v);
            
            bool flag = true;
            for (auto it = areas.begin(); it != areas.end(); ++it) {
                if (it->first >= r.x2)
                    flag = false;
            }
            
            // new area
            if (flag) {
                int curSize = areas.rbegin()->first + areas.rbegin()->second;
                if (r.x2 > curSize) {
                    ans += ((long long)(r.x2-curSize)*(long long)r.y2) % mod;
                }
            }

            // for ()
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> rectangles;

    rectangles = {{0,0,2,2},{1,0,2,3},{1,0,3,1}};
    cout << sol.rectangleArea(rectangles) << endl;
    rectangles = {{0,0,1000000000,1000000000}};
    cout << sol.rectangleArea(rectangles) << endl;
    
    return 0;
}