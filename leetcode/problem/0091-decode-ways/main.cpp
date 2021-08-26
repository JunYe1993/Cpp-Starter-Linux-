#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    int size;
    vector<int> dp;

    bool isValid (string& s, int index, int length) {
        if (length == 1) 
            return (s[index] != '0');
        else {
            if (index == size-1) return false;
            else if (s[index] == '1') return true;
            else if (s[index] == '2') return (s[index+1] < '7');
            else return false;
        }
    } 
    
    int get (string& str, int index) {
        
        if (index == size) return 1;
        if (dp[index] > 0) return dp[index];

        int number = 0;
        if (isValid(str, index, 1))
            number += get(str, index+1);

        if (isValid(str, index, 2))
            number += get(str, index+2);

        dp[index] = number;
        return number;
    }
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        size = s.size();
        dp = vector<int>(size, -1);
        return get(s, 0);
    }
};

int main() {
    Solution sol;
    string str;

    str = "12";
    cout << sol.numDecodings(str) << endl;
    str = "226";
    cout << sol.numDecodings(str) << endl;
    str = "0";
    cout << sol.numDecodings(str) << endl;
    str = "06";
    cout << sol.numDecodings(str) << endl;

    return 0;
}