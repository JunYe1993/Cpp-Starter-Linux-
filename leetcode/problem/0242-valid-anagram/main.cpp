#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> dict(26, 0);
        for(auto&c:s) ++dict[c-'a'];
        for(auto&c:t) {
            if (dict[c-'a'] == 0)
                return false;
            else
                --dict[c-'a'];
        }
        return true;
    }
};

int main() {
    Solution sol = Solution();
    string s, t;
    
    s = "anagram";
    t = "nagaram";
    cout << sol.isAnagram(s, t) << endl;

    s = "rat";
    t = "car";
    cout << sol.isAnagram(s, t) << endl;

    return 0;
}