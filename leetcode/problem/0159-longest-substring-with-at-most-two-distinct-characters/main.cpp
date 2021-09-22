#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <climits>

using namespace std;

class Solution {
    char getMinChar (unordered_map<char, int>& chars) {
        unordered_map<char, int>::iterator ret;
        int minIndex = INT_MAX;
        for (auto it = chars.begin(); it != chars.end(); ++it) {
            if ((*it).second < minIndex) {
                minIndex = (*it).second;
                ret = it;
            }
        }
        return (*ret).first;
    }

public:
    int lengthOfLongestSubstringTwoDistinct (string s) {
        
        unordered_map<char, int> chars;
        
        int longest = 0;
        int curLength = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (chars.find(s[i]) == chars.end()) {
                if (chars.size() < 2) {
                    chars[s[i]] = i;
                    ++curLength;
                } else {
                    char to_delete_char = getMinChar(chars);
                    longest = max(longest, curLength);
                    curLength = i - chars[to_delete_char];
                    chars.erase(to_delete_char);
                    chars[s[i]] = i;
                }
            } else {
                chars[s[i]] = i;
                ++curLength;
            }
        }
        longest = max(longest, curLength);
        return longest;
    }
};

int main() {
    Solution sol;
    string str;

    str = "eceba";
    cout << sol.lengthOfLongestSubstringTwoDistinct(str) << endl;
    str = "ccaabbb";
    cout << sol.lengthOfLongestSubstringTwoDistinct(str) << endl;

    return 0;
}