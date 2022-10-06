#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    void reverse(string &str, size_t s, size_t e) {
        char temp;
        while (s < e) {
            temp = str[s];
            str[s++] = str[e];
            str[e--] = temp;
        }
    }

    string reverseWords(string s) {
        int state = 0;
        int startindex = 0, endindex = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (state == 0 && s[i] != ' ') {
                startindex = i;
                state = 1;
            } else if (state == 1 && s[i] == ' ') {
                endindex = i - 1;
                state = 0;
                reverse(s, startindex, endindex);
            }
        }
        if (state == 1)
            reverse(s, startindex, (int)s.size()-1);

        return s;
    }
};

int main () {
    Solution sol;

    cout << sol.reverseWords("Let's take LeetCode contest") << endl;
    cout << sol.reverseWords("God Ding") << endl;

    return 0;
}