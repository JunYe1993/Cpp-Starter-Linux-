#include<iostream>
#include<map>
#include<set>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringQ(string s) {
        
        map<char, int> subString;
        auto window = subString.size();
        int startIndex = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (subString.find(s[i])==subString.end()) {
                subString[s[i]] = i;
                window = max(subString.size(), window);
            } else {
                for (;startIndex <= subString[s[i]]; ++startIndex)
                    subString.erase(s[startIndex]);
                subString[s[i]] = i;
            }
        }

        return (int)window;
    }

    int lengthOfLongestSubstring(string s) {
        
        string temp = "";
        auto window = temp.size();

        for (auto&c:s) {
            auto index = temp.find(c);
            if (index != string::npos) {
                window = max(temp.size(), window);
                temp = temp.substr(index+1, temp.size()-index-1);
            }
            temp = temp + c;
        }
        
        return (int)max(temp.size(), window);
    }
};

int main() {
    Solution sol = Solution();
    string str;
    
    // str = "abcabcbb";
    // cout << sol.lengthOfLongestSubstring(str) << endl;
    // str = "bbbbb";
    // cout << sol.lengthOfLongestSubstring(str) << endl;
    // str = "pwwkew";
    // cout << sol.lengthOfLongestSubstring(str) << endl;
    // str = "";
    // cout << sol.lengthOfLongestSubstring(str) << endl;
    str = " ";
    cout << sol.lengthOfLongestSubstring(str) << endl;
    
    return 0;
}