#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canAttendMeetings (vector<vector<int>>& intervals) {
        
        if (intervals.empty()) return true;
        sort(intervals.begin(), intervals.end(), 
            [](vector<int>& a, vector<int>& b){
                return a[0] < b[0];
            }
        );

        int size = intervals.size();
        int preBound = intervals[0][1];
        for (int i = 1; i < size; ++i)
            if (preBound > intervals[i][0]) return false;
            else preBound = intervals[i][1];

        return true;
    }
};

int main() {

    Solution sol;
    vector<vector<int>> intervals;

    intervals = {{0,30},{5,10},{15,20}};
    printf("%s\n", (sol.canAttendMeetings(intervals)?"True":"False"));
    intervals = {{7,10},{2,4}};
    printf("%s\n", (sol.canAttendMeetings(intervals)?"True":"False"));

    return 0;
}