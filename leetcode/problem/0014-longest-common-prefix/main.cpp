#include<iostream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0, continueFlag = true;
        string s;
        while (continueFlag) {
            char c = '@';
            for (auto&s:strs) {
                if (index < (int)s.size()) {
                    if (c == '@')
                        c = s[index];
                    else if (c != s[index]) {
                        continueFlag = false;
                        break;
                    }  
                } else {
                    continueFlag = false;
                    break;
                }
            }
            if (continueFlag) {
                s += c;
                ++index;
            }
        }
        return s;
    }
};

int main() {
    Solution sol = Solution();
    vector<string> strs;
    
    strs = {"flower","flow","flight"};
    cout << sol.longestCommonPrefix(strs) << endl;
    strs = {"dog","racecar","car"};
    cout << sol.longestCommonPrefix(strs) << endl;

    return 0;
}