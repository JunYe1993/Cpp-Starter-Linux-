#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMeetingRooms (vector<vector<int>>& intervals) {
        
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), 
            [](vector<int>& a, vector<int>& b){return a[0] < b[0];});

        
        bool isOverlap = true;
        int count = 0;
        for (; isOverlap; ++count) {
            // for (auto&v:intervals)
            //     cout << v[0] << " " << v[1] << " ";
            // cout << endl;
            vector<vector<int>> next;
            int size = intervals.size();
            int bound = intervals[0][1];
            for (int i = 1; i < size; ++i) {
                if (bound > intervals[i][0])
                    next.push_back({intervals[i][0], min(bound, intervals[i][1])});
                bound = max(bound, intervals[i][1]);
            }
            intervals = next;
            isOverlap = !intervals.empty();
        }

        return count;
    }
};

int main() {

    Solution sol;
    vector<vector<int>> intervals;
    
    intervals = {{0,30},{5,10},{15,20}};
    cout << sol.minMeetingRooms(intervals) << endl;
    intervals = {{7,10},{2,4}};
    cout << sol.minMeetingRooms(intervals) << endl;
    intervals = {{4,18},{1,35},{12,45},{25,46},{22,27}};
    cout << sol.minMeetingRooms(intervals) << endl;

    return 0;
}