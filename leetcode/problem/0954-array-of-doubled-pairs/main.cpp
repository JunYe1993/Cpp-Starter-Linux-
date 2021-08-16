#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        auto rest = arr.size();
        queue<int> q;
        
        for (auto&n:arr) {
            if (q.empty()) q.push(n);
            else {
                int value = q.front();
                if (value < 0 && n*2 == value) q.pop();
                else if (value >= 0 && value*2 == n) q.pop();
                else q.push(n);
            }
            --rest;
            if (q.size()>rest) return false;
        }

        return q.empty();
    }
};

int main() {
    Solution sol;
    vector<int> arr;

    arr = {3,1,3,6};
    cout << sol.canReorderDoubled(arr) << endl;
    arr = {2,1,2,6};
    cout << sol.canReorderDoubled(arr) << endl;
    arr = {4,-2,2,-4};
    cout << sol.canReorderDoubled(arr) << endl;
    arr = {1,2,4,16,8,4};
    cout << sol.canReorderDoubled(arr) << endl;
    
    return 0;
}