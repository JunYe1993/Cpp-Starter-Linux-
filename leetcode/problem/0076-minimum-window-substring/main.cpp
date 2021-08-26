#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        
        // init
        unordered_map<char, int> Tmap;
        for (auto&c:t) {
            if (Tmap.find(c) == Tmap.end()) Tmap[c] = 1;
            else ++Tmap[c];
        }

        // try fisrt window start from 0
        int endIndex = 0;
        int charCount = Tmap.size();
        for (auto&c:s) {
            ++endIndex;
            if (Tmap.find(c) != Tmap.end()) {
                --Tmap[c];
                if (Tmap[c] == 0) --charCount;
                if (charCount == 0) break;
            }
        }
        
        // there's no window
        if (charCount > 0) return "";
        
        int startIndex = 0;
        for (; startIndex < endIndex; ++startIndex) {
            if (Tmap.find(s[startIndex]) != Tmap.end()) {
                ++Tmap[s[startIndex]];
                if (Tmap[s[startIndex]] > 0) break;
            }
        }

        vector<string> strs = {s.substr(startIndex, endIndex-startIndex)};
        int minIndex = 0;
        while (endIndex < (int)s.size()) {
            // cout << "startIndex : " << startIndex << ", " << s[startIndex] << endl;
            // cout << "endIndex   : " << endIndex   << ", " << s[endIndex]   << endl;
            // cout << endl;
            
            if (Tmap.find(s[endIndex]) != Tmap.end())
                --Tmap[s[endIndex]];
            
            if (s[endIndex] == s[startIndex]) {
                ++startIndex;
                for (; startIndex < endIndex; ++startIndex) {
                    if (Tmap.find(s[startIndex]) != Tmap.end()) {
                        ++Tmap[s[startIndex]];
                        if (Tmap[s[startIndex]] > 0) break;
                    }
                }
                strs.push_back(s.substr(startIndex, endIndex-startIndex+1));
                minIndex = (strs[minIndex].size() < strs.back().size()) ? minIndex:(int)strs.size()-1;
            }
            ++endIndex;
        }
        //for (auto&s:strs) 
        //    cout << s << endl;
        //cout << endl;

        return strs[minIndex];
    }
};

int main() {
    Solution sol;
    string s, t;

    // s = "ADOBECODEBANC";
    // t = "ABC";
    // cout << sol.minWindow(s, t) << endl;
    // s = "a";
    // t = "a";
    // cout << sol.minWindow(s, t) << endl;
    // s = "a";
    // t = "aa";
    // cout << sol.minWindow(s, t) << endl;
    s = "cabwefgewcwaefgcf";
    t = "cae";
    cout << sol.minWindow(s, t) << endl;
    
    return 0;
}