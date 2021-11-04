#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:

    int maxDistToClosest (vector<int>& seats) {
        
        int size = seats.size();
        int longest0 = 0;
        int start = 0, end = 0;

        for (int i = 0; i < size; ++i) {
            if (seats[i] == 0) end = i+1;
            else {
                // cout << "start : " << start << endl;
                // cout << "end : " << end << endl;
                if (start < end) {
                    int cur = (start == 0) ? end:(end-start+1)/2;
                    // cout << "cur : " << cur << endl;
                    longest0 = max (longest0, cur);
                }
                start = end = i+1;
            }
        }
        
        if (seats[size-1] == 0) 
            longest0 = max (longest0, size - start);
        
        return longest0;
    }
};

int main() {
    
    Solution sol;
    vector<int> seats;

    seats = {1,0,0,0,1,0,1};
    cout << sol.maxDistToClosest(seats) << endl;
    seats = {1,0,0,0};
    cout << sol.maxDistToClosest(seats) << endl;
    seats = {0,1};
    cout << sol.maxDistToClosest(seats) << endl;

    return 0;
}