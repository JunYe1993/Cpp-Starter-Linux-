#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Solution {
    vector<vector<int>> mem;
    int getThrough (int left, int right, string& s) {
        if (left == right) return 1;
        if (left >  right) return 0;
        if (mem[left][right]) return mem[left][right];
        return mem[left][right] = s[left] == s[right] ? 2+getThrough(left+1, right-1, s):
            max(getThrough(left+1, right, s), getThrough(left, right-1, s));
    }

public:
    int longestPalindromeSubseq (string s) {
        mem = vector<vector<int>>(s.size(),vector<int>(s.size(), 0));
        return getThrough (0, (int)s.size()-1, s);
    }
};

int main() {

    Solution sol;
    string str;
    
    str = "bbbab";
    cout << sol.longestPalindromeSubseq (str) << endl;
    str = "cbbd";
    cout << sol.longestPalindromeSubseq (str) << endl;

    return 0;
}