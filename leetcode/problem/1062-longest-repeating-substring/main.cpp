#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    int longestRepeatingSubstring (string s) {
        set<string> subStrings;
        int size = s.size();
        int length = size - 1;
        for (; length > 0; --length) {
            subStrings.insert(s.substr(0, length));
            for (int j = 1; j + length - 1 < size; ++j) {
                string cur = s.substr(j, length);
                if (subStrings.find(cur) != subStrings.end()) return length;
                else subStrings.insert(cur);
            }
            subStrings.clear();
        }
        return length;
    }
};

int main () {

    Solution sol;
    string str;

    str = "abcd";
    cout << sol.longestRepeatingSubstring (str) << endl;
    str = "abbaba";
    cout << sol.longestRepeatingSubstring (str) << endl;
    str = "aabcaabdaab";
    cout << sol.longestRepeatingSubstring (str) << endl;
    str = "aaaaa";
    cout << sol.longestRepeatingSubstring (str) << endl;

    return 0;
}