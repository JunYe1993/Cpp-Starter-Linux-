#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        
        char ret = 'a'-1;
        int maxDuration = 0;
        for (int i = releaseTimes.size()-1; i >= 0; --i) {
            int duration = (i == 0) ? releaseTimes[i]:releaseTimes[i]-releaseTimes[i-1];
            if (duration > maxDuration || (duration == maxDuration && keysPressed[i] > ret)) {
                maxDuration = duration;
                ret = keysPressed[i];
            }
        }

        // cout << maxDuration << endl;
        return ret;
    }
};

int main() {
    Solution sol;
    vector<int> releaseTimes;
    string keysPressed;

    releaseTimes = {9,29,49,50};
    keysPressed = "cbcd";
    cout << sol.slowestKey(releaseTimes, keysPressed) << endl;
    releaseTimes = {12,23,36,46,62};
    keysPressed = "spuda";
    cout << sol.slowestKey(releaseTimes, keysPressed) << endl;

    return 0;
}