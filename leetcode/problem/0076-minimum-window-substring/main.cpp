#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {

    unordered_map<char, int> Tmap;
    size_t unfinish_chars;
    vector<string> windows;
    queue<pair<int, char>> state;

    bool isValidWindow_by_push (char c) {
        if (--Tmap[c] == 0)
            if (--unfinish_chars == 0)
                return true;
        return false;
    }

    bool isValidWindow_by_pop (char c) {
        if (++Tmap[c] == 1)
            if (++unfinish_chars == 1)
                return false;
        return true;
    }

    void pop2minWindow (string& s, size_t curIndex) {
        // printf("curIndex : %2d\n", (int)curIndex);
        while (state.size()) {
            if (isValidWindow_by_pop(state.front().second)) 
                state.pop();
            else {
                --Tmap[state.front().second];
                unfinish_chars = 0;
                windows.push_back(s.substr(state.front().first, curIndex-state.front().first+1));
                break;
            }
        }
    }

public:

    string minWindow (string s, string t) {

        // init
        Tmap.clear();
        windows.clear();
        queue<pair<int, char>>().swap(state);
        
        for (auto&c:t) ++Tmap[c];

        bool valid_window_state = false;
        unfinish_chars = Tmap.size();
        for (size_t i = 0; i < s.size(); ++i) {
            if (Tmap.find(s[i]) != Tmap.end()) {        
                state.push({i, s[i]});
        
                // for first window
                if (!valid_window_state) {
                    if (isValidWindow_by_push(s[i])) {
                        valid_window_state = true;
                        pop2minWindow(s, i);
                    }
                
                // find others window by base on first window
                } else {
                    --Tmap[s[i]];
                    if (s[i] == state.front().second)
                        pop2minWindow(s, i);
                }
            }
        }

        size_t index;
        size_t min_size = 1000000;
        for (size_t i = 0; i < windows.size(); ++i) {
            // cout << windows[i] << endl;
            if (min_size > windows[i].size()) {
                min_size = windows[i].size();
                index = i;
            }
        }
        // cout << endl;
        
        return (valid_window_state) ? windows[index]:"";
    }

    string minWindowQ (string s, string t) {
        
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

    s = "ADOBECODEBANC";
    t = "ABC";
    cout << sol.minWindow(s, t) << endl;
    s = "a";
    t = "a";
    cout << sol.minWindow(s, t) << endl;
    s = "a";
    t = "aa";
    cout << sol.minWindow(s, t) << endl;
    s = "cabwefgewcwaefgcf";
    t = "cae";
    cout << sol.minWindow(s, t) << endl;
    s = "bba";
    t = "ba";
    cout << sol.minWindow(s, t) << endl;
    
    return 0;
}