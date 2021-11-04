#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

class Solution {

    struct charTracker {
        char c;
        int count;
    };

    void getTracker (string s, vector<struct charTracker>& tracker) {
        if (!s.empty()) {
            tracker.push_back({s[0], 1});
            for (size_t i = 1; i < s.size(); ++i) {
                if (s[i] == tracker.back().c) ++tracker.back().count;
                else tracker.push_back({s[i], 1});
            }
        }
    }

    bool cmp2Tracker (vector<struct charTracker>& target, vector<struct charTracker>& cmp2) {
        if (target.size() != cmp2.size()) return false;
        for (size_t i = 0; i < target.size(); ++i) {
            if (target[i].c != cmp2[i].c) return false;
            if (target[i].count == 2 && cmp2[i].count == 1) return false;
            if (target[i].count < cmp2[i].count) return false; 
        }
        return true;
    }

public:
    int expressiveWords(string s, vector<string>& words) {
        
        vector<struct charTracker> target;
        getTracker(s, target);

        int res = 0;
        for (auto&word:words) {
            vector<struct charTracker> cur;
            getTracker(word, cur);
            if (cmp2Tracker(target, cur)) ++res;
        }

        return res;
    
    }
};

int main() {
    Solution sol = Solution();
    vector<string> words;
    string str;

    str = "heeellooo", words = {"hello", "hi", "helo"};
    cout << sol.expressiveWords(str, words) << endl;
    str = "zzzzzyyyyy", words = {"zzyy","zy","zyy"};
    cout << sol.expressiveWords(str, words) << endl;

    return 0;
}