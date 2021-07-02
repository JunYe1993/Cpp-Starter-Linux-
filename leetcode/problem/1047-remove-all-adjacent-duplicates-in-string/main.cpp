#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 暴力解
    string removeDuplicatesQ (string s) {
        for (auto it = s.begin(); it != s.end() && it != s.end()-1;) {
            if (*it == *(it+1)) {
                it = s.erase(it);
                it = s.erase(it);
                if (it != s.begin()) --it;       
            } else {
                ++it;
            }
        }
        return s;
    }

    // stack 解
    string removeDuplicates (string s) {
        string ret;
        for (auto&c:s) {
            if (!ret.empty() && c == ret.back())
                ret.pop_back();
            else
                ret.push_back(c);
        }
        return ret;
    }
};

int main() {
    Solution sol;
    string str;

    str = "abbaca";
    cout << sol.removeDuplicates(str) << endl;

    str = "aaaaaa";
    cout << sol.removeDuplicates(str) << endl;

    return 0;
}