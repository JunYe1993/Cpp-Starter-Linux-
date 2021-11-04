#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert (vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        bool isOverlap, isAdded = false;
        vector<vector<int>> res;
        auto it = intervals.begin();
        for (; it != intervals.end(); ++it) {
            isOverlap = (*it)[0] <= newInterval[1] && (*it)[1] >= newInterval[0];
            // printf("Current intervals : %2d, %2d\n", (*it)[0], (*it)[1]);
            // printf("  New   intervals : %2d, %2d\n", newInterval[0], newInterval[1]);
            // printf("is overlap : %s\n", (isOverlap) ? "True":"False");
            if (isOverlap) {
                newInterval[0] = min ((*it)[0], newInterval[0]);
                newInterval[1] = max ((*it)[1], newInterval[1]);
            } else {
                if ((*it)[0] > newInterval[1]) {
                    res.push_back(newInterval);
                    isAdded = true;
                    break;
                } else
                    res.push_back(*it);
            }
        }
        if (!isAdded) res.push_back(newInterval);
        res.insert(res.end(), it, intervals.end());
        return res;
    }

    // vector.erase() TLE
    vector<vector<int>> insertQ (vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        bool isOverlap;
        for (auto it = intervals.begin(); it != intervals.end();) {
            isOverlap = (*it)[0] <= newInterval[1] && (*it)[1] >= newInterval[0];
            
            // printf("Current intervals : %2d, %2d\n", (*it)[0], (*it)[1]);
            // printf("  New   intervals : %2d, %2d\n", newInterval[0], newInterval[1]);
            // printf("is overlap : %s\n", (isOverlap) ? "True":"False");
            
            if (isOverlap) {
                newInterval[0] = min ((*it)[0], newInterval[0]);
                newInterval[1] = max ((*it)[1], newInterval[1]);
                intervals.erase(it);
            } else {
                if (newInterval[0] > (*it)[1]) ++it;
                else {
                    intervals.insert(it, newInterval);
                    return intervals;
                }
            }
        }
        intervals.push_back(newInterval);
        return intervals;
    }
};

int main() {
    Solution sol;
    vector<int> newInterval;
    vector<vector<int>> intervals;

    intervals = {{1,3},{6,9}};
    newInterval = {2,5};
    for (auto&v:sol.insert(intervals, newInterval)) {
        cout << v[0] << " ";
        cout << v[1] << " ";
    }
    cout << endl;
    intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    newInterval = {4,8};
    for (auto&v:sol.insert(intervals, newInterval)) {
        cout << v[0] << " ";
        cout << v[1] << " ";
    }
    cout << endl;
    intervals = {};
    newInterval = {4,8};
    for (auto&v:sol.insert(intervals, newInterval)) {
        cout << v[0] << " ";
        cout << v[1] << " ";
    }
    cout << endl;
    intervals = {{3,10}};
    newInterval = {4,8};
    for (auto&v:sol.insert(intervals, newInterval)) {
        cout << v[0] << " ";
        cout << v[1] << " ";
    }
    cout << endl;
    
    return 0;
}