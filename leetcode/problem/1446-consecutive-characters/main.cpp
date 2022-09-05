#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPower (string s) {
        
        if (s.empty()) return 0;
        int size = s.size();
        int count = 1, ret = 0;

        for (int i = 1; i < size; ++i) {
            if (s[i-1] == s[i]) 
                ++count;
            else {
                ret = max(count, ret);
                count = 1;
            } 
        }
        ret = max(count, ret);
        return ret;
    }
};

int main() {
    Solution sol;
    string s;

    s = "leetcode";
    cout << sol.maxPower(s) << endl;
    s = "abbcccddddeeeeedcba";
    cout << sol.maxPower(s) << endl;
    s = "triplepillooooow";
    cout << sol.maxPower(s) << endl;
    s = "hooraaaaaaaaaaay";
    cout << sol.maxPower(s) << endl;
    s = "tourist";
    cout << sol.maxPower(s) << endl;

    return 0;
}