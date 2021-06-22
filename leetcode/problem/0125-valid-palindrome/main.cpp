#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string edited;
        for(auto&c:s) {
            if (isalpha(c))
                edited += tolower(c);
            if (isdigit(c))
                edited += c;
        }
        if (edited.size() < 2) return true;
        for(size_t b = 0, e = edited.size()-1; b < e; b++, --e){
            if (edited[b] != edited[e])
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol = Solution();
    string s, t;
    
    s = "A man, a plan, a canal: Panama";
    cout << sol.isPalindrome(s) << endl;

    s = "race a car";
    cout << sol.isPalindrome(s) << endl;

    s = "0p";
    cout << sol.isPalindrome(s) << endl;

    return 0;
}