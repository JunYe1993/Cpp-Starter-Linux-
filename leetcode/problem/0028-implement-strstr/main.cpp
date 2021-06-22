#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        int hSize = (int)haystack.size();
        int nSize = (int)needle.size();
        int ret = -1;
        if (nSize > hSize) return ret;
        for (int i = 0; i < hSize-nSize+1; ++i) {
            if (haystack[i] == needle[0]) {
                string temp(haystack.begin()+i, haystack.begin()+i+nSize);
                if (temp == needle)
                    return i;        
            }
        }
        return -1;
    }
};

int main() {
    Solution sol = Solution();
    string haystack, needle;
    
    haystack = "hello";
    needle = "ll";
    cout << sol.strStr(haystack, needle) << endl;

    haystack = "aaaaa";
    needle = "baa";
    cout << sol.strStr(haystack, needle) << endl;

    haystack = "abc";
    needle = "c";
    cout << sol.strStr(haystack, needle) << endl;

    return 0;
}