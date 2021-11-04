#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:

    // space (1)
    string reverseWords (string s) {

        reverse (s.begin(), s.end());
        
        int sindex = -1, last = -1;
        for (auto it = s.begin(); it != s.end();) {
            if (*it != ' ' && sindex < 0) sindex = it-s.begin();
            else if (*it == ' ') {
                if (sindex < 0) {
                    s.erase (it);
                    continue;
                } else {
                    reverse (s.begin()+sindex, it);
                    last = it - s.begin();
                    sindex = -1;
                }
            }
            ++it;
        }
        if (sindex >= 0) reverse (s.begin()+sindex, s.end());
        else if (last >= 0) s.resize(last);
        return s;
    }

    // first thought
    string reverseWordsQ (string s) {
        
        string res;
        int count = 0;
        for (int i = s.size()-1; i >= 0; --i) {
            if (s[i] != ' ') {
                ++count;
            } else {
                if (count > 0) {
                    res = res + s.substr(i+1, count) + " ";
                    count = 0;
                }
            }
        }
        if (count > 0) res = res + s.substr(0, count);
        else if (!res.empty()) res.erase(res.end()-1);

        return res;
    }
};

int main () {

    Solution sol;
    string str;

    str = "the sky is blue";
    cout << sol.reverseWords(str) << endl;
    str = "  hello world  ";
    cout << sol.reverseWords(str) << endl;
    str = "a good   example";
    cout << sol.reverseWords(str) << endl;
    str = "  Bob    Loves  Alice   ";
    cout << sol.reverseWords(str) << endl;
    str = "Alice does not even like bob";
    cout << sol.reverseWords(str) << endl;

    return 0;
}