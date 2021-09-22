#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        for (size_t i = 0, j = s.size()-1; i < j; ) {
            if (isalpha(s[i]) && isalpha(s[j])) {
                char tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
                ++i;
                --j;
            }
            if (!isalpha(s[i])) ++i;
            if (!isalpha(s[j])) --j;
        }
        return s;
    }
};

int main() {
    Solution sol;
    string str;

    str = "ab-cd";
    cout << sol.reverseOnlyLetters(str) << endl;
    str = "a-bC-dEf-ghIj";
    cout << sol.reverseOnlyLetters(str) << endl;
    str = "Test1ng-Leet=code-Q!";
    cout << sol.reverseOnlyLetters(str) << endl;
    
    
    return 0;
}