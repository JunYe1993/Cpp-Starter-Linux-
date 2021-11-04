#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool backspaceCompare (string s, string t) {
        
        string s_new, t_new;
        int count;

        count = 0;
        for (int i = s.size()-1; i >= 0; --i) {
            if (s[i] == '#') ++count;
            else if (count > 0) --count;
            else s_new = s[i] + s_new;
        }
        count = 0;
        for (int i = t.size()-1; i >= 0; --i) {
            if (t[i] == '#') ++count;
            else if (count > 0) --count;
            else t_new = t[i] + t_new;
        }

        // cout << s_new << endl;
        // cout << t_new << endl;
        return (s_new == t_new);
    }
};

int main() {
    
    Solution sol;
    string s, t;

    s = "ab#c";
    t = "ad#c";
    cout << ((sol.backspaceCompare(s, t)) ? "True":"False") << endl;
    s = "ab##";
    t = "c#d#";
    cout << ((sol.backspaceCompare(s, t)) ? "True":"False") << endl;
    s = "a##c";
    t = "#a#c";
    cout << ((sol.backspaceCompare(s, t)) ? "True":"False") << endl;
    s = "a#c";
    t = "b";
    cout << ((sol.backspaceCompare(s, t)) ? "True":"False") << endl;

    return 0;
}